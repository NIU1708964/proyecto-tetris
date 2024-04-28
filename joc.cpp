#include "joc.h"
#include "figura.h"
#include <fstream>

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if(fitxer.is_open())
	{
		int tipus, fila, columna, gir;
		fitxer >> tipus >> fila >> columna >> gir;











		fitxer.close();
	}
}
bool giraFigura(DireccioGir direccio)
{
	//implementar una funcio dins de la clase figura que permeti girar la figura y comprobar
	//si colisiona contra altres elements
}
bool mouFigura(int dirX)
{
	m_figura.mou(dirX);
	if(figura.colisiona)
	//exemple
	//implementar metode colisiona tauler per evitar un moviment si colisiona
	//implementar una funcio dins de la clase figura que permeti moure la figura
}
int baixaFigura()
{
	if()
	//si la figura omple una fila, eliminar-la
}
void escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer << tauler[i][j] << " ";
			}
			fitxer << endl;
		}
		fitxer.close();
	}
}