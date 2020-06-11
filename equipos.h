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
    void crea_alineacionVisitante();
    void muestra_alineacionVisitante();
    double calc_bateo_equipo(); //Uso del metodo abstracto de Jugador para obtener el bateo colectivo del equipo.
    
  };

/**
 * crea_alineacionLocal genera objetos en Jugadores[]
 *
 * Genera objetos de bateadores y pitcher y posteriormente los
 * guarda en la variable de instancia en j[]
 *
 * @param
 * @return
 **/
void Equipos::crea_alineacionLocal(){

  //Polimorfismo, creamos objetos el cual usaremos para la alineación de los Yankees
  j[local] = new Bateador("Brett Gardner","Derecho","CF",0.261,0);
  local++;
  j[local] = new Bateador("Aaron Judge","Derecho","RF",0.332,0);
  local++;
  j[local] = new Bateador("Giancarlo Stanton","Derecho","LF",0.295,0);
  local++;
  j[local] = new Bateador("Didi Gregorius","Zurdo","SS",0.310,0);
  local++;
  j[local] = new Bateador("Gary Sanchez","Derecho","C",0.283,0);
  local++;
  j[local] = new Bateador("Neil Walker","Derecho","1B",0.264,0);
  local++;
  j[local] = new Bateador("Tyler Austin","Zurdo","DH",0.315,0);
  local++;
  j[local] = new Bateador("Tyler Wade","Derecho","2B",0.301,0);
  local++;
  j[local] = new Bateador("Miguel Andujar","Zurdo","3B",0.247,0);
  local++;
  j[local] = new Pitcher("Gerrit Cole","Derecho","P",2,2,7,3,0);
  local++;

}

/**
 * muestra_alineacionLocal imprime los objetos, los bateadores y el pitcher..
 *
 * utiliza el arreglo j[] y el número de local, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */

void Equipos::muestra_alineacionLocal(){

  //Ciclo para imprimir los objetos
	for(int i=0; i<local ;i++)
		  cout << j[i]->to_string();
     
}
/**
 * calc_bateo_equipo calcula el promedio del bateo de los bateadores de cada equipo y los imprime
 *
 * utiliza el arreglo j[], para recorrer el arreglo hasta el 9, ya que solo queremos los          * bateadores e ir sumandolos.
 *
 * @param 
 * @return "total"(La suma del bateo colectivo)
 */
double Equipos::calc_bateo_equipo(){ //Promedio del bateo de cada equipo de i<9 ya que solo queremos los bateadores, los pitchers cuentan con otras estadisticas

    double total=0;
    for(int i=0; i<9; i++)
        total = total + j[i]->stats_juego();
    return total;
}

/**
 * crea_alineacionVisitante genera objetos en Jugadores[]
 *
 * Genera objetos de bateadores y pitcher y posteriormente los
 * guarda en la variable de instancia en j[]
 *
 * @param
 * @return
 */
void Equipos::crea_alineacionVisitante(){

   //Polimorfismo, creamos objetos el cual usaremos para la alineación de los Nationals
  j[visitante] = new Bateador("Trea Turner","Derecho","SS",0.297,0);
  visitante++;
  j[visitante] = new Bateador("Adam Eaton","Derecho","RF",0.285,0);
  visitante++;
  j[visitante] = new Bateador("Anthony Rendon","Derecho","3B",0.265,0);
  visitante++;
  j[visitante] = new Bateador("Juan Soto","Derecho","LF",0.332,0);
  visitante++;
  j[visitante] = new Bateador("Howie Kendrick","Zurdo","DH",0.278,0);
  visitante++;
  j[visitante] = new Bateador("Asdrubal Cabrera","Derecho","2B",0.267,0);
  visitante++;
  j[visitante] = new Bateador("Ryan Zimmerman","Derecho","1B",0.288,0);
  visitante++;
  j[visitante] = new Bateador("Kurt Susuki","Zurdo","C",0.240,0);
  visitante++;
  j[visitante] = new Bateador("Victor Robles","Derecho","CF",0.274,0);
  visitante++;
  j[visitante] = new Pitcher("Max Scherzer","Derecho","P",4,3,7,5,0);
  visitante++;



}
/**
 * muestra_alineacionVisitante imprime los objetos, los bateadores y el pitcher para el siguiente * equipo.
 *
 * utiliza el arreglo j[] y el número de visitante, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */

void Equipos::muestra_alineacionVisitante(){

  //Ciclo para imprimir los objetos
	for(int i=0; i<visitante ;i++)
		  cout << j[i]->to_string();
     
}



#endif
