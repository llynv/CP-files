
/*
  Code by: linvg
  Created: 06.10.2024 04:14:39
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
   vector<vector<int>> adj(n + 1);
   vector<int> a(n + 1), b(n + 1);
   for (int i = 2; i <= n; ++i) {
      int p, x, y;
      cin >> p >> x >> y;
      adj[p].push_back(i);
      a[i] = x;
      b[i] = y;
   }

   vector<int> pref, r(n + 1);
   pref.push_back(0);
   auto dfs = [&] (int u, int total, auto&&dfs) -> void {
      if (u != 1) {
         int p = (upper_bound(all(pref), total) - pref.begin()) - 1;
         r[u] = p;
      }
      for (auto v : adj[u]) {
         if (pref.size()) pref.push_back(pref.back() + b[v]);
         else pref.push_back(b[v]);
         dfs(v, total + a[v], dfs);
         pref.pop_back();
      }
   };
   dfs(1, 0, dfs);
   for (int i = 2; i <= n; ++i) cout << r[i] << ' ';
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}