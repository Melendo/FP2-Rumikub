/*
Nombres: Ignacio Melendo, Nico Trefftz
Grupo: G

*/

#include"Tablero.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>


int main() {

    tBolsa bolsa;
    tTablero tablero;
    tSoportes soportes;
    bool victoria = false;
    int turnoDe = 0;
    int victoriaDe = -1;
    srand(time(NULL));

    turnoDe = rand() % NUMJUG;

    inicializarBolsa(bolsa);
    for (int i = 0; i < NUMJUG; i++) {
        iniSoporte(soportes[i], INISOPORTE);
    }
    repartir(bolsa, soportes);

    while (!victoria) {

        victoria = turno(turnoDe, soportes, tablero, bolsa);

        if (turnoDe == NUMJUG - 1) {
            turnoDe = 0;
        }
        else {
            turnoDe++;
        }
        for (int i = 0; i < NUMJUG; i++) {
            if (soportes[i].contador == 0) {
                victoria = true;
            }
        }
        if (bolsa.fichasdisp == 0) {
            victoria = true;

        }
        for (int i = 0; i < NUMJUG; i++) {
            if (soportes[i].contador == 0) {
                victoria = true;
            }
        }


    }

    victoriaDe = menor(soportes);
    cout << "El jugador " << victoriaDe + 1 << " ha ganado el juego!\n";


    delTablero(tablero);//Se borra el tablero con todas las jugadas
    delBolsa(bolsa);//Se borran todas las fichas de la bolsa
    for (int i = 0; i < NUMJUG; i++) { // Se borran los soportes de los jugadores
        borrarSoporte(soportes[i]);
    }

    _CrtDumpMemoryLeaks();
    return 0;
}