#include <iostream>
#include "pantalla.h"
#include "rlutil.h"

using namespace std;

void jugarUnJugador(const std::string &nombre1, int &puntajeFinal)
{

    int totalPuntos = 0;
    int puntajePrimerTiro=0;

    //10 rondas
    for(int ronda = 1; ronda <= 10; ronda++)
    {


        int dados[5];
        tiradaDados(dados);

        int lanzamiento= 1;
        bool seguir = true;

        while(seguir && lanzamiento <4)
        {

            cout << "---------------------------" << endl;
            cout << "     RONDA " << ronda << endl;
            cout << "---------------------------" << endl;
            cout<< "LANZAMIENTO N: "<< lanzamiento << endl;
            cout<<"----------------------------------------"<< endl;

            mostrarDados(dados);
            int frec[6];
            bool generala = false;
            puntajeFinal=calcularPuntaje(dados, 5);
            contarFrecuencias(dados, 5, frec);
            for (int i=0; i<6; i++)
            {

                if(frec[i]== 5)
                {
                    generala = true;
                }
            }
            if(generala)
            {
                system("cls");
                cout<< "HICISTE GENERALA, GANASTE. "<<endl;

                return ;
            }
            if(lanzamiento<4)
            {
                char opcion;
                cout<< " VOLVES A TIRAR? (S/N): ";
                cin>> opcion;

                if(opcion == 'S' || opcion == 's')
                {
                    volverATirarDados(dados);
                }
                else
                {
                    seguir=false;
                }

            }
            lanzamiento++;
        }
        mostrarDados(dados);
        int puntos = calcularPuntaje(dados, 5);
        cout << "PUNTAJE DE LA RONDA: " << puntos << endl;

        totalPuntos += puntos;

        pausa();
        borrarPantalla();
        cout<< "RONDA N: "<<ronda<<endl;
        cout<< "PUNTAJE "<<nombre1<<": "<<totalPuntos<< endl;
         pausa();
        borrarPantalla();
    }

    cout << "===================================" << endl;
    cout << "   FIN DEL JUEGO" << endl;
    cout << "   PUNTAJE TOTAL DE: "<<nombre1 <<": "<< totalPuntos <<" puntos"<< endl;
    cout << "===================================" << endl;
    puntajeFinal = totalPuntos;
}

void TiradaManual(const std::string &nombre3,int &puntajeFinal, int dados[], int cantidad)
{

    int totalPuntos = 0;
    int puntajePrimerTiro=0;
    for(int ronda = 1; ronda <= 10; ronda++)
    {

        int dados[5];
        int lanzamiento= 1;
        bool seguir = true;


        while(seguir &&lanzamiento <4)
        {

            cout << "---------------------------" << endl;
            cout << "     RONDA " << ronda << endl;
            cout << "---------------------------" << endl;
            cout<< "LANZAMIENTO N: "<< lanzamiento << endl;
            cout<<"----------------------------------------"<< endl;

            for(int i=0; i< cantidad; i++)
            {

                do
                {
                    cout<< "INGRESE EL VALOR DEL DADO "<< i+1 << "(1-6): ";
                    cin>> dados[i];
                    if(dados[i]<1 || dados[i]>6){
                        cout<<"ERROR: el valor tiene que ser entre 1 y 6. "<<endl;
                    }
                }
                while(dados[i]<1 || dados[i]>6);
            }
            puntajeFinal=calcularPuntaje(dados, 5);
            int frec[6];
            contarFrecuencias(dados, 5, frec);
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

            if(lanzamiento<4)
            {
                char opcion;
                cout<< " VOLVES A TIRAR? (S/N): ";
                cin>> opcion;

                if(opcion == 'S' || opcion == 's')
                {
                    for(int i=0; i< cantidad; i++)
                    {



                        while(dados[i]<1 || dados[i]>6){
                            cout<< "INGRESE EL VALOR DEL DADO "<< i+1 << "(1-6): ";
                            cin>> dados[i];
                        }
                    }
                }
                else
                {
                    seguir=false;
                }


            }

            lanzamiento++;
        }
        int puntos = calcularPuntaje(dados, 5);
        cout << "PUNTAJE DE LA RONDA: " << puntos << endl;
        totalPuntos += puntos;
        pausa();
        borrarPantalla();


    }
    cout << "===================================" << endl;
    cout << "   FIN DEL JUEGO" << endl;
    cout << "   PUNTAJE TOTAL DE: "<<nombre3 <<": "<< totalPuntos <<" puntos"<< endl;
    cout << "===================================" << endl;
    puntajeFinal = totalPuntos;
}
