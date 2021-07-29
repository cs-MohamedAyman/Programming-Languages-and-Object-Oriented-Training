#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const char marks[2] = {'X', 'O'};
char small_grid[N][N];
char big_grid[N*N][N*N];
int curr_box = -1, next_box = -1;

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {
    cout << "Player 1: " << marks[0] << "  vs  Player 2: " << marks[1] << "\n";
    for (int i = 0; i < N*N*3+N*3; cout << "-", i++);
    cout << "-\n";
    for (int i = 0; i < N*N; i++) {
        cout << "|  ";
        for (int j = 0; j < N*N; j++) {
            if (j % N == 0 and j > 0)
				cout << "|  ";
            cout << big_grid[i][j] << "  ";
		}
        cout << "|\n";
        if (i % N == N - 1) {
			for (int i = 0; i < N*N*3+N*3; cout << "-", i++);
			cout << "-\n";
		}
    }

}
//This function converts the given position in the big grid into a box number
int cvt_big_grid_pos_to_box(int i, int j) {

}
//This function converts the given box number into a position index in the big grid
void cvt_box_to_big_grid_pos(int x, int &i, int &j) {

}
//This function converts the given position in the small grid into a box number
int cvt_small_grid_pos_to_box(int i, int j) {

}
//This function converts the given box number into a position index in the small grid
void cvt_box_to_small_grid_pos(int x, int &i, int &j) {

}
//This function converts the given position in the big grid into a position index in the big grid
void cvt_big_grid_pos_to_big_grid_pos(int &i, int &j) {
	int box_idx = cvt_big_grid_pos_to_box(i, j);
	cvt_box_to_big_grid_pos(box_idx, i, j);
}
//This function converts the given position in the big grid into a position index in the small grid
void cvt_big_grid_pos_to_small_grid_pos(int &i, int &j) {
	int box_idx = cvt_big_grid_pos_to_box(i, j);
	cvt_box_to_small_grid_pos(box_idx, i, j);
}
//This function checks if the game has a win state or not
bool check_win(char grid[N][N], int r=0, int c=0) {

}
//This function checks if the game has a win state or not
bool check_win(char grid[N*N][N*N], int r=0, int c=0) {

}
//This function checks if the game has a tie state or not
bool check_tie(char grid[N][N], char mark, int r=0, int c=0) {

}
//This function checks if the game has a tie state or not
bool check_tie(char grid[N*N][N*N], char mark, int r=0, int c=0) {

}
//This function checks if the given cell in the big grid is empty or not 
bool check_empty_in_big_grid(int i, int j) {

}
//This function checks if the given cell in the small grid is empty or not 
bool check_empty_in_small_grid(int i, int j) {

}
//This function checks if given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function calculates the current selected box 
void set_next_box(int i, int j) {

}
//This function sets the given mark to the given cell in the big grid
void set_cell_in_big_grid(int i, int j, char mark) {

}
//This function sets the given mark to the given box
void fill_box(int r, int c, char mark) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid position input
void read_input(int &i, int &j) {
    string box_idx = (next_box == -1)? "any box" : "box " + to_string(next_box);
	cout << "Enter the row index and column index in " << box_idx << ": ";
	cin >> i >> j;
    int si = i, sj = j;
	cvt_big_grid_pos_to_small_grid_pos(si, sj);
    while (!check_valid_position(i, j) || !check_empty_in_big_grid(i, j) ||
          (next_box != -1 && next_box != cvt_big_grid_pos_to_box(i, j)) ||
          (next_box == -1 && !check_empty_in_small_grid(si, sj))) {
		cout << "Enter a valid row index and column index in " << box_idx << ": ";
		cin >> i >> j;
		si = i, sj = j;
		cvt_big_grid_pos_to_small_grid_pos(si, sj);
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Ultimate Tic-Tac-Toe Game!\n";
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
        set_cell_in_big_grid(i, j, marks[player]);
        //Check if the selected box has a win state
        if (check_win(big_grid, i, j)) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement in a box
            cout << "Congrats, Player " << marks[player] << " is completed the box " << curr_box << ".\n";
            fill_box(i, j, marks[player]);
		}
        //Check if the selected box has a full state
        else if (check_tie(big_grid, marks[player], i, j) && check_tie(big_grid, marks[1-player], i, j)) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement in a box
            cout << "Woah! That's a tie in the box " << curr_box << ".\n";
            fill_box(i, j, '#');
		}
        //Calculate the next selected box 
        set_next_box(i, j);
        //Check if the small grid has a win state
        if (check_win(small_grid)) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
		}
        //Check if the grid has a tie state
        if (check_tie(small_grid, marks[player]) && check_tie(small_grid, marks[1-player])) {
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
