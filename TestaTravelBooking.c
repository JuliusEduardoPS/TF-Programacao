#include <stdio.h>
#include "TravelBooking.h"

int main(void) {
  char nome[50];
  printf("Digite um nome\n");
  scanf("%50s", nome);

  NoPassageiro* pass1 = criaNoPassageiro(1,nome,"teste" );
  imprimePass(pass1);

  // NoPassageiro* pass2 = criaNoPassageiro(2 ,"rafa","teste2");
  
  // NoPassageiro* pass3 = criaNoPassageiro(3,"yuri","teste3" );
  // NoPassageiro* pass4 = criaNoPassageiro(4,"pablo","teste4");

  // ListaPassageiro* listaPass = criaListaPassageiro();
  // enfileiraPassageiro(pass1,listaPass);
  // enfileiraPassageiro(pass2,listaPass);
  // enfileiraPassageiro(pass3,listaPass);
  // enfileiraPassageiro(pass4,listaPass);



  // NoVoo* voo1 = criaNoVoo(1,"Natal","Salvador");
  // NoVoo* voo2 = criaNoVoo(2,"Fortaleza","SP");
  
  // ListaVoo* listaVoo = criaListaVoo();

  // enfileiraVoo(voo1,listaVoo);
  // enfileiraVoo(voo2,listaVoo);



  // Data* data = criaData(5,10,2023);
  // Data* data2 = criaData(2,10,2023);



  // Reserva* novaReserva = criaReserva(7,data,listaPass,listaVoo);
  // Reserva* novaReserva2 = criaReserva(2,data2,listaPass,listaVoo);


  // Agenda* novaAgenda = criaAgenda(novaReserva);
  // Agenda* novaAgenda2 = criaAgenda(novaReserva2);

  // abb_insere_no(novaAgenda,novaAgenda2);
  // imprimir(novaAgenda);





  // abb_remove_no(novaAgenda,data2);
  // imprimir(novaAgenda);



  return 0;
}


  // ListaPassageiro* lista = criaListaPassageiro();
  // enfileiraPassageiro(pass1,lista);
  // enfileiraPassageiro(pass2,lista);
  // enfileiraPassageiro(pass3,lista);


  // imprimeLista(lista);
  // imprimePass(pass1);