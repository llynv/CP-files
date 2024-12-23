
/*
  Code by: linvg
  Created: 16.08.2024 02:59:23
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
const int N = 2001;

int dp[N][N], a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for (int i = 1; i < n; ++i) {
        dp[i][i + 1] = a[i] != a[i + 1];
        res += dp[i][i + 1];
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 1; j + i <= n; ++j) {
            int l = j, r = j + i, suml = a[j], sumr = a[j + i];
            dp[j][j + i] = i;
            if (a[j] == a[j + i]) {
                dp[j][j + i] = dp[j + 1][j + i - 1];
                res += dp[j][j + i];
                continue;
            }
            while (l < r) {
                if (suml < sumr) suml += a[++l];
                else if (suml > sumr) sumr += a[--r];
                else {
                    dp[j][j + i] = dp[l + 1][r - 1] + (j + i - r + l - j);
                    break;
                }
            }
            res += dp[j][j + i];
        }
    }
    cout << res << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}