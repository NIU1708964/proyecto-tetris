#include "Joc.h"
#include <fstream>

using namespace std;

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;

		m_figura.set_fila_columna(fila, columna);
		m_figura.iniciarFigura(TipusFigura(tipus));

		for (int i = 0; i < gir; i++)
		{
			m_figura.girar(true);
		}

		ColorFigura taulerInicial[MAX_FILA][MAX_COL];
		int color;


		for (int i = 0; i < MAX_FILA; i++)
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer >> color;
				taulerInicial[i][j] = ColorFigura(color);
			}

		m_tauler.inicialitza(taulerInicial);
		fitxer.close();
	}
}



bool Joc::giraFigura(DireccioGir direccio)
{

	bool colisio;

	Figura figuraTemporal = m_figura;

	if (direccio == GIR_HORARI)
	{
		figuraTemporal.girar(true);
	}
	else {
		figuraTemporal.girar(false);
	}

	if (m_tauler.colisionaFigura(figuraTemporal))
	{
		colisio = true;
	}
	else
	{
		colisio = false;

		if (direccio == GIR_HORARI)
		{
			m_figura.girar(true);
		}
		else
		{
			m_figura.girar(false);
		}

	}

	return !colisio;


}

bool Joc::mouFigura(int direccio)
{
	bool direccion;

	if (direccio == 1) {
		direccion = true;
	}
	else if (direccio == -1) {
		direccion = false;
	}

	m_figura.desplazamientoLateral(direccion);
	bool colisiona = m_tauler.colisionaFigura(m_figura);
	if (colisiona)
	{
		bool dirContrari = !direccion;
		m_figura.desplazamientoLateral(dirContrari);
	}
	return !colisiona;
}



int Joc::baixaFigura()
{
	int nFiles = -1;

	m_figura.desplazamientoVertical(false);


	if (m_tauler.colisionaFigura(m_figura))
	{
		m_figura.desplazamientoVertical(true);

		nFiles = m_tauler.colocaFigura(m_figura);
		m_figura.figuraVacia();

	}

	return nFiles;

}

void Joc::escriuTauler(const string& nomFitxer)
{

	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{

		m_tauler.pintaFigura(m_figura);

		ColorFigura tauler[MAX_FILA][MAX_COL];
		m_tauler.getTauler(tauler);

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer << int(tauler[i][j]) << " ";
			}
			fitxer << endl;
		}

		fitxer.close();

	}
}

void Joc::DibuixaJoc() {

	m_tauler.dibuixaTauler();
	m_figura.DibuixarFigura(); 
}


bool Joc::NovaFigura() {


	int Figura = (rand() % N_TIPUS_FIGURES) + 1;
	int Columna;
	int GiroInicial = (rand() % 4);

	TipusFigura NovaFigura = TipusFigura(Figura);

	switch (NovaFigura) {

	case FIGURA_O: Columna = (rand() % (N_COL_TAULER - 1)) + 1; break;
	case FIGURA_I: Columna = (rand() % (N_COL_TAULER - 3)) + 1; break;
	default: Columna = (rand() % (N_COL_TAULER - 2)) + 1; break;

	}

	m_figura.iniciarFigura(NovaFigura);
	m_figura.set_fila_columna(1, Columna);

	for (int i = 0; i < GiroInicial; i++)
	{
		m_figura.girar(true);

	}

	bool colision = m_tauler.colisionaFigura(m_figura);

	return colision;

}

int Joc::BaixarTot() {

	bool Baixar = true;
	int nFiles = 0;

	while (Baixar) { 

		m_figura.desplazamientoVertical(false);

		if (m_tauler.colisionaFigura(m_figura)) 
		{
			m_figura.desplazamientoVertical(true); 

			nFiles = m_tauler.colocaFigura(m_figura); 
			m_figura.figuraVacia();

			Baixar = false;
		}


	}

	return nFiles; 
}

void Joc::ReemplazaFiguraActual(const Figura& reemp) {

	m_figura = reemp;
	for (int i = 0; i < reemp.getGir(); i++) {

		m_figura.girar(true);   

	}
		
}

