#include "Tauler.h"

Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        m_tauler[i][0] = NO_COLOR;
        m_tauler[i][MAX_COL + 1] = NO_COLOR;
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j + 1] = COLOR_NEGRE;
    }
    for (int j = 0; j < MAX_COL + 2; j++)
    {
        m_tauler[MAX_FILA][j] = NO_COLOR;
    }
    for (int i = 0; i < MAX_FILA; i++)
        m_lliures[i] = MAX_COL;
}

void Tauler::inicialitza(ColorFigura taulerInicial[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
        m_lliures[i] = MAX_COL;
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j + 1] = taulerInicial[i][j];
            if (taulerInicial[i][j] != COLOR_NEGRE)
                m_lliures[i]--;
        }
}

bool Tauler::colisionaFigura(const Figura& figura)
{
    bool colisiona = false;

    int estructura[MAX_ALTURA][MAX_AMPLADA];
    figura.getEstructura(estructura);

    for (int filaEstructura = 0; filaEstructura < figura.getAltura(); filaEstructura++)
    {
        int filaTauler = figura.getFila() - 1 + filaEstructura;
        for (int colEstructura = 0; colEstructura < figura.getAnchura(); colEstructura++)
        {
            int colTauler = figura.getColumna() + colEstructura;
            if ((estructura[filaEstructura][colEstructura] != 0 && m_tauler[filaTauler][colTauler]) != 0)
            {
                colisiona = true;
            }
        }
    }
    return colisiona;
}

void Tauler::getTauler(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
            tauler[i][j] = m_tauler[i][j + 1];
    }
}


int Tauler::colocaFigura(const Figura& figura)
{
    int estructura[MAX_ALTURA][MAX_AMPLADA];
    int numFilesComp = 0;

    ColorFigura color = figura.getColor();
    figura.getEstructura(estructura);
    int filaTauler = figura.getFila() - 1;

    for (int filaEstructura = 0; filaEstructura < figura.getAltura(); filaEstructura++)
    {
        int colTauler = figura.getColumna();

        for (int colEstructura = 0; colEstructura < figura.getAnchura(); colEstructura++)
        {
            if (estructura[filaEstructura][colEstructura] != 0)
            {
                m_tauler[filaTauler][colTauler] = color;
                m_lliures[filaTauler]--;
                if (m_lliures[filaTauler] == 0)
                {

                    numFilesComp++;
                    eliminaFila(filaTauler);

                }
            }
            colTauler++;
        }
        filaTauler++;
    }
    return numFilesComp;
}



void Tauler::pintaFigura(const Figura& figura)
{
    int estructura[MAX_ALTURA][MAX_AMPLADA];

    ColorFigura color = figura.getColor();
    figura.getEstructura(estructura);
    int filaTauler = figura.getFila() - 1;
    for (int filaEstructura = 0; filaEstructura < figura.getAltura(); filaEstructura++)
    {
        int colTauler = figura.getColumna();
        for (int colEstructura = 0; colEstructura < figura.getAnchura(); colEstructura++)
        {
            if (estructura[filaEstructura][colEstructura] != 0)
            {
                pinta(filaTauler, colTauler, color);
            }
            colTauler++;
        }

        filaTauler++;

    }
}


void Tauler::eliminaFila(int fila)
{
    if (fila > 0)
    {
        for (int i = fila; i > 0; i--)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                m_tauler[i][j + 1] = m_tauler[i - 1][j + 1];
            }
            m_lliures[i] = m_lliures[i - 1];
        }
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[0][j + 1] = COLOR_NEGRE;
        m_lliures[0] = MAX_COL;

    }
}



void Tauler::dibuixaTauler() {

    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false); 
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false); 

    for (int i = 0; i < MAX_FILA; i++) {

        for (int j = 0; j < MAX_COL; j++) 
        {
            if (m_tauler[i][j + 1] != COLOR_NEGRE) {

                switch (m_tauler[i][j + 1])
                {
                case COLOR_GROC: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_GROC, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break; 
                case COLOR_BLAUCEL: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUCEL, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break;
                case COLOR_MAGENTA: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_MAGENTA, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break; 
                case COLOR_TARONJA: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_TARONJA, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break;
                case COLOR_BLAUFOSC: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_BLAUFOSC, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break;
                case COLOR_VERMELL: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERMELL, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break; 
                case COLOR_VERD: GraphicManager::getInstance()->drawSprite(GRAFIC_QUADRAT_VERD, POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false); break;
                }

            }

        }

    }

}
