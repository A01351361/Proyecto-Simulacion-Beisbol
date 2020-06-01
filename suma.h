#ifndef SUMA_H //Definir clase
#define SUMA_H
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;


class Suma{ 

  private: //Declaración de variables

    float totalhits;
    int totalcarreras;
  



  public: //Declaración de constructor y metodos
    Suma();
    Suma(float, int);
     Suma operator+(const Suma& valores)
    {
      Suma temp; //Suma d
      temp.totalhits = this->totalhits + valores.totalhits;
      temp.totalcarreras = this->totalcarreras + valores.totalcarreras;
      return temp;
    }
    float getHits();
    int getCarreras();
     

  };








#endif