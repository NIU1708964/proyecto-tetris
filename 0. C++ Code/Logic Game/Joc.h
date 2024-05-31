#ifndef JOC_H
#define JOC_H
#include "Figura.h"
#include "Tauler.h" 
#include "GraphicManager.h"
#include <string>


class Joc
{
public:
	Joc() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int direccio);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);
	void DibuixaJoc();
	bool NovaFigura();
	int BaixarTot();
	void ReemplazaFiguraActual(const Figura& reemp); 

	


private:

	Tauler m_tauler;
	Figura m_figura;   

};

#endif
