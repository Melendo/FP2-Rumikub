#include"Bolsa.h"

//CONSTANTES

const int MAXFICHAS = 50;//Máximo de fichas que puede tener un jugador
const int INISOPORTE = 8;
//TIPOS

struct tSoporte {//Contiene la lista de fichas de cada jugador

	tFichaPtr fichas;
	int contador = 0;
	int capacidad = 0;

};


//DECLARACION FUNCIONES

void ordenarPorNum(tSoporte& soporte);//Ordena las fichas del soporte por números de menor a mayor

void ordenarPorColor(tSoporte& soporte); //Ordena por color el soporte que le des

int puntJug(const tSoporte soporte);//Devuelve la puntucación de un jugador particular

void mostrar(tSoporte soporte);//Muestra el soporte por pantalla

void iniSoporte(tSoporte &soporte, int capacidad);//Crea un soporte de 8 posiciones en memoria dinamica

void nuevaFicha(tSoporte& soporte, tFicha ficha); //Añade una ficha al soporte, si esta lleno lo amplia en 8 

bool comprobarVacios(tSoporte soporte);//Comprueba el numero de posiciones vacias de cada soporte

void borrarSoporte(tSoporte& soporte);//Borra un soporte de la existencia