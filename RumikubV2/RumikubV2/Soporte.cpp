#include "Soporte.h"

//FUNCIONES

void ordenarPorNum(tSoporte& soporte) {
	int pos = 0;
	tFicha tmp;
	bool inter = true;

	for (int i = 1; i < soporte.contador; i++) {
		pos = i;
		
		while (pos > 0 && (soporte.fichas[pos - 1].num > soporte.fichas[pos].num) || soporte.fichas[pos - 1].num == soporte.fichas[pos].num && soporte.fichas[pos - 1].color > soporte.fichas[pos].color) {
			tmp = soporte.fichas[pos];
			soporte.fichas[pos] = soporte.fichas[pos - 1];
			soporte.fichas[pos - 1] = tmp;
			pos--;
		}
	}
}

void ordenarPorColor(tSoporte& soporte) {

	int pos;
	tFicha tmp;

	for (int i = 1; i < soporte.contador; i++) {
		pos = i;

		while (pos > 0 && (soporte.fichas[pos - 1].color > soporte.fichas[pos].color) ||
			soporte.fichas[pos - 1].color == soporte.fichas[pos].color && soporte.fichas[pos - 1].num > soporte.fichas[pos].num) {
			tmp = soporte.fichas[pos];
			soporte.fichas[pos] = soporte.fichas[pos - 1];
			soporte.fichas[pos - 1] = tmp;
			pos--;
		}
	}
}

int puntJug(const tSoporte soporte) {
	int puntuacion = 0;
	for (int i = 0; i < soporte.contador; i++) {
		puntuacion += soporte.fichas[i].num;
	}
	return puntuacion;
}

void mostrar(tSoporte soporte) {
	cout << "Soporte:";
	for (int i = 0; i < soporte.contador; i++)
		mostrarFicha(soporte.fichas[i]);
	cout << endl;
}

void iniSoporte(tSoporte & soporte, int capacidad) {
	soporte.fichas = new tFicha[capacidad];
	soporte.capacidad = capacidad;
	soporte.contador = 0;
}

void nuevaFicha(tSoporte& soporte, tFicha ficha) {

	int auxcont = soporte.contador;
	if (soporte.contador == soporte.capacidad) {
		//Copiamos nuestro soporte en un auxiliar
		tSoporte aux;
		iniSoporte(aux, soporte.contador);
		for (int i = 0; i < soporte.contador; i++)
			aux.fichas[i] = soporte.fichas[i];
		//Borramos nuestro soporte y lo ampliamos en 8, copiando luego el que teniamos en el auxiliar
		delete [] soporte.fichas;
		iniSoporte(soporte, soporte.capacidad + 8);
		soporte.contador = auxcont;
		for (int i = 0; i < soporte.contador; i++) {
			soporte.fichas[i] = aux.fichas[i];
		}
		delete [] aux.fichas;
	
		
	}

	if (ficha.num != -1) {
		soporte.fichas[soporte.contador] = ficha;
		soporte.contador++;
	}
}

void borrarSoporte(tSoporte& soporte) {
	delete [] soporte.fichas;
	soporte.capacidad = 0;
	soporte.contador = 0;
}

bool comprobarVacios(tSoporte soporte) {
	return ((soporte.capacidad - soporte.contador) > 8);
}