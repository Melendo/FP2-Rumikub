#include"Jugadas.h"

//CONSTANTES

//TIPOS

typedef tJugada tArrayJugadas[NUMCOLUMNAS * 2];

struct tTablero {

	tArrayJugadas jugadas;
	int contador = 0;

};

//DECLARACION FUNCIONES

int menu();//Muestra el menu por pantalla con las opciones Ordenar num, ordenar col, sugerir, poner y fin

void nuevaJugada(tTablero& tablero, tJugada jugada);//Inserta una nueva jugada en el tablero

bool jugar(tTablero& tablero, tSoporte& soporte);//Permite al usuario colocar fichas de su soporte en el tablero, como nuevas series o escaleras, o fichas independientes en jugadas que haya sobre el tablero

void mostrar(tTablero& tablero);//Muestra el tablero por pantalla

bool turno(const int numTurno, tSoportes& soportes, tTablero& tablero, tBolsa& bolsa);//En esta funcion se juega el turno de cada jugador, devuelve true si el jugador se queda sin fichas

void mostrarIndices(int num);//Muestra los indices para seleccionar las fichas

void delTablero(tTablero& tablero);//Elimina la memoria dinamica del tablero



