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

	void figuraVacia();
	void llenarFigura(int parametro, int anch, int alt);
	
	void iniciarFigura(TipusFigura tipo_figura);
	void desplazamientoLateral(bool direccio);
	void desplazamientoVertical(bool direccio);
	void girar(bool sentido);

	int getEstructura(int estructura[MAX_ALTURA][MAX_ANCHURA])const;
	int getAltura() const { return m_altura; }
	ColorFigura getColor() const { return m_colorFigura; }


private:

	TipusFigura m_tipoFigura;
	ColorFigura m_colorFigura;
	int m_pos_fila;
	int m_pos_columna; // Comienza en el max de altura del tablero
	int m_anchura;
	int m_altura;
	int m_estructura[MAX_ALTURA][MAX_ANCHURA];
}