#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"





void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments){ 

	

	m_mode = mode;
	tiempo = 0.0;
	puntuacio_actual = 0;
	nivell_actual = 1;
	velocitat_actual = VELOCITAT_PRIMER_NIVEL;  
	final = false;

	primeroF = nullptr;
	primeroM = nullptr;


	Figuras = primeroF;
	Movimientos = primeroM;





	if (m_mode == MODE_TEST)
	{
		m_joc.inicialitza(fitxerInicial);
		 
		m_joc.DibuixaJoc();  

		LLegirFigures(fitxerFigures); 
		LLegirMoviments(fitxerMoviments);

		Figuras = primeroF;
		Movimientos = primeroM;
		


		//AGREGAR COSAS DE LISTAS DINAMICAS CON NODOS ENLAZADOS(MIRARLAS)
	}
	else if (mode == MODE_NORMAL) {

		final = m_joc.NovaFigura(); 

	}


}


void Partida::actualitza(int mode, double deltaTime) { 

	m_mode = mode;
	int FilesCompletades=-1;

	NivellActualitzacio();

	if (m_mode == MODE_NORMAL)
	{
		if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
		{
			m_joc.mouFigura(1);
		}
		else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT)) {
			m_joc.mouFigura(-1);
		}
		else if (Keyboard_GetKeyTrg(KEYBOARD_UP)) {
			m_joc.giraFigura(GIR_HORARI);
		}
		else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN)) {
			m_joc.giraFigura(GIR_ANTI_HORARI);
		}


		if (Keyboard_GetKeyTrg(KEYBOARD_SPACE)) {

			FilesCompletades = m_joc.BaixarTot(); 
			puntuacio_actual += COLOCAR_FIGURA;
			final=m_joc.NovaFigura();   
			tiempo = 0.0;


		}
		else {

			tiempo += deltaTime;

			if (tiempo > velocitat_actual)
			{
				FilesCompletades = m_joc.baixaFigura(); 

				if (FilesCompletades != -1) {

					final=m_joc.NovaFigura();
					puntuacio_actual += COLOCAR_FIGURA;

				}

				tiempo = 0.0;

			}

		}

		switch (FilesCompletades)
		{
		case 1: puntuacio_actual += ELIMINAR_1_FILA; break;
		case 2: puntuacio_actual += ELIMINAR_2_FILA; break;
		case 3: puntuacio_actual += ELIMINAR_3_FILA; break;
		case 4: puntuacio_actual += ELIMINAR_4_FILA; break;

		}

		if (puntuacio_actual == PUJAR_NIVEL * nivell_actual)
		{
			nivell_actual++;
			velocitat_actual *= AUGMENT_VELOCITAT;

		}

		m_joc.DibuixaJoc();

	}
	else if (m_mode == MODE_TEST) {

		tiempo += deltaTime;
		TipusMoviment moviment;

		if (tiempo > velocitat_actual)
		{

			tiempo = 0.0;
			final = false;

			if (Movimientos != nullptr)
			{
				moviment = Movimientos->getValor(); 
				Movimientos = Movimientos->getNext(); 

				switch (moviment) {
				case MOVIMENT_ESQUERRA: m_joc.mouFigura(-1); break;
				case MOVIMENT_DRETA: m_joc.mouFigura(1); break;
				case MOVIMENT_GIR_HORARI: m_joc.giraFigura(GIR_HORARI); break;
				case MOVIMENT_GIR_ANTI_HORARI: m_joc.giraFigura(GIR_ANTI_HORARI); break;
				case MOVIMENT_BAIXA_FINAL:
					FilesCompletades = m_joc.BaixarTot();
					puntuacio_actual += COLOCAR_FIGURA;
					if (Figuras == nullptr) {
						final = true;
					}
					else {

						Figura aux = Figuras->getValor(); 
						m_joc.ReemplazaFiguraActual(aux);
						Figuras = Figuras->getNext(); 

						   

					}
					break;
				case MOVIMENT_BAIXA:

					FilesCompletades = m_joc.baixaFigura();
					if (FilesCompletades != -1) {

						puntuacio_actual += COLOCAR_FIGURA;
						if (Figuras == nullptr) {
							final = true;
						}else{

							Figura aux = Figuras->getValor();
							m_joc.ReemplazaFiguraActual(aux);
							Figuras = Figuras->getNext(); 


						}

					}



				}



			}



		}

		switch (FilesCompletades)
		{
		case 1: puntuacio_actual += ELIMINAR_1_FILA; break;
		case 2: puntuacio_actual += ELIMINAR_2_FILA; break;
		case 3: puntuacio_actual += ELIMINAR_3_FILA; break;
		case 4: puntuacio_actual += ELIMINAR_4_FILA; break;

		}



		m_joc.DibuixaJoc();
	

	}

}


void Partida::MostrarPuntuacio_Nivell()
{

	string msg = "Puntuacio: " + to_string(puntuacio_actual) + ",     Nivell: " + to_string(nivell_actual);  
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg); 

}



// AGREGAR LO DE LAS LISTAS CON NODOS

void Partida::LLegirFigures(const string& fitxerFigures) {

	ifstream fitxerFiguras; 

	fitxerFiguras.open(fitxerFigures);
	if (fitxerFiguras.is_open())
	{
		int tipus, fila, columna, gir;
		fitxerFiguras >> tipus >> fila >> columna >> gir;

		Figura aux;

		aux.set_fila_columna(fila, columna);
		aux.setGir(gir);
		aux.iniciarFigura(TipusFigura(tipus));

		while (!fitxerFiguras.eof())
		{
			NodeFigures* NodoFigura = new NodeFigures; 

			NodoFigura->SetFigura(aux);
			NodoFigura->SetNext(nullptr);

			if (primeroF == nullptr) {
				primeroF = NodoFigura;
			}
			else {
				bool trobat = false;
				NodeFigures* siguiente = primeroF;

				while (!trobat) {
					if (siguiente->getNext() == nullptr)
					{
						siguiente->SetNext(NodoFigura);
						trobat = true;
					}
					else {
						siguiente = siguiente->getNext();
					}
				}
			}
			fitxerFiguras >> tipus >> fila >> columna >> gir;
			aux.set_fila_columna(fila, columna);
			aux.setGir(gir);
			aux.iniciarFigura(TipusFigura(tipus));
			
		}
	}
	fitxerFiguras.close();
}


void Partida::LLegirMoviments(const string& fitxerMoviments) { 


	ifstream fitxerMoviment;


	fitxerMoviment.open(fitxerMoviments);
	if (fitxerMoviment.is_open())
	{
		int tipus;

		fitxerMoviment >> tipus;

		TipusMoviment aux = TipusMoviment(tipus);

		while (!fitxerMoviment.eof())
		{

			NodeMoviments* NodoMovimiento = new NodeMoviments;
			NodoMovimiento->SetMoviment(aux);
			NodoMovimiento->SetNext(nullptr);

			if (primeroM == nullptr) {

				primeroM = NodoMovimiento;

			}
			else {

				bool trobat = false;
				NodeMoviments* siguiente = primeroM;
				while (!trobat)
				{
					if (siguiente->getNext() == nullptr)
					{
						siguiente->SetNext(NodoMovimiento);  
						trobat = true;
					}
					else
						siguiente = siguiente->getNext();
				}
			}

			fitxerMoviment >> tipus;
			aux = TipusMoviment(tipus);
		}
	}

	fitxerMoviment.close();

}

void Partida::NivellActualitzacio() {

	if (puntuacio_actual >= (PUJAR_NIVEL * nivell_actual))
	{
		nivell_actual++;
		velocitat_actual *= AUGMENT_VELOCITAT;

	}

}