#include "joc.h"
#include "figura.h"
#include "tauler.h"
#include <fstream>

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if(fitxer.is_open())
	{
		Tablero.Tauler();

		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;

		while (!fitxer.eof())
		{
			m_figura.iniciarFigura(tipus);

			for (int i = 0; i < gir; i++)
			{
				m_figura.girar(true);
			}

			m_figura.set_fila_columna(fila, columna);
			
			Tablero.colocaFigura(m_figura);

			fitxer >> tipus >> fila >> columna >> gir;

		}

		fitxer.close();
	}
}
bool Joc::giraFigura(DireccioGir direccio)
{
	m_figura.gira(direccio);
	bool colisiona = m_tauler.colisionaFigura(m_figura);
	if (colisiona)
	{
		if (direccio == GIR_HORARI)
			direccio = GIR_ANTI_HORARI;
		else
			direccio = GIR_HORARI;
		m_figura.gira(direccio);
	}
	return !colisiona;
}

bool Joc::mouFigura(int direccio)
{
	m_figura.mouFigura(direccio);
	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);
	if (colisiona)
	{
		dirContrari = -direccio;
		m_figuraActual.mou(dirContrari);
	}
	return !colisiona;
}

int Joc::baixaFigura()
{
	int nFiles;
	m_figura.baixa();

	if (m_tauler.colisionaFigura(m_figura))
	{
		nFiles = m_tauler.colocaFigura(m_figuraActual);
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