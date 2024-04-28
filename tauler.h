#include <iostream>
#include "Figura.h"

#define MAX_COLUMNES = 8
#define MAX_FILES = 8

using namespace std;

class Tauler()
{
private:

	ColorFigura m_tauler[N_FILES][N_COLUMNES];
	int m_lliures[MAX_FILES]

public:
	Tauler();
	void inicialitzaTauler(ColorFigura TaulerInicial[MAX_FILES][MAX_COLUMNES]); 
	bool colisionaFigura(const FIgura & figura); //utilitza metode colisiona dins de la classe figura
	int getLliures(int fila);
	//faltan metodes
};
