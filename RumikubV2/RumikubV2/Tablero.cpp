#include "Tablero.h"

//FUNCIONES

int menu() {


	int opcion;
	cout << "1: Ordenar por num, ";
	cout << "2: Ordenar por color, ";
	cout << "3: Sugerir, ";
	cout << "4: Poner, ";
	cout << "5: Sig, ";
	cout << "0: Fin >>>";

	cin >> opcion;

	while (opcion < 0 || opcion > 5) {

		cout << "El numero introducido no se corresponde con ninguna opcion";
		cout << "Introduzca otra opcion >>>";
		cin >> opcion;
	}

	return opcion;
}

void nuevaJugada(tTablero& tablero, tJugada jugada) {

	int contJugada = contarjugada(jugada), aux = 0;
	newJugada(tablero.jugadas[tablero.contador]);
	for (int i = 0; i < contJugada; i++) {
		
		tablero.jugadas[tablero.contador][i] = jugada[i];
		aux = i;
	}
	tablero.jugadas[tablero.contador][aux + 1].num = -1;
	tablero.contador++;

}

bool jugar(tTablero& tablero, tSoporte& soporte) {

	int cont, pos, numjugada = 0;
	tJugada jugada;
	newJugada(jugada);
	tTablero tabaux;
	tabaux.contador = 0;
	bool jugadaValida = false, aux;

	cont = nuevaJugada(soporte, jugada);
	int contJugada = contarjugada(jugada);
	cout << "Jugada: ";
	mostrarJugada(jugada);
	if (cont == 0) {
		jugadaValida = false;
		cout << " -No se ha introducido ninguna jugada\n\n";
	}
	else if (cont == 2) {
		jugadaValida = false;
		cout << " -Jugada no valida\n\n";
	}
	else if (cont == 1) {
		for (int i = 0; i < tablero.contador; i++) {

			aux = ponerFicha(tablero.jugadas[i], jugada[0]);

			if (aux) {
				nuevaJugada(tabaux, tablero.jugadas[i]);
			}

		}
		if (tabaux.contador > 0) {

			if (tabaux.contador > 1) {//SI HAY MAS DE UNA JUGADA DONDE PONER SE LE DA AL JUGADOR LA OPCION DE ELEGIR
				cout << "Hay mas de una jugada donde poner la ficha" << endl;
				for (int i = 0; i < tabaux.contador; i++) {
					cout << i << " ";
					mostrarJugada(tabaux.jugadas[i]);
					cout << endl;
				}
				cout << "Escoja jugada: ";
				cin >> numjugada;
			}
			int i = 0;
			bool encontrado = false;

			while (i < tablero.contador && !encontrado) {
				if (sonIguales(tablero.jugadas[i], tabaux.jugadas[numjugada])) {
					encontrado = true;
				}
				i++;
			}

			colocarFicha(tablero.jugadas[i - 1], jugada[0]);
			eliminaFichas(soporte, tablero.jugadas[i - 1]);
			jugadaValida = true;
			cout << " -Se ha anadido correctamente la ficha\n\n";

		}
		else {
			jugadaValida = false;
			cout << " -No se ha podido anadir la ficha en ninguna jugada del tablero\n\n";
		}
	}

	else {
		//COMPROBAR SI ES UNA SERIE
		bool esserie = true;
		bool esescalera = false;
		int i = 1;
		tFicha ficha = jugada[0];
		while (i < contJugada && esserie) {
			if (ficha.num == jugada[i].num)
				if (ficha.color != jugada[i].color) {
					ficha = jugada[i];
				}
				else
					esserie = false;
			else
				esserie = false;
			i++;
		}
		if (esserie) {
			cout << " -Serie correcta!\n\n";
			jugadaValida == true;
		}

		if (!esserie) {//SI NO ES SERIE DEBE SER ESCALERA
			i = 1;
			ficha = jugada[0];
			esescalera = true;

			while (esescalera && i < contJugada) {
				if (ficha.color == jugada[i].color)
					if (jugada[i].num - 1 == ficha.num)
						ficha = jugada[i];
					else
						esescalera = false;
				else
					esescalera = false;
				i++;

				if (esescalera) {
					jugadaValida == true;
				}
			}
			if (esescalera) {
				cout << " -Escalera correcta!\n\n";
			}
		}

		if (!esescalera && !esserie) {
			cout << " -Jugada incorrecta\n\n";
		}

		if (esescalera || esserie) {
			nuevaJugada(tablero, jugada);
			eliminaFichas(soporte, jugada);
		}
	}
	delTablero(tabaux);
	delete[] jugada;
	return jugadaValida;
}

void mostrar(tTablero& tablero) {

	cout << "Tablero:\n";
	for (int i = 0; i < tablero.contador; i++) {
		cout << i + 1 << ": ";
		mostrarJugada(tablero.jugadas[i]);

		cout << endl;
	}
}

bool turno(const int numTurno, tSoportes& soportes, tTablero& tablero, tBolsa& bolsa) {
	bool finJuego = false;
	bool endTurno = false;
	int opcion;
	int poneFicha = 0;


	while (!endTurno) {
		mostrar(tablero);
		cout << "\nTurno para el jugador " << numTurno + 1 << endl;
		mostrar(soportes[numTurno]);
		opcion = menu();
		switch (opcion) {
		case 1:
			ordenarPorNum(soportes[numTurno]);
			break;
		case 2:
			ordenarPorColor(soportes[numTurno]);
			break;
		case 3:
			mostrarSeries(soportes[numTurno]);
			mostrarEscaleras(soportes[numTurno]);
			break;
		case 4:
			mostrar(tablero);
			cout << endl;
			mostrar(soportes[numTurno]);
			mostrarIndices(soportes[numTurno].contador);
			if (jugar(tablero, soportes[numTurno])) {
				poneFicha++;
			}

			break;
		case 5:
			endTurno = true;
			break;

		case 0:
			endTurno = true;
			finJuego = true;
			break;
		}
	}

	if (poneFicha == 0) {
		nuevaFicha(soportes[numTurno], robar(bolsa));
	}

	return finJuego;
}

void mostrarIndices(int num) {

	cout << "	";
	for (int i = 1; i < num + 1; i++) {
		tFicha ficha;
		ficha.num = i;
		ficha.color = BLANCO;
		mostrarFicha(ficha);
	}
	

	cout << endl;
}

void delTablero(tTablero& tablero) {
	for (int i = 0; i < tablero.contador; i++) {
		delete [] tablero.jugadas[i];
	}
}
