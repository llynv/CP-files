/*
  Code by: linvg
  Created: 02.12.2024 21:56:33
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

struct segtree {
   int size;
   vector<pair<int, int>> t;

   segtree() {}

   segtree(int n) {
      size = n;
      t.assign(4 * size, { -INF, INF });
   }

   void update(int index, int l, int r, int pos, pair<int, int> val) {
      if (pos < l || pos > r) return;
      if (l == r) {
         t[index] = val;
         return;
      }
      int m = (l + r) / 2;
      update(index * 2, l, m, pos, val);
      update(index * 2 + 1, m + 1, r, pos, val);
      t[index] = comp(t[index * 2], t[index * 2 + 1]);
   }

   pair<int, int> comp(pair<int, int> a, pair<int, int> b) {
      return { max(a.first, b.first), min(a.second, b.second) };
   }

   pair<int, int> query(int index, int l, int r, int ql, int qr) {
      if (l > qr || r < ql) return { -INF, INF };
      if (l >= ql && r <= qr) return t[index];
      int m = (l + r) / 2;
      return comp(query(index * 2, l, m, ql, qr), query(index * 2 + 1, m + 1, r, ql, qr));
   }

   pair<int, int> query(int l, int r) {
      return query(1, 0, size - 1, l, r);
   }
};

void solve()
{
   int n;
   cin >> n;
   vector<array<int, 3>> a(n);
   vector<int> p;
   for (int i = 0; i < n; ++i) {
      cin >> a[i][0] >> a[i][1];
      a[i][2] = i;
      p.push_back(a[i][0]);
      p.push_back(a[i][1]);
   }
   sort(all(p));
   p.erase(unique(all(p)), p.end());
   sort(all(a), [&](array<int, 3>& x, array<int, 3>& y) {
      if (x[0] == y[0]) return x[1] > y[1];
      return x[0] < y[0];
      });
   for (int i = 0; i < n; ++i) {
      a[i][0] = lower_bound(all(p), a[i][0]) - p.begin();
      a[i][1] = lower_bound(all(p), a[i][1]) - p.begin();
   }
   segtree st(sz(p));
   vector<int> res(n);
   int mock = 0;
   int sz = p.size() - 1;
   st.update(1, 0, sz, a[0][1], { a[0][0], a[0][1] });
   for (int i = 1; i < n; ++i) {
      for (; mock < i and a[mock][0] <= a[i][0]; ++mock) {
         st.update(1, 0, sz, a[mock][1], { a[mock][0], a[mock][1] });
      }
      auto cp = st.query(a[i][1], sz);
      if (i < n - 1 and a[i][1] == a[i + 1][1] and a[i][0] == a[i + 1][0]) {
         cp = { a[i + 1][0], a[i + 1][1] };
      }
      if (cp.second == INF) continue;
      int l = cp.first, r = cp.second;
      res[a[i][2]] = p[a[i][0]] - p[l] + p[r] - p[a[i][1]];
   }
   for (int i = 0; i < n; ++i) {
      cout << res[i] << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}