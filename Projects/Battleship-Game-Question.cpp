#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int M = 10;
const int n_battleship = 6;
const int n_player = 2;
bool player;
const char used_cell = '#';
const char true_hit = 'O';
const char false_hit = 'X';
const char sunken_cell = '$';
const char marks[n_player] = {'1', '2'};
const int length_shapes[n_battleship] = {5, 5, 4, 3, 3, 2};
int used_segments[n_player][n_battleship][4];
char grid[2][N][M];

//This function prints the grid of Battleship Game as the game progresses
void print_grid(bool p, bool display_used_cells=false) {
    cout << "The Grid of Player " << marks[p] << '\n';
    cout << "-";
	for (int _ = 0; _ < M; cout << "----", _++);
	cout << '\n';
	for (int i = 0; i < N; i++) {
        cout << "| ";
		for (int j = 0; j < M; j++) {
            if (grid[p][i][j] == '.' || (grid[p][i][j] == used_cell && !display_used_cells))
                cout << "  | ";
            else
				cout << grid[p][i][j] << " | ";
		}
        cout << '\n';
		cout << "-";
		for (int _ = 0; _ < M; cout << "----", _++);
		cout << '\n';
	}
}
//This function checks if the game has a win state or not
bool check_win() {

}
//This function checks if given cell is empty or not 
bool check_empty(int i, int j) {

}
//This function checks if given cell is sunken or not 
bool check_sunken(int i, int j) {

}
//This function checks if given cell is damaged or not 
bool check_damaged(int i, int j) {

}
//This function checks if given cell is used or not 
bool check_used(int i, int j) {

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
    while (!check_valid_position(i, j) || (!check_empty(i, j) && !check_used(i, j))) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j;
	}
}
//This function checks if given side is valid or not 
bool check_valid_side(int length, int i1, int j1, int i2, int j2) {

}
//This function arranges the points of the side
void arrange_side_points(int &i1, int &j1, int &i2, int &j2) {

}
//This function checks if the given side is empty or not 
bool check_empty_side(bool p, int length, int i1, int j1, int i2, int j2) {

}
//This function checks if the given side is damaged or not 
bool check_damaged_side(bool p, int length, int i1, int j1, int i2, int j2) {

}
//This function sets the sunken cell to the given side
void set_sunken_side(bool p, int length, int i1, int j1, int i2, int j2) {

}
//This function hits the given cell
bool hit_cell(int i, int j) {

}
//This function reads a valid segment input
void read_input_segment(bool p, int length, int &i1, int &j1, int &i2, int &j2) {
	cout << "Enter the two points of the side: ";
	cin >> i1 >> j1 >> i2 >> j2;
    arrange_side_points(i1, j1, i2, j2);
    while (!check_valid_side(length, i1, j1, i2, j2) || !check_empty_side(p, length, i1, j1, i2, j2)) {
		cout << "Enter a valid two points of the side: ";
		cin >> i1 >> j1 >> i2 >> j2;
		arrange_side_points(i1, j1, i2, j2);
	}
}
//This function sets the used cell to the given side
void set_used_side(bool p, int length, int i1, int j1, int i2, int j2) {

}
//This function reverts set the used cell to the given side
void revert_set_used_side(bool p, int length, int i1, int j1, int i2, int j2) {

}


//MAIN FUNCTION
void play_game() {
    cout << "Battleship Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grid
        print_grid(1-player);
        //Read an input position from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i, j;
		read_input(i, j);
        //Hit the player in the input position
        bool hited = hit_cell(i, j);
        //Prints the grid
        print_grid(1-player);
        if (hited) 
            cout << "The selected position has been destroyed successfully\n";
        else
            cout << "The selected position was an empty position\n";
        //Check if the grid has a win state
        if (check_win()) {
            //Announcement of the final statement
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
		}
        if (!hited) {
            //Player number changes after each turn
            player = 1 - player;
		}
	}
}
//This function sets the configuration of the given player
void set_config(bool curr_player) {
    cout << "You are set the configuration of player " << curr_player << '\n';
	for (int i = 0; i < n_battleship; i++) {
        int length = length_shapes[i];
        print_grid(curr_player, true);
        while (true) {
            cout << "please select a valid segment of length " << length << '\n';
            int i1, j1, i2, j2;
			read_input_segment(curr_player, length, i1, j1, i2, j2);
            set_used_side(curr_player, length, i1, j1, i2, j2);
            used_segments[curr_player][i][0] = i1;
            used_segments[curr_player][i][1] = j1;
			used_segments[curr_player][i][2] = i2;
			used_segments[curr_player][i][3] = j2;
			print_grid(curr_player, true);
            char c;
			cout << "Confirm this shape [Y/N] ";
			cin >> c;
			if (c == 'y' || c == 'Y')
                break;
            revert_set_used_side(curr_player, length, i1, j1, i2, j2);
            used_segments[curr_player][i][0] = 0;
            used_segments[curr_player][i][1] = 0;
			used_segments[curr_player][i][2] = 0;
			used_segments[curr_player][i][3] = 0;
            print_grid(curr_player, true);
		}
	}
}
int main() {
	while (true) {
		grid_clear();
		set_config(0);
		set_config(1);
		play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
	}
}
