/*
  Code by: linvg
  Created: 28.09.2024 20:34:06
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

void add (int i, int v, vector<int> &bit) {
   for (; i < sz(bit); i += i & -i) bit[i] += v;
}

int sum (int i, vector<int> &bit) {
   int res = 0;
   for (; i > 0; i -= i & -i) res += bit[i];
   return res;
}

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
   
   vector<int> child(n + 1), max_height(n + 1), cur_height(n + 1), fw(n + 1), cut_in_height(n + 1);

   function<int(int, int, int)> dfs = [&](int u, int p, int height) -> int {
      cur_height[u] = height;
      for (int v : adj[u]) {
         if (v == p) continue;
         child[u] += dfs(v, u, height + 1);
         max_height[u] = max(max_height[u], max_height[v]);
      }
      child[u] += 1;
      max_height[u] = max(max_height[u], height);
      return child[u];
   };
   dfs(1, 0, 0);

   for (int i = 1; i <= n; ++i) {
      if (max_height[i] != cur_height[i]) {
         cut_in_height[cur_height[i]] += child[i] - 1;
      }
      add(max_height[i] + 1, 1, fw);
   }

   int res = INF;
   for (int cut = 1; cut <= max_height[1]; ++cut) {
      res = min(res, cut_in_height[cut] + sum(cut, fw));
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}