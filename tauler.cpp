#include "Tauler.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{

    for (int i = 0; i < MAX_FILES + 1; i++) //a�ado + 1
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][MAX_COLUMNES + 1] = NO_COLOR; //cambio + 2 a + 1
        for (int j = 0; j < MAX_COLUMNES; j++)
        {
            m_tauler[i][j + 1] = COLOR_NEGRE; //a�ado + 1
        }
    } //for revisado
    
    for (int j = 0; j < MAX_COLUMNES + 2; j++)
    {
        m_tauler[MAX_FILES][j] = NO_COLOR; //en la fila 8 (index 9) habra un borde
    }
    for (int i = 0; i < MAX_FILES; i++)
    {
        m_lliures[i] = MAX_COLUMNES;
    } //for2 revisado
}

void Tauler::inicialitza(ColorFigura tauler[MAX_FILES][MAX_COLUMNES]) 
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        for (int j = 0; j < MAX_COLUMNES; j++)
        {
            m_tauler[i][j + 1] = tauler[i][j]; //revisado
            if (tauler[i][j] != COLOR_NEGRE)
            {
                m_lliures[i]--;
            }
        }
    }       
} //revisado

bool Tauler::colisionaFigura(const Figura& figura)
{
    bool colisionaFigura = false; //elimino int estructura[][]

    int filaTauler = figura.getFila();
    figura.getEstructura(estructura);

    int filaEstructura = 0;

    do
    {
        int colTauler = figura.getColumna();
        int colEstructura = 0;

        do
        {
            if (m_tauler[filaTauler][colTauler] != 0) //si en el tablero no hay cero colisiona
            {
                colisionaFigura = true;
            }
            colEstructura++;
            colTauler++;
        } while (!colisionaFigura && colEstructura < figura.getAnchura()); //getAmplada

        filaEstructura++;
        filaTauler++;
    } while (!colisionaFigura && filaEstructura < figura.getAltura());

    return colisionaFigura;
} //revisado ?

int Tauler::colocaFigura(const Figura& figura)
{
    int estructura[MAX_ALTURA][MAX_ANCHURA];
    int numFilesComp = 0;

    ColorFigura color = figura.getColor();
    figura.getEstructura(estructura);
    int filaTauler = figura.getFila() - 1;
    int filaEstructura = 0;

    while (filaEstructura < figura.getAltura())
    {
        int colTauler = figura.getColumna() + 1;
        int colEstructura = 0;
        while (colEstructura < figura.getAnchura())
        {
            if (estructura[filaEstructura][colEstructura] != 0)
            {
                m_tauler[filaTauler][colTauler] = color;
                m_lliures[filaTauler]--;
                if (m_lliures[filaTauler] == 0)
                {
                    numFilesComp++;
                    baixa(filaTauler);
                }
            }
            colTauler++;
            colEstructura++;
        }
        filaTauler++;
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
    for (int i = 0; i < MAX_COLUMNES; i++)
    {
        m_tauler[0][i + 1] = COLOR_NEGRE;
    }
    m_lliures[0] = MAX_COLUMNES;
}

void Tauler::getTauler(ColorFigura tauler[MAX_FILES][MAX_COLUMNES])
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        for (int j = 0; j < MAX_COLUMNES; j++)
            tauler[i][j] = m_tauler[i][j];
    }
}

void::Tauler::limpiarTauler(const Figura& figura) {

    for (int i = 0; i < figura.getAltura(); i++) {
        for (int j = 0; j < figura.getAnchura(); j++)
        {
            if (figura.obtenerEstructura(i, j) != 0) {

                m_tauler[figura.getFila() + i - 1][figura.getColumna() + j - 1] = COLOR_NEGRE;
            }
        }
    }
}

void::Tauler::implementacioFigura(const Figura& figura) {

    ColorFigura Taula[MAX_FILES][MAX_COLUMNES];

    getTauler(Taula);

    for (int i = 0; i < figura.getAltura(); i++) {
        for (int j = 0; j < figura.getAnchura(); j++)
        {
            if (figura.obtenerEstructura(i, j) != 0) {

                Taula[figura.getFila() + i - 1][figura.getColumna() + j - 1] = figura.getColor();
            }

        }
    }

    inicialitza(Taula);
}