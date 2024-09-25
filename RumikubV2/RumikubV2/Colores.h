#include<iomanip>
#include<iostream>

using namespace std;

//TIPOS
typedef enum tColor { ROJO, AMARILLO, VERDE, AZUL, BLANCO, VACIO }; //Declaramos los colores de las fichas y un color VACIO para indicar la ausencia de estas

//FUNCIONES
void colorTexto(tColor color);//Funcion para cambiar el color

