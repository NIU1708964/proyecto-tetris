#pragma once
#define MAX_ALTURA 10
#define MAX_ANCHURA 10

#include <iostream>

typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;


typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;


class Figura {

public:

	void FiguraVacia();
	void LlenarFigura(int parametro, int anch, int alt);
	void IniciarFigura(TipusFigura tipo_figura);
	void Dezplazamiento_lateral(bool direccio);
	void Dezplazamiento_vertical(bool direccio);
	void Girar(bool sentido);

private:

	TipusFigura tipo_figura;
	ColorFigura color_figura;
	int pos_fila; //
	int pos_columna; // Comienza en el max de altura del tablero
	int anchura;
	int altura;
	int estructura[MAX_ALTURA][MAX_ANCHURA];


	


	


}