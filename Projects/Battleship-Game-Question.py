N, M = 10, 10
marks = ['1', '2']
used_cell, true_hit, false_hit, sunken_cell = '#', 'O', 'X', '$'
grid = []
used_segments = []
length_shapes = [5, 5, 4, 3, 3, 2]
player = 0

#This function prints the grid of Battleship Game as the game progresses
def print_grid(p, display_used_cells=False):
    print('The Grid of Player', marks[p])
    print('-' + '----' * M)
    for i in range(N):
        print(end='| ')
        for j in range(M):
            if grid[p][i][j] == '.' or (grid[p][i][j] == used_cell and not display_used_cells):
                print(' ', end=' | ')
            else:
                print(grid[p][i][j], end=' | ')
        print()
        print('-' + '----' * M)

#This function checks if the game has a win state or not
def check_win():
    pass

#This function checks if given cell is empty or not 
def check_empty(i, j):
    pass

#This function checks if given cell is sunken or not 
def check_sunken(i, j):
    pass

#This function checks if given cell is damaged or not 
def check_damaged(i, j):
    pass

#This function checks if given cell is used or not 
def check_used(i, j):
    pass

#This function checks if given position is valid or not 
def check_valid_position(i, j):
    pass

#This function sets the given mark to the given cell
def set_cell(i, j, mark):
    pass

#This function clears the game structures
def grid_clear():
    pass

#This function reads a valid position input
def read_input():
    i, j = map(int, input('Enter the row index and column index: ').split())
    while not check_valid_position(i, j) or (not check_empty(i, j) and not check_used(i, j)):
        i, j = map(int, input('Enter a valid row index and a valid column index: ').split())
    return i, j

#This function checks if given side is valid or not 
def check_valid_side(length, i1, j1, i2, j2):
    pass

#This function arranges the points of the side
def arrange_side_points(i1, j1, i2, j2):
    pass

#This function checks if the given side is empty or not 
def check_empty_side(p, length, i1, j1, i2, j2):
    pass

#This function checks if the given side is damaged or not 
def check_damaged_side(p, length, i1, j1, i2, j2):
    pass

#This function sets the sunken cell to the given side
def set_sunken_side(p, length, i1, j1, i2, j2):
    pass

#This function hits the given cell
def hit_cell(i, j):
    pass

#This function reads a valid segment input
def read_input_segment(p, length):
    i1, j1, i2, j2 = map(int, input('Enter the two points of the side: ').split())
    i1, j1, i2, j2 = arrange_side_points(i1, j1, i2, j2)
    while not check_valid_side(length, i1, j1, i2, j2) or not check_empty_side(p, length, i1, j1, i2, j2):
        i1, j1, i2, j2 = map(int, input('Enter a valid two points of the side: ').split())
        i1, j1, i2, j2 = arrange_side_points(i1, j1, i2, j2)
    return i1, j1, i2, j2

#This function sets the used cell to the given side
def set_used_side(p, length, i1, j1, i2, j2):
    pass

#This function reverts set the used cell to the given side
def revert_set_used_side(p, length, i1, j1, i2, j2):
    pass


#MAIN FUNCTION
def play_game():
    global player
    print("Battleship Game!")
    print("Welcome...")
    print("============================")
    while True:
        #Prints the grid
        print_grid(1-player)
        #Read an input position from the player
        print('Player %s is playing now' % marks[player])
        i, j = read_input()
        #Hit the player in the input position
        hited = hit_cell(i, j)
        #Prints the grid
        print_grid(1-player)
        if hited: 
            print('The selected position has been destroyed successfully')
        else:
            print('The selected position was an empty position')
        #Check if the grid has a win state
        if check_win():
            #Announcement of the final statement
            print('Congrats, Player %s is won!' % marks[player])
            break
        if not hited:
            #Player number changes after each turn
            player = 1 - player 

#This function sets the configuration of the given player
def set_config(curr_player):
    print('You are set the configuration of player', curr_player)
    for i in range(len(length_shapes)):
        length = length_shapes[i]
        print_grid(curr_player, True)
        while True:
            print('please select a valid segment of length', length)
            i1, j1, i2, j2 = read_input_segment(curr_player, length)
            set_used_side(curr_player, length, i1, j1, i2, j2)
            used_segments[curr_player][i] = [i1, j1, i2, j2]
            print_grid(curr_player, True)
            c = input('Confirm this shape [Y/N] ')
            if c in 'yY':
                break
            revert_set_used_side(curr_player, length, i1, j1, i2, j2)
            used_segments[curr_player][i] = [0, 0, 0, 0]
            print_grid(curr_player, True)

while True:
    grid_clear()
    set_config(0)
    set_config(1)
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
