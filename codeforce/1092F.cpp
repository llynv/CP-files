
/*
  Code by: linvg
  Created: 10.10.2024 11:43:40
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
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) cin >> a[i]; 
   vector<vector<int>> adj(n + 1);
   for (int i = 1; i < n; ++i)
   {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   vector<int> sum_up(n + 1), sum_down(n + 1), vst(n + 1), total_child(n + 1);
   auto dfs = [&] (int u, auto&&dfs) -> void {  
      vst[u] = 1;
      total_child[u] = a[u];
      for (auto v : adj[u]) {
         if (vst[v]) continue;   
         dfs(v, dfs);
         total_child[u] += total_child[v];
         sum_down[u] += sum_down[v] + total_child[v];
      }
   };
   int total = accumulate(all(a), 0LL);
   auto dfs2 = [&] (int u, auto&&dfs2)    -> void {
      vst[u] = 1;
      for (auto v : adj[u]) {
         if (vst[v]) continue; 
         sum_up[v] += sum_up[u] + total - 2 * total_child[v] + sum_down[u] - sum_down[v];
         dbg(u, v, sum_down[u], sum_down[v], sum_up[v]);
         dfs2(v, dfs2);
      }
   };

   dfs(1, dfs);
   vst.assign(n + 1, 0);
   dfs2(1, dfs2);
   int ans = 0;
   for (int i = 1; i <= n; ++i) ans = max(ans, sum_up[i] + sum_down[i]);
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