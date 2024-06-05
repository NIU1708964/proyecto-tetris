//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 
#include <windows.h>

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include <iostream>
#include "./Tetris.h"

using namespace std;


int main(int argc, const char* argv[])
{
    cout << "--------------------------" << endl;
    cout << "**********TETRIS**********" << endl;
    cout << "--------------------------" << endl;

    cout << endl;

    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);
    
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);

    Tetris tetris("./data/Games/puntuacions.txt");

    tetris.mostraMenu();

    int punts;
    bool sortir = false;
    string nom, fitxerInicial, fitxerFigures, fitxerMoviments;

    do
    {
        char opcio = _getch();

        switch (opcio)
        {
        case '1':
            
            punts = tetris.juga(pantalla, 0, "", "", ""); 
            
            cout << "Introdueix el nom del jugador: "; cin >> nom;
            tetris.actualitzaPuntuacions(nom, punts);

            break;
        case '2':
            cout << "Introdueix el nom dels fitxers:" << endl;
            cout << "Fitxer Inicial: "; cin >> fitxerInicial; 
            cout << "Fitxer Figures: "; cin >> fitxerInicial;
            cout << "Fitxer Moviments: "; cin >> fitxerInicial;
            tetris.juga(pantalla, 1, "./data/Games/" + fitxerInicial, "./data/Games/" + fitxerFigures, "./data/Games/" + fitxerMoviments);
            break;
        case '3':
            tetris.mostraPuntuacions();
            break;
        case '4':
            sortir = true;

            cout << "Sortint del programa...";
            Sleep(1000);
            break;
        default:
            cout << "ERROR: Opcio no valida.";
        }

        tetris.mostraMenu();

        tetris.guardaPuntuacions("./data/Games/puntuacions.txt");
    } while (!sortir);

    SDL_Quit;

    return 0;
}

