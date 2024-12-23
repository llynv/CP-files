#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
void DBVT (T (&arr)) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Vector[" << i+1 << "] = " << arr[i] << "\n";
    }
}

template<typename T, int N>
void DBARR (T (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cout << "Array[" << i+1 << "] = " << arr[i] << "\n";
    }
}

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

int s[30][100007];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) s[0][i] = i;
    for (int i = 1; i <= k; ++i) {
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += s[i-1][j];
            s[i][j] += sum;
            cout << s[i][j] << " ";
        }
        cout << "\n-----\n";
        // DBARR(s[i]);
    }
}