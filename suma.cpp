#include "suma.h"

Suma::Suma() //Uso del CPP para realizar la sobrecarga 
{

}

Suma::Suma(float valoresH, int valoresC){
  totalhits = valoresH;
  totalcarreras = valoresC;
}

float Suma::getHits()
{
  return totalhits;
}

int Suma::getCarreras()
{
  return totalcarreras;
}