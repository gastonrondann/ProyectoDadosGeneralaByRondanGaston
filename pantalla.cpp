#include <iostream>
#include "pantalla.h"
#include "rlutil.h"
using namespace std;


void borrarPantalla()
{
    rlutil::cls(); // limpia pantalla usando rlutil
}

void pausa()
{
    cout << endl << "Presione una tecla para continuar...";
    rlutil::anykey();
}







