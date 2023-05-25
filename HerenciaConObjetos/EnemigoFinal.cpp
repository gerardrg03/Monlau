#pragma once
#include <iostream>
#include "EnemigoFinal.h"
using namespace std;

EnemigoFinal::EnemigoFinal(string pNombre, int pVida, int pAtaque, int pPosicionX, int pPosicionY, string pCabeza, string pTorso, string pPiernas, bool pAlerta, int pAtaqueEspecial) 
	: Personaje (pNombre, pVida, pAtaque, pPosicionX, pPosicionY, pCabeza, pTorso, pPiernas, pAlerta)
{
	ataqueEspecial = pAtaqueEspecial;
}

int EnemigoFinal::getAtaqueEspecial() {
	return ataqueEspecial;
}

void EnemigoFinal::setAtaqueEspecial(int pAtaqueEspecial) {
	ataqueEspecial = pAtaqueEspecial;
}

