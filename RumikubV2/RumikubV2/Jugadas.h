#include"Soportes.h"

//CONSTANTES

//TIPOS

typedef tFicha* tJugada;

//DECLARACION FUNCIONES

void iniJugada(tJugada& jugada);//Inicializa una jugada con tamaño num+1

bool sonIguales(tJugada izq, tJugada der);//Sobrecarga el operador == para comparar dos tJugadas

int buscar(const tJugada jugada, tFicha ficha);//Devuelve una posicion de una ficha en una jugada -1 si no esta

void eliminaFichas(tSoporte& soporte, const tJugada jugada);//Elimina del soporte las fichas que hay en la jugada

void iniJugada(tJugada jugada);//Inicializa las fichas de la jugada a -1

void mostrarSeries(tSoporte soporte);//Muestra las posibles series que puede crear con las fichas del soporte

void mostrarEscaleras(tSoporte soporte);//Muestra las posibles escaleras que puede crear con las fichas del soporte

void mostrarJugada(const tJugada jugada);//Muestra la jugada por pantalla

bool ponerFicha(tJugada jugada, tFicha ficha);//Devuelve true si la ficha se puede incluir en la jugada existente

void colocarFicha(tJugada& jugada, tFicha ficha);//Permite colocar una ficha en una jugada existente 

int nuevaJugada(tSoporte soporte, tJugada& jugada);//Permite al jugador introducir nuevos valores de fichas

int contarjugada(const tJugada jugada);//Cuenta el numero de fichas que hay en una jugada

void newJugada(tJugada& jugada);//inicializa una jugada
