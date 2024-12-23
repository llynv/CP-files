/*
  Code by: linvg
  Created: 01.10.2024 15:37:36
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
   int n;
   cin >> n;
   vector<vector<int>> adj(n + 1);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<int> colors(n + 1), child(n + 1);

   auto dfs = [&] (int u, int p, auto&&dfs) -> void {
      int cnt = 1;
      for (auto v : adj[u]) {
         if (v == p) continue;
         dfs(v, u, dfs);
         cnt += child[v];
      }
      child[u] = cnt;
   };

   dfs(1, 0, dfs);

   auto dfs_color = [&] (int u, int p, int c, auto&&dfs_color) -> void {
      if (child[u] * 2 == n && !c) {
         c = 1;
      }
      colors[u] = c;
      for (auto v : adj[u]) {
         if (v == p) continue;
         dfs_color(v, u, c, dfs_color);
      }
   };

   for (int i = 1; i <= n; ++i) {
      if (child[i] * 2 == n) {
         dfs_color(1, 0, 0, dfs_color);
         cout << "YES\n";
         for (int j = 1; j <= n; ++j) {
            cout << colors[j] << " ";
         }
         cout << "\n";
         return;
      }
   }
   dbg(child);
   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}