#include"Fichas.h"

//DEFINICION FUNCIONES

bool operator==(tFicha izq, tFicha der) {return izq.color == der.color && izq.num == der.num;}

void mostrarFicha(tFicha ficha) {

	colorTexto(ficha.color);
	cout << setw(3) << ficha.num;
	colorTexto(BLANCO);
	cout << " ";

}
