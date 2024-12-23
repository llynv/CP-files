
/*
  Code by: linvg
  Created: 04.10.2024 23:33:55
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
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) cin >> a[i];

   if (n == 1) {
      cout << a[1] << '\n';
      return;
   }

   vector<vector<array<int, 2>>> adj(n + 1);
   vector<int> dp_up(n + 1), dp_down(n + 1);
   for (int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({ v, w });
      adj[v].push_back({ u, w });
   }

   auto dfs = [&] (int u, int p, auto&&dfs) -> void {
      dp_up[u] = a[u];
      dp_down[u] = a[u];
      vector<pair<int, int>> down;
      for (auto [v, w] : adj[u]) {
         if (v == p) continue;
         dp_up[v] = max(dp_up[v], dp_up[u] - w + a[v]);
         dfs(v, u, dfs);
         down.push_back({v, w});
         dp_down[u] = max(dp_down[u], dp_down[v] + a[u] - w);
      }
      sort(all(down), [&] (pair<int, int> &x, pair<int, int> &y) {
         return dp_down[x.first] - x.second < dp_down[y.first] - y.second;
      });
      dbg(u, down);
      for (auto [v, w] : adj[u]) {
         if (v == p) continue;
         if (down.empty()) break;
         if (down.back().first == v && down.size() > 1) {
            dp_up[v] = max(dp_up[v], dp_down[v] + dp_down[down[down.size() - 2].first] + a[u] - w - down[down.size() - 2].second);
         } else if (down.back().first != v) {
            dp_up[v] = max(dp_up[v], dp_down[v] + dp_down[down.back().first] + a[u] - w - down.back().second);
         }
      }
   };

   dfs(1, 0, dfs);
   int ans = 0;
   for (int i = 1; i <= n; ++i) ans = max({ans, dp_up[i], dp_down[i]});
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}