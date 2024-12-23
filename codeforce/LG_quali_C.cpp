
/*
  Code by: linvg
  Created: 12.10.2024 10:33:45
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

void solve() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(n + 1), b(m + 1);
   vector<vector<int>> sb(m + 1);
   vector<pair<int, int>> edges;
   map<int, int> ta, tb;
   for (int i = 1; i <= k; ++i) {
      int u, v;
      cin >> u >> v;
      a[u]++, b[v]++;
      sb[v].push_back(u);
   }
   for (int i = 1; i <= m; i++) for (int j : sb[i]) edges.push_back({ a[j], b[i] });
   sort(all(a));
   sort(all(b));
   int maxS = 0;
   for (int i = sz(a) - 1, j = n; i >= 0; --i, --j) {
      maxS += a[i] * j;
      ta[a[i]] = j;
   }
   for (int i = sz(b) - 1, j = m; i >= 0; --i, --j) {
      maxS += b[i] * j;
      tb[b[i]] = j;
   }
   int minMS = INF;
   for (auto [u, v] : edges) {
      minMS = min(minMS, ta[u] + tb[v]);
   }
   cout << maxS << " " << maxS - minMS << "\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}