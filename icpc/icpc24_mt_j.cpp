
/*
  Code by: linvg
  Created: 22.10.2024 14:17:28
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

struct LCA
{
   vector<int> d;
   vector<vector<int>> f, adj;

   LCA(int n) : adj(n + 1), d(n + 1), f(n + 1, vector<int>(20)) {}

   LCA& addEdge(int u, int v)
   {
      adj[u].push_back(v);
      adj[v].push_back(u);
      return *this;
   }

   void dfs(int u, int p)
   {
      f[u][0] = p;
      for (int i = 1; i < 20; ++i)
      {
         f[u][i] = f[f[u][i - 1]][i - 1];
      }
      for (int v : adj[u])
      {
         if (v == p)
            continue;
         d[v] = d[u] + 1;
         dfs(v, u);
      }
   }

   int lca(int u, int v)
   {
      if (d[u] < d[v])
         swap(u, v);
      for (int i = 19; i >= 0; --i)
      {
         if (d[f[u][i]] >= d[v])
            u = f[u][i];
      }
      if (u == v)
         return u;
      for (int i = 19; i >= 0; --i)
      {
         if (f[u][i] != f[v][i])
         {
            u = f[u][i];
            v = f[v][i];
         }
      }
      return f[u][0];
   }

   int dist(int u, int v)
   {
      return d[u] + d[v] - 2 * d[lca(u, v)];
   }
};


void solve()
{
   int n, q;
   cin >> n >> q;
   LCA lca(n);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      lca.addEdge(u, v);
   }
   lca.dfs(1, 1);
   while (q--) {
      int x, y, z;
      cin >> x >> y >> z;
      dbg(x, y, z);
      dbg(lca.lca(x, y), lca.lca(x, z), lca.lca(y, z));
      bool ok = false;
      ok |= lca.lca(x, y) == x && lca.lca(y, z) == y;
      ok |= lca.lca(x, z) == y;
      ok |= lca.lca(x, y) == y && lca.lca(y, z) == lca.lca(x, z);
      ok |= lca.lca(y, z) == y && lca.lca(x, z) == lca.lca(y, z);
      cout << (ok ? "YES\n" : "NO\n");
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