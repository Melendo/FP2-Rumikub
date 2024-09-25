#ifndef Soportes_h
#define Soportes_h
#include"Soporte.h"

//CONSTANTES

const int NUMJUG = 2;//Entre 2 y 4	, numero de jugadores
const int INIFICHAS = 14;//Entre 6 y 14 numero de fichas que se reparten inicialmente a cada jugador

//TIPOS

typedef tSoporte tSoportes[NUMJUG];//Array que contiene los soportes de los jugadores

//DECLARACION DE FUNCIONES

void repartir(tBolsa& bolsa, tSoportes& soportes);//Añade las fichas iniciales a un soporte

int menor(const tSoportes soportes);//Devuelve la posicion del array tSoportes con el jugador que va ganando (el que sumando todos los valores de sus fichas tiene menos puntos)

#endif