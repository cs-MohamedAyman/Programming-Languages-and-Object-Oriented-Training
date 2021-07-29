#include <bits/stdc++.h>
using namespace std;

const int N = 3;
int grid[N][N];

//This function prints the grid of 8 Puzzle Game as the game progresses
void print_grid() {
	for (int i = 0; i < (N * N + N + 1); cout << "-", i++);
	cout << "\n";
	for (int i = 0; i < N; i++) {
        cout << "|";
		for (int j = 0; j < N; j++) {
			string e = "";
            if (grid[i][j] == 0) {
				for (int t = 0; t < N; e += " ", t++);
			}
            else {
                int str_len = to_string(grid[i][j]).size();
                int r1 = (N - str_len + 1) / 2;
                int r2 = (N - str_len) - r1;
				for (int t = 0; t < r1; e += " ", t++);
				e += to_string(grid[i][j]);
				for (int t = 0; t < r2; e += " ", t++);
			}
			cout << e << "|";
		}
		cout << "\n";
		for (int t = 0; t < (N * N + N + 1); cout << "-", t++);
		cout << "\n";
	}
}
//This function generates cells in the given grid
void generate_grid() {
    for (int i = 1; i < N*N; i++) {
		int a = rand() % N;
		int b = rand() % N;
		while (grid[a][b] != 0) {
			a = rand() % N;
			b = rand() % N;
		}
		grid[a][b] = i;
	}
}

//This function checks if the game state reachs the win state or not 
bool check_win() {

}
//This function checks if given cell is empty or not 
bool check_empty(int i, int j) {

}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function checks if the given position has a movement state or not
bool check_available_move(int i, int j) {

}
//This function moves the position with the empty cell
void move(int i, int j) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid direction
void read_input(int &i, int &j) {
    cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || check_empty(i, j) || !check_available_move(i, j)) {
        cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "8 Puzzle Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
		int i, j;
		read_input(i, j);
        //Move with the input position
        move(i, j);
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
