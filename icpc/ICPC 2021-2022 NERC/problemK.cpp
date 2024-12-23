/*
  Code by: linvg
  Created: 01.10.2024 22:06:06
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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{  
   int n, m, q;
   cin >> n >> m >> q;
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)), pref(n + 1, vector<int>(m + 1, 0));
   dp[1][1] = 1;
   pref[1][1] = 1;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {   
         if (i + j == 2) continue;
         dbg(i, j, dp[i][j], pref[i][j]);
         dp[i][j] = pref[i][j - 1] + pref[i - 1][j] + (pref[i - 1][j] != 0) + (pref[i][j - 1] != 0) + 1;
         pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
         dbg(i, j, dp[i][j], pref[i][j]);
      }
   }
   // print dp 
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cout << dp[i][j] << " ";
      }
      cout << endl;
   }

}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}