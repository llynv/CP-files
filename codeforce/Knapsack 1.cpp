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

struct KPS
{
    int w;
    int v;
};

bool cmp (KPS a, KPS b) {return a.w < b.w;}

int f[107][100007];

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<KPS> c(n); 
    for (int i = 0; i < n; ++i) {
        cin >> c[i].w >> c[i].v;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (j >= c[i-1].w) {
                f[i][j] = max(f[i-1][j], f[i-1][j-c[i-1].w] + c[i-1].v);
                // res = max(res, f[i][j]);
            } else {
                f[i][j] = f[i-1][j];
            }
            // cout << f[i][j] << " ";
        }
    }
    cout << f[n][w];
}