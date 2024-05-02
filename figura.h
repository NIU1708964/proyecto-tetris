#pragma once
#define MAX_ALTURA 4
#define MAX_AMPLADA 4
#define MAX_ANCHURA 4

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



typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;


class Figura {

public:

	void figuraVacia();
	void llenarFigura(int parametro, int anch, int alt);
	void iniciarFigura(TipusFigura tipo_figura);
	void set_fila_columna(int fila, int columna) { m_pos_fila = fila; m_pos_columna = columna; }
	void desplazamientoLateral(bool direccio);
	void desplazamientoVertical(bool direccio);
	void girar(bool sentido);

	int getFila() const { return m_pos_fila; }
	int getColumna() const { return m_pos_columna; }

	int getAltura() const { return m_altura; }
	int getAnchura() const { return m_anchura; }
	ColorFigura getColor() const { return colorFigura; }
	void getEstructura(int m_estructura[MAX_ALTURA][MAX_ANCHURA]) const;
	int obtenerEstructura(int fila, int columna) const { return estructura[fila][columna]; }


private:

	TipusFigura tipoFigura;
	ColorFigura colorFigura;
	int m_pos_fila;
	int m_pos_columna; // Comienza en el max de altura del tablero
	int m_anchura;
	int m_altura;
	int estructura[MAX_ALTURA][MAX_ANCHURA];

};