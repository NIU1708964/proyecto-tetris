

#include "tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILES; i++) 
	{
		for (int j = 0; j < MAX_COLUMNES; j++) 
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}

		m_lliures[i] = MAX_COLUMNES;
	}
}

void Tauler::inicialitzaTauler(ColorFigura TaulerInicial[MAX_FILES][MAX_COLUMNES]) {

	for (int i = 0; i < MAX_FILES; i++)
	{
		m_lliures[i] = 0;

		for (int j = 0; j < MAX_COLUMNES; j++) {

			m_tauler[i][j] = TaulerInicial[i][j];

			if (TaulerInicial[i][j] = COLOR_NEGRE)
			{
				m_lliures[i]++;

			}
		}	
	}
}


bool Tauler::colisionaFigura() {


	bool colisiona = false;



	if ()



}





