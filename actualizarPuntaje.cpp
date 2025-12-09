#include <iostream>
#include "pantalla.h"

using namespace std;

// Actualizar el mejor puntaje para mostrar en Puntuacion mas alta
void actualizarMejorPuntaje(const std::string &nombre, int puntaje, std::string &mejorJugador, int &mejorPuntaje)
{
    if (puntaje > mejorPuntaje)
    {
        mejorPuntaje = puntaje;
        mejorJugador = nombre;
    }
}
