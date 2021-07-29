#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int M = 8;
int mines = 8;
int grid[N][M];
int viewed_grid[N][M];

//This function prints the grid of Minesweeper Game as the game progresses
void print_grid() {
	for (int i = 0; i < (5 * M + M + 1); cout << "-", i++);
	cout << "\n";
	for (int i = 0; i < N; i++) {
        cout << "|";
		for (int j = 0; j < M; j++) {
			string e = "";
            if (viewed_grid[i][j] == 0)
                e = "  .  ";
            else if (viewed_grid[i][j] == 2)
                e = "  F  ";
            else if (grid[i][j] == 0)
                e = "     ";
            else if (grid[i][j] == -1)
                e = "  *  ";
            else
                e = "  " + to_string(grid[i][j]) + "  ";
			cout << e << "|";
		}
		cout << "\n";
		for (int t = 0; t < (5 * M + M + 1); cout << "-", t++);
		cout << "\n";
	}
}
//This function generates mines in the grid
void generate_mines() {
	for (int i = 0; i < mines; i++) {
        int a = rand() % N;
        int b = rand() % M;
        while (grid[a][b] != 0) {
			a = rand() % N;
			b = rand() % M;
		}
        grid[a][b] = -1;
	}
}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function calculates the total number of mines in the neighbour cells
bool calc_neighbour_mines() {

}    
//This function generates cells in the grid
void generate_grid() {
    //Generate mines in the grid
    generate_mines();
    //Calculate neighbour mines in the grid
    calc_neighbour_mines();
}
//This function checks if the given position is hidden or not
bool check_hide_cell(int i, int j) {

}
//This function checks if the given position is viewed or not
bool check_mines_cell(int i, int j) {

}
//This function checks if the given position is viewed or not
bool check_view_cell(int i, int j) {

}
//This function checks if the given position is flagged or not
bool check_flag_cell(int i, int j) {

}
//This function checks if the game state reachs the win state or not 
bool check_win() {

}
//This function checks if given operation is valid or not 
bool check_valid_operation(char x) {

}
//This function flips the flag mark to the given cell
void flip_flag(int i, int j) {

}
//This function showes the given cell
void show_cell(int i, int j) {

}
//This function showes all mines cells
void show_all_mines() {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid position
void read_input(int &i, int &j, char &op) {
    cout << "Enter the position and operation type: ";
	cin >> i >> j >> op;
    while (!check_valid_position(i, j) || check_view_cell(i, j) || !check_valid_operation(op) ||
           (tolower(op) == 'f' && check_view_cell(i, j)) || (tolower(op) == 's' && !check_hide_cell(i, j))) {
        cout << "Enter a valid position and a valid operation type: ";
		cin >> i >> j >> op;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Minesweeper Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
		int i, j;
		char op;
        read_input(i, j, op);
        //Flip the cell with a flag
        if (op == 'f')
            flip_flag(i, j);
        //Show the cell
        else {
            show_cell(i, j);
            //Check if the grid has a mines state
            if (check_mines_cell(i, j)) {
                //Show the cell
                show_all_mines();
				//Prints the grid
				print_grid();
                //Announcement of the final statement
                cout << "Game Over!\n";
                break;
			}
		}
        //Check if the grid has a win state
        if (check_win()) {
			//Prints the grid
			print_grid();
            //Announcement of the final statement
            cout << "Congrats, You won!\n";
            break;
		}
	}
}
int main() {
	while (true) {
		grid_clear();
        generate_grid();
		play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
	}
}
