#include <iostream>
#include <vector>

using namespace std;

// Define a struct to represent a position in the map
struct Pos {
    int row, col;
};

// Define a vector of all possible moves
vector<Pos> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Define a recursive function to explore the map and count rooms
void explore(vector<string>& map, int row, int col) {
    // Mark the current position as visited
    map[row][col] = '#';

    // Explore all neighboring positions
    for (auto move : moves) {
        int new_row = row + move.row;
        int new_col = col + move.col;
        if (new_row >= 0 && new_row < map.size() &&
            new_col >= 0 && new_col < map[0].size() &&
            map[new_row][new_col] == '.') {
            explore(map, new_row, new_col);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Read in the map
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    // Count the number of rooms
    int num_rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.') {
                num_rooms++;
                explore(map, i, j);
            }
        }
    }

    // Output the result
    cout << num_rooms << endl;

    return 0;
}
