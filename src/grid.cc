/**********************************************
** Program name: Juego de la vida
** Author: Cristopher Alexandro Medina Peschiutta
** Date: 03/03/2022
** Description: This is the implementation file 
for the grid class.
***********************************************/


#include "../include/grid.h"
#include <iostream>

using namespace std;

/* Constructor */
Grid::Grid (int rows, int columns, int turn):
rows_(rows+2),
columns_(columns+2),
turn_(turn)
{
    assert(rows >= 2 && columns >= 2);
	assert(turn >= 1);
    mesh_ = new Cell*[(rows + 2) * (columns + 2)];
	for(int i = 0; i < rows + 2; i++) 
		for(int j = 0; j < columns + 2; j++)
			mesh_[i * (columns + 2) + j] = new Cell(i, j);
	

    create_cell();

    for(int i = 0; i < turn; i++){
        cout << endl << "Turno: " << i + 1 << endl;
        write();
        next_generation();
    }    
}



/* Destructor */
Grid::~Grid ()
{

}



/* Getter del atributo rows_ */
int Grid::get_rows (void)
{
    return rows_;
}


/* Getter del atributo columns_ */
int Grid::get_columns (void) const
{
    return columns_;
}

Cell** Grid::get_mesh() const{

    return mesh_;

}

void Grid::create_cell(){

    int num_cell = 0;
    do{
    cout << "Cuantas celulas vivas quiere empezar? ";
    cin >> num_cell;
    if (num_cell > (get_columns() - 2) * (get_rows() - 2))
        cout << "El numero de celulas introducidas supera la capacidad de la rejilla" << endl;
    }while(num_cell > (get_columns() - 2) * (get_rows() - 2));

    cout << "Indique las coordenadas (i , j) de la celula" << endl;
    State state;
    state.set_state(1);
    for(;num_cell > 0; num_cell--){
        int pos_i = 0, pos_j = 0;
        do{
        cout << "[" << num_cell << "]: ";
        cin >> pos_i >> pos_j;
        if(pos_i > (get_rows() -2) || pos_j > (get_columns() - 2))
            cout << "La coordenada introducida esta fuera del rango de la rejilla" << endl;
        }while(pos_i > (get_rows() -2) || pos_j > (get_columns() - 2));
               
        mesh_[pos_i * get_columns() + pos_j]->set_State(state);

    }
}



void Grid::next_generation() {

    for(int i = 1; i < get_rows() - 1; i++)
		for(int j = 1; j < get_columns() - 1; j++)
			mesh_[i * get_columns() + j] -> neighbors(*this);

	for(int i = 1; i < get_rows() -1; i++)
		for(int j = 1; j < get_columns() -1; j++)
			mesh_[i * get_columns() + j] -> updateState();

}



/* Getter del atributo turn_ */
int Grid::get_turn (void)
{
    return turn_;
}



/* Setter del atributo turn_ */
void Grid::set_turn (int turn)
{
    turn_ = turn;
}



/* Imprime la tabla por la salida especificada */
void Grid::write(void)
{
    for(int i = 1; i < get_rows() - 1; i++) {
		for(int j = 1; j < get_columns() - 1; j++)
			std::cout << *mesh_[i * get_columns() + j] << "| ";

		std::cout << std::endl;
	}
}
