#ifndef SIMULACION_H //Definir clase
#define SIMULACION_H
#ifdef _WIN32
#include <Windows.h> //Para PAUSAS
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "jugadores.h" //Biblioteca con mis objetos a usar que en este caso es Jugadores

#include <stdio.h>
#include <random> //Biblioteca para crear numeros aleatorios

using namespace std;


class Simulacion { 

  private: //Declaración de variables
    int hits; 
    int dato;
    float totalhits;
    int totalcarreras;
    float totalhitsv;
    int totalcarrerasv;
  



  public: //Declaración de constructor y metodos
    Simulacion(): hits(0), totalhits(0), totalcarreras(0), totalhitsv(0), totalcarrerasv(0){};;
    Simulacion(int h, float th, int tc,float thl, int tcl){
      hits = h;
      totalhits = thl;
      totalcarreras = tcl;
      totalhits = th;
      totalcarreras = tc;
  


    } //Construcutor
    int getHits(){return hits;}
    int getDato(){return dato;}
    int getTotalHits(){return totalhits;}
    int crea_jugada_local(float &totalhitsl, int &totalcarrerasl);
    int crea_jugada_visitante(float &totalhits, int &totalcarreras);
   
  };


int Simulacion::crea_jugada_visitante(float &totalhits, int &totalcarreras){
   random_device rd; //Genero un numero aleatorio de 1 a 5
   mt19937 mt(rd());
   uniform_int_distribution<int> dist(1, 5); //Rango 1 a 5
   int hits =0;
   int carreras = 0;
  
   for (int i=0; i < 3;){ //Funcion for en la cual va de 0 a 3 que quiere decir que hubo 3 outs en la funcion. La funcion consiste en que se genera un numero aleatorio y dependiendo del numero que sera de 1 a 5 se inicializa un if para determinar que jugada fue.
     sleep(1);
    if (dist(mt) == 1 ){
        hits++;
        cout << "jugada = Hit" << endl<< endl;
        ;}
      
      else if (dist(mt) ==  2 ||dist(mt) == 3 || dist(mt) == 4 || dist(mt) == 5) {
        cout << "jugada = Out" << endl<< endl;;
        i++;}
      }
        totalhits = hits;
    
      if (hits > 2){ // Si hits es mayor a 2 se inicializa esta funcion en la cual la variable carreras es igual a los hits totales del equipo en esa entrada menos 2 ya que si hay 2 hits quiere decir que en las bases se encuentra uno en primera base y otro en segunda base. La probabilidad que si hay otro hit el de 2da base anote. Entonces carreras se iguala a Hits -2.
        int carreras(0);
        carreras = hits - 2;
        cout << "Carreras Anotadas: " << carreras << endl;
        totalcarreras = carreras;}
      else {
        cout << "No hubo carreras anotadas" << endl;}
      
      cout << "Hits Totales:  " << totalhits <<endl ;  sleep(1);
     
      return(totalcarreras);
 
  }

 int Simulacion::crea_jugada_local(float &totalhitsl, int &totalcarrerasl){
   random_device rd; //Genero un numero aleatorio de 1 a 5
   mt19937 mt(rd());
   uniform_int_distribution<int> dist(1, 5); //Rango 1 a 5
   int hitsl =0;
   int carrerasl = 0;
  
   for (int i=0; i < 3;){ //Funcion for en la cual va de 0 a 3 que quiere decir que hubo 3 outs en la funcion. La funcion consiste en que se genera un numero aleatorio y dependiendo del numero que sera de 1 a 5 se inicializa un if para determinar que jugada fue.
     sleep(1);
    if (dist(mt) == 1 ){
        hitsl++;
        cout << "jugada = Hit" << endl<< endl;
        ;}
      
      else if (dist(mt) ==  2 ||dist(mt) == 3 || dist(mt) == 4 || dist(mt) == 5) {
        cout << "jugada = Out" << endl<< endl;;
        i++;}
      }
        totalhitsl = hitsl;
    
      if (hitsl > 2){// Si hits es mayor a 2 se inicializa esta funcion en la cual la variable carreras es igual a los hits totales del equipo en esa entrada menos 2 ya que si hay 2 hits quiere decir que en las bases se encuentra uno en primera base y otro en segunda base. La probabilidad que si hay otro hit el de 2da base anote. Entonces carreras se iguala a Hits -2.
        int carrerasl(0);
        carrerasl = hitsl - 2;
        cout << "Carreras Anotadas: " << carrerasl << endl;
        totalcarrerasl = carrerasl;}
      else {
        cout << "No hubo carreras anotadas" << endl;}
      
      cout << "Hits Totales:  " << totalhitsl <<endl ;  sleep(1);
     
      return(totalcarrerasl);
 
  }
    
#endif