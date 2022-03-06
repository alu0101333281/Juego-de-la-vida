/**********************************************
** Program name: Juego de la vida
** Author: Cristopher Alexandro Medina Peschiutta
** Date: 03/03/2022
** Description: This is the header file for the class Cell.
***********************************************/

#pragma once
#include <iostream>
#include "state.h"

class Grid;
class Cell{

public:

    void updateState();

    int neighbors(const Grid&);

    friend std::ostream& operator<<(std::ostream&, const Cell&);

    State get_State() const;

    void set_State(State&);

    void set_position(std::pair<int, int> pos);

    void set_position(int, int);

    std::pair<int, int> get_position();

    Cell(int, int); //Constructor

    Cell(){} //constructor por defecto, inicializado

    ~Cell(){} //destructor, inicializado

private:

    State state_;

    std::pair <int, int > pos_;

    int countneighbors_;

};