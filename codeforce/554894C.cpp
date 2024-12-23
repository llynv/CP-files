/*
  Code by: linvg
  Created: 02.10.2024 17:38:51
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

void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> adj(n + 1);
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v); 
      adj[v].push_back(u);
   }

   vector<int> child(n + 1), par(n + 1);

   auto dfs = [&] (int u, int p, auto&&dfs) -> void {
      child[u] = 1;
      for (auto v : adj[u]) {
         if (v == p) continue;
         dfs(v, u, dfs);
         par[v] = u;
         child[u] += child[v];
      }
   };

   dfs(1, 0, dfs);
   
   vector<int> dp(n + 1);
  
   vector<vector<bool>> ans(n + 1, vector<bool>(n + 1));

   for (int i = 1; i <= n; ++i) {
      vector<int> arr;
      dp.assign(n + 1, 0);
      int total = n;
      for (auto v : adj[i]) {
         if (v == par[i]) {
            if (n - child[i] > 0 && child[i] - 1 > 0) {
               ans[n - child[i]][child[i] - 1] = 1;
               ans[child[i] - 1][n - child[i]] = 1;
            }
         } else if (child[v] > 0 && n - child[v] - 1 > 0) {
            for (int j = n; j >= child[v]; --j) {
               dp[j] = max(dp[j], dp[j - child[v]] + child[v]);
            }
         }
      }
      for (int j = 1; j < n; ++j) {
         if (dp[j] > 0 && n - dp[j] - 1 > 0) {
            // ans.push_back({dp[j], n - dp[j] - 1});
            ans[dp[j]][n - dp[j] - 1] = 1;
            ans[n - dp[j] - 1][dp[j]] = 1;
         }
      }
   }

   vector<array<int, 2>> res;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (ans[i][j]) {
            res.push_back({i, j});
         }
      }
   }
   cout << sz(res) << '\n';
   for (auto [a, b] : res) {
      cout << a << ' ' << b << '\n';
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