#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

#define MAX_COLUMNES = 8
#define MAX_FILES = 8

using namespace std;

class Tauler()
{
private:

	ColorFigura m_tauler[N_FILES + 1][N_COLUMNES + 2];// +1 a fila y +2 a columna para los bordes
	int m_lliures[MAX_FILES]

public:
	Tauler();
	void inicialitzaTauler(ColorFigura tauler[MAX_FILES][MAX_COLUMNES]); 
	bool colisionaFigura(const Figura& figura);
	int colocaFigura();

	void baixa(int fila);
};
#endif