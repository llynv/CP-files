import sys
import math
from queue import PriorityQueue

# Initialize the game board
board = [['.' for _ in range(10)] for _ in range(10)]

def print_board(board):
    for row in board:
        print(' '.join(row), file=sys.stderr)
    print(file=sys.stderr)

def count_threes(board, player):
	threes = 0
	# Check horizontal and vertical
	for i in range(10):
		for j in range(8):
			if board[i][j] == board[i][j+1] == board[i][j+2] == player:
				threes += 3
			if board[j][i] == board[j+1][i] == board[j+2][i] == player:
				threes += 3
	# Check diagonals
	for i in range(8):
		for j in range(8):
			if board[i][j] == board[i+1][j+1] == board[i+2][j+2] == player:
				threes += 3
			if board[i][j+2] == board[i+1][j+1] == board[i+2][j] == player:
				threes += 3
				
	twos = 0
	# Check horizontal and vertical
	for i in range(10):
		for j in range(9):
			if board[i][j] == board[i][j+1] == player:
				twos += 1
			if board[j][i] == board[j+1][i] == player:
				twos += 1
	# Check diagonals	
	for i in range(9):
		for j in range(9):
			if board[i][j] == board[i+1][j+1] == player:
				twos += 1
			if board[i][j+1] == board[i+1][j] == player:
				twos += 1
	return threes + twos

def heuristic(board, player, row, col):
	opponent = 'O' if player == 'X' else 'X'
	center_control = 0
	adjacency_bonus = 0
	directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (1, 1), (-1, 1), (1, -1)]

	for i in range(3, 7):
		for j in range(3, 7):
			if board[i][j] == player:
				center_control += 20 - abs(i - 5) - abs(j - 5)

	for direction in directions:
		ni, nj = row + direction[0], col + direction[1]
		if 0 <= ni < 10 and 0 <= nj < 10 and board[ni][nj] == player:
			adjacency_bonus += 100

	return count_threes(board, player) * .2 + 10 * adjacency_bonus + 50 * center_control


def best_move(board, valid_actions, player):
    
	# Initialize a priority queue to store the moves and their scores

    pq = PriorityQueue()
    for action in valid_actions:
        row, col = action
        if board[row][col] == '.':
            # Make a temporary move
            board[row][col] = player
            # Calculate the heuristic value
            score = heuristic(board, player, row, col)
            # Undo the temporary move
            board[row][col] = '.'
            # Push the move and its score to the priority queue
            pq.put((-score, action))
    if not pq.empty():
        return pq.get()[1]
    return valid_actions[0]

# Game loop
while True:
    # Get the opponent's last move
    opponent_row, opponent_col = [int(i) for i in input().split()]
    if opponent_row != -1 and opponent_col != -1:
        board[opponent_row][opponent_col] = 'O'
    
    # Get the valid actions for this turn
    valid_action_count = int(input())
    valid_actions = []
    for _ in range(valid_action_count):
        row, col = [int(j) for j in input().split()]
        valid_actions.append((row, col))

    # Find the best move
    row, col = best_move(board, valid_actions, 'X')
    board[row][col] = 'X'
    
    # Output the chosen move
    print(f"{row} {col}")

    # Debug: print the board state
    print_board(board)
