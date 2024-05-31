#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 21;
const int MAX_COL = 11;

class Tauler
{
public:
    Tauler();
    void inicialitza(ColorFigura taulerInicial[MAX_FILA][MAX_COL]);
    bool colisionaFigura(const Figura& figura);
    int colocaFigura(const Figura& figura);

    void pintaFigura(const Figura& figura);
    void pinta(const int x, const int y, const ColorFigura color) { m_tauler[x][y] = color; }

    void getTauler(ColorFigura tauler[MAX_FILA][MAX_COL]);

    void eliminaFila(int fila);
    void dibuixaTauler();

private:

    ColorFigura m_tauler[MAX_FILA][MAX_COL + 2];

    int m_lliures[MAX_FILA];

};
#endif 
