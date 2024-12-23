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

void solve()
{
   int n1, n2, k1, k2;
   cin >> n1 >> n2 >> k1 >> k2;
   vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2, 0))));
   for (int i = 1; i <= min(k1, n1); ++i) dp[i][0][0] = 1;
   for (int i = 1; i <= min(k2, n2); ++i) dp[0][i][1] = 1;
   for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
         for (int k = 1; k <= min(k1, n1); ++k) {
            if (i - k >= 0) dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
         }
         for (int k = 1; k <= min(n2, k2); ++k) {
            if (j - k >= 0) dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
         }
      }
   }

   cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}