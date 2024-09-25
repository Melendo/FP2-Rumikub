#include"Fichas.h"

//CONSTANTES
const int NUMFILAS = 8;//Numero de filas en la bolsa
const int NUMCOLUMNAS = 9;//Entre 8 y 13 numero de columnas disponibles de cada color
const int NOFICHA = -1;//Cuando no hay una ficha en la bolsa

//TIPOS
typedef tFichaPtr tArrayBolsa[NUMFILAS][NUMCOLUMNAS];

struct tBolsa {

	tArrayBolsa bolsa;
	int fichasdisp = 0;
};

//DECLARACION DE FUNCIONES

void inicializarBolsa(tBolsa& bolsa);//Genera las fichas dentro de la bolsa

tFicha robar(tBolsa& bolsa);//Devuelve 1 tFicha de la bolsa vaciando su espacio en esta

void mostrar(tBolsa bolsa);//Muestra la bolsa por pantalla

tColor inicializarColor(int columna);//Dada una columna de la bolsa devuelve su color correspondiente

int generarFilaAleatoria();//Genera un numero aleatorio en el intervalo de las filas de la bolsa

int generarColumnaAleatoria(); //Generar un numero aleatorio en el intervalo de las columnas de la bolsa

void delBolsa(tBolsa& bolsa);//Elimina la memoria dinamica de la bolsa

