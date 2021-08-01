#include <bits/stdc++.h>
using namespace std;

const int N = 10;
const int M = 10;
const int n_players = 2;
const int n_components = 6;
char marks[n_players] = {'X', 'O'};
int max_cell_width = max(8, n_players * 2 + 2);
char ladder_symbol = 'L';
char snake_symbol = 'S';
char grid[N][M];
int player_position[n_players];
int snakes[n_components][n_players];
int ladders[n_components][n_players];

//This function converts the given indices into position
void convert_indices_to_position(int i, int j, int &p) {

}
//This function converts the given position into indices
void convert_position_to_indices(int p, int &i, int &j) {

}
//This function prints the grid of Snakes and Ladders as the game progresses
void print_grid() {
	for (int i = 0; i< n_players; i++) {
        cout << "Player " << i+1 << ": " << marks[i] << "  ";
        if (i < n_players-1)
            cout << "vs  ";
	}
	cout << "\n";
	for (int i = 0; i < max_cell_width * M; cout << "-", i++);
	cout << "-\n";
	for (int i = 0; i < N; i++) {
        cout << "|";
		for (int j = 0; j < M; j++) {
            string cell = "", symbol = "";
			int p;
            convert_indices_to_position(i, j, p);
			for (int k = 0; k < n_components; k++) {
                if (p == ladders[k][0] || p == ladders[k][1]) {
                    symbol = ladder_symbol+to_string(k+1);
                    break;
				}
                if (p == snakes[k][0] || p == snakes[k][1]) {
                    symbol = snake_symbol+to_string(k+1);
                    break;
				}
			}
			cell += symbol;
			for (int k = 0; k < 2 - symbol.size(); cell += " ", k++);
			for (int k = 0; k < max_cell_width - 2 - 3 - 1; cell += " ", k++);
			for (int k = 0; k < 3 - to_string(p).size(); cell += " ", k++);
			cell += to_string(p);
			cout << cell << "|";
		}
		cout << "\n";
        cout << "|";
		for (int j = 0; j < M; j++) {
            string cell = "";
			for (int k = 0; k < n_players; k++) {
				int p1, p2;
				convert_position_to_indices(player_position[k], p1, p2);
				if (p1 == i && p2 == j) cell += " ", cell += marks[k];
			}
			int t = cell.size();
			for (int k = 0; k < max_cell_width - 1 - t; cell += " ", k++);
			cout << cell << "|";
		}
		cout << "\n";
		for (int j = 0; j < max_cell_width * M; cout << "-", j++);
		cout << "-\n";
	}
	for (int i = 0; i < n_players; i++)
        cout << "Player " << marks[i] << " in "<< player_position[i] << '\n';
	for (int i = 0; i < max_cell_width * M; cout << "-", i++);
	cout << "-\n";
}
//This function checks if the given player reach the end of the game or not 
bool check_win(int player) {

}
//This function generate a random dice face
int generate_dice_face() {

}
//This function prints the given dice face
string print_dice_face(int i) {
    string s = "";
    if (i == 1) {
        s += " _____ \n";
        s += "|     |\n";
        s += "|  *  |\n";
        s += "|_____|\n";
	}
    if (i == 2) {
        s += " _____ \n";
        s += "|    *|\n";
        s += "|     |\n";
        s += "|*____|\n";
	}
    if (i == 3) {
        s += " _____ \n";
        s += "|    *|\n";
        s += "|  *  |\n";
        s += "|*____|\n";
	}
    if (i == 4) {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|     |\n";
        s += "|*___*|\n";
	}
    if (i == 5) {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|  *  |\n";
        s += "|*___*|\n";
	}
    if (i == 6) {
        s += " _____ \n";
        s += "|*   *|\n";
        s += "|*   *|\n";
        s += "|*___*|\n";
	}
    return s;
}
//This function checks if given face is valid or not 
bool check_valid_face(char i) {

}
//This function moves the given player by the given value
void move_player(int player, int moves) {

}
//This function generates snakes and ladders in the grid
void generate_snakes_and_ladders(char symbol) {
    int n_mid = N/2, m_mid = M/2;
    int areas_beg[n_components][4] = {{1, 1, n_mid-1, m_mid-1},             {1, m_mid, n_mid-1, M-2}, 
									  {n_mid, 1, N-2, m_mid-1},             {n_mid, m_mid, N-2, M-2}, 
									  {n_mid-2, m_mid-2, n_mid-2, m_mid+1}, {0, m_mid-2, 0, m_mid+1}};
    int areas_end[n_components][4] = {{1, 1, n_mid-1, m_mid-1},             {1, m_mid, n_mid-1, M-2}, 
									  {n_mid, 1, N-2, m_mid-1},             {n_mid, m_mid, N-2, M-2}, 
									  {N-1, m_mid-2, N-1, m_mid+1},         {n_mid+1, m_mid-2, n_mid+1, m_mid+1}};
    for (int i = 0; i < n_components; i++) {
        int xb1 = areas_beg[i][0], yb1 = areas_beg[i][1];
		int	xe1 = areas_beg[i][2], ye1 = areas_beg[i][3];
        int xb2 = areas_end[i][0], yb2 = areas_end[i][1];
		int xe2 = areas_end[i][2], ye2 = areas_end[i][3];
        int x1 = rand() % (xe1 - xb1 + 1) + xb1;
        int y1 = rand() % (ye1 - yb1 + 1) + yb1;
        int x2 = rand() % (xe2 - xb2 + 1) + xb2;
        int y2 = rand() % (ye2 - yb2 + 1) + yb2;
        while (x1 == x2 || y1 == y2 || abs(x1 - x2) + abs(y1 - y2) <= int(min(sqrt(N), sqrt(M))) ||
               grid[x1][y1] != '.' || grid[x2][y2] != '.') {
			x1 = rand() % (xe1 - xb1 + 1) + xb1;
			y1 = rand() % (ye1 - yb1 + 1) + yb1;
			x2 = rand() % (xe2 - xb2 + 1) + xb2;
			y2 = rand() % (ye2 - yb2 + 1) + yb2;
		}
        grid[x1][y1] = symbol;
        grid[x2][y2] = symbol;
        int p1, p2;
		convert_indices_to_position(x1, y1, p1);
        convert_indices_to_position(x2, y2, p2);
        if (symbol == ladder_symbol) {
			ladders[i][0] = min(p1, p2); 
			ladders[i][1] = max(p1, p2);
		}
        if (symbol == snake_symbol) {
			snakes[i][0] = min(p1, p2);
			snakes[i][1] = max(p1, p2);
		}
	}
}
//This function gets the movement value of the given position
int get_entity_value(int p) {

}
//This function clears the game structures
void grid_clear() {

}
//This function reads a valid input
void read_input(char &i) {
    cout << "Choose the dice face [A B C D E F]: ";
    cin >> i;
    while (!check_valid_face(i)) {
        cout << "Choose a valid dice face [A B C D E F]: ";
        cin >> i;
    }
}
//MAIN FUNCTION
void play_game() {
    cout << "Snakes and Ladders Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    int player = 0;
    while (true) {
        //Prints the grid
        print_grid();
        //Read an input dice face from the player
        cout << "Player " << marks[player] << " is playing now\n";
		char i;
        read_input(i);
        //Generate a dice face
        int dice_face = generate_dice_face();
        cout << print_dice_face(dice_face) << '\n';
        //Move the player position
        move_player(player, dice_face);
        //Get the movement value if there is an entity
        int entity_value = get_entity_value(player_position[player]);
        if (entity_value > 0) {
            //Prints the grid
            print_grid();
            cout << "Player " << marks[player] << " face a ladder, there is a movement from " << 
				    player_position[player] << " to " << player_position[player]+entity_value << '\n';
			//Move the player position
            move_player(player, entity_value);
		}
        if (entity_value < 0) {
            //Prints the grid
            print_grid();
            cout << "Player " << marks[player] << " face a snake, there is a movement from " << 
				    player_position[player] << " to " << player_position[player]+entity_value << '\n';
            //Move the player position
            move_player(player, entity_value);
		}
        //Check if the state of the grid has a win state
        if (check_win(player)) {
            //Prints the grid
            print_grid();
            cout << "Congrats, Player " << marks[player] << " is won!\n";
            break;
		}
        //Player number changes after each turn
        player = (player + 1) % n_players;
    }
}
int main() {
	while (true) {
		grid_clear();
		generate_snakes_and_ladders(ladder_symbol);
		generate_snakes_and_ladders(snake_symbol);
		play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
	}
}
