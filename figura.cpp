#include <iostream>
#include "Figura.h"

void Figura::FiguraVacia() {

	for (int i = 0; i < altura; i++)
	{
		for (int k = 0; k < anchura; k++) {

			estructura[i][k] = 0;
		}
	}

}

void Figura::LlenarFigura(int parametro, int anch, int alt) {

	for (int i = 0; i < alt; i++)
	{
		for (int k = 0; k < anch; k++) {

			estructura[i][k] = parametro;
		}
	}

}


void Figura::IniciarFigura(TipusFigura tipo_figura) {


	switch (tipo_figura)
	{
	case FIGURA_O:
		altura = 2;
		anchura = 2;

		FiguraVacia();
		LlenarFigura(1, altura, anchura);

		color_figura = COLOR_GROC;

		break;


	case FIGURA_I:

		altura = 4;
		anchura = 4;

		FiguraVacia();

		int i = 1;

		for (int k = 0; k < anchura; k++) {

			estructura[i][k] = 1;
		}

		color_figura = COLOR_BLAUCEL;

		break;

	case FIGURA_T:

		altura = 3;
		anchura = 3;

		FiguraVacia();

		estructura[0][1] = 1;

		i = 1;

		for (int k = 0; k < anchura; k++) {

			estructura[i][k] = 1;
		}
		color_figura = COLOR_MAGENTA;

		break;

	case FIGURA_L:

		altura = 3;
		anchura = 3;

		FiguraVacia();

		estructura[0][2] = 1;

		i = 1;

		for (int k = 0; k < anchura; k++) {

			estructura[i][k] = 1;
		}

		color_figura = COLOR_TARONJA;

		break;

	case FIGURA_J:

		altura = 3;
		anchura = 3;

		FiguraVacia();

		estructura[0][0] = 1;

		i = 1;

		for (int k = 0; k < anchura; k++) {

			estructura[i][k] = 1;
		}

		color_figura = COLOR_BLAUFOSC;

		break;

	case FIGURA_Z:

		altura = 3;
		anchura = 3;

		FiguraVacia();

		estructura[0][0] = 1;
		estructura[0][1] = 1;
		estructura[1][1] = 1;
		estructura[1][2] = 1;

		color_figura = COLOR_VERMELL;

		break;


	case FIGURA_S:

		altura = 3;
		anchura = 3;

		FiguraVacia();

		estructura[1][0] = 1;
		estructura[0][1] = 1;
		estructura[1][1] = 1;
		estructura[0][2] = 1;

		color_figura = COLOR_VERD;

		break;

	}
}

void Figura::Dezplazamiento_lateral(bool direccio) {

	// Si direccio es true la figura se desplazara a la derecha, en cambio si es false irá a la izquierda
	// En la clase Tauler creo que para que no choque con otra figura hay que implementar un if ( fila +/- 1 != 1) { Figura.Desplazamiento_lateral}

	if (direccio)
	{

		for (int i = 0; i < altura; i++)
		{
			for (int k = 0; k < anchura; k++) {

				if (estructura[i][k] == 1) {
					pos_fila++;}
			}
		}
	}
	else {
		for (int i = 0; i < altura; i++)
		{
			for (int k = 0; k < anchura; k++) {

				if (estructura[i][k] == 1) { //corregir
					pos_fila--;
				}
			}
		}
	}
}

void Figura::Dezplazamiento_abajo() {

	// En la clase Tauler creo que para que no choque con otra figura hay que implementar un if ( columna - 1 != 1) { Figura.Desplazamiento_abajo}

	for (int i = 0; i < altura; i++)
	{
		for (int k = 0; k < anchura; k++) {

			if (estructura[i][k] = 1) {
				pos_columna--;
			}
		}
	}

}


void Figura::Girar(bool sentido) {

	// Si sentido es true, sera un giro en sentido horario, si es false será en sentido antihorario

	int matriz_transpuesta[MAX_ANCHURA][MAX_ALTURA];

	for (int i = 0; i < anchura; ++i) {
		for (int j = 0; j < altura; ++j) {
			matriz_transpuesta[j][i] = estructura[i][j];

		}
	}

	for (int i = 0; i < altura; ++i) {
		for (int j = 0; j < anchura; ++j) {
			estructura[i][j] = matriz_transpuesta[i][j];
		}
	}

	if (sentido)
	{
		for (int i = 0; i < anchura; ++i) {
			for (int j = 0; j < altura / 2; ++j) {
				int temp = estructura[i][j];
				estructura[i][j] = estructura[i][anchura - 1 - j];
				estructura[i][anchura - 1 - j] = temp;
			}
		}

	}
	else {

		for (int i = 0; i < altura; ++i) {
			for (int j = 0; j < anchura / 2; ++j) {
				int temp = estructura[i][j];
				estructura[i][j] = estructura[i][altura - 1 - j];
				estructura[i][altura - 1 - j] = temp;
			}
		}
	}

}

