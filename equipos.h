#ifndef EQUIPOS_H//Definir clase
#define EQUIPOS_H
#include <string>
#include <iostream>
#include <sstream>
#include "jugadores.h" //Biblioteca con mis objetos a usar que en este caso es Jugadores

using namespace std;
const int MAX = 100;


class Equipos { 

  private: //Declaración de variables
    int local; //Equipo Local
    int visitante; //Equipo Visitante
    Jugadores *j[MAX]; //apuntador para Jugadores



  public: //Declaración de constructor y metodos
    Equipos(): local(0),visitante(0){}; //Construcutor
    void crea_alineacionLocal();
    void muestra_alineacionLocal();
    void muestra_alineacion(string posicion);
    void crea_alineacionVisitante();
    void muestra_alineacionVisitante();
    
  };

void Equipos::crea_alineacionLocal(){

  //Polimorfismo, creamos objetos el cual usaremos para la alineación de los Yankees
  j[local] = new Local("Brett Gardner","Derecho","CF",0.261,0);
  local++;
  j[local] = new Local("Aaron Judge","Derecho","RF",0.332,0);
  local++;
  j[local] = new Local("Giancarlo Stanton","Derecho","LF",0.295,0);
  local++;
  j[local] = new Local("Didi Gregorius","Zurdo","SS",0.310,0);
  local++;
  j[local] = new Local("Gary Sanchez","Derecho","C",0.283,0);
  local++;
  j[local] = new Local("Neil Walker","Derecho","1B",0.264,0);
  local++;
  j[local] = new Local("Tyler Austin","Zurdo","DH",0.315,0);
  local++;
  j[local] = new Local("Tyler Wade","Derecho","2B",0.301,0);
  local++;
  j[local] = new Local("Miguel Andujar","Zurdo","3B",0.247,0);
  local++;
  j[local] = new Pitcher_Local("Gerrit Cole","Derecho","P",1.55,0);
  local++;

}
void Equipos::muestra_alineacionLocal(){

  //Ciclo para imprimir los objetos
	for(int i=0; i<local ;i++)
		  cout << j[i]->to_string();
     
}

void Equipos::crea_alineacionVisitante(){

   //Polimorfismo, creamos objetos el cual usaremos para la alineación de los Nationals
  j[visitante] = new Visitante("Trea Turner","Derecho","SS",0.297,0);
  visitante++;
  j[visitante] = new Local("Adam Eaton","Derecho","RF",0.285,0);
  visitante++;
  j[visitante] = new Local("Anthony Rendon","Derecho","3B",0.265,0);
  visitante++;
  j[visitante] = new Local("Juan Soto","Derecho","LF",0.332,0);
  visitante++;
  j[visitante] = new Local("Howie Kendrick","Zurdo","DH",0.278,0);
  visitante++;
  j[visitante] = new Local("Asdrubal Cabrera","Derecho","2B",0.267,0);
  visitante++;
  j[visitante] = new Local("Ryan Zimmerman","Derecho","1B",0.288,0);
  visitante++;
  j[visitante] = new Local("Kurt Susuki","Zurdo","C",0.240,0);
  visitante++;
  j[visitante] = new Local("Victor Robles","Derecho","CF",0.274,0);
  visitante++;
  j[visitante] = new Pitcher_Visitante("Max Scherzer","Derecho","P",2.3,0);
  visitante++;



}
void Equipos::muestra_alineacionVisitante(){

  //Ciclo para imprimir los objetos
	for(int i=0; i<visitante ;i++)
		  cout << j[i]->to_string();
     
}
#endif
