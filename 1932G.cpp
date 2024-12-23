/*
  Code by: linvg
  Created: 18.12.2024 19:32:40
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

int fpow(int a, int b, int mod) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
}

struct Hash
{
   size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
   }
};


void solve()
{
   int n, m, H;
   cin >> n >> m >> H;
   vector<int> l(n + 1), s(n + 1);
   for (int i = 1; i <= n; ++i) cin >> l[i];
   for (int i = 1; i <= n; ++i) cin >> s[i];
   vector<vector<int>> adj(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   auto calc_min_step = [&] (int s_v, int s_u, int l_v, int l_u) -> int {
      if (l_u == l_v) return 1;
      if (s_v == 0 && s_u == 0) return -1;
      int x = (l_u - l_v + H) % H;
      int y = (s_v - s_u + H) % H;
      // x = y * k
      int _g = gcd(y, H);
      if (x % _g) return -1;
      x /= _g;
      y /= _g;
      int _h = H / _g;
      int k = x * fpow(y, _h - 2, _h) % _h;
      dbg(s_v, s_u, l_v, l_u, x, y, _g, _h, k);
      return k;
   };

   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
   vector<int> dist(n + 1, INF);
   pq.push({0, 0, 1});
   dist[1] = 0;

   cerr << "H = " << H << endl;

   while (!pq.empty()) {
      auto [d, step, u] = pq.top();
      pq.pop();
      if (d != dist[u] && dist[u] != INF) continue;
      int level = (l[u] + s[u] * step) % H;
      dbg(u, d, step, level);
      for (auto &v : adj[u]) {
         int this_level = (l[v] + s[v] * step) % H;
         int new_step = calc_min_step(s[v], s[u], this_level, level);
         if (new_step == -1) continue;
         if (dist[v] > d + new_step) {
            dist[v] = d + new_step;
            pq.push({dist[v], new_step + step, v});
         }      
      }
   }

   cout << (dist[n] == INF ? -1 : dist[n]) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}