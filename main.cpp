#include <iostream>
#include "pantalla.h"
#include "rlutil.h"
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    int opcion;
    string nombre1, nombre2, nombre3;
    string mejorJugador;
    int mejorPuntaje = 0;
    char respuesta;
    int dados[5];
    int puntajeFinal = 0;

    srand(time(0));
    rlutil::setBackgroundColor(rlutil::MAGENTA);

    do
    {
        borrarPantalla();
        cout << endl << "BIENVENIDOS A 'GENERALA!' " << endl;
        cout << "---------------------------------" << endl;
        cout << "1 - JUGAR CON  UN JUGADOR " << endl;
        cout << "2 - JUGAR CON  DOS JUGADORES " << endl;
        cout << "3 - VER LA PUNTUACION MAS ALTA" << endl;
        cout << "4 - VER CREDITOS" << endl;
        cout << "0 - SALIR" << endl;
        cout << "-------------------------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
        cout << endl;

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        borrarPantalla();

        switch (opcion)
        {
        case 1:
        {
            cout<< "DESEA ACTIVAR EL MODO MANUAL?(S/N): "<< endl;
            cin>>respuesta;

            if(respuesta == 'S' || respuesta == 's')
            {
                system("cls");
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "--- INGRESE NOMBRE DEL JUGADOR---"<< endl << endl;
            getline(cin, nombre3);
            cout << endl<< "Buena suerte " << nombre3 << endl;
            system("pause");
            system("cls");
            cout << endl;
                TiradaManual(nombre3, puntajeFinal,  dados, 5);
                actualizarMejorPuntaje(nombre3, puntajeFinal, mejorJugador, mejorPuntaje);
            }
            else
            {
                 system("cls");
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "--- INGRESE NOMBRE DEL JUGADOR---"<< endl << endl;
            getline(cin, nombre1);
            cout << endl<< "Buena suerte " << nombre1 << endl;
            system("pause");
            system("cls");
            cout << endl;
                jugarUnJugador(nombre1, puntajeFinal);

                actualizarMejorPuntaje(nombre1, puntajeFinal, mejorJugador, mejorPuntaje);
            }

            break;
        }
        case 2:
        {
            cout << "--- INGRESE JUGADOR NUMERO 1 ---"<< endl << endl;
            getline(cin, nombre1);
            cout << "--- INGRESE JUGADOR NUMERO 2 ---"<< endl << endl;
            getline(cin, nombre2);
            cout << "Iniciando juego para dos jugadores..." << endl;
            cout << "Buena suerte " << nombre1 << " y " << nombre2 << endl;
            cout << endl;
            int puntos1 = 0;
            int puntos2 = 0;

            jugarDosJugadores(nombre1, nombre2, puntos1, puntos2,puntajeFinal);

            actualizarMejorPuntaje(nombre1, puntos1, mejorJugador, mejorPuntaje);
            actualizarMejorPuntaje(nombre2, puntos2, mejorJugador, mejorPuntaje);
            break;
        }
        case 3:
            cout << endl<< "==== PUNTUACION MAS ALTA ====" << endl;
            if (mejorPuntaje == 0)
            {
                cout << "Aun no hay puntuaciones registradas." << endl;
            }
            else
            {
                cout << "Jugador: " << mejorJugador << endl;
                cout << "Puntaje: " << mejorPuntaje << endl;
            }
            cout << "=============================" << endl << endl;

            break;
        case 4:
            cout << endl << "  =========== CREDITOS ===========  " << endl;
            cout << "\tCreado por: " << endl;
            cout << "\tGaston Nicolas Rondan. " << endl;
            cout << endl << "  ================================  " << endl << endl;
            break;
        case 0:
            cout << endl << "\tGRACIAS POR JUGAR, HASTA LUEGO!" << endl;
            cout <<endl << "\tSaliendo del juego..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl << endl;
        }
        pausa();
    }
    while(opcion !=0 );

    return 0;
}




