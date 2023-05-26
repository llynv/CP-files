#include <bits/stdc++.h>
#define int long long
#define BSIZE 9
using namespace std;

int board [BSIZE][BSIZE];
vector<int> validNumber [BSIZE][BSIZE];

bool columnCheck(int column, int currentNumber)
{
    for (int i = 0; i < BSIZE; ++i){
        if (board[i][column] == currentNumber){
            return true;
        }
    }
    return false;
}

bool rowCheck(int row, int currentNumber)
{
    for (int i = 0; i < BSIZE; ++i){
        if (board[row][i] == currentNumber){
            return true;
        }
    }
    return false;
}

bool boxCheck(int column, int row, int currentNumber)
{
    int boxColumn = column - column % 3;
    int boxRow = row - row % 3;

    for (int i = boxRow; i < boxRow + 3; ++i){
        for (int j = boxColumn; j < boxColumn + 3; ++j){
            if (board[i][j] == currentNumber){
                return true;
            }
        }
    }
    return false;
}

bool isValidPlacement(int currentNumber, int column, int row)
{
    return !columnCheck(column, currentNumber)
        && !rowCheck(row, currentNumber)
        && !boxCheck(column, row, currentNumber);
}

void boardInput()
{
    for (int i = 0; i < BSIZE; ++i){
        for (int j = 0; j < BSIZE; ++j){
            char num;
            cin >> num;
            board[i][j] = num - '0';
        }
    }
}

void insertNum()
{
    for (int row = 0; row < BSIZE; ++row){
        for (int column = 0; column < BSIZE; ++column){
            if (board[row][column] == 0){
                for (int nums = 1; nums <= BSIZE; ++nums){
                    if (isValidPlacement(nums, column, row)){
                        validNumber[row][column].emplace_back(nums);
                    }
                }
            }
        }
    }

    for (int row = 0; row < BSIZE; ++row){
        for (int column = 0; column < BSIZE; ++column){
            if (validNumber[row][column].size() == 1){
                board[row][column] = validNumber[row][column].back();
            }
        }
    }
}

bool solve()
{
    for (int row = 0; row < BSIZE; ++row){
        for (int column = 0; column < BSIZE; ++column){
            if (board[row][column] == 0){
                for (auto number: validNumber[row][column]){
                    if (isValidPlacement(number, column, row)){
                        board[row][column] = number;

                        if (solve()){
                            return true;
                        } else {
                            board[row][column] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
}

void printBoard()
{
    for (int i = 0; i < 25; ++i){
        cout << "-";
    }
    cout << "\n";

    for (int row = 0; row < BSIZE; ++row){

        cout << "| ";

        for (int column = 0; column < BSIZE; ++column){
            cout << board[row][column] << " ";
            if ((column + 1) % 3 == 0){
                cout << "| ";
            }
        }
        if ((row + 1) % 3 == 0){
            cout << "\n";
            for (int i = 0; i < 25; ++i){
                cout << "-";
            }
        }
        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    boardInput();
    insertNum();
    solve();
    printBoard();
}
