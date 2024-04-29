#include "tauler.h"
#include "figura.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][MAX_COL + 1] = NO_COLOR;
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j + 1] = COLOR_NEGRE;
    }
    for (int j = 0; j < MAX_COL + 4; j++)
    {
        m_tauler[MAX_FILA][j] = NO_COLOR;
    }
    for (int i = 0; i < MAX_FILA; i++)
        m_lliures[i] = MAX_COL;
}

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