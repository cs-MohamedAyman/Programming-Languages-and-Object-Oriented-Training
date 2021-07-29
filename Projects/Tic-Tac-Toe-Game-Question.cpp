#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const int n_players = 2;
const char marks[n_players] = {'X', 'O'};
char grid[N][N];

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    cout << "--";
    for (int i = 0; i < N; cout << "---", i++);
    cout << "--\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << "  ";
        cout << "|\n";
        cout << "--";
        for (int i = 0; i < N; cout << "---", i++);
        cout << "--\n";
    }
}
//This function checks if the game has a win state or not
bool check_win() {

}
//This function checks if the game has a tie state or not for the given mark
bool check_tie_player(char mark) {

}
//This function checks if the game has a tie state or not
bool check_tie() {
    bool all_tie = true;
    for (int i = 0; i < n_players; i++)
        if (!check_tie_player(marks[i]))
            all_tie = false;
    return all_tie;
}
//This function checks if given cell is empty or not 
bool check_empty(int i, int j) {

}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function sets the given mark to the given cell
void set_cell(int i, int j, char mark) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid position input
void read_input(int &i, int &j) {
	cout << "Enter the row index and column index: ";
	cin >> i >> j;
    while (!check_valid_position(i, j) || !check_empty(i, j)) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    bool player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input position from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);
        //Set the player mark in the input position
        set_cell(i, j, marks[player]);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
        }
        //Check if the grid has a tie state
        if (check_tie()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Woah! That's a tie!\n";
            break;
        }
        //Player number changes after each turn
        player = 1 - player;
    }
}
int main() {
    while (true) {
    	grid_clear();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
