/*
  Code by: linvg
  Created: 21.09.2024 06:15:20
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

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n + 1);
   int sum = 0;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
   }

   vector<vector<int>> adj(n + 1);
   for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }

   vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(4, 0)));
   vector<vector<int>> dp2(n + 1, vector<int>(2, 0));

   vector<int> vst(n + 1, 0);
   auto dfs = [&](int u, int p, auto&& dfs) -> void {
      vst[u] = 1;
      for (int j = 1; j <= 3; ++j) {
         dp[u][1][j] = a[u];
         dp2[u][1] = a[u];
      }
      for (auto v : adj[u]) {
         if (v == p) continue;
         if (!vst[v]) {
            dfs(v, u, dfs);
            dp2[u][0] += dp2[v][1];
            dp2[u][1] += dp2[v][0];
            for (int j = 1; j <= 3; ++j) {
               dp[u][0][j] += max({ dp[v][0][j] + dp[u][1][j - 1], dp[v][1][j] + dp[u][0][j - 1], dp[v][1][j - 1], dp[v][0][j - 1] });
               dp[u][1][j] += max({ dp[v][0][j - 1], dp[v][1][j - 1], dp[v][0][j] + dp[u][0][j - 1] });
            }
         }
      }
      };

   dfs(1, 0, dfs);
   dbg(sum);
   int res = INF;
   res = min({ res, 2 * sum - max(dp2[1][1], dp2[0][1]), 3 * sum - max(dp[1][1][2], dp[1][0][2]) });
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