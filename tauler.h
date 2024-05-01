#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

#define MAX_COLUMNES 8
#define MAX_FILES 8

using namespace std;

class Tauler
{
public:

	Tauler();
	void inicialitza(ColorFigura tauler[MAX_FILES][MAX_COLUMNES]);
	bool colisionaFigura(const Figura& figura);
	int colocaFigura(const Figura& figura);
	void baixa(int fila);
	void getTauler(ColorFigura tauler[MAX_FILES][MAX_COLUMNES]);
	void limpiarTauler(const Figura& figura);
	void implementacioFigura(const Figura& figura);

private:

	ColorFigura m_tauler[MAX_FILES + 1][MAX_COLUMNES + 2];// +1 a fila y +2 a columna para los bordes
	int m_lliures[MAX_FILES];
};
#endif