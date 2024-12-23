
/*
  Code by: linvg
  Created: 15.09.2024 21:48:25
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
const int MOD = 1e9 + 7;
vector<int> f(1e4 + 7, 0), ff(1e4 + 7, 0);

void solve()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        // cout << (x % 2 == 1) ? ((f[r] - f[l - 1] + MOD) % MOD) : (ff[r] - ff[l - 1] + MOD) % MOD << '\n';
        if (x % 2 == 1) {
            cout << (f[r] - f[l - 1] + MOD) % MOD << '\n';
        } else {
            int total = (r + 2) * (r + 1) / 2 - l * (l + 1) / 2;
            cout << (total - ((f[r] - f[l - 1] + MOD) % MOD) + MOD) % MOD << '\n';
        }
    }
}


int32_t main() {
    int n = 1000;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        f[i] += dp[i][0];
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] %= 2;
            f[i] += dp[i][j];
            f[i] %= MOD;
        }
    }
    for (int i = 2; i <= n; ++i) {
        f[i] += f[i - 1];
        f[i] %= MOD;
    }

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}