#include "Jugadas.h"

//FUNCIONES

void newJugada(tJugada& jugada) {
	int numFichas = NUMFILAS * NUMCOLUMNAS;
	jugada = new tFicha[(numFichas) + 1];
	for (int i = 0; i < numFichas; i++) {//cambiar por inijugada
		jugada[i].num = -1;
		jugada[i].color = BLANCO;
	}
}

bool sonIguales(tJugada izq, tJugada der) {

	int contizq, contder;
	contizq = contarjugada(izq);
	contder = contarjugada(der);
	bool iguales = true;
	int i = 0;
	if (contizq > contder || contder > contizq)
		iguales = false;
	else {
		while (iguales && i < contizq) {
			if (izq[i] == der[i])
				iguales = true;
			else
				iguales = false;
			i++;
		}
	}
	return iguales;
}

int buscar(const tJugada jugada, tFicha ficha) {

	int i = 0, pos = -1;
	bool encontrado = false;
	int contJugada = contarjugada(jugada);

	while (!encontrado && i < contJugada) {
		if (jugada[i] == ficha) {
			encontrado = true;
			pos = i;
		}
		i++;
	}
	return pos;
}

void eliminaFichas(tSoporte& soporte, const tJugada jugada) {

	int contJugada = contarjugada(jugada);
	int j = 0, i = 0;
	bool encontrado = false;
	int contaux =0;
	for (int i = 0; i < contJugada; i++) {
		while (j < soporte.contador && !encontrado) {
			if (soporte.fichas[j] == jugada[i]) {
				for (int k = j; k < soporte.contador; k++)
					soporte.fichas[k] = soporte.fichas[k + 1];
				soporte.contador--;
				
				if (comprobarVacios(soporte)) {
					
					//Copiamos nuestro soporte en un auxiliar
					tSoporte aux;
					iniSoporte(aux, soporte.contador);
					for (int i = 0; i < soporte.contador; i++)
						aux.fichas[i] = soporte.fichas[i];
					contaux = aux.capacidad;
					//Borramos nuestro soporte y lo ampliamos en 8, copiando luego el que teniamos en el auxiliar
					delete [] soporte.fichas;
					
					iniSoporte(soporte, soporte.capacidad - 4);
					soporte.contador = contaux;
					for (int i = 0; i < soporte.contador; i++) {
						soporte.fichas[i] = aux.fichas[i];
					}
					delete [] aux.fichas;
					
				}
				encontrado = true;
			}
			j++;
		}
		j = 0;
		encontrado = false;
	}
}

void iniJugada(tJugada jugada) {

	for (int i = 0; i < NUMCOLUMNAS + 1; i++) {
		jugada[i].num = -1;
		jugada[i].color = VACIO;
	}
}

void mostrarSeries(tSoporte soporte) {
	tJugada aux;
	newJugada(aux);
	int cont = 0, auxCont = 0;
	bool mismocolor = false;

	ordenarPorNum(soporte);

	while (cont <= soporte.contador - 3) {

		auxCont = 0;
		aux[auxCont] = soporte.fichas[cont];
		auxCont++;


		while (cont < soporte.contador && soporte.fichas[cont].num == soporte.fichas[cont + 1].num) {

			mismocolor = false;
			for (int i = 0; i < auxCont; i++) {
				if (soporte.fichas[cont + 1].color == aux[i].color) {
					mismocolor = true;
				}
			}
			if (!mismocolor) {
				aux[auxCont] =  soporte.fichas[cont + 1];
				auxCont++;

			}
			cont++;
		}

		if (auxCont >= 3) {
			aux[auxCont].num = -1;
			auxCont++;
			mostrarJugada(aux);
			cout << endl;
		}
		cont++;
	}
	delete [] aux;
}

void mostrarEscaleras(tSoporte soporte) {
	tJugada aux;
	newJugada(aux);
	int cont = 0;
	bool siguienteNum = false;
	int contAux;
	ordenarPorColor(soporte);


	while (cont <= soporte.contador - 3) {

		contAux = 0;
		aux[contAux] =  soporte.fichas[cont];
		contAux++;


		while ((cont < soporte.contador) && (soporte.fichas[cont].color == soporte.fichas[cont + 1].color) && (soporte.fichas[cont + 1].num == aux[contAux - 1].num + 1
			|| soporte.fichas[cont + 1].num == aux[contAux - 1].num)) {

			siguienteNum = false;

			if (soporte.fichas[cont + 1].num == aux[contAux - 1].num + 1) {
				siguienteNum = true;
			}

			if (siguienteNum) {
				aux[contAux] =  soporte.fichas[cont + 1];
				contAux++;

			}
			cont++;
		}

		if (contAux >= 3) {
			aux[contAux].num = -1;
			contAux++;
			mostrarJugada(aux);
			cout << endl;
		}
		cont++;
	}
	delete [] aux;
}

void mostrarJugada(const tJugada jugada) {

	tFicha aux = jugada[0];
	int i = 0;

	while (aux.num != -1) {
		aux = jugada[i];
		if (aux.num != -1)
			mostrarFicha(jugada[i]);
		i++;
	}
}

bool ponerFicha(tJugada jugada, tFicha ficha) {
	bool distintaficha = false;
	bool añadirescalera = false;
	bool jugadavalida = false;
	int contJugada = contarjugada(jugada);
	if (jugada[0].num == jugada[1].num) {//SI EL PRIMER NUMERO Y EL SEGUNDO SON IGUALES TENEMOS UNA SERIE
		int i = 0;
		distintaficha = true;
		while (i < contJugada && distintaficha) {
			if (jugada[i].color == ficha.color)
				distintaficha = false;
			if (jugada[i].num != ficha.num)
				distintaficha = false;
			i++;
		}
	}
	else {//SI NO ES UNA SERIE ES UNA ESCALERA

		if (ficha.color == jugada[0].color) {
			if (jugada[0].num - 1 == ficha.num)
				añadirescalera = true;
			else if (jugada[contJugada - 1].num + 1 == ficha.num)
				añadirescalera = true;
		}
	}
	if (añadirescalera || distintaficha)
		jugadavalida = true;

	return jugadavalida;
}

void colocarFicha(tJugada& jugada, tFicha ficha) {

	int contJugada = contarjugada(jugada);
	if (jugada[0].num == jugada[1].num) {//Si el color del primero es igual al del segundo entonces tenemos una serie
		jugada[contJugada] = ficha;
		contJugada++;
	}
	else { //Si es una escalera
		if (ficha.num < jugada[0].num) {//Comprobamos si la ficha encaja al comienzo
			for (int i = contJugada - 1; i >= 0; i--) {
				jugada[i + 1] = jugada[i];//Desplazamos la lista una posición a la derecha para ponerla al principio
			}
			jugada[0] = ficha;
			contJugada++;
		}
		else {//Si no encaja al comienzo entonces la colocamos la final
			jugada[contJugada] = ficha;
			contJugada++;
		}
	}
	jugada[contJugada].num = -1;
}

int nuevaJugada(tSoporte soporte, tJugada& jugada) {

	int cont = 0;
	int posicion;

	cout << "Fichas (0 al final): ";

	cin >> posicion;
	while (posicion != 0) {

		jugada[cont] =  soporte.fichas[posicion - 1];
		cont++;
		cin >> posicion;
	}

	return cont;
}

int contarjugada(const tJugada jugada) {

	int cont = 0;
	while (jugada[cont].num != -1) {
		cont++;
	}
	return cont;
}
