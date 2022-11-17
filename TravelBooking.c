#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int dia;
  int mes;
  int ano;
};

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo {
  Voo *voo;
  NoVoo *proximo;
};

struct lista_voo {
  NoVoo *primeiro;
  NoVoo *ultimo;
};

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  NoPassageiro *proximo;
};

struct lista_passageiro {
  NoPassageiro *primeiro;
  NoPassageiro *ultimo;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  // Assento assento;
};

struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
  Agenda *pai;

};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};

// FUNÇÕES LISTA PASSAGEIRO

ListaPassageiro* criaListaPassageiro(){
  ListaPassageiro *listaPassageiro = (ListaPassageiro *)malloc(sizeof(ListaPassageiro));
  listaPassageiro->primeiro = NULL;
  listaPassageiro->ultimo = NULL;

  return listaPassageiro;
}


int enfileiraPassageiro(NoPassageiro* passageiro,ListaPassageiro* fila){
  if(fila->primeiro == NULL){
    fila->primeiro = passageiro;
  }else{
    fila->ultimo->proximo = passageiro;
  }

  fila->ultimo = passageiro;
  
return 1;
}


Passageiro* desenfileiraPassageiro(ListaPassageiro* fila){
  NoPassageiro* aux = fila->primeiro;

    fila->primeiro = aux->proximo;
    if(aux->proximo == NULL){
      fila->ultimo = NULL;
    }

    aux->proximo = NULL;
    Passageiro* passageiro = aux->passageiro;
    free(aux);
    return passageiro;


}

void imprimeLista(ListaPassageiro* fila){
  NoPassageiro* aux = fila->primeiro;
  while(aux != NULL){
    for(int i = 0;i<strlen(aux->passageiro->nome);i++){
    printf("%c",aux->passageiro->nome[i]);

  }
   printf("\n");
    aux = aux->proximo;
  }
  
}

// 


// FUNÇÕES PASSAGEIRO

NoPassageiro* criaNoPassageiro(int id,char *nome,char *endereco){
  NoPassageiro *passageiro_novo_no = (NoPassageiro *)malloc(sizeof(NoPassageiro));
  Passageiro  *passageiro_novo = (Passageiro *)malloc(sizeof(Passageiro));

  passageiro_novo->id=id;
  passageiro_novo->nome = nome;
  passageiro_novo->endereco = endereco;
  passageiro_novo_no->passageiro=passageiro_novo;
  passageiro_novo_no->proximo = NULL;

  return passageiro_novo_no;

}

void imprimePass(NoPassageiro* pass){


  printf("%s\n",pass->passageiro->nome);

  
  
}
// 

// FUNÇÕES VOO

NoVoo* criaNoVoo( int codigo,char *origem,char *destino){
  NoVoo *voo_novo_no = (NoVoo *)malloc(sizeof(NoVoo));
  Voo  *voo_novo = (Voo *)malloc(sizeof(Voo));

  voo_novo->codigo = codigo;
  voo_novo->destino = destino;
  voo_novo->origem = origem;
 
  voo_novo_no->voo=voo_novo;
  voo_novo_no->proximo = NULL;

  return voo_novo_no;

}

// 

// FUNÇÕES LISTA VOO

ListaVoo* criaListaVoo(){
  ListaVoo *listaVoo = (ListaVoo *)malloc(sizeof(ListaVoo));
  listaVoo->primeiro = NULL;
  listaVoo->ultimo = NULL;

  return listaVoo;
}


int enfileiraVoo(NoVoo* voo,ListaVoo* fila){
  if(fila->primeiro == NULL){
    fila->primeiro = voo;
  }else{
    fila->ultimo->proximo = voo;
  }

  fila->ultimo = voo;
  
return 1;
}

Voo* desenfileiraVoo(ListaVoo* fila){
  NoVoo* aux = fila->primeiro;

    fila->primeiro = aux->proximo;
    if(aux->proximo == NULL){
      fila->ultimo = NULL;
    }

    aux->proximo = NULL;
    Voo* voo = aux->voo;
    free(aux);
    return voo;


}
// 

// FUNÇÕES RESERVA


Reserva *criaReserva(int codigo, Data* data, ListaPassageiro* ListaPass, ListaVoo* Listavoo){
  Reserva *novaReserva = (Reserva*) malloc(sizeof(Reserva));

  if(novaReserva == NULL){
    printf("Erro de alocacao");
    return NULL;
  }

  novaReserva->codigo = codigo;
  novaReserva->data_viagem = data;
  novaReserva->passageiro = desenfileiraPassageiro(ListaPass);
  novaReserva->voo = desenfileiraVoo(Listavoo);

  return novaReserva;

}




// 

// FUNÇÃO DATA;

Data* criaData(int dia,int mes,int ano){
  Data *novaData = (Data*) malloc(sizeof(Data));
  novaData->ano = ano;
  novaData->mes = mes;
  novaData->dia = dia;

  return novaData;


}



// Funções ABB

Agenda *criaAgenda(Reserva *reserva){
  Agenda *novaAgenda = (Agenda*) malloc(sizeof(Agenda));

  if(novaAgenda == NULL){
    printf("Erro de alocacao");
    return NULL;
  }

  novaAgenda->reserva = reserva;
  novaAgenda->dir = NULL;
  novaAgenda->esq = NULL;
  novaAgenda->pai = NULL;
  return novaAgenda;


}


Agenda *abb_insere_no(Agenda *raiz, Agenda *no) {
  if(raiz == NULL && no == NULL){
    return NULL;
  }else if(raiz == NULL){
   return no;
  }else if(abb_busca_no(raiz,calculaData(no)) == no){
    printf("Agenda ja existe");
    return NULL;
  }else{
     if(calculaData(no)  < calculaData(raiz)){
      inserirEsquerda(raiz,no);
    }else{
      inserirDireita(raiz,no);
    }
  }
}

int calculaData(Agenda *no){
  int total = 0;
  total += (no->reserva->data_viagem->ano) * 12 * 30;
  total += (no->reserva->data_viagem->mes) * 30;
  total += (no->reserva->data_viagem->dia);
  return total;

}

void inserirEsquerda(Agenda* raiz,Agenda* no){
      if(raiz->esq == NULL){
        no->pai = raiz;
        raiz->esq = no;
      }else{
         if(calculaData(no)  < calculaData(raiz->esq)){
          inserirEsquerda(raiz->esq,no);
         }else{
          inserirDireita(raiz->esq,no);
      }
  }
}

void inserirDireita(Agenda* raiz,Agenda* no){
      if(raiz->dir == NULL){
        no->pai = raiz;
        raiz->dir = no;
      }else{
          if(calculaData(no)  > calculaData(raiz->dir) ){
          inserirDireita(raiz->dir,no);
         }else{
          inserirEsquerda(raiz->dir,no);
      }
  }
}


void imprimir(Agenda *raiz){

  if(raiz != NULL){

    imprimir(raiz->esq);
    printf("%s\n",raiz->reserva->passageiro->nome);
    printf("%s\n",raiz->reserva->voo->destino);
    printf("---\n");


    imprimir(raiz->dir);

  }
}






Agenda *abb_busca_no(Agenda *raiz, int chave) {
  if(raiz == NULL){
    return NULL;
  }else{
    if(raiz->reserva->codigo == chave){
      return raiz;
    }else{
      if(chave < calculaData(raiz) ){
        return abb_busca_no(raiz->esq,chave);
      }else{
        return abb_busca_no(raiz->dir,chave);

      }
    }
  }
}

Agenda *abb_remove_no(Agenda *raiz, Data* data) {
  int chave = 0;
  chave += (data->ano) * 12 * 30;
  chave += (data->mes) * 30;
  chave += (data->dia);

  if(raiz == NULL){
    return NULL;
  }else{
    if(raiz->reserva->data_viagem == data){
      if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        return NULL;
      }else if(raiz->esq != NULL && raiz->dir != NULL){
        Agenda* aux = raiz->esq;
        while (aux->dir != NULL){
          aux = aux->dir;
        }
        raiz->reserva->data_viagem = aux->reserva->data_viagem ;
        aux->reserva->data_viagem = data;
        raiz->esq = abb_remove_no(raiz->esq,data);
        return raiz;

        
      }else{
        Agenda* aux;
        if(raiz->esq != NULL){
          aux = raiz->esq;
        }else{
          aux = raiz->esq;
        }
        free(raiz);
        return aux;
      }
    }else{
      if(chave < calculaData(raiz)){
        raiz->esq = abb_remove_no(raiz->esq,data);
      }else{
        raiz->dir = abb_remove_no(raiz->dir,data);
      }
      return raiz;
    }
  }
}