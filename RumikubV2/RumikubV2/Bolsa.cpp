#include "Bolsa.h"

//FUNCIONES
void inicializarBolsa(tBolsa& bolsa) {
	for (int i = 0; i < NUMFILAS; i++) {
		for (int j = 0; j < NUMCOLUMNAS; j++) {
			bolsa.bolsa[i][j] = new tFicha();
			bolsa.bolsa[i][j]->color = inicializarColor(i);
			bolsa.bolsa[i][j]->num = j + 1;
			bolsa.fichasdisp++;
		}
	}

	
}

tColor inicializarColor(int columna) {

	tColor color = BLANCO;

	if (columna == 0 || columna == 4)
		color = ROJO;
	else if (columna == 1 || columna == 5)
		color = AMARILLO;
	else if (columna == 2 || columna == 6)
		color = VERDE;
	else if(columna == 3 || columna == 7)
		color = AZUL;

	return color;
}

tFicha robar(tBolsa& bolsa) {

	int f, c, auxf, auxc;
	bool valido = false, vuelta = false, nohayfichas = false;
	tFicha ficha;
	ficha.color = VACIO;
	ficha.num = -1;

	f = generarFilaAleatoria();
	c = generarColumnaAleatoria();

	auxf = f;
	auxc = c;

	while (bolsa.bolsa[f][c] == NULL && !nohayfichas) {

		c++;
		if (c > NUMCOLUMNAS - 1) {
			f++;
			c = 0;
		}
		if (f > NUMFILAS - 1) {

			f = 0;
			c = 0;
			vuelta = true;
		}
		if (f == auxf && c == auxc && vuelta) {
			nohayfichas = true;
		}
	}

	if (!nohayfichas) {
		ficha = *bolsa.bolsa[f][c];
		bolsa.fichasdisp--;
		delete bolsa.bolsa[f][c];
		bolsa.bolsa[f][c] = NULL;
	}
	return ficha;
}

int generarColumnaAleatoria() {
	return rand() % NUMCOLUMNAS;
}

int generarFilaAleatoria() {
	return rand() % NUMFILAS;
}

void mostrar(tBolsa bolsa) {

	for (int j = 0; j < NUMFILAS; j++) {
		for (int i = 0; i < NUMCOLUMNAS; i++) {
			if (bolsa.bolsa[j][i] != NULL) {
				colorTexto(bolsa.bolsa[j][i]->color);
				cout << bolsa.bolsa[j][i]->num << " ";
			}
			else {
				colorTexto(BLANCO);
				cout << -1 << " ";
			}
		}
		cout << endl;
	}
	colorTexto(BLANCO);
	cout << endl;
}

void delBolsa(tBolsa& bolsa) {
	for (int i = 0; i < NUMFILAS; i++) {
		for (int j = 0; j < NUMCOLUMNAS; j++) {
			delete bolsa.bolsa[i][j];
		}
	}
}

