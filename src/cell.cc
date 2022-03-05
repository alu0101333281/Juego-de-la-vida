/**********************************************
** Program name: Juego de la vida
** Author: Cristopher Alexandro Medina Peschiutta
** Date: 03/03/2022
** Description: This is the implementation file 
for the cell class.
***********************************************/


#include "../include/cell.h"
#include "../include/grid.h"

using namespace std;


State Cell::get_State() const {

return state_;

}

void Cell::set_State(State& estado){

estado = state_;

}

void Cell::set_position(pair<int, int> pos){

pos_ = pos;

}


void Cell::set_position(int i, int j){

pos_ = make_pair(i , j);

}

std::pair<int,int> Cell::get_position(){

    return pos_;

}

Cell::Cell(int i, int j){

set_position(i , j);

}


void Cell::updateState(){

    if(state_.get_state() == 0){
        if(countneighbors_== 3)
            state_.set_state(1);
    
        else
            state_.set_state(0);

    }

    else if(state_.get_state() == 1){
        if(countneighbors_ != 2 || countneighbors_ != 3)
            state_.set_state(0);
        else
            state_.set_state(1);
    }

}




int Cell::neighbors(const Grid& board){
    int counter = 0;
    for(int i = get_position().first - 1; i <= get_position().first + 1; i++)
		for(int j = get_position().second - 1; j <= get_position().second + 1; j++)
			if(i != get_position().first || j != get_position().second)
				if(board.get_mesh()[i * board.get_columns() + j]->get_State().get_state() == 1);
				counter++;	

    return counter;

}


std::ostream& operator<<(std::ostream& out, const Cell& cell){

    if(cell.get_State().get_state()== 1)
        out << 'X';
    else
        out << ' ';

    return out;
}

