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
  int cansancio; 
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
    virtual double stats_juego() = 0;  //Sobreescritura
    
    };
    
  



//Declaro objeto  que hereda de Jugadores
class Local: public Jugadores{

    //Variables de instancia del objeto
    private:
        double stats_jugador;

    //Metodos del objeto
    public:

        Local():Jugadores("","","","Local",0){};
        Local (string nombre, string mano, string posicion, double stats_j, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), stats_jugador(stats_j){};

        string getNombre(){ return nombre; }
        string getMano(){ return mano; }
        string getPosicion(){ return posicion; }
        int  getCansancio(){ return cansancio; }
        double stats_juego(){ return stats_jugador; }
        string to_string();
};
 string Local::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para un bateo de "<< 
         stats_jugador << " avg, " <<  "es un bateador "<< mano << "\n";
    return aux.str();
}


//Declaro objeto  que hereda de Jugadores
class Visitante: public Jugadores{

    //Variables de instancia del objeto
    private:
        double stats_jugador;

    //Metodos del objeto
    public:

        Visitante():Jugadores("","","","Visitante",0){};
        Visitante (string nombre, string mano, string posicion, double stats_j, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), stats_jugador(stats_j){};

        string getNombre(){ return nombre; }
        string getMano(){ return mano; }
        string getPosicion(){ return posicion; }
        double stats_juego(){ return stats_jugador; }
       
        string to_string();
 
};

 string Visitante::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para un bateo de "<< 
         stats_jugador << " avg, " <<  "es un bateador "<< mano << "\n";
    return aux.str();
}

//Declaro objeto  que hereda de Jugadores
class Pitcher_Local: public Jugadores{

    //Variables de instancia del objeto
    private:
        double stats_jugador;

    //Metodos del objeto

    
    public:

        Pitcher_Local():Jugadores("","","","Local",0){};
        Pitcher_Local (string nombre, string mano, string posicion, double stats_p_l, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), stats_jugador(stats_p_l){};

        string getNombre(){ return nombre; }
        string getMano(){ return mano; }
        string getPosicion(){ return posicion; }
        string to_string();
        double stats_juego(){ return stats_jugador; }
    
 
};

string Pitcher_Local::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para una efectividad de "<< 
         stats_jugador << " ERA, " <<  "es un pitcher "<< mano << "\n";
    return aux.str();
}
//Declaro objeto  que hereda de Jugadores
class Pitcher_Visitante: public Jugadores{

    //Variables de instancia del objeto
    private:
        double stats_jugador;

    //Metodos del objeto
    public:

        Pitcher_Visitante():Jugadores("","","","Visitante",0){};
        Pitcher_Visitante (string nombre, string mano, string posicion, double stats_p_v, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), stats_jugador(stats_p_v){};

        string getNombre(){ return nombre; }
        string getMano(){ return mano; }
        string getPosicion(){ return posicion; }
        double stats_juego(){ return stats_jugador; }
        string to_string();
  
 
};

string Pitcher_Visitante::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para una efectividad de "<< 
         stats_jugador << " ERA, " <<  "es un pitcher "<< mano << "\n";
    return aux.str();
}


#endif
