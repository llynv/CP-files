
/*
  Code by: linvg
  Created: 14.10.2024 15:20:33
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

struct Edge
{
   int u, v, w;
   bool operator < (const Edge& o) {
      return w < o.w;
   }

   bool operator > (const Edge& o) {
      return w > o.w;
   }

   bool operator == (const Edge& o) {
      return w == o.w;
   }

   friend ostream& operator << (ostream& os, const Edge& o) {
      os << o.u << ' ' << o.v << ' ' << o.w;
      return os;
   }
};


struct DSU
{
   vector<int> counter, parent;

   DSU(int n)
   {
      parent.resize(n + 1);
      counter.resize(n + 1, 1);
      for (int i = 0; i <= n; i++)
         parent[i] = i;
   }

   int find_root(int i)
   {
      while (i != parent[i])
      {
         parent[i] = parent[parent[i]];
         i = parent[i];
      }
      return parent[i];
   }

   void connect(int a, int b)
   {
      int c = find_root(a), d = find_root(b);
      if (c != d)
      {
         parent[c] = d;
         counter[d] += counter[c], counter[c] = 0;
      }
   }

   bool is_connected(int a, int b)
   {
      return find_root(a) == find_root(b);
   }

   int component_size(int i)
   {
      int p = find_root(i);
      return counter[p];
   }
};

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<Edge> edges(m);
   vector<vector<array<int, 2>>> adj(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[i] = { u, v, w };
      adj[u].push_back({ v, w });
      adj[v].push_back({ u, w });
   }
   sort(all(edges));
   dbg(edges);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
   q.push({ 0, 1 });
   int total = 0;
   while (!q.empty() || total < k) {
      auto [d, u] = q.top();
      q.pop();
      for (auto [v, w] : adj[u]) {
         if ()
      }
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