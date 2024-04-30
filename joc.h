#ifndef JOC_H
#define JOC_H
#include "tauler.h"
#include "figura.h"
#include <string>
using namespace std;

#define MAX_FILA 8
#define MAX_COL 8

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

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

	Figura m_figura;
	Tauler m_tauler;


};


#endif