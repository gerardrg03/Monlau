#include <iostream>
#include <windows.h>
#include <string>
#include "Lancha.h"

//constructor
Lancha::Lancha(std::string pNombre, int pVelocidad, int pDistancia, bool pNitro, int pDado) {
	nombre = pNombre;
	velocidad = pVelocidad;
	distancia = pDistancia;
	nitro = pNitro;
	dado = pDado;
}

//GETTERS
std::string Lancha::getNombre() {
	return nombre;
}
int Lancha::getVelocidad() {
	return velocidad;
}
int Lancha::getDistancia() {
	return distancia;
}
bool Lancha::getNitro() {
	return nitro;
}
int Lancha::getDado() {
	return dado;
}


//SETTERS
void Lancha::setNombre(std::string pNombre) {
	nombre = pNombre;
}
void Lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}
void Lancha::setDistancia(int pDistancia) {
	distancia = pDistancia;
}
void Lancha::setNitro(bool pNitro) {
	nitro = pNitro;
}
void Lancha::setDado(int pDado) {
	dado = pDado;
}

//métodos propios
void Lancha::printStatus() {
	std::cout << getNombre() << " ha alcanzado una velocidad de " << getVelocidad() << "m/s , ha recorrido una distancia de " << getDistancia() << "m y ";
	if ( getNitro() ) {
		std::cout << "aun tiene nitro.\n";
	}
	else {
		std::cout << "ya no le queda nitro.\n";
	}
}
void Lancha::tuTurno() {
	std::cout << getNombre() << ", es tu turno.\n";
}
void Lancha::tirarDado(){
	int valor = 1 + (rand() % 6);
	setDado(valor);
	std::cout << getNombre() << " ha sacado un " << getDado() << ".\n";
	setVelocidad(getVelocidad()+getDado());
	std::cout << "La velocidad de " << getNombre() << " ha incrementado a " << getVelocidad() << "m/s.\n";
}
void Lancha::nitroYDistancia() {
	if (getNitro()) {
		int nitro;
		do {
			std::cout << "Quieres usar el nitro? *Recuerda que puede tanto ayudarte como perjudicarte*\n";
			std::cout << "[1] Usar nitro\n[2] No usar nitro\n";
			std::cin >> nitro;
			if (nitro != 1 && nitro != 2) {
				std::cout << "Numero invalido. Tienes que seleccionar una de las opciones marcadas.\n";
			}
			else if (nitro == 1) {
				setNitro(false);
				int binario = rand() % 2;
				if (binario == 1) {
					setVelocidad(getVelocidad() / 2);
					std::cout << "Algo ha ido mal con el nitro. Tu lancha ha bajado a " << getVelocidad() << "m/s.\n";
				}
				else {
					setVelocidad(getVelocidad() * 2);
					std::cout << "Has salido disparado en un segundo. Tu velocidad ahora es de " << getVelocidad() << "m/s.\n";
				}
			}
		} while (nitro != 1 && nitro != 2);
	}
	else {
		std::cout << "Ya no te queda nitro.\n";
	}
	setDistancia(getDistancia() + getVelocidad() * 100);
	std::cout << "Has recorrido una distancia de " << getDistancia() << ".\n\n";
}
void Lancha::marcadorGrafico() {
	int distancia = (getDistancia() / 200) + 1;
	std::cout << "\n";
	for (int i = 0; i <= distancia; i++) {
		std::cout << " ";
	}
	std::cout << "    ___\n";
	for (int i = 0; i <= distancia; i++) {
		std::cout << " ";
	}
	std::cout << "___[\\==\\__\n";

	for (int i = 0; i <= distancia; i++) {
		std::cout << "~";
	}
	std::cout << "\\________/\n";
	for (int i = 0; i <= distancia; i++) {
		std::cout << "~";
	}
	std::cout << "\n";
}
