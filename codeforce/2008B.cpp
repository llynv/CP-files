
/*
  Code by: linvg
  Created: 01.09.2024 21:40:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

bool checksqrt(int n) {
    int x = sqrt(n);
    return x * x == n;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (!checksqrt(n)) {
        cout << "No\n";
        return;
    }
    int m = sqrt(n);
    vector<vector<char>> a((int) m, vector<char>((int) m, '*'));
    int id = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[id++];
        }
    }
    dbg(a);
    for (int i = 0; i < m; ++i) {
        if (a[i][0] != '1' || a[i][m - 1] != '1') {
            cout << "No\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (a[0][i] != '1' || a[m - 1][i] != '1') {
            cout << "No\n";
            return;
        }
    }
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (a[i][j] != '0') {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}