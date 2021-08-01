#include <bits/stdc++.h>
using namespace std;

const int N = 4;
const int M = 4;
int grid[N][M];
bool viewed_grid[N][M];

//This function prints the grid of Match Cards Game as the game progresses
void print_grid() {
	for (int i = 0; i < (4 * M + M + 1); cout << "-", i++);
	cout << "\n";
	for (int i = 0; i < N; i++) {
        cout << "|";
		for (int j = 0; j < N; j++) {
			string e = "";
            if (viewed_grid[i][j] == 0)
                e = "    ";
            else {
                e = to_string(grid[i][j]);
                if (e.size() == 1) e = " " + e;
                e = " " + e + " ";
			}
			cout << e << "|";
		}
		cout << "\n";
		for (int t = 0; t < (4 * M + M + 1); cout << "-", t++);
		cout << "\n";
	}
}
//This function checks if the game state reachs the win state or not 
bool check_win() {

}
//This function generates cells in the given grid
void generate_grid() {
    for (int i = 1; i < N*M/2+1; i++) {
		for (int j = 0; j < 2; j++) {
			int a = rand() % N;
			int b = rand() % M;
			while (grid[a][b] != 0) {
				a = rand() % N;
				b = rand() % M;
			}
			grid[a][b] = i;
		}
	}
}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function checks if the given cells are identical cells or not
bool check_identical_cells(int i1, int j1, int i2, int j2) {

}
//This function shows the given cell
void show(int i, int j) {

}
//This function hides the given cell
void hide(int i, int j) {

}
//This function checks if the given position is hidden or not
bool check_hide_cell(int i, int j) {

}
//This function checks if the given positions are the same or not
bool check_same_position(int i1, int j1, int i2, int j2) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid direction
void read_input(int &i1, int &j1, int &i2, int &j2) {
    cout << "Enter the two positions of the cells: ";
	cin >> i1 >> j1 >> i2 >> j2;
    while (!check_valid_position(i1, j1) || !check_valid_position(i2, j2) || 
		   !check_hide_cell(i1, j1) || !check_hide_cell(i2, j2) || check_same_position(i1, j1, i2, j2)) {
        cout << "Enter a valid two positions of the cells: ";
		cin >> i1 >> j1 >> i2 >> j2;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Match Cards Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
		int i1, j1, i2, j2;
		read_input(i1, j1, i2, j2);
        //Show the input cells
        show(i1, j1);
        show(i2, j2);
        //Prints the grid
        print_grid();
        //Check if the input cells are identical
        if (!check_identical_cells(i1, j1, i2, j2)) {
            //Hide the input cells
            hide(i1, j1);
            hide(i2, j2);
            cout << "The selected cells are not the same\n";
		}
        else
            cout << "The selected cells are the same\n";
        //Check if the grid has a win state
        if (check_win()) {
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
