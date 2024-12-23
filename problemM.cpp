/*
  Code by: linvg
  Created: 05.12.2024 18:36:29
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

struct SegmentTree {
   vector<int> t;
   int n;
   SegmentTree(int _n) {
      n = _n;
      t.assign(4 * n, INF);
   }
   void update(int v, int tl, int tr, int pos, int val) {
      if (tl == tr) {
         t[v] = val;
         return;
      }
      int tm = (tl + tr) / 2;
      if (pos <= tm) update(v * 2, tl, tm, pos, val);
      else update(v * 2 + 1, tm + 1, tr, pos, val);
      t[v] = min(t[v * 2], t[v * 2 + 1]);
   }
   int get(int v, int tl, int tr, int l, int r) {
      if (l > r) return INF;
      if (tl > r || tr < l) return INF;
      if (l <= tl && r >= tr) return t[v];
      int tm = (tl + tr) / 2;
      return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
   }
};

struct SegmentTreeSum {
   int n;
   vector<int> st, lz;
   SegmentTreeSum(int n) : n(n) {
      st.assign(4 * n, 0);
      lz.assign(4 * n, -1);
   }

   void push(int i, int l, int r) {
      if (lz[i] == -1) return;
      if (l < r) {
         int m = (l + r) >> 1;
         st[i << 1] = lz[i] * (m - l + 1);
         st[i << 1 | 1] = lz[i] * (r - m);
         lz[i << 1] = lz[i];
         lz[i << 1 | 1] = lz[i];
      }
      lz[i] = -1;
   }

   void update(int i, int l, int r, int u, int v, int val) {
      if (r < u || v < l) return;
      push(i, l, r);
      if (u <= l && r <= v) {
         st[i] = val * (r - l + 1);
         lz[i] = val;
         push(i, l, r);
         return;
      }
      push(i, l, r);
      int m = (l + r) >> 1;
      update(i << 1, l, m, u, v, val);
      update(i << 1 | 1, m + 1, r, u, v, val);
      st[i] = st[i << 1] + st[i << 1 | 1];
   }

   int getSum(int i, int l, int r, int u, int v) {
      if (r < u || v < l) return 0;
      push(i, l, r);
      if (u <= l && r <= v) return st[i];
      int m = (l + r) >> 1;
      return getSum(i << 1, l, m, u, v) + getSum(i << 1 | 1, m + 1, r, u, v);
   }
};

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   SegmentTreeSum st(n);
   SegmentTree stm(n);
   vector<int> b;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b.push_back(a[i]);
      if (i > 0) a[i] = min(a[i], a[i - 1]);
      st.update(1, 0, n - 1, i, i, a[i]);
      stm.update(1, 0, n - 1, i, b[i]);
   }
   auto find_last = [&] (int p, int val) -> int {
      int l = p, r = n - 1, pos = p;
      while (l <= r) {
         int m = (l + r) >> 1;
         int x = stm.get(1, 0, n - 1, 0, m);
         if (x == val) {
            l = m + 1;
            pos = m;
         } else {
            r = m - 1;
         }
      }

      return pos;
   };

   cout << st.getSum(1, 0, n - 1, 0, n - 1) << '\n';

   int q;
   cin >> q;
   while (q--) {
      int t, p;
      cin >> t >> p;
      if (t == 1) {
         b[p]++;
         stm.update(1, 0, n - 1, p, b[p]);
         int mn = stm.get(1, 0, n - 1, 0, p);
         int x = find_last(p, mn);
         dbg(p, x, mn);
         st.update(1, 0, n - 1, p, x, mn);
      } else {
         b[p]--;
         stm.update(1, 0, n - 1, p, b[p]);
         int mn = stm.get(1, 0, n - 1, 0, p);
         int x = find_last(p, mn);
         dbg(p, x, mn);
         st.update(1, 0, n - 1, p, x, mn);
      }
      cout << st.getSum(1, 0, n - 1, 0, n - 1) << '\n';
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