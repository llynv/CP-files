#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Define the size of the board
const int BOARD_SIZE = 10;

// Define the player symbols
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY_CELL = '.';

// Define the directions for checking adjacency
const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                                           {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

// Function to print the board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cerr << cell << " ";
        }
        cerr << endl;
    }
    cerr << endl;
}

// Function to count the number of three-in-a-row configurations
int countThrees(const vector<vector<char>>& board, char player) {
    int threes = 0;
    // Check horizontal and vertical
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE - 2; ++j) {
            if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == player) {
                threes++;
            }
            if (board[j][i] == board[j+1][i] && board[j][i] == board[j+2][i] && board[j][i] == player) {
                threes++;
            }
        }
    }
    // Check diagonals
    for (int i = 0; i < BOARD_SIZE - 2; ++i) {
        for (int j = 0; j < BOARD_SIZE - 2; ++j) {
            if (board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == player) {
                threes++;
            }
            if (board[i][j+2] == board[i+1][j+1] && board[i][j+2] == board[i+2][j] && board[i][j+2] == player) {
                threes++;
            }
        }
    }
    return threes;
}

// Function to calculate the adjacency score
int adjacencyScore(const vector<vector<char>>& board, int row, int col, char player) {
    int score = 0;
    for (const auto& direction : DIRECTIONS) {
        int ni = row + direction.first;
        int nj = col + direction.second;
        if (ni >= 0 && ni < BOARD_SIZE && nj >= 0 && nj < BOARD_SIZE && board[ni][nj] == player) {
            score++;
        }
    }
    return score;
}

// Function to calculate the central control score
int centralControlScore(int row, int col) {
    vector<pair<int, int>> centralPositions = {{4, 4}, {4, 5}, {5, 4}, {5, 5}};
    if (find(centralPositions.begin(), centralPositions.end(), make_pair(row, col)) != centralPositions.end()) {
        return 3;
    }
    if (row >= 3 && row <= 6 && col >= 3 && col <= 6) {
        return 2;
    }
    if (row >= 2 && row <= 7 && col >= 2 && col <= 7) {
        return 1;
    }
    return 0;
}

int heuristic(const vector<vector<char>>& board, int row, int col, char player) {
    int threes = countThrees(board, player);
    int opponentThrees = countThrees(board, player == PLAYER_X ? PLAYER_O : PLAYER_X);
    int score = threes - opponentThrees;
    score += adjacencyScore(board, row, col, player);
    score -= adjacencyScore(board, row, col, player == PLAYER_X ? PLAYER_O : PLAYER_X);
    score += centralControlScore(row, col);
    return score;
}

// Calculate first three moves to be placed and then use the heuristic function
// to calculate the best move
// The heuristic function calculates the score of the move based on the number of threes
// the player has, the adjacency score, and the central control score
// The move with the highest score is chosen as the best move
// The best move is outputted to the console

// use recursion to calculate the best move
// The best move is calculated using a priority queue

// Function to find the best move using recursion
pair<int, pair<int, int>> bestMove(const vector<vector<char>>& board, const vector<pair<int, int>>& validActions, char player, int depth) {
    if (depth == 0) {
        return {0, {0, 0}};
    }
    pair<int, int> bestAction = validActions[0];
    int bestScore = -1e9;
    for (const auto& action : validActions) {
        int row = action.first;
        int col = action.second;
        if (board[row][col] == EMPTY_CELL) {
            vector<vector<char>> tempBoard = board;
            tempBoard[row][col] = player;
            int score = heuristic(tempBoard, row, col, player);
            vector<pair<int, int>> nextValidActions;
            for (const auto& direction : DIRECTIONS) {
                int ni = row + direction.first;
                int nj = col + direction.second;
                if (ni >= 0 && ni < BOARD_SIZE && nj >= 0 && nj < BOARD_SIZE && tempBoard[ni][nj] == EMPTY_CELL) {
                    nextValidActions.push_back({ni, nj});
                }
            }
            pair<int, pair<int, int>> nextMove = bestMove(tempBoard, nextValidActions, player, depth - 1);
            score -= nextMove.first;
            if (score > bestScore) {
                bestScore = score;
                bestAction = action;
            }
        }
    }
    return {bestScore, bestAction};
}

int main() {
    // Initialize the game board
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, EMPTY_CELL));

    // Game loop
    bool firstMove = true;
    while (true) {
        // Get the opponent's last move
        int opponentRow, opponentCol;
        cin >> opponentRow >> opponentCol;
        if (opponentRow != -1 && opponentCol != -1) {
            board[opponentRow][opponentCol] = PLAYER_O;
            firstMove = false;
        }

        // Get the valid actions for this turn
        int validActionCount;
        cin >> validActionCount;
        vector<pair<int, int>> validActions;
        for (int i = 0; i < validActionCount; ++i) {
            int row, col;
            cin >> row >> col;
            validActions.push_back({row, col});
            board[row][col] = EMPTY_CELL;
        }

        // If it's the first move, place it in the center
        if (firstMove) {
            vector<pair<int, int>> centerPositions = {{4, 4}, {4, 5}, {5, 4}, {5, 5}};
            pair<int, int> centerMove = centerPositions[rand() % 4];
            cout << centerMove.first << " " << centerMove.second << endl;
            board[centerMove.first][centerMove.second] = PLAYER_X;
            firstMove = false;
        } else {
            // Find the best move   
            pair<int, pair<int, int>> bestAction = bestMove(board, validActions, PLAYER_X, 1);
            cout << bestAction.second.first << " " << bestAction.second.second << endl;
            board[bestAction.second.first][bestAction.second.second] = PLAYER_X;
        }
    }
    return 0;
}