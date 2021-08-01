#include <bits/stdc++.h>
using namespace std;

const int root_N = 3;
const int N = root_N * root_N;
const int n_modes = 35;
const int max_shared_boxes = 100;
const int max_grids = 5;
int mode;
int grids[max_grids][N][N];
int cpy_grids[max_grids][N][N];
int **similar_boxes[n_modes];
int n_grids[n_modes];
string graphs[n_modes];
const char symbols[10] = {'.', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

#define arr_int new int[4]
#define arr_int_p new int*[max_shared_boxes]
#define rep(x) for (int i = 0; i < x; i++)
#define rep_var(i, x) for (int i = 0; i < x; i++)
#define center_str(s, n) string((n+1)/2, ' ') + s + string(n/2, ' ')
#define cnt_str(s, x) count(s.begin(), s.end(), x)


//This function checks if the given mode is valid or not 
bool check_valid_mode(int x) {
    return 0 <= x && x < n_modes;
}
//This function sets the configuration of Multi-Sudoku Game grids 
void set_config() {
	cout << "Enter the mode index: ";
	cin >> mode;
    while (!check_valid_mode(mode)) {
		cout << "Enter a valid mode index: ";
		cin >> mode;
	}
}
//This function prints the mode type
string print_mode_type(int max_height, int max_width, int n_elements, int &curr_idx, int grid_type) {
    string dashes = "", spaces1 = "", spaces2 = "";
	rep(max_width * 8) dashes +="-";
	rep(max_width * 3) spaces1+=" ";
	rep(max_width * 4) spaces2+=" ";
    max_width += max(0, max_width * (8 - n_elements - 1)) / n_elements;
    cout << "+" + dashes + "+" << '\n';
    cout << ("|" + spaces1 + to_string(grid_type) + " Grid(s) Multi-Sudoku" + spaces2 + "|") << '\n';
    cout << "+" + dashes + "+" << '\n';
    string res = "";
	int cnt_end_lines = cnt_str(graphs[curr_idx], '\n');
	rep((max_height - cnt_end_lines + 2) / 2) res+="\n";
	rep_var(i, max_height) {
		rep_var(j, n_elements) {
			cnt_end_lines = cnt_str(graphs[curr_idx+j], '\n');
            if (i < cnt_end_lines) {
				string temp = "", s = graphs[curr_idx+j];
				int element_idx = 0;
				while (element_idx <= i) {
					int pos = s.find("\n");
					temp = s.substr(0, pos);
					s.erase(0, pos + 1);
					element_idx ++;
				}
				int additional_spaces = max_width - temp.size();
				res += center_str(temp, additional_spaces);
			}
            else
                res += string(max_width, ' ');
		}
        res += "\n";
	}
	rep_var(j, n_elements) {
		string mode_num = curr_idx+j > 9? to_string(curr_idx+j) : "0"+to_string(curr_idx+j);
		string temp = "mode " + mode_num;
		int additional_spaces = max_width - temp.size();
		res += center_str(temp, additional_spaces);
	}
    curr_idx += n_elements;
    res += "\n";
    return res;
}
//This function prints the modes of Multi-Sudoku Game
void print_modes() {
    int idx = 0, max_width = 22;
    cout << print_mode_type(3, max_width, 1, idx, 1);
    cout << print_mode_type(5, max_width, 8, idx, 2);
    cout << print_mode_type(7, max_width, 8, idx, 3);
    cout << print_mode_type(7, max_width, 8, idx, 3);
    cout << print_mode_type(7, max_width, 8, idx, 4);
    cout << print_mode_type(7, max_width, 2, idx, 5);
}
//This function contracts the modes of Multi-Sudoku Game grids 
void contract_modes() {
	int idx = 0;
    string NL = "\n";
    //mode 00
    graphs[idx] = "* * *"+NL+
                  "* * *"+NL+
                  "* * *"+NL;
    similar_boxes[idx] = arr_int_p{}; 
    n_grids[idx] = 1;
	idx ++;
    //mode 01
    graphs[idx] = "* * *    "+NL+
                  "* * *    "+NL+
                  "* * * * *"+NL+
                  "    * * *"+NL+
                  "    * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 8, 1, 0}};
    n_grids[idx] = 2;
	idx ++;
    //mode 02
    graphs[idx] = "    * * *"+NL+
                  "    * * *"+NL+
                  "* * * * *"+NL+
                  "* * *    "+NL+
                  "* * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}};
    n_grids[idx] = 2;
	idx ++;
    //mode 03
    graphs[idx] = "* * *  "+NL+
                  "* * *  "+NL+
                  "* * * *"+NL+
                  "  * * *"+NL+
                  "  * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 7, 1, 0}, arr_int{0, 8, 1, 1}};
    n_grids[idx] = 2;
	idx ++;
    //mode 04
    graphs[idx] = "  * * *"+NL+
                  "  * * *"+NL+
                  "* * * *"+NL+
                  "* * *  "+NL+
                  "* * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 1}, arr_int{0, 7, 1, 2}};
    n_grids[idx] = 2;
	idx ++;
    //mode 05
    graphs[idx] = "* * *    "+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "    * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 5, 1, 0}, arr_int{0, 8, 1, 3}};
    n_grids[idx] = 2;
	idx ++;
    //mode 06
    graphs[idx] = "    * * *"+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "* * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 2}, arr_int{0, 6, 1, 5}};
    n_grids[idx] = 2;
	idx ++;
    //mode 07
    graphs[idx] = "* * *  "+NL+
                  "* * * *"+NL+
                  "* * * *"+NL+
                  "  * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 4, 1, 0}, arr_int{0, 5, 1, 1}, arr_int{0, 7, 1, 3}, arr_int{0, 8, 1, 4}};
    n_grids[idx] = 2;
	idx ++;
    //mode 08
    graphs[idx] = "  * * *"+NL+
                  "* * * *"+NL+
                  "* * * *"+NL+
                  "* * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 1}, arr_int{0, 4, 1, 2}, arr_int{0, 6, 1, 4}, arr_int{0, 7, 1, 5}};
    n_grids[idx] = 2;
	idx ++;
    //mode 09
    graphs[idx] = "* * *        "+NL+
                  "* * *        "+NL+
                  "* * * * *    "+NL+
                  "    * * *    "+NL+
                  "    * * * * *"+NL+
                  "        * * *"+NL+
                  "        * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 8, 1, 0}, arr_int{1, 8, 2, 0}};
    n_grids[idx] = 3;
	idx ++;
    //mode 10
    graphs[idx] = "        * * *"+NL+
                  "        * * *"+NL+
                  "    * * * * *"+NL+
                  "    * * *    "+NL+
                  "* * * * *    "+NL+
                  "* * *        "+NL+
                  "* * *        "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}, arr_int{1, 6, 2, 2}};
    n_grids[idx] = 3;
	idx ++;
    //mode 11
    graphs[idx] = "* * *    "+NL+
                  "* * *    "+NL+
                  "* * * *  "+NL+
                  "  * * *  "+NL+
                  "  * * * *"+NL+
                  "    * * *"+NL+
                  "    * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 7, 1, 0}, arr_int{0, 8, 1, 1}, arr_int{1, 7, 2, 0}, arr_int{1, 8, 2, 1}};
    n_grids[idx] = 3;
	idx ++;
    //mode 12
    graphs[idx] = "    * * *"+NL+
                  "    * * *"+NL+
                  "  * * * *"+NL+
                  "  * * *  "+NL+
                  "* * * *  "+NL+
                  "* * *    "+NL+
                  "* * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 1}, arr_int{0, 7, 1, 2}, arr_int{1, 6, 2, 1}, arr_int{1, 7, 2, 2}};
    n_grids[idx] = 3;
	idx ++;
    //mode 13
    graphs[idx] = "* * *        "+NL+
                  "* * * * *    "+NL+
                  "* * * * * * *"+NL+
                  "    * * * * *"+NL+
                  "        * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 5, 1, 0}, arr_int{0, 8, 1, 3}, arr_int{1, 5, 2, 0}, arr_int{1, 8, 2, 3}};
    n_grids[idx] = 3;
	idx ++;
    //mode 14
    graphs[idx] = "        * * *"+NL+
                  "    * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "* * * * *    "+NL+
                  "* * *        "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 2}, arr_int{0, 6, 1, 5}, arr_int{1, 3, 2, 2}, arr_int{1, 6, 2, 5}};
    n_grids[idx] = 3;
	idx ++;
    //mode 15
    graphs[idx] = "* * *    "+NL+
                  "* * * *  "+NL+
                  "* * * * *"+NL+
                  "  * * * *"+NL+
                  "    * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 4, 1, 0}, arr_int{0, 5, 1, 1}, arr_int{0, 7, 1, 3}, arr_int{0, 8, 1, 4}, arr_int{1, 4, 2, 0}, arr_int{1, 5, 2, 1}, arr_int{1, 7, 2, 3}, arr_int{1, 8, 2, 4}};
    n_grids[idx] = 3;
	idx ++;
    //mode 16
    graphs[idx] = "    * * *"+NL+
                  "  * * * *"+NL+
                  "* * * * *"+NL+
                  "* * * *  "+NL+
                  "* * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 1}, arr_int{0, 4, 1, 2}, arr_int{0, 6, 1, 4}, arr_int{0, 7, 1, 5}, arr_int{1, 3, 2, 1}, arr_int{1, 4, 2, 2}, arr_int{1, 6, 2, 4}, arr_int{1, 7, 2, 5}};
    n_grids[idx] = 3;
	idx ++;
    //mode 17
    graphs[idx] = "* * *    "+NL+
                  "* * *    "+NL+
                  "* * * * *"+NL+
                  "    * * *"+NL+
                  "* * * * *"+NL+
                  "* * *    "+NL+
                  "* * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 8, 1, 0}, arr_int{1, 6, 2, 2}};
    n_grids[idx] = 3;
	idx ++;
    //mode 18
    graphs[idx] = "    * * *"+NL+
                  "    * * *"+NL+
                  "* * * * *"+NL+
                  "* * *    "+NL+
                  "* * * * *"+NL+
                  "    * * *"+NL+
                  "    * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}, arr_int{1, 8, 2, 0}};
    n_grids[idx] = 3;
	idx ++;
    //mode 19
    graphs[idx] = "    * * *    "+NL+
                  "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * *   * * *"+NL+
                  "* * *   * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}, arr_int{0, 8, 2, 0}};
    n_grids[idx] = 3;
	idx ++;
    //mode 20
    graphs[idx] = "* * *   * * *"+NL+
                  "* * *   * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL+
                  "    * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 8, 2, 0}, arr_int{1, 6, 2, 2}};
    n_grids[idx] = 3;
	idx ++;
    //mode 21
    graphs[idx] = "* * *  "+NL+
                  "* * *  "+NL+
                  "* * * *"+NL+
                  "  * * *"+NL+
                  "* * * *"+NL+
                  "* * *  "+NL+
                  "* * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 7, 1, 0}, arr_int{0, 8, 1, 1}, arr_int{1, 6, 2, 1}, arr_int{1, 7, 2, 2}};
    n_grids[idx] = 3;
	idx ++;
    //mode 22
    graphs[idx] = "  * * *"+NL+
                  "  * * *"+NL+
                  "* * * *"+NL+
                  "* * *  "+NL+
                  "* * * *"+NL+
                  "  * * *"+NL+
                  "  * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 1}, arr_int{0, 7, 1, 2}, arr_int{1, 7, 2, 0}, arr_int{1, 8, 2, 1}};
    n_grids[idx] = 3;
	idx ++;
    //mode 23
    graphs[idx] = "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "* * *   * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 2}, arr_int{0, 5, 1, 5}, arr_int{0, 6, 2, 0}, arr_int{0, 8, 2, 3}};
    n_grids[idx] = 3;
	idx ++;
    //mode 24
    graphs[idx] = "* * *   * * *"+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 5, 2, 0}, arr_int{0, 8, 2, 3}, arr_int{1, 3, 2, 2}, arr_int{1, 6, 2, 5}};
    n_grids[idx] = 3;
	idx ++;
    //mode 25
    graphs[idx] = "    * * *    "+NL+
                  "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * *   * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL+
                  "    * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}, arr_int{0, 8, 2, 0}, arr_int{1, 8, 3, 0}, arr_int{2, 6, 3, 2}};
    n_grids[idx] = 4;
	idx ++;
    //mode 26
    graphs[idx] = "  * * *    "+NL+
                  "  * * * * *"+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "* * * * *  "+NL+
                  "    * * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 5, 1, 0}, arr_int{0, 6, 2, 1}, arr_int{0, 7, 2, 2}, arr_int{0, 8, 1, 3}, arr_int{3, 0, 2, 5}, arr_int{3, 1, 1, 6}, arr_int{3, 2, 1, 7}, arr_int{3, 3, 2, 8}};
    n_grids[idx] = 4;
	idx ++;
    //mode 27
    graphs[idx] = "    * * *  "+NL+
                  "* * * * *  "+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "  * * * * *"+NL+
                  "  * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 2}, arr_int{0, 6, 1, 5}, arr_int{0, 7, 2, 0}, arr_int{0, 8, 2, 1}, arr_int{3, 0, 1, 7}, arr_int{3, 1, 1, 8}, arr_int{3, 2, 2, 3}, arr_int{3, 3, 2, 5}};
    n_grids[idx] = 4;
	idx ++;
    //mode 28
    graphs[idx] = "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL+
                  "    * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{1, 2, 0, 3}, arr_int{1, 5, 0, 6}, arr_int{1, 8, 3, 0}, arr_int{2, 0, 0, 5}, arr_int{2, 3, 0, 8}, arr_int{2, 6, 3, 2}};
    n_grids[idx] = 4;
	idx ++;
    //mode 29
    graphs[idx] = "    * * *    "+NL+
                  "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{1, 2, 0, 6}, arr_int{1, 5, 3, 0}, arr_int{1, 8, 3, 3}, arr_int{2, 0, 0, 8}, arr_int{2, 3, 3, 2}, arr_int{2, 6, 3, 5}};
    n_grids[idx] = 4;
	idx ++;
    //mode 30
    graphs[idx] = "  * * *    "+NL+
                  "  * * *    "+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "  * * *    "+NL+
                  "  * * *    "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 1}, arr_int{0, 7, 1, 2}, arr_int{0, 8, 2, 0}, arr_int{3, 0, 1, 7}, arr_int{3, 1, 1, 8}, arr_int{3, 2, 2, 6}};
    n_grids[idx] = 4;
	idx ++;
    //mode 31
    graphs[idx] = "    * * *  "+NL+
                  "    * * *  "+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "* * * * * *"+NL+
                  "    * * *  "+NL+
                  "    * * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 6, 1, 2}, arr_int{0, 7, 2, 0}, arr_int{0, 8, 2, 1}, arr_int{3, 0, 1, 8}, arr_int{3, 1, 2, 6}, arr_int{3, 2, 2, 7}};
    n_grids[idx] = 4;
	idx ++;
    //mode 32
    graphs[idx] = "  * * *  "+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "  * * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 3, 1, 1}, arr_int{0, 4, 1, 2}, arr_int{0, 4, 2, 0}, arr_int{0, 5, 2, 1}, arr_int{1, 2, 2, 0}, 
								   arr_int{3, 0, 1, 4}, arr_int{3, 1, 1, 5}, arr_int{3, 1, 2, 3}, arr_int{3, 2, 2, 4}, arr_int{1, 8, 2, 6},
								   arr_int{1, 4, 0, 6}, arr_int{1, 4, 3, 0}, arr_int{0, 6, 3, 0},
								   arr_int{2, 4, 0, 8}, arr_int{2, 4, 3, 2}, arr_int{0, 8, 3, 2},
								   arr_int{0, 7, 3, 1}, arr_int{1, 5, 2, 3}, arr_int{0, 7, 1, 5}, arr_int{0, 7, 2, 3}, arr_int{1, 5, 3, 1}, arr_int{2, 3, 3, 1}};
    n_grids[idx] = 4;
	idx ++;
    //mode 33
    graphs[idx] = "* * *   * * *"+NL+
                  "* * *   * * *"+NL+
                  "* * * * * * *"+NL+
                  "    * * *    "+NL+
                  "* * * * * * *"+NL+
                  "* * *   * * *"+NL+
                  "* * *   * * *"+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 8, 2, 0}, arr_int{1, 6, 2, 2}, arr_int{2, 6, 3, 2}, arr_int{2, 8, 4, 0}};
    n_grids[idx] = 5;
	idx ++;
    //mode 34
    graphs[idx] = "  * * *  "+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "* * * * *"+NL+
                  "  * * *  "+NL;
    similar_boxes[idx] = arr_int_p{arr_int{0, 0, 1, 1}, arr_int{0, 3, 1, 4}, arr_int{0, 6, 1, 7}, arr_int{0, 1, 1, 2}, arr_int{0, 4, 1, 5}, arr_int{0, 7, 1, 8}, 
								   arr_int{0, 0, 2, 3}, arr_int{0, 1, 2, 4}, arr_int{0, 2, 2, 5}, arr_int{0, 3, 2, 6}, arr_int{0, 4, 2, 7}, arr_int{0, 5, 2, 8}, 
								   arr_int{0, 1, 3, 0}, arr_int{0, 4, 3, 3}, arr_int{0, 7, 3, 6}, arr_int{0, 2, 3, 1}, arr_int{0, 5, 3, 4}, arr_int{0, 8, 3, 7}, 
								   arr_int{0, 3, 4, 0}, arr_int{0, 4, 4, 1}, arr_int{0, 5, 4, 2}, arr_int{0, 6, 4, 3}, arr_int{0, 7, 4, 4}, arr_int{0, 8, 4, 5},
								   arr_int{1, 2, 3, 0}, arr_int{1, 5, 3, 3}, arr_int{1, 8, 3, 6}, arr_int{2, 6, 4, 0}, arr_int{2, 7, 4, 1}, arr_int{2, 8, 4, 2},
								   arr_int{2, 3, 1, 1}, arr_int{2, 4, 1, 2}, arr_int{2, 4, 3, 0}, arr_int{2, 5, 3, 1},
								   arr_int{4, 3, 1, 7}, arr_int{4, 4, 1, 8}, arr_int{4, 4, 3, 6}, arr_int{4, 5, 3, 7},
								   arr_int{1, 1, 2, 3}, arr_int{1, 4, 2, 6}, arr_int{1, 4, 4, 0}, arr_int{1, 7, 4, 3},
								   arr_int{3, 1, 2, 5}, arr_int{3, 4, 2, 8}, arr_int{3, 4, 4, 2}, arr_int{3, 7, 4, 5},
								   arr_int{4, 0, 1, 4}, arr_int{4, 1, 1, 5}, arr_int{4, 1, 3, 3}, arr_int{4, 2, 3, 4},
								   arr_int{2, 6, 1, 4}, arr_int{2, 7, 1, 5}, arr_int{2, 7, 3, 3}, arr_int{2, 8, 3, 4},
								   arr_int{1, 2, 1, 4}, arr_int{1, 5, 1, 7}, arr_int{1, 5, 4, 1}, arr_int{1, 8, 4, 4},
								   arr_int{3, 0, 1, 4}, arr_int{3, 3, 1, 7}, arr_int{3, 3, 4, 1}, arr_int{3, 6, 4, 4}};
    n_grids[idx] = 5;
	idx ++;
}
//This function prints the grid of Sudoku Game as the game progresses
void print_grid(int grid_idx=0) {
    for (int i = 0; i < N*3; cout << "-", i++);
    for (int i = 0; i < root_N; cout << "---", i++);
    cout << "-\n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
		for (int j = 0; j < N; j++) {
            if (j % root_N == 0 && j > 0)
                cout << "|  ";
			cout << symbols[grids[grid_idx][i][j]] << "  ";
		}
		cout << "|\n";
        if (i % root_N == root_N - 1) {
			for (int i = 0; i < N*3; cout << "-", i++);
			for (int i = 0; i < root_N; cout << "---", i++);
			cout << "-\n";
		}
	}
}
//This function prints the grids of Multi-Sudoku Game as the game progresses
void print_grids() {
	for (int grid_idx = 0; grid_idx < n_grids[mode]; grid_idx++)
        print_grid(grid_idx);
}
//This function clears the game structures
void grid_clear() {
	for (int i = 0; i < n_grids[mode]; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				grids[i][j][k] = 0;
				cpy_grids[i][j][k] = 0;
			}
		}
	}
}
