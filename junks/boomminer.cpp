
#include <iostream>
#define int long long
using namespace std;
int a[6][6], b[6][6];
void input()
{
    for (int i = 0; i <= 5; ++i)
        for (int j = 0; j <= 5; ++j)
            a[i][j] = 17; //create maximum border for matrix
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            cin >> a[i][j];
}
bool check(int row, int col)
{
    bool c = true;
    for (int i = row; i < row + 3; ++i) {
        for (int j = col; j < col + 3; ++j) {
            if (i != row + 1 && j != col + 1) {
                a[i][j]--;
                if (a[i][j] < 0)
                    c = false;
            }
        } 
    }
    return c;
}
void restore(int row, int col)
{
    for (int i = row; i < row + 3; ++i)
        for (int j = col; j < col + 3; ++j)
            a[i][j]++;
}
void printMatrix()
{
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}
bool solve()
{
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (check(i-1, j-1)) {
                b[i][j] = 1;
                if (solve()) {
                    return true;
                } else {
                    solve();
                    restore(i-1, j-1);
                    b[i][j] = 0;
                }
            }
        }
    }
}
int32_t main() {
    input();
    solve();
    printMatrix();
}