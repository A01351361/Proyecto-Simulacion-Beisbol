[![Run on Repl.it](https://repl.it/badge/github/A01351361/Proyecto-Simulacion-Beisbol)](https://repl.it/github/A01351361/Proyecto-Simulacion-Beisbol)
# Proyecto-Simulacion-Beisbol
Cuenta con Boton para correr el Codigo en Rep.it **Run on Repl.it**

# Funcionalidad
El programa permite que puedas visualizar las alineaciones de dos equipos diferentes de la MLB, que en este caso es Yankees y Nationals, para poder observar que jugadores participaran durante el juego, los pitchers abridores, y alguna estadisticas recientes de cada uno de los jugadores, con su respectivo previo del juego.

Aparte, el programa permite realizar una simulación del juego de beisbol en el cual se realizan jugadas aleatorias por equipo, con su respectiva probabilidad para que sea más interactivo y puedas apostar con tus amigos sobre quien ganara entre los dos equipos, la simulación dura 5 entradas y al final te arroja un resumen del juego donde te da el resultado, las estadisticas de los bateadores y de los pitchers.

# Consideraciones
El codigo solamente corre en la plataforma de Repl.it, en el cual se ha agregado un boton de **Run on Repl.it** para facilitarlo.



# Explicación Código
Este programa es un simulador elaborado para realizar simulaciones de beisbol con tus equipos favoritos y poder apostar con tus amigos ya que aqui es todo aleatoriamente.


Contamos con una interfaz creada en el Main donde te da tres opciones a escoger, las opciones son las siguientes:
1. Muestra Alineacion // Donde se crean los objetos de los jugadores de sus respectivos equipos.
2. Iniciar Simulacion // La simulacion se inicializa, realizando jugadas con su respectivo porcentaje de probabilidad para que la simulacion sea mas interesante, se juega a 5 entradas cada equipo tiene 5 turnos es decir 15 outs.
3. Salir del Programa // Solamante da las gracias por usar el programa y se cierra.


En la clase de Equipos, realizamos polimorfismo con las clases creadas en Jugadores las cuales se dividen en Jugadores Locales, Jugadores Visitantes, Pitchers. En donde hacemos una lista simulando la alineacion de un equipo de MLB, creando objetos de los jugadores e imprimiendolos cada que se crea el objeto para que en la consola nos muestre la alineacion del equipo visitante y del local, posteriormente se agrego un previo del juego para hacer la simulacion mas interactiva.

En la clase de simulacion se crea una funcion la cual genera numeros aleatorios y dependiendo del numero te arroja una jugada el cual se guarda en el main para realizar la suma de las estadisticas al final y poder realizar una recoplicacion de aquella y dar el resultado final.

En la clase de Jugadores se hacen las variables de instancia para cada jugador, usando un metodo abstracto para que las clases hijas obtengan los stats del jugador pero diferentes, ya sean que son Locales, Visitantes, que si es un pitcher, o un bateador, son funciones que se usan en la clase de Equipos para poder crear los objetos y mandarlos a imprimir.

Finalmente en el Main se realiza un do-while para poder crear un interfa mas interactivo y poder usar las tres opciones que contamos, en el main mandamos a llamar las funciones de muestra_alineacion para mostrar los objetos creados en Equipos. Para el caso 2 (Iniciar Simulacion) se manda a llamar las funciones de Local y Visitante el cual realiza las jugadas aleatoriamentes y las guarda en variables para que al final se sumen y se realicen las estadisticas de bateo y pitcheo de los equipos, asi como las carreras para dar un resultado final del juego. 

Al final del main se le agrega sobrecarga por medio de Suma.h y Suma.cpp el cual realizan la suma de los hits totales entra ambos equipos y las carreras totales entre ambos equipos.

Se agrego:
HERENCIA (En Jugadores)

METODOS DE ACCESO 

SOBREESCRITURA y SOBRECARGA (Suma.cpp y Suma.h) (Jugadores.h)

POLIMORFISMO (Equipos.h, Jugadores.h)

CLASES ABSTRACTAS (Jugadores.h - Virtual stats_jugador () = 0;)

