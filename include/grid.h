/**********************************************
** Program name: Juego de la vida
** Author: Cristopher Alexandro Medina Peschiutta
** Date: 03/03/2022
** Description: This is the header file for the class Grid.
***********************************************/

#pragma once

using namespace std;

#include "cell.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>


class Grid{

public:

    Grid();  /* Constructor por defecto */
	
	Grid(int rows, int columns, int turn);  /* Constructor */
	
	~Grid();  /* Destructor */

	int get_rows (void);  /* Getter del atributo rows_ */

	int get_columns (void) const;  /* Getter del atributo columns */

    void create_cell(void);

	int get_turn (void);  /* Getter del atributo turn_ */

    void write (void);  /* Imprime la tabla por la salida especificada */

    void next_turn (void);  /* Actualiza el tablero y pasa un turno */

    void next_generation();

    void set_turn (int turn);  /* Setter del atributo turn_ */

	Cell** get_mesh() const;

private:
    
	int rows_;  /* Número de filas del tablero */
	
	int columns_;  /* Número de columnas del tablero */
	
	Cell** mesh_;  /* Doble puntero array que simula el tablero */
	
	int turn_;  /* Turno actual del juego */
    
};