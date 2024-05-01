#include <iostream>
#include "Figura.h"

void Figura::figuraVacia() {

	for (int i = 0; i < m_altura; i++)
	{
		for (int k = 0; k < m_anchura; k++) {

			estructura[i][k] = 0;
		}
	}

}

void Figura::llenarFigura(int parametro, int anch, int alt) {

	for (int i = 0; i < alt; i++)
	{
		for (int k = 0; k < anch; k++) {

			estructura[i][k] = parametro;
		}
	}

}


void Figura::iniciarFigura(TipusFigura tipo_figura) {

	int i;
	tipoFigura = tipo_figura;


	switch (tipo_figura)
	{
	case FIGURA_O:

		m_altura = 2;
		m_anchura = 2;

		figuraVacia();
		llenarFigura(1, m_altura, m_anchura);

		colorFigura = COLOR_GROC;

		break;


	case FIGURA_I:

		m_altura = 4;
		m_anchura = 4;

		figuraVacia();

		i = 1;

		for (int k = 0; k < m_anchura; k++) {

			estructura[i][k] = 1;
		}

		colorFigura = COLOR_BLAUCEL;

		break;

	case FIGURA_T:

		m_altura = 3;
		m_anchura = 3;

		figuraVacia();

		estructura[0][1] = 1;

		i = 1;

		for (int k = 0; k < m_anchura; k++) {

			estructura[i][k] = 1;
		}
		colorFigura = COLOR_MAGENTA;

		break;

	case FIGURA_L:

		m_altura = 3;
		m_anchura = 3;

		figuraVacia();

		estructura[0][2] = 1;

		i = 1;

		for (int k = 0; k < m_anchura; k++) {

			estructura[i][k] = 1;
		}

		colorFigura = COLOR_TARONJA;

		break;

	case FIGURA_J:

		m_altura = 3;
		m_anchura = 3;

		figuraVacia();

		estructura[0][0] = 1;

		i = 1;

		for (int k = 0; k < m_anchura; k++) {

			estructura[i][k] = 1;
		}

		colorFigura = COLOR_BLAUFOSC;

		break;

	case FIGURA_Z:

		m_altura = 3;
		m_anchura = 3;

		figuraVacia();

		estructura[0][0] = 1;
		estructura[0][1] = 1;
		estructura[1][1] = 1;
		estructura[1][2] = 1;

		colorFigura = COLOR_VERMELL;

		break;


	case FIGURA_S:

		m_altura = 3;
		m_anchura = 3;

		figuraVacia();

		estructura[1][0] = 1;
		estructura[0][1] = 1;
		estructura[1][1] = 1;
		estructura[0][2] = 1;

		colorFigura = COLOR_VERD;

		break;

	}
}

void Figura::desplazamientoLateral(bool direccio) {

	// Si direccio es true la figura se desplazara a la derecha, en cambio si es false irá a la izquierda
	// En la clase Tauler creo que para que no choque con otra figura hay que implementar un if ( columna +/- 1 != 1) { Figura.Desplazamiento_lateral}

	if (direccio)
	{
		m_pos_columna++;
	}
	else {
		m_pos_columna--;
	}
}

void Figura::desplazamientoVertical(bool direccio) {

	// Si direccio es true la figura se desplazara hacia arriba, en cambio si es false irá hacia abajo.
	// En la clase Tauler creo que para que no choque con otra figura hay que implementar un if ( fila - 1 != 1) { Figura.Desplazamiento_abajo}

	if (direccio)
	{
		m_pos_fila--;
	}
	else {
		m_pos_fila++;
	}

}

void Figura::girar(bool sentido) {

	// Si sentido es true, sera un giro en sentido horario, si es false será en sentido antihorario

	int matriz_transpuesta[MAX_ALTURA][MAX_ANCHURA];

	for (int i = 0; i < m_altura; ++i) {
		for (int j = 0; j < m_anchura; ++j) {
			matriz_transpuesta[j][i] = estructura[i][j];

		}
	}

	for (int i = 0; i < m_altura; ++i) {
		for (int j = 0; j < m_anchura; ++j) {
			estructura[i][j] = matriz_transpuesta[i][j];
		}
	}

	if (sentido)
	{
		for (int i = 0; i < m_anchura / 2; ++i) {
			for (int j = 0; j < m_altura; ++j) {
				int temp = estructura[j][i];
				estructura[j][i] = estructura[j][m_anchura - 1 - i];
				estructura[j][m_anchura - 1 - i] = temp;
			}
		}

	}
	else {

		for (int i = 0; i < m_altura / 2; ++i) {
			for (int j = 0; j < m_anchura; ++j) {
				int temp = estructura[i][j];
				estructura[i][j] = estructura[m_altura - 1 - i][j];
				estructura[m_altura - 1 - i][j] = temp;
			}
		}
	}

}

void Figura::getEstructura(int m_estructura[MAX_ALTURA][MAX_ANCHURA]) const
{
	for (int i = 0; i < m_altura; i++)
		for (int j = 0; j < m_anchura; j++)
			m_estructura[i][j] = estructura[i][j];
}

