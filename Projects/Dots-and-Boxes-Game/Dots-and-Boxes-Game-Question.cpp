#include <bits/stdc++.h>
using namespace std;

const int N = 5;
const int M = 5;
const int n_players = 2;
char marks[n_players] = {'X', 'O'};
int count_boxes[n_players];
char grid[N-1][M-1];
bool horizontal_grid[N+1][M];
bool vertical_grid[N][M+1];

//This function prints the grid of Dots-and-Boxes as the game progresses
void print_grid() {
	for (int i = 0; i< n_players; i++) {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
	}
	cout << "\n";
	cout << "--";
	for (int i = 0; i < M-1; cout << "------", i++);
	cout << "\n";
	for (int i = 0; i < N; i++) {
        cout << " . ";
		for (int j = 0; j < M; j++) {
            (horizontal_grid[i][j])? cout << "---" : cout << "   ";
            if (j < M-1)
                cout << " . ";
		}
        cout << "\n";
		for (int j = 0; j < M+1; j++) {
            (vertical_grid[i][j])? cout << " |  " : cout << "    ";
            if (i < N-1 && j < M-1)
                (grid[i][j] != '.')? cout << grid[i][j] : cout << " ";
            cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i< n_players; i++)
        cout << "Player " << marks[i] << " is " << count_boxes[i] << "\n";
	cout << "--";
	for (int i = 0; i < M-1; cout << "------", i++);
	cout << "\n";
}
//This function checks if the grid is full or not
bool check_full() {

}
//This function checks if given horizontal side is empty or not 
bool check_empty_horizontal_side(int i, int j) {

}
//This function checks if given vertical side is empty or not 
bool check_empty_vertical_side(int i, int j) {

}
//This function checks if the given side is empty or not 
bool check_empty_side(int i1, int j1, int i2, int j2) {

}
//This function checks if the given position is valid in the grid or not 
bool check_valid_position(int i, int j) {

}
//This function checks if given side is valid or not 
bool check_valid_side(int i1, int j1, int i2, int j2) {

}
//This function sets a horizontal side
void set_horizontal_side(int i, int j) {

}
//This function sets a vertical side
void set_vertical_side(int i, int j) {

}
//This function sets the given side
void set_side(int i1, int j1, int i2, int j2) {

}
//This function checks if the given box is complete or not
bool is_complete_box(int i, int j) {

}
//This function sets a mark to the given completed box
void set_box(int i, int j, int player) {

}
//This function checks and sets the completed box
bool set_neighbor_box(int i1, int j1, int i2, int j2, int player) {

}
//This function checks and sets the neighbor completed boxes
bool set_neighbor_boxes(int i1, int j1, int i2, int j2, int player) {

}
//This function arranges the points of the side
void arrange_side_points(int &i1, int &j1, int &i2, int &j2) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid position input
void read_input(int &i1, int &j1, int &i2, int &j2) {
    cout << "Enter the two points of the side: ";
    cin >> i1 >> j1 >> i2 >> j2;
    arrange_side_points(i1, j1, i2, j2);
    while (!check_valid_position(i1, j1) || !check_valid_position(i2, j2) ||
           !check_valid_side(i1, j1, i2, j2) || !check_empty_side(i1, j1, i2, j2)) {
		cout << "Enter a valid two points of the side: ";
		cin >> i1 >> j1 >> i2 >> j2;
		arrange_side_points(i1, j1, i2, j2);
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Dots-and-Boxes Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input from the player
        cout << "Player " << marks[player] << " is playing now\n";
        int i1, j1, i2, j2;
		read_input(i1, j1, i2, j2);
        //Set the input position with the mark
        set_side(i1, j1, i2, j2);
        //Set the neighbor boxes with the mark
        bool box_complete = set_neighbor_boxes(i1, j1, i2, j2, player);
        //Check if the state of the grid has a complete state
        if (check_full()) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
			int max_count_boxes = *max_element(count_boxes, count_boxes+n_players);
            if (count(count_boxes, count_boxes+n_players, max_count_boxes) == 1) {
				int idx_max_player = find(count_boxes, count_boxes+n_players, max_count_boxes) - count_boxes;
                cout << "Congrats, Player " << marks[idx_max_player] << " is won!\n";
			}
            else
                cout << "Woah! That's a tie!\n";
            break;
		}
		//Keep the player if there is a complete box
        if (!box_complete) {
            //Player number changes after each turn
            player = (player + 1) % n_players;
		}
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
