/*
  Code by: linvg
  Created: 18.12.2024 14:36:19
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
const int N = 1e5 + 7;

int fact[N];

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<int>> adj(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<int> vst(n + 1);
   auto dfs = [&] (int u, int& comp, auto&&dfs) -> void {
      vst[u] = 1;
      comp++;
      for (auto &c : adj[u]) {
         if (vst[c]) continue;
         dfs(c, comp, dfs);
      } 
   };

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      if (!vst[i]) {
         int comp = 0;
         dfs(i, comp, dfs);
         if (comp <= 2) continue;
         ans += fact[comp];
         ans %= MOD;
      }
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   fact[0] = 1;
   for (int i = 1; i < N; ++i) fact[i] = (fact[i - 1] * i) % MOD;
   solve();
   return 0;
}