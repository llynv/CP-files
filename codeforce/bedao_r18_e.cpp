
/*
  Code by: linvg
  Created: 19.10.2024 10:26:10
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

   int max_component_size() {
      int res = 0;
      for (int i = 0; i < counter.size(); ++i) {
         res = max(res, counter[i]);
      }
      return res;
   }
};

void solve()
{
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<array<int, 2>> edges(m);
   for (auto &c : edges) {
      cin >> c[0] >> c[1];
   }
   auto dfs = [&] (int u, vector<vector<int>>& adj, vector<int>& vst, auto&&dfs) -> int {
      vst[u] = 1;
      int sum = a[u - 1];
      for (auto&v : adj[u]) {
         if (!vst[v]) {
            sum += dfs(v, adj, vst, dfs);
         }
      }
      return sum;
   };
   for (int i = 0; i < q; ++i) {
      int l, r;
      cin >> l >> r;
      vector<int> vst(n + 1);
      vector<vector<int>> adj(n + 1);
      for (int j = l - 1; j < r; ++j) {
         adj[edges[j][0]].push_back(edges[j][1]);
         adj[edges[j][1]].push_back(edges[j][0]);
      }
      int res = 0;
      for (int j = 1; j <= n; ++j) {
         if (!vst[j]) {
            int x = dfs(j, adj, vst, dfs);
            res = max(res, x);
            dbg(j, x);
         }
      }
      cout << res << '\n';
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