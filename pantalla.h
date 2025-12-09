#pragma once
#include <string>

//Limpia pantalla
void borrarPantalla();
// Pausa para que el jugador presione una tecla
void pausa();


// AGREGAR Funciones para agregar en jugar.h
// Controla el modo de juego para un solo jugador
void jugarUnJugador(const std::string &nombre1, int &puntajeFinal);

// Modo dos jugadores
void jugarDosJugadores(const std::string &nombre1, const std::string &nombre2, int &puntaje1, int &puntaje2, int &puntajeFinal);

//Funciones de dados
int tirarDado();
void tiradaDados(int dados[]);
void mostrarDados(int dados[]);

// Funciones de puntaje --NUEVO --
void contarFrecuencias(const int dados[], int cantidad, int frec[]);
int calcularPuntaje(const int dados[], int cantidad);

void volverATirarDados(int dados[]);

// Puntajes para estadisticas
void actualizarMejorPuntaje(const std::string &nombre, int puntaje,std::string &mejorJugador, int &mejorPuntaje);

// Funcion para la tirada manual

void TiradaManual(const std::string &nombre3,int &puntajeFinal,int dados[], int cantidad);




