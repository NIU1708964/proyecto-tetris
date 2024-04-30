#include "joc.h"
#include "figura.h"
#include "tauler.h"
#include <fstream>

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		m_tauler = Tauler();

		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;

		while (!fitxer.eof())
		{
			m_figura.iniciarFigura(TipusFigura(tipus));

			for (int i = 0; i < gir; i++)
			{
				m_figura.girar(true);
			}

			m_figura.set_fila_columna(fila, columna);

			m_tauler.colocaFigura(Figura_actual);

			fitxer >> tipus >> fila >> columna >> gir;

		}

		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	bool direccion; 

	if (direccio==GIR_HORARI) {
		direccion = true;
	}
	else {
		direccion = false;
	}

	m_figura.girar(direccion);
	bool colisiona = m_tauler.colisionaFigura(m_figura);
	if (colisiona)
	{
		if (direccio == GIR_HORARI)
			direccion = false;
		else
			direccion = true;
		m_figura.gira(direccion);
	}
	return !colisiona;
}

bool Joc::mouFigura(int direccio)
{
	bool direccion;

	if (direccio == 1) {
		direccion = true;
	}
	else if(direcio=-1){
		direccion = false;
	}

	m_figura.desplazamientoLateral(direccion);
	bool colisiona = m_tauler.colisionaFigura(m_figura);
	if (colisiona)
	{
		dirContrari = !direccion; 
		m_figura.desplazamientoLateral(dirContrari);
	}
	return !colisiona;
}

int Joc::baixaFigura()
{
	int nFiles;
	m_figura.desplazamientoVertical(false);

	if (m_tauler.colisionaFigura(m_figura))
	{
		nFiles = m_tauler.colocaFigura(m_figura);
	}
	return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
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
}//incompleto