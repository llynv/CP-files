
/*
  Code by: linvg
  Created: 05.10.2024 00:28:36
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
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   int sum_xor = 0;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      sum_xor ^= a[i];
   }
   vector<vector<int>> adj(n + 1);
   for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   if (sum_xor == 0) return cout << "YES\n", void();
   if (k <= 2) return cout << "NO\n", void();

   vector<int> child_xor(n + 1);
   auto dfs = [&](int u, int p, auto&& dfs) -> void {
      child_xor[u] = a[u];
      for (auto& v : adj[u]) {
         if (v == p) continue;
         dfs(v, u, dfs);
         child_xor[u] ^= child_xor[v];
      }
      };
   dfs(1, -1, dfs);
   int cnt1 = 0, cnt0 = 0;
   dbg(sum_xor);
   for (int i = 1; i <= n; ++i) cnt1 += (sz(adj[i]) == 1 && a[i] == sum_xor);
   if (cnt1 >= 2) return cout << "YES\n", void();

   auto dfs_state = [&](int u, int p, auto&& dfs_state, bool state = true) -> void {
      if (u != 1 && child_xor[u] == (state ? sum_xor : 0)) {
         cnt0 += state;
         dbg(u, state, child_xor[u]);
         state = !state;
      }
      for (auto& v : adj[u]) {
         if (v == p) continue;
         dfs_state(v, u, dfs_state, state);
      }
   };

   dbg(child_xor);

   for (bool state : {true, false}) {
      dfs_state(1, -1, dfs_state, state);
      dbg(cnt0);
      if (cnt0 >= 2) return cout << "YES\n", void();
   }

   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}