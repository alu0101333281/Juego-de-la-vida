#include <iostream>

#include "../include/grid.h"



/**
 * @brief      Main program
 */
int main() {
	int filas = 0;
	int columnas = 0;
	int turnos = 1;
	std::cout << "Indique la cantidad de filas: ";
	std::cin >> filas;
	std::cout << "Indique la cantidad de columnas: ";
	std::cin >> columnas;
	std::cout << "Indique la cantidad de turnos del juego: ";
	std::cin >> turnos;
	Grid juego(filas, columnas, turnos);
};