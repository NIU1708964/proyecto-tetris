#include "joc.h"
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

		m_figura.set_fila_columna(fila, columna);
		m_figura.iniciarFigura(TipusFigura(tipus));

		for (int i = 0; i < gir; i++)
		{
			m_figura.girar(true);
		}

		ColorFigura taulerInicial[MAX_FILA][MAX_COL];
		int color;


		for (int i = 0; i < MAX_FILES; i++)
			for (int j = 0; j < MAX_COLUMNES; j++)
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
	bool direccion;

	if (direccio == GIR_HORARI) {
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
		m_figura.girar(direccion);
	}
	return !colisiona;
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
	int nFiles = 0;
	m_figura.desplazamientoVertical(false);

	if (m_tauler.colisionaFigura(m_figura))
	{
		m_figura.desplazamientoVertical(true);

		nFiles = m_tauler.colocaFigura(m_figura);

		m_figura.iniciarFigura(NO_FIGURA);
		m_figura.set_fila_columna(-1, -1);

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

		for (int i = 0; i < m_figura.getAltura(); i++) {
			for (int j = 0; j < m_figura.getAnchura(); j++)
			{
				if (m_figura.obtenerEstructura(i, j) != 0) {

					tauler[m_figura.getFila() + i - 1][m_figura.getColumna() + j - 1] = m_figura.getColor();
				}

			}
		}

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