#include"Colores.h"


using namespace std;

//TIPOS
struct tFicha {//Almacenamos la informaci�n de cada ficha

	tColor color;
	int num;
};

typedef tFicha* tFichaPtr;
//FUNCIONES

bool operator==(tFicha izq, tFicha der); //Sobrecarga del operador == para comparar dos fichas

void mostrarFicha(tFicha ficha);//Muestra la ficha por pantalla