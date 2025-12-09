#include <iostream>
#include "pantalla.h"

using namespace std;

int tirarDado()
{
    return rand()% 6 + 1;
}
// Simula tirar los 5 dados
void tiradaDados(int dados[])
{
    for(int i=0; i<5; i++)
    {
        dados[i] = tirarDado();
    }
}

void mostrarDados(int dados[])
{
    cout << " [ ";
    for(int i=0; i<5; i++)
    {
        cout << dados[i] << " ";
    }
    cout << " ] " << endl;
}

void volverATirarDados(int dados[])
{
    int cantidad;
    cout<< "CUANTOS DADOS VOLVES A TIRAR?: ";
    cin>>cantidad;

    for(int i=0; i<cantidad; i++)
    {

        int indice;
        cout<< "CUAL? (1-5): ";
        cin>>indice;

        dados[indice - 1] = tirarDado();
    }
}

