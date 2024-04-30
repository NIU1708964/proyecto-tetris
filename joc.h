#ifndef JOC_H
#define JOC_H
#include "tauler.h"
#include "figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	Joc() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:

	Figura Figura_actual;
	Tauler Tablero;


};

#endif