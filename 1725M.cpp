/*
  Code by: linvg
  Created: 04.12.2024 22:10:48
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
   int n, m;
   cin >> n >> m;
   vector<vector<array<int, 2>>> edges(n + 1);
   map<pair<int, int>, bool> hasEdge;
   for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[u].push_back({ v, w });
      hasEdge[{u, v}] = 1;
   }
   vector<vector<array<int, 2>>> dijk_adj(n + 1);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
   q.push({ 0, 1 });
   vector<int> dist_from_root(n + 1, -1);
   dist_from_root[1] = 0;
   while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      for (auto [v, w] : edges[u]) {
         if (dist_from_root[v] == -1 || dist_from_root[v] > w + d) {
            dijk_adj[u].push_back({v, w});
            if (hasEdge.count({v, u})) 
               dijk_adj[v].push_back({u, w});
            dist_from_root[v] = w + d;
            q.push({d + w, v});
         }
      }
   }

   vector<int> dist_to_root(n + 1, INF);
   dist_from_root[1] = 0;

   auto dfs = [&] (int u, int dist, auto&&dfs) -> void {
      for (auto &[v, d] : edges[u]) {
         if (dist_to_root[v] != INF) {
            dist_from_root[u] = min(dist_to_root[u], u + dist);
         }
      }
   };
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}