#ifndef JUGADORES_H//Definir clase
#define JUGADORES_H
#include <string>
#include <sstream>
using namespace std;

class Jugadores { 

  protected: //Declaración de variables
  string nombre; // Nombre del jugador
  string mano; //Derecho o Zurdo
  string posicion; //Posicion en la que juega
  int cansancio; //Cansancio, pero en esta simulacion todavia no se le da uso
  string equipo_pos;



  public: //Declaración de metodos
    Jugadores(): nombre(""),mano(""),posicion(""),equipo_pos(""), cansancio(0){}; //Constructor por default de Jugadores
    Jugadores(string name, string hand,string pos, string equipo, int c): nombre(name), mano(hand), cansancio(c), posicion(pos),  equipo_pos(equipo){};

    string getNombre() {return nombre;}
    string getMano() {return mano;}
    string getPosicion(){return posicion;}
    string getEquipo_pos(){return equipo_pos;}
    int getCansancio(){return cansancio;}
    virtual string to_string() = 0; // Funcion para convertir atributos a string
    virtual double stats_juego() = 0;  //Sobreescritura y Metodo abstracto
    
    
    };
    




//Declaro objeto  que hereda de Jugadores
class Bateador: public Jugadores{

    //Variables de instancia del objeto
    private:
        double bateador;

    //Metodos del objeto
    public:

        Bateador():Jugadores("","","","Visitante",0){};
        Bateador (string nombre, string mano, string posicion, double stats_j, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), bateador(stats_j){};

        double stats_juego(){ return bateador; } //De metodo abstracto
        string to_string();
 
};

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado, en el cual imprime lo que sera el objeto de la alineacion, para un bateador con su respectiva posicion.
 */

 string Bateador::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para un bateo de "<< 
         stats_juego() << " avg, " <<  "es un bateador "<< mano << "\n";
    return aux.str();
}

//Declaro objeto  que hereda de Jugadores
class Pitcher: public Jugadores{

    //Variables de instancia del objeto
    private:
        double carreras, bases_por_bola, entradas, hits;

    //Metodos del objeto

    
    public:

        Pitcher():Jugadores("","","","Local",0){};
        Pitcher (string nombre, string mano, string posicion, double c, double bb, double e, double h, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), carreras(c), bases_por_bola(bb), entradas(e), hits(h){};

        double stats_juego(){ return ((carreras*9)/ entradas); } //De metodo abstracto

        /**
 * double whip regresa un valor estadistico para el pitcher.
 *
 * Toma los hits, las bases por bola y las entradas declaradas en el objetos y realiza un calculo.
 *
 * @param
 * @return whip regresa un numero con decimales determinado como el whip del pitcher.
 */
        double whip(){return ((hits + bases_por_bola)/entradas);}
         string to_string();
 
};

/**
 * to_string convierte los atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado, en el cual imprime lo que sera el objeto de la alineacion para un pitcher en el cual imprime dos variables extras.
 */

string Pitcher::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para una efectividad de "<< 
         stats_juego() << " ERA, " << whip() << " Whip " << " es un pitcher "<< mano << "\n";
    return aux.str();
}
#endif
