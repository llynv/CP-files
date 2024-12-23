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

const int INF = 0x3f3f3f3f;

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

int f[1007][1007] {INF};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    f[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= 100) {
            f[i][j] = min(f[i-1][j] + a[i], f[i-1][j+1]);
        }
    }
}