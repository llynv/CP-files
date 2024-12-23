/*
  Code by: linvg
  Created: 29.09.2024 23:41:05
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

//DSU unite, find, calculate number of connected components

struct DSU {
   vector<int> p, sz;
   int n;
   DSU(int _n) : n(_n) {
      p.resize(n);
      iota(all(p), 0);
      sz.assign(n, 1);
   }
   int find(int x) {
      return x == p[x] ? x : p[x] = find(p[x]);
   }
   bool unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) return false;
      if (sz[x] < sz[y]) swap(x, y);
      p[y] = x;
      sz[x] += sz[y];
      return true;
   }
   int size(int x) {
      return sz[find(x)];
   }
   int components() {
      int res = 0;
      for (int i = 1; i < n; ++i) {
         if (p[i] == i) ++res;
      }
      return res;
   }
};

void solve()
{
   int n, m;
   cin >> n >> m;
   DSU dsu(n + 1);

   set<int> s;
   for (int i = 1; i <= n; ++i) s.insert(i);

   for (int i = 0; i < m; ++i) {
      int a, d, k;
      cin >> a >> d >> k;
      for (int j = a + d, step = 1; step <= k; ++step) {
         if (j > n) break;
         dsu.unite(j, j - d);
         if (s.find(j) == s.end()) {
            int nxt = dsu.size(j);
            int x = max(0ll, (int) ceil(1.0 * nxt / d));
            if (j + x * d > n) {
               dsu.unite(j, n);
               break;
            }
            step += x - 1;
            if (step >= k) break;
            j += x * d;
            dsu.unite(j, j - x * d);
         }
         else {
            s.erase(j);
            j += d;
         }
      }
   }

   cout << dsu.components() << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}