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

		m_figuraActual.set_fila_columna(fila, columna);
		m_figuraActual.iniciarFigura(TipusFigura(tipus));

		for (int i = 0; i < gir; i++)
		{
			m_figuraActual.girar(true);
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

	bool direccion;

	if (direccio == GIR_HORARI) {
		direccion = true;
	}
	else {
		direccion = false;
	}
	m_figuraActual.girar(direccion);

	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);

	if (colisiona)
	{
		if (direccio == GIR_HORARI)
			direccion = false;
		else
			direccion = true;

		m_figuraActual.girar(direccion);
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

	m_figuraActual.desplazamientoLateral(direccion);
	bool colisiona = m_tauler.colisionaFigura(m_figuraActual);
	if (colisiona)
	{
		bool dirContrari = !direccion;
		m_figuraActual.desplazamientoLateral(dirContrari);
	}
	return !colisiona;

}

int Joc::baixaFigura()
{

	int nFiles = 0;
	m_figuraActual.desplazamientoVertical(false);

	if (m_tauler.colisionaFigura(m_figuraActual))
	{
		m_figuraActual.desplazamientoVertical(true);

		nFiles = m_tauler.colocaFigura(m_figuraActual);

		m_figuraActual.iniciarFigura(NO_FIGURA);
		m_figuraActual.set_fila_columna(-1, -1);

	}
	return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{

		m_tauler.dibuixaFigura(m_figuraActual);

		ColorFigura tauler[MAX_FILA][MAX_COL];
		m_tauler.getValorsTauler(tauler);
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

