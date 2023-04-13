#include <iostream>
#include <conio.h>
#include <windows.h>
#include <locale>
#include <string>
#include "Lancha.h"

int numeroDeJugadores() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
	int jug;
	do {
		std::cout << "Que modo de juego quieres jugar?\n";
		std::cout << "[1] Un jugador vs IA\n[2] Dos jugadores\n[3] Tres jugadores\n";
		std::cin >> jug;
		if (jug != 1 && jug != 2 && jug != 3) {
			std::cout << "Modo de juego no valido.\n";
		}
		else {
			return jug;
		}
	} while (jug != 1 && jug != 2 && jug != 3); 
	return 0;
}
std::string ponerNombre() {
	std::string nombre;
	std::cout << "Introduce el nombre de jugador:\n";
	std::cin >> nombre;
	nombre[0] = toupper(nombre[0]);
	return nombre;
}


int main() {
	//SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));
	int numJug = numeroDeJugadores();
	if (numJug == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
		Lancha jugador1(ponerNombre(), 0, 0, true, 1 + (rand() % 6));
		Lancha jugador2("Bot", 0, 0, true, 1 + (rand() % 6));

		for (int i = 1; i <= 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
			std::cout << "\nTURNO " << i << "\n\n";
			//turno jugador1
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.tuTurno();
			std::cout << jugador1.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador1.tirarDado();
			jugador1.nitroYDistancia();

			//turno jugador2
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.tuTurno();
			Sleep(1000);
			jugador2.tirarDado();
			Sleep(1000);
			if (jugador2.getNitro()) {
				
				if (i>2 && jugador2.getDistancia() * 1.10 < jugador1.getDistancia()) {
					jugador2.setNitro(false);
					int binario = rand() % 1;
					if (binario == 0) {
						jugador2.setVelocidad(jugador2.getVelocidad() / 2);
						std::cout << "Algo ha ido mal con el nitro de " << jugador2.getNombre() << ". Su lancha ha bajado a " << jugador2.getVelocidad() << "m/s.\n";
					}
					else {
						jugador2.setVelocidad(jugador2.getVelocidad() * 2);
						std::cout << jugador2.getNombre() << " ha salido disparado en un segundo. Su velocidad ahora es de " << jugador2.getVelocidad() << "m/s.\n";
					}
				}
			}
			else {
				std::cout << "A " << jugador2.getNombre() << " no le queda nitro.\n";
			}
			jugador2.setDistancia(jugador2.getDistancia() + jugador2.getVelocidad() * 100);
			std::cout << jugador2.getNombre() << " ha recorrido una distancia de " << jugador2.getDistancia() << ".\n\n";

			//marcador
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.printStatus();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.printStatus();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x16);
			std::cout << "\n";
			jugador1.marcadorGrafico();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x14);
			jugador2.marcadorGrafico();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
		std::cout << "\n";
		if (jugador1.getDistancia() < jugador2.getDistancia()) {
			std::cout << "1º: " << jugador1.getDistancia() << "\n";
			std::cout << "2º: " << jugador2.getDistancia() << "\n";
		}
		else if (jugador1.getDistancia() > jugador2.getDistancia()) {
			std::cout << "1º: " << jugador2.getDistancia() << "\n";
			std::cout << "2º: " << jugador1.getDistancia() << "\n";
		}
		else {
			std::cout << jugador1.getNombre() <<" y " << jugador2.getNombre() << " han empatrtado.\n";
		}
	}
	else if (numJug == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
		Lancha jugador1(ponerNombre(), 0, 0, true, 1 + (rand() % 6));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		Lancha jugador2(ponerNombre(), 0, 0, 1, 1 + (rand() % 6));

		for (int i = 1; i <= 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
			std::cout << "\nTURNO " << i << "\n\n";
			//turno jugador1
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.tuTurno();
			std::cout << jugador1.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador1.tirarDado();
			jugador1.nitroYDistancia();

			//turno jugador2
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.tuTurno();
			std::cout << jugador2.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador2.tirarDado();
			jugador2.nitroYDistancia();

			//marcador
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.printStatus();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.printStatus();


			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x16);
			std::cout << "\n";
			jugador1.marcadorGrafico();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x14);
			jugador2.marcadorGrafico();
			
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
		std::cout << "\n";
		if (jugador1.getDistancia() < jugador2.getDistancia()) {
			std::cout << "1º: " << jugador1.getDistancia() << "\n";
			std::cout << "2º: " << jugador2.getDistancia() << "\n";
		}
		else if (jugador1.getDistancia() > jugador2.getDistancia()) {
			std::cout << "1º: " << jugador2.getDistancia() << "\n";
			std::cout << "2º: " << jugador1.getDistancia() << "\n";
		}
		else {
			std::cout << jugador1.getNombre() << " y " << jugador2.getNombre() << " han empatrtado.\n";
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
		Lancha jugador1(ponerNombre(), 0, 0, true, 1 + (rand() % 6));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
		Lancha jugador2(ponerNombre(), 0, 0, true, 1 + (rand() % 6));
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
		Lancha jugador3(ponerNombre(), 0, 0, true, 1 + (rand() % 6));

		for (int i = 1; i <= 5; i++) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
			std::cout << "\nTURNO " << i << "\n\n";
			//turno jugador1
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.tuTurno();
			std::cout << jugador1.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador1.tirarDado();
			jugador1.nitroYDistancia();

			//turno jugador2
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.tuTurno();
			std::cout << jugador2.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador2.tirarDado();
			jugador2.nitroYDistancia();

			//turno jugador3
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
			jugador3.tuTurno();
			std::cout << jugador3.getNombre() << ", pulsa cualquier tecla para tirar el dado.\n";
			_getch();
			jugador3.tirarDado();
			jugador3.nitroYDistancia();

			//marcador
			Sleep(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			jugador1.printStatus();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			jugador2.printStatus();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
			jugador3.printStatus();

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x16);
			std::cout << "\n";
			jugador1.marcadorGrafico();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x14);
			jugador2.marcadorGrafico();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x12);
			jugador3.marcadorGrafico();
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);
		std::cout << "\n";
		if (jugador1.getDistancia() != jugador2.getDistancia() && jugador1.getDistancia() != jugador3.getDistancia()) {
			if (jugador1.getDistancia() > jugador2.getDistancia() && jugador1.getDistancia() > jugador3.getDistancia()) {
				if (jugador2.getDistancia() > jugador3.getDistancia()) {
					std::cout << "1º: " << jugador1.getNombre() << "\n";
					std::cout << "2º: " << jugador2.getNombre() << "\n";
					std::cout << "3º: " << jugador3.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador1.getNombre() << "\n";
					std::cout << "2º: " << jugador3.getNombre() << "\n";
					std::cout << "3º: " << jugador2.getNombre() << "\n";
				}
			}
			else if (jugador2.getDistancia() > jugador1.getDistancia() && jugador2.getDistancia() > jugador3.getDistancia()) {
				if (jugador1.getDistancia() > jugador3.getDistancia()) {
					std::cout << "1º: " << jugador2.getNombre() << "\n";
					std::cout << "2º: " << jugador1.getNombre() << "\n";
					std::cout << "3º: " << jugador3.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador2.getNombre() << "\n";
					std::cout << "2º: " << jugador3.getNombre() << "\n";
					std::cout << "3º: " << jugador1.getNombre() << "\n";
				}
			}
			else {
				if (jugador1.getDistancia() > jugador2.getDistancia()) {
					std::cout << "1º: " << jugador3.getNombre() << "\n";
					std::cout << "2º: " << jugador1.getNombre() << "\n";
					std::cout << "3º: " << jugador2.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador3.getNombre() << "\n";
					std::cout << "2º: " << jugador2.getNombre() << "\n";
					std::cout << "3º: " << jugador1.getNombre() << "\n";
				}
			}
		}
		else {
			if (jugador1.getDistancia() == jugador2.getDistancia()) {
				if (jugador1.getDistancia() > jugador3.getDistancia()) {
					std::cout << "1º: " << jugador1.getNombre() << "(Empate)\n";
					std::cout << "1º: " << jugador2.getNombre() << "(Empate)\n";
					std::cout << "3º: " << jugador3.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador3.getNombre() << "\n";
					std::cout << "2º: " << jugador1.getNombre() << "(Empate)\n";
					std::cout << "2º: " << jugador2.getNombre() << "(Empate)\n";
				}
			}
			else if (jugador1.getDistancia() == jugador3.getDistancia()) {
				if (jugador1.getDistancia() > jugador2.getDistancia()) {
					std::cout << "1º: " << jugador1.getNombre() << "(Empate)\n";
					std::cout << "1º: " << jugador3.getNombre() << "(Empate)\n";
					std::cout << "3º: " << jugador2.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador2.getNombre() << "\n";
					std::cout << "2º: " << jugador1.getNombre() << "(Empate)\n";
					std::cout << "2º: " << jugador3.getNombre() << "(Empate)\n";
				}
			}
			else if (jugador2.getDistancia() == jugador3.getDistancia()) {
				if (jugador1.getDistancia() > jugador2.getDistancia()) {
					std::cout << "1º: " << jugador2.getNombre() << "(Empate)\n";
					std::cout << "1º: " << jugador3.getNombre() << "(Empate)\n";
					std::cout << "3º: " << jugador1.getNombre() << "\n";
				}
				else {
					std::cout << "1º: " << jugador1.getNombre() << "\n";
					std::cout << "2º: " << jugador2.getNombre() << "(Empate)\n";
					std::cout << "2º: " << jugador3.getNombre() << "(Empate)\n";
				}
			}
			else {
				std::cout << "Ha habido un triple empate entre " << jugador1.getNombre() << ", " << jugador2.getNombre() << " y " << jugador3.getNombre() << "\n";
			}
		}
	}
}
