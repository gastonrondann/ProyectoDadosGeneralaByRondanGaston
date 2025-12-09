#include <iostream>
#include "pantalla.h"

using namespace std;


void jugarDosJugadores(const std::string &nombre1, const std::string &nombre2, int &puntaje1, int &puntaje2,int &puntajeFinal)
{
    int total1 = 0;
    int total2 = 0;
    int puntajePrimerTiro=0;

    // 10 rondas
    for(int ronda = 1; ronda <= 3; ronda++)
    {
        // Jugador 1
        cout << "=================================================" << endl;
        cout << " RONDA " << ronda << " - JUGADOR: " << nombre1 << " || PUNTAJE TOTAL: " <<total1 << endl;
        cout << "=================================================" << endl;

        int dados1[5];
        tiradaDados(dados1);

        int lanzamiento = 1;
        bool seguir = true;
        while(seguir && lanzamiento < 4)
        {
            mostrarDados(dados1);
            puntajeFinal=calcularPuntaje(dados1, 5);
            int frec[6];
            contarFrecuencias(dados1, 5, frec);
            bool generala = false;
            for (int i=0; i<6; i++)
            {

                if(frec[i]== 5)generala = true;
            }
            if(generala)
            {
                system("cls");
                cout<< "HICISTE GENERALA, GANASTE. "<<endl;

                return ;
            }
            char opc;
            cout << "VOLVES A TIRAR? (S/N): ";
            cin >> opc;
            cout << "===============================================" << endl;
            if(opc == 'S' || opc == 's')
            {
                volverATirarDados(dados1);
            }
            else seguir = false;

            lanzamiento++;
        }

        int puntos1 = calcularPuntaje(dados1, 5);
        cout << "PUNTAJE DE LA RONDA PARA " << nombre1 << ": " << puntos1 << endl;
        //sumamos los puntos de la partida
        total1 += puntos1;

        pausa();
        borrarPantalla();
        cout<< "RONDA N: "<<ronda<<endl;
        cout<< "PROXIMO TURNO: "<<nombre2<<endl;
        cout<< "PUNTAJE "<<nombre1<<": "<<total1<< endl;
        cout<< "PUNTAJE "<<nombre2<<": "<<total2<< endl;
         pausa();
        borrarPantalla();

        // Jugador 2
        cout << "===============================================" << endl;
        cout << " RONDA " << ronda << " - JUGADOR: " << nombre2 << " || PUNTAJE TOTAL: " << total2 << endl;
        cout << "===============================================" << endl;

        int dados2[5];
        tiradaDados(dados2);

        lanzamiento = 1;
        seguir = true;

        while(seguir && lanzamiento < 4)
        {
            mostrarDados(dados2);
            puntajeFinal=calcularPuntaje(dados2, 5);
            int frec[6];
            contarFrecuencias(dados2, 5, frec);
            bool generala = false;
            for (int i=0; i<6; i++)
            {

                if(frec[i]== 5)generala = true;
            }
            if(generala)
            {
                system("cls");
                cout<< "HICISTE GENERALA, GANASTE. "<<endl;

                return ;
            }
            char opc;
            cout << "VOLVES A TIRAR? (S/N): ";
            cin >> opc;
            cout << "===============================================" << endl;
            if(opc == 'S' || opc == 's')
            {
                volverATirarDados(dados2);
            }
            else seguir = false;

            lanzamiento++;
        }

        int puntos2 = calcularPuntaje(dados2, 5);
        cout << "PUNTAJE DE LA RONDA PARA " << nombre2 << ": " << puntos2 << endl;
        // sumamos los puntos de la partida
        total2 += puntos2;
         pausa();
        borrarPantalla();
        cout<< "RONDA N: "<<ronda<<endl;
        cout<< "PROXIMO TURNO: "<<nombre1<<endl;
        cout<< "PUNTAJE "<<nombre1<<": "<<total1<< endl;
        cout<< "PUNTAJE "<<nombre2<<": "<<total2<< endl;


        pausa();
        borrarPantalla();
    }

    // Finaliza el juego
    cout << "===================================" << endl;
    cout << "          FIN DEL JUEGO            " << endl;
    cout << "===================================" << endl;

    cout << nombre1 << " TOTAL: " << total1 << " puntos" << endl;
    cout << nombre2 << " TOTAL: " << total2 << " puntos" << endl;

    cout << "-----------------------------------" << endl;

    puntaje1 = total1;
    puntaje2 = total2;

    if(total1 > total2)
        cout << "GANADOR: " << nombre1 << endl;
    else if(total2 > total1)
        cout << "GANADOR: " << nombre2 << endl;
    else
        cout << "EMPATE!" << endl;

    cout << "===================================" << endl;
}
