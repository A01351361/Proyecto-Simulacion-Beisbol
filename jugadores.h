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
class Local: public Jugadores{

    //Variables de instancia del objeto
    private:
        double bateador_local;

    //Metodos del objeto
    public:

        Local():Jugadores("","","","Local",0){};
        Local (string nombre, string mano, string posicion, double stats_j, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), bateador_local(stats_j){};

        double stats_juego(){ return bateador_local; }
        string to_string();
};
 string Local::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para un bateo de "<< 
         bateador_local << " avg, " <<  "es un bateador "<< mano << "\n";
    return aux.str();
}


//Declaro objeto  que hereda de Jugadores
class Visitante: public Jugadores{

    //Variables de instancia del objeto
    private:
        double bateador_visitante;

    //Metodos del objeto
    public:

        Visitante():Jugadores("","","","Visitante",0){};
        Visitante (string nombre, string mano, string posicion, double stats_j, int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), bateador_visitante(stats_j){};

        double stats_juego(){ return bateador_visitante; }
        string to_string();
 
};

 string Visitante::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para un bateo de "<< 
         bateador_visitante << " avg, " <<  "es un bateador "<< mano << "\n";
    return aux.str();
}

//Declaro objeto  que hereda de Jugadores
class Pitcher_Local: public Jugadores{

    //Variables de instancia del objeto
    private:
        double bateo, whip;

    //Metodos del objeto

    
    public:

        Pitcher_Local():Jugadores("","","","Local",0){};
        Pitcher_Local (string nombre, string mano, string posicion, double b, double w , int cansancio):
          Jugadores(nombre,mano,posicion,"Local",cansancio), bateo(b), whip(w){};

        double stats_juego(){ return bateo, whip; }
         string to_string();
 
};

string Pitcher_Local::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para una efectividad de "<< 
         bateo << " ERA, "  << whip << " whip "<<  " es un pitcher "<< mano << "\n";
    return aux.str();
}
//Declaro objeto  que hereda de Jugadores
class Pitcher_Visitante: public Jugadores{

    //Variables de instancia del objeto
    private:
        double bateo_v, whip_v;

    //Metodos del objeto
    public:

        Pitcher_Visitante():Jugadores("","","","Visitante",0){};
        Pitcher_Visitante (string nombre, string mano, string posicion, double b_v, double w_v , int cansancio):
          Jugadores(nombre,mano,posicion,"Visitante",cansancio),bateo_v(b_v), whip_v(w_v){};

        double stats_juego(){ return bateo_v, whip_v; }
        string to_string();
  
 
};

string Pitcher_Visitante::to_string(){
    stringstream aux;
    aux << " " << posicion << " - " << nombre << " " << "para una efectividad de "<< 
         bateo_v << " ERA, "<< whip_v << " whip " <<  "es un pitcher "<< mano << "\n";
    return aux.str();
}


#endif
