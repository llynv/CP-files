#include <iostream>

using namespace std;

int max_possible_maximum(int n, int k, int a[]) {
    int table[k + 1][n];

    for (int i = 0; i < n; i++) {
        table[0][i] = a[i];
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                table[j][i] = max(table[j - 1][i], a[i] + table[j - 1][i - 1]);
            }
            else {
                table[j][i] = max(table[j - 1][i], table[j][i - 1]);
            }
        }
    }

    int max_value = 0;
    for (int i = 0; i < n; i++) {
        max_value = max(max_value, table[k][i]);
    }

    return max_value;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int max_value = max_possible_maximum(n, k, a);
        cout << max_value << endl;
    }
    return 0;
}