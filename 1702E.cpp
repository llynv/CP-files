/*
  Code by: linvg
  Created: 09.12.2024 08:25:39
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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
   vector<pair<int, int>> a(n);
   vector<int> deg(n + 1);
   for (int i = 0; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      deg[u]++;
      deg[v]++;
      a[i] = {u, v};
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   vector<int> vis(n + 1);
   function<int(int)> dfs = [&](int u) -> int {
      vis[u] = 1;
      for (auto v : adj[u]) {
         if (!vis[v]) return dfs(v) + 1;
      }
      return 1;
   };
   for (int i = 1; i <= n; ++i) {
      if (a[i - 1].first == a[i - 1].second || deg[i] != 2) return void(cout << "NO\n");
      if (vis[i]) continue;
      if (dfs(i) % 2 != 0) return void(cout << "NO\n");
   }
   cout << "YES\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}