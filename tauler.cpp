#include "tauler.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][MAX_COL + 2] = NO_COLOR;
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j + 2] = COLOR_NEGRE;
    }
    for (int j = 0; j < MAX_COL + 2; j++)
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
    bool colisionaFigura = false;
    int estructura[MAX_ALCADA][MAX_AMPLADA];

    int filaEstructura = 0;
    int filaTauler = figura.getFila() - 1;
    
    figura.getEstructura(estructura);
    while(!colisionaFigura && (filaEstructura <= figura.getAltura()));
    {
        int colEstructura = 0;
        int colTauler = figura.getColumna() + 1;
        while (!colisionaFigura && (colEstructura <= figura.getAnchura()))
        {
            if ((estructura[filaEstructura][colEstructura] * m_tauler[filaTauler][colTauler]) != 0) //si l'espai en el tauler esta lliure hi haura un 0
            {
                colisionaFigura = true;
            }
            colEstructura++;
            colTauler++;
        } 

        filaEstructura++;
        filaTauler++;
    } 
    return colisionaFigura;

}

int Tauler::colocaFigura(const Figura& figura)
{
    int estructura[MAX_ALTURA][MAX_ANCHURA];
    int numFilesComp = 0;

    ColorFigura color = figura.getColor();
    figura.getEstructura(estructura);
    int filaTauler = figura.getFila() - 1;
    int filaEstructura = 0;

    while(filaEstructura < figura.getAltura())
    {
        int colTauler = figura.getColumna + 1;
        int colEstructura = 0;
        while(colEstructura < figura.getEstructura)
        {
            if (mascara[filaMascara][colMascara] != 0)
            {
                m_tauler[filaTauler][colTauler] = color;
                m_lliures[filaTauler]--;
                if (m_lliures[filaTauler] == 0)
                {
                    numFilesComp++;
                    baixa(filaTauler);
                }
            }
            colEstructura++;
        }
        filaEstructura++;
    }
    return numFilesComp;
}

void Tauler::baixa(int fila)
{
    if (fila > 0)
    {
        for (int i = fila; i > 0; i++)
        {
            for (int j = 0; j > 0; j++)
            {
                m_tauler[i][j + 1] = m_tauler[i - 1][j + 1];
            }
            m_lliures[i] = m_lliures[i - 1];
        }
    }
    for (int i = 0; i < MAX_COL; i++)
    {
        m_tauler[0][i + 1] = COLOR_NEGRE;
    }
    m_lliures[0] = MAX_COL;
}

void Tauler::getTauler(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            tauler[i][j] = m_tauler[i][j + 1];
    }
}