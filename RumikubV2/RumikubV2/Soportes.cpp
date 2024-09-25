#include "Soportes.h"

//FUNCIONES

void repartir(tBolsa& bolsa, tSoportes& soportes) {

	for (int i = 0; i < NUMJUG; i++) {
		for (int j = 0; j < INIFICHAS; j++) {
			nuevaFicha(soportes[i],robar(bolsa));
		}
	}
}

int menor(const tSoportes soportes) {
	int ganador = -1;
	int puntuacionAux;
	int puntuacionMax;
	int indiceMax = 0;
	puntuacionMax = puntJug(soportes[0]);
	for (int i = 1; i < NUMJUG; i++) {
		puntuacionAux = puntJug(soportes[i]);
		if (puntuacionAux < puntuacionMax) {
			puntuacionMax = puntuacionAux;
			indiceMax = i;
		}
	}
	return indiceMax;
}

