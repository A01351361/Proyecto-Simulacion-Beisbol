/*
* Proyecto Simulacion Beisbol 1.3
* Erick Gerardo Calderon Reyes
* A01351361
* 25/05/20


APP SIMULACION 1.1
Se realizo herencias, sobre carga en las funciones y sobreescritura.
Se agrego polimorfismo con un arreglo para poder imprimir la alineacion de cada equipo que en este caso es de Yankees vs Nationales de la MLB en el cual se le agrego la posicion del jugador, el nombre, el batting average (Porcentaje de hits) y que si es derecho o zurdo, tambien se realizo para los pitchers con su ERA el cual consiste en la cantidad de carreras por juego, usando una alineación creible con los jugadores que tienen en este momento.

APP SIMULACION BEISBOL 1.2
En esta actualización se le agrego la simulación de un juego de beisbol con jugadas aleatorias, el juego consiste en 5 entradas para cada uno de los equipos, local y visitante en donde tendran que hacer hits para generar carreras y poder ganar el partido. Se le agrego una funcion donde consiste en generar numeros aleatorios donde el hit y el out tiene un procentaje de probabilidad en el cual el out es mas probable que el hit, la funcion cuenta con un for para cuando el contador de out llegue a 3 outs se acabe la funcion y guarde los datos de hits y carreras que realizaron los eequipos, asi hasta dentro de 5 entradas para que al final se sume todas las carreras del visitante y del local para generar un resultado final y posteriormente crear un analisis de estadistica el cual te da los numeros de bateo de cada equipo por medio de una formila de batting average y otra formula llamada Whip el cual es para el pitcher que consiste en cuanto es el porcentaje que el pitcher embasa a bateadores por entrada.

La simulacion consiste en simular un juego entre dos equipos donde las jugadas se basan por probabilidades y solo llega a 5 entradas.

APP SIMULACION BEISBOL 1.3
Se le agrego una interfaz para poder interactuar con las diferentes opciones que te dan, para poder visualizar la alineacion, salir del programa e iniciar la simulacion. Se agrego un archivo de suma el cual realiza sobrecarga con la suma de las variables de hits y de carreras.
*/


#include <iostream>   // para imprimir.
 // bibliotecas con objetos de mi proyecto.
#include "jugadores.h"
#include "equipos.h"
#include "simulacion.h"
#ifdef _WIN32
#include <Windows.h> //Libreria para agregar Pausa a la simulacion
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include "suma.h" //Archivo donde se realiza la sobre carga



using namespace std;

int opc1;
string alta;
  float hitsv1; //Definimos la variable donde se guarda el total de hits para cada entrada de los equipos
  float hitsv2;
  float hitsv3;
  float hitsv4;
  float hitsv5;
  float hitsl1;
  float hitsl2;
  float hitsl3;
  float hitsl4;
  float hitsl5;
  int totalcarrerasv1; //Definimos la variable donde se guarda el total de carreras para cada entrada de los equipos
  int totalcarrerasv2;
  int totalcarrerasv3;
  int totalcarrerasv4;
  int totalcarrerasv5;
  int totalcarrerasl1;
  int totalcarrerasl2;
  int totalcarrerasl3;
  int totalcarrerasl4;
  int totalcarrerasl5;



  float totalhitsv;  //Definimos la variable de hits totales del visitante, usamos float en estas ya que al final usaremos la suma de los hits y carreras para realizar estadistica de los pitchers como bateadores y requerimos de los decimales.
  int totalcarrerasv;
  float totalhitsl;
  int totalcarrerasl;
  float Average_v;
  float Average_l;
  float Whip_v;
  float Whip_l;
  int opcion;
  int o1;

  double t = 0;


  
 void Starting ()
    {
    cout<<"\n\tBienvenido al Interfaz de nuestra Simulacion de Beisbol";
    cout<<"\n\n\t¿Deseas entrar a la aplicacion?: ";
    cout<<"\n\t1. Si";
    cout<<"\n\t2. Salir del programa";
  }

    void Interfaz ()
    {
    cout<<"\n\n\tSelecciona una acción: ";
    cout<<"\n\t1. Salir del programa";
    cout<<"\n\t2. Ver Alineacion de los Equipos";
    cout<<"\n\t3. Iniciar Simulacion";
    }
int opcionaplicacion;


   

   
int main(int argc, char* argv[]) {
Equipos equipos;
Simulacion simulacion;
Suma suma;
opcion=1;

cout << "\n\n\tBienvenido al simulador de Beisbol"<<endl;
if (opcion == 1){
  do{
Interfaz();
cout<<"\n\n\tQue deseas hacer: ";
  fflush(stdin);
  cin>>o1;
  system("clear");

switch (o1){
case 2:
	cout << endl << "New York Yankees Line-Up" << endl << endl ;
  equipos.crea_alineacionLocal();  // Creamos alineacion por medio de polimorfismo
  equipos.muestra_alineacionLocal(); // Imprimimos Alineacion visitante
   
  t = equipos.calc_bateo_equipo();
  cout << endl << " Bateo colectivo de " << t/10 << " avg " <<endl << endl;
  cout << endl; sleep(1); 
  cout << " Washington Nationals Line-Up" << endl << endl ; 
  equipos.crea_alineacionVisitante();
  equipos.muestra_alineacionVisitante(); // Imprimimos Alineacion local 
    t = equipos.calc_bateo_equipo();
  cout << endl << " Bateo colectivo de " << t/9 << " avg " <<endl << endl;
  cout << endl; sleep(1); 
  cout << endl << "Previo del juego:" << endl << endl ; sleep(1);// Una breve previa del juego para hacer la simulacion mas interactiva.
    cout << endl << "El dia de hoy tendremos duelo de pitcheo por parte de los dos equipos, en el cual han demostrado la calidad de pitchers que son, contando con muy pocas carreras en lo que va de la temporada regular." << endl << endl <<"Por parte de los Yankees, subira al monticulo Gerrit Cole, proveniente de los Astros de Houston. Cole ha tenido una magnifica temporada regular con una efectividad de 1.55, un Whip de 0.97 y un OBA de 0.199avg esto quiere decir que no concede muchos hits por entrada" << endl
    << endl << "Por parte de los Nationals, subira al diamante el veterano Max Scherzer el cual tiene una temporada regular muy buena como en casi todas las temporadas con una marca de 2.3 de efectividad, 1.3 Whip y un OBA de 0.230avg" << endl << endl ; sleep(1);

    


break;
case 1:
cout <<"\n\t\t¡Gracias por utilizar nuestro Simulador de Beisbol!\n";
cout <<"\t\t¡Usted ha salido del programa!\n";
exit(0);
case 3:
  cout <<  endl <<  "Inicio de simulacion " <<  "..." << endl; sleep (3);
  
  cout << endl << "Entrada 1°, "<< "Yankees " << endl << endl;sleep (1);
  simulacion.crea_jugada_visitante(hitsv1, totalcarrerasv1);


  cout << endl << endl << "Entrada 1°, Nationals" << endl<< endl ;sleep (1);
  simulacion.crea_jugada_local(hitsl1, totalcarrerasl1);



cout << endl << endl << "CAMBIO DE ENTRADA " << endl;sleep(1);
  cout << endl << "Entrada 2°, "<< "Yankees " << endl << endl;sleep (1);
  
  simulacion.crea_jugada_visitante(hitsv2, totalcarrerasv2);


  cout << endl << endl<< "Entrada 2°, Nationals" << endl<< endl ;sleep (1);
  simulacion.crea_jugada_local(hitsl2, totalcarrerasl2);

   cout << endl << endl << "CAMBIO DE ENTRADA " << endl;sleep(1);
  cout << endl << "Entrada 3°, "<< "Yankees " << endl << endl; sleep (1);
  simulacion.crea_jugada_visitante(hitsv3, totalcarrerasv3);
  


  cout << endl << endl<< "Entrada 3°, Nationals" << endl<< endl ;sleep (1);
  simulacion.crea_jugada_local(hitsl3, totalcarrerasl3);
cout << endl << endl << "CAMBIO DE ENTRADA " << endl;sleep(1);
  cout << endl << "Entrada 4°, "<< "Yankees " << endl << endl; sleep (2);
  simulacion.crea_jugada_visitante(hitsv4, totalcarrerasv4);


  cout << endl << endl<< "Entrada 4°, Nationals" << endl<< endl ;sleep (1);
  simulacion.crea_jugada_local(hitsl4, totalcarrerasl4);
cout << endl << endl << "CAMBIO DE ENTRADA " << endl;sleep(1);
   cout << endl << "Entrada 5°, "<< "Yankees " << endl << endl; sleep (1);
  simulacion.crea_jugada_visitante(hitsv5, totalcarrerasv5);

  cout << endl << endl<< "Entrada 5°, Nationals" << endl<< endl ;sleep (1);
  simulacion.crea_jugada_local(hitsl5, totalcarrerasl5);

 cout << endl << endl << "RESUMEN DEL JUEGO " << endl;sleep (2);

totalcarrerasv =  totalcarrerasv1 + totalcarrerasv2 + totalcarrerasv3 + totalcarrerasv4 + totalcarrerasv5;

totalcarrerasl = totalcarrerasl1 + totalcarrerasl2 + totalcarrerasl3 + totalcarrerasl4 + totalcarrerasl5;

totalhitsv = hitsv1 + hitsv2 + hitsv3 + hitsv4 + hitsv5;

totalhitsl = hitsl1 + hitsl2 + hitsl3 + hitsl4 + hitsl5;

cout  << endl << "RESULTADO " << endl<< endl;sleep (1);
cout << "Yankees " << totalcarrerasv << " - " << totalcarrerasl << " Nationals" << endl;

cout  << endl<< endl << "ESTADISTICAS DEL JUEGO " << endl<< endl;sleep (1);

cout << endl << "Total de hits de Yankees " << hitsv1 + hitsv2 + hitsv3 + hitsv4 + hitsv5; sleep (1);
cout << endl << "Total de hits de Nationals " << hitsl1 + hitsl2 + hitsl3 + hitsl4 + hitsl5<< endl; sleep (1);

cout << endl << "Total de carreras de Yankees " << totalcarrerasv;
cout << endl << "Total de carreras de Nationals " << totalcarrerasl; sleep (1);
Average_v = (totalhitsv / (15+totalhitsv)); // Sacamos el bateo por medio de formula
Average_l = (totalhitsl / (15+totalhitsl));
Whip_v = (totalhitsl / 15);  // Sacamos el whip del pitcher por medio de formula
Whip_l = (totalhitsv / 15); 
cout << endl << endl << "Average de bateo de Yankees " << Average_v<< " avg";

cout << endl << "Average de bateo de Nationals " << Average_l << " avg"; sleep (1);

cout << endl << endl << "Stats del pitcher Gerrit Cole (Yankees) " << endl << "OBA: " << Average_l << " avg" << endl <<  "Whip: " << Whip_v << endl;

cout << endl << "Stats del pitcher Max Scherzer (Nationals) " << endl << "OBA: " << Average_v << " avg" << endl <<  "Whip: " << Whip_l << endl;

Suma s1(totalhitsv,totalcarrerasv); // Sobrecarga
Suma s2(totalhitsl,totalcarrerasl);
Suma s3;
s3 = s1 + s2;
cout << endl << "El total de hits entre ambos equipos fue de " << s3.getHits() << ", el total de carreras entre ambos equipos fue de " << s3.getCarreras() << endl;
break;
}
  } while(o1!=4);}
  cout <<"No ha escogido un numero valido";
  exit(0);
return 0;



}