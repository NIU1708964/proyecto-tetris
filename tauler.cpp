#include "tauler.h"
#include <iostream>

using namespace std;

Tauler::Tauler()
{

    for (int i = 0; i < MAX_FILES + 1; i++) //añado + 1
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][MAX_COLUMNES + 1] = NO_COLOR; //cambio + 2 a + 1
        for (int j = 0; j < MAX_COLUMNES; j++)
        {
            m_tauler[i][j + 1] = COLOR_NEGRE; //añado + 1
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
    int filaEstructura = 0;

    int filaTauler = figura.getFila(); //se ha quitado el -1
    for (int filaEstructura = 0; filaEstructura < figura.getAltura; filaEstructura++) //se ha cambiado las estructuras while a for
    {
        int colTauler = figura.getColumna() + 1;
        for (int colEstructura = 0; colEstructura < figura.getAnchura; colEstructura++)
        {
            if (estructura[filaEstructura][colEstructura] != 0)
            {
                m_tauler[filaTauler][colTauler] = color;
                m_lliures[filaTauler] == 0;
                if (m_lliures[filaTauler] == 0)
                {
                    numFilesComp++;
                    baixa(filaTauler);
                }
            }
            colTauler++;
        }
        filaTauler++;
    }
    return numFilesComp;
}

void Tauler::baixa(int fila)
{
    if (fila > 0)
    {
        for (int i = fila; i > 0; i--)//i++ a i--
        {
            for (int j = 0; j > MAX_COLUMNES; j++)//se cambia el j>0 a j>maxcol
            {
                m_tauler[i][j + 1] = m_tauler[i - 1][j + 1];
            }
            m_lliures[i] = m_lliures[i - 1];
        }
        for (int i = 0; i < MAX_COLUMNES; i++)
        {
            m_tauler[0][i + 1] = COLOR_NEGRE;
        }
        m_lliures[0] = MAX_COLUMNES;
    }  //se coloca todo dentro del if
}

void Tauler::getTauler(ColorFigura tauler[MAX_FILES][MAX_COLUMNES])
{
    for (int i = 0; i < MAX_FILES; i++)
    {
        for (int j = 0; j < MAX_COLUMNES; j++)
        {
            tauler[i][j] = m_tauler[i][j + 1]; //se añade un j + 1 para evitar los bordes
        }
    }
}