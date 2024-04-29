

#include "tauler.h"
#include "figura.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{

void Tauler::inicialitza(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 1] = tauler[i][j];
            if (tauler[i][j] != COLOR_NEGRE)
                m_lliures[i]--;
        }
}

bool Tauler::colisionaFigura(const Figura& figura)
{
    bool colisiona = false;
    while()
    return colisiona;
}//son necesarios algunos metodos dentro de la clase figura