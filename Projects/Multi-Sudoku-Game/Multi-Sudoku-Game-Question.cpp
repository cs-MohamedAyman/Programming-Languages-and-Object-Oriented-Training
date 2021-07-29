#include <bits/stdc++.h>
#include "utils.cpp"
using namespace std;

//This function checks if the game has a win state or not
bool check_win_grid(int grid_idx) {

}
//This function checks if the game has a win state or not
bool check_win() {
	for (int grid_idx = 0; grid_idx < n_grids[mode]; grid_idx++) {
        if (!check_win_grid(grid_idx))
            return false;
	}
    return true;
}
//This function checks if the given position is valid or not 
bool check_valid_position(int i, int j) {

}
//This function checks if the given grid index is valid or not 
bool check_valid_grid_index(int grid_idx) {

}
//This function checks if the given cell is original or not
bool check_original_cell(int grid_idx, int i, int j) {

}
//This function checks if the given value is valid with the given cell
bool check_valid_value(int grid_idx, int i, int j, int v) {

}
//This function converts the given position in the grid into a box number
int cvt_grid_pos_to_box(int i, int j) {

}
//This function converts the given box number into a position index in the grid
void cvt_box_to_grid_pos(int x, int &a, int &b) {

}
//This function copies a cell from the givne source grid to the given target grid
bool check_valid_value_cell(int grid_idx_s, int box_idx_s, int grid_idx_t, int box_idx_t, int i, int j, int v) {

}
//This function checks if the given value is valid with the shared boxes in the other grids
bool check_valid_value_in_shared_boxes(int grid_idx, int i, int j, int v) {

}
//This function copies a cell from the givne source grid to the given target grid
void cpy_cell(int grid_idx_s, int box_idx_s, int grid_idx_t, int box_idx_t, int i, int j, bool set_original=false) {

}
//This function copies the shared boxes in the other grids
void cpy_cell_in_shared_boxes(int grid_idx, int i, int j, int v) {
	for (int i = 0; i < max_shared_boxes; i++) {
		int grid_i = similar_boxes[mode][i][0], box_i = similar_boxes[mode][i][1], 
			grid_j = similar_boxes[mode][i][2], box_j = similar_boxes[mode][i][3];
		if (grid_i == -1 && box_i == -1 && grid_j == -1 && box_j == -1)
			break;
        if (grid_idx == grid_i)
            cpy_cell(grid_i, box_i, grid_j, box_j, i, j);
        if (grid_idx == grid_j)
            cpy_cell(grid_j, box_j, grid_i, box_i, i, j);
	}
}
//This function sets the given value to the given cell
void set_cell(int grid_idx, int i, int j, int v) {

}
//This function gets the similar boxes the other grids
void get_similar_boxes(int grid_idx, int box_idx, int shared_boxes[max_shared_boxes][2]) {

}
//This function copies the given box in the shared boxes in the other grids
void cpy_box_in_shared_boxes(int grid_idx, int box_idx, int shared_boxes[max_shared_boxes][2], bool set_original=false) {

}
//This function checks if the given box is empty or not
bool is_empty_box(int grid_idx, int box_idx) {

}
//This function checks if the given box is divided into empty cells and non-empty cells or not
bool is_half_box(int grid_idx, int box_idx) {

}
//This function copies the all boxes of the given grid in the shared boxes in the other grids
void cpy_similar_boxes(int grid_idx) {
    for (int i = 0; i < N; i+=root_N) {
		for (int j = 0; j < N; j+=root_N) {
            int box_idx = cvt_grid_pos_to_box(i, j);
            int shared_boxes[max_shared_boxes][2];
			get_similar_boxes(grid_idx, box_idx, shared_boxes);
            cpy_box_in_shared_boxes(grid_idx, box_idx, shared_boxes, true);
		}
	}
}
//This function solves the grid
bool solve_grid(int grid_idx, int i, int j) {
    if (j == N) {
        i += 1;
        j = 0;
	}
    if (i == N)
        return true;
    if (check_original_cell(grid_idx, i, j))
        return solve_grid(grid_idx, i, j+1);
    for (int k = 1; k < N+1; k++) {
        if (check_valid_value_in_shared_boxes(grid_idx, i, j, k)) {
            grids[grid_idx][i][j] = k;
            cpy_grids[grid_idx][i][j] = k;
            if (solve_grid(grid_idx, i, j+1))
                return true;
            grids[grid_idx][i][j] = 0;
            cpy_grids[grid_idx][i][j] = 0;
		}
	}
    return false;
}
//This function generates cells in the grids
void generate_cells(int grid_idx=0) {
    for (int k = 0; k < N; k+=root_N) {
        int box_idx = cvt_grid_pos_to_box(k, k);
        if (!is_empty_box(grid_idx, box_idx))
            continue;
		for (int i = 0; i < root_N; i++) {
			for (int j = 0; j < root_N; j++) {
                int n = rand() % N + 1;
                while (!check_valid_value_in_shared_boxes(grid_idx, k+i, k+j, n) ||
                      check_original_cell(grid_idx, k+i, k+j)) {
                    n = rand() % N + 1;
				}
                grids[grid_idx][k+i][k+j] = n;
                cpy_grids[grid_idx][k+i][k+j] = n;
			}
		}
	}
}
//This function removes cells in the grids
void remove_cells(int grid_idx=0) {
    for (int k = 0; k < (N+1)/2; k++) {
		for (int i = 0; i < N; i+=root_N) {
			for (int j = 0; j < N; j+=root_N) {
                int box_idx = cvt_grid_pos_to_box(i, j);
                if (is_half_box(grid_idx, box_idx))
                    continue;
                int t1 = rand() % root_N;
                int t2 = rand() % root_N;
                while (!check_original_cell(grid_idx, i+t1, j+t2)) {
					t1 = rand() % root_N;
					t2 = rand() % root_N;
				}
                grids[grid_idx][i+t1][j+t2] = 0;
                cpy_grids[grid_idx][i+t1][j+t2] = 0;
			}
		}
	}
}
//This function generates cells in the given grid
void generate_grids() {
    //Generate cells in the grid
    generate_cells();
	for (int grid_idx = 0; grid_idx < n_grids[mode]; grid_idx++) {
        //Solve the complete grid
        solve_grid(grid_idx, 0, 0);
        //Copy the similar boxes in the another grids
        cpy_similar_boxes(grid_idx);
	}
	for (int grid_idx = 0; grid_idx < n_grids[mode]; grid_idx++) {
        //Remove cells in the grid to be solved
        remove_cells(grid_idx);
        //Copy the similar boxes in the another grids
        cpy_similar_boxes(grid_idx);
	}
}
//This function reads a valid position and value inputs
void read_input(int &grid_idx, int &i, int &j, int &v) {
	cout << "Enter the row index and column index and value: ";
	cin >> grid_idx >> i >> j >> v;
    while (!check_valid_position(i, j) || !check_valid_value(grid_idx, i, j, v) || check_original_cell(grid_idx, i, j)) {
		cout << "Enter a valid row index and column index and value: ";
		cin >> grid_idx >> i >> j >> v;
	}
}
//MAIN FUNCTION
void play_game() {
    cout << "Multi-Sudoku Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {
        //Prints the grids
        print_grids();
        //Read an input from the player
		int grid_idx, i, j, v;
        read_input(grid_idx, i, j, v);
        //Set the input position with the value
        set_cell(grid_idx, i, j, v);
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grids();
			//Announcement of the final statement
            cout << "Congrats, You won!\n";
            break;
		}
	}
}
int main() {
	while (true) {
		contract_modes();
		print_modes();
		set_config();
		grid_clear();
		generate_grids();
		play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
	}
}
