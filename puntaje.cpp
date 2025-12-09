#include <iostream>
#include "pantalla.h"

using namespace std;

//Cuenta cuántas veces salió cada número/cara de los dados del 1 al 6

void contarFrecuencias(const int dados[], int cantidad, int frec[])
{
    // Inicializa en cero el contador de cada cara del dado
    for (int i = 0; i < 6; i++) frec[i] = 0;

    // Recorre los dados y suma 1, establecemos indices del array (0 al 5)
    for (int i = 0; i < cantidad; i++)
    {
        frec[dados[i] - 1]++;
    }
}
//Calculamos el puntaje con las combinaciones que hay

int calcularPuntaje(const int dados[], int cantidad)
{

// usamos la variable 'frec' para contar las veces que salen las CARAS del dado

    int frec[6];
    contarFrecuencias(dados, cantidad, frec);

    bool escalera = false;
    bool full = false;
    bool poker = false;
    bool generala = false;

    // Para detectar "Generala": (5 caras iguales)
    for (int i = 0; i < 6; i++)
    {
        if (frec[i] == 5) generala = true;
    }

    // Para detectar "Poker": (4 caras iguales)
    for (int i = 0; i < 6; i++)
    {
        if (frec[i] == 4) poker = true;
    }

    // Para detectar "Full": ( debe tener 3 caras iguales + 2 caras iguales)

    bool tiene3 = false, tiene2 = false;
    for (int i = 0; i < 6; i++)
    {
        if (frec[i] == 3) tiene3 = true;
        if (frec[i] == 2) tiene2 = true;
    }
    if (tiene3 && tiene2) full = true;

    // detectar escalera (desordenada u ordenada)= 1,2,3,4,5 o 2,3,4,5,6
    //comparamos si las caras salen en orden para formar escalera
    //establecemos orden para poder detectar escalera
    if ((frec[0] == 1 && frec[1] == 1 && frec[2] == 1 && frec[3] == 1 && frec[4] == 1) ||
            (frec[1] == 1 && frec[2] == 1 && frec[3] == 1 && frec[4] == 1 && frec[5] == 1))
    {
        escalera = true;
    }

    // Calcular puntaje según la combinación de mayor valor
    int puntaje = 0;

    //Establecemos cuales son los puntajes para las combinaciones
    if (generala) puntaje = 50;
    else if (poker) puntaje = 40;
    else if (full) puntaje = 30;
    else if (escalera) puntaje = 25;
    else
    {
        // Calcular el puntaje cuando no hay ninguna combinacion
        // Juegos de 1 a 6: valor * cantidad (ej: tres 6 = 18 puntos)
        int mayorJuego = 0;
        for (int i = 0; i < 6; i++)
        {
            int juego = (i + 1) * frec[i];
            if (juego > mayorJuego) mayorJuego = juego;
        }
        puntaje = mayorJuego;
    }

    return puntaje;
}
