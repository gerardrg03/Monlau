#pragma once
#include <iostream>
class Lancha
{
private:
	//propiedades lancha
	std::string nombre;
	int velocidad;
	int distancia;
	int nitro;
	int dado;
	std::string icono;

public:
	//CONSTRUCTOR
	Lancha(std::string pNombre, int pVelocidad, int pDistancia, bool pNitro, int pDado);
	
	//GETTERS
	std::string getNombre();
	int getVelocidad();
	int getDistancia();
	bool getNitro();
	int getDado();
	//std::string getIcono();

	//SETTERS
	void setNombre(std::string pNombre);
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setNitro(bool pNitro);
	void setDado(int pDado);
	//void setIcono(std::string pIcono);

	//métodos propios
	void printStatus();
	void tuTurno();
	void tirarDado();
	void nitroYDistancia();
	void marcadorGrafico();
};

