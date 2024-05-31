#ifndef TEST_H 
#define TEST_H 

#include <string>
#include "InfoJoc.h" 
#include "Figura.h"
#include <stdlib.h>

#pragma once

class NodeFigures { 

public:

	Figura& getValor() { return nodoFigura; }
 	NodeFigures* getNext() { return seguent; }
	void SetFigura(const Figura& nodoFig) { nodoFigura = nodoFig; }  
	void SetNext(NodeFigures* next) { seguent = next; } 

private:

	Figura nodoFigura; 
	NodeFigures* seguent;

};

class NodeMoviments {

public:
 
	TipusMoviment& getValor() { return nodoMoviment; } 
	NodeMoviments* getNext() { return seguent; } 
	void SetMoviment(const TipusMoviment& nodoMov) { nodoMoviment = nodoMov; }
	void SetNext(NodeMoviments* next) { seguent = next; } 

private:
	TipusMoviment nodoMoviment; 
	NodeMoviments* seguent;

};


#endif 

