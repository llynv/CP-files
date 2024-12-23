/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));

    dp[n][2][1] = 1;
    dp[n][s[n - 1] == 'K'][1] = 1;

    for (int i = n - 1; i > 0; --i) {
        if (s[i - 1] == 'K') {
            for (int j = 1; j >= 0; --j) {
                dp[i][2][j] = dp[i + 1][2][j] + dp[i + 1][0][j ^ 1];
                dp[i][1][j] = dp[i + 1][2][j] + dp[i + 1][1][j];
                dp[i][0][j] = dp[i + 1][0][j];
            }
        }
        else {
            for (int j = 1; j >= 0; --j) {
                dp[i][0][j] = dp[i + 1][2][j] + dp[i + 1][0][j];
                dp[i][2][j] = dp[i + 1][2][j] + dp[i + 1][1][j];
                dp[i][1][j] = dp[i + 1][1][j];
            }
        }

        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 1; k++) {
                dp[i][j][k] %= mod;
            }
        }
    }
    cout << dp[1][2][1] % mod << "\n";
}


int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}