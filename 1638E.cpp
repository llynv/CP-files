
/*
  Code by: linvg
  Created: 07.11.2024 05:00:20
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

struct SegmentTreeSum {
   int n;
   vector<int> t, lazy;
   SegmentTreeSum(int _n) : n(_n), t(4 * n), lazy(4 * n) {}
   void push(int v, int tl, int tr) {
      if (lazy[v] != 0) {
         t[v] += lazy[v] * (tr - tl + 1);
         if (tl != tr) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
         }
         lazy[v] = 0;
      }
   }
   void update(int v, int tl, int tr, int l, int r, int add) {
      push(v, tl, tr);
      if (l > r) return;
      if (l == tl && r == tr) {
         lazy[v] += add;
         push(v, tl, tr);
         return;
      }
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), add);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
      t[v] = t[v * 2] + t[v * 2 + 1];
   }
   int query(int v, int tl, int tr, int l, int r) {
      push(v, tl, tr);
      if (l > r) return 0;
      if (l == tl && r == tr) return t[v];
      int tm = (tl + tr) / 2;
      return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
   }
};

struct SegmentTreePoint {
   int n;
   vector<int> t, lazy;
   SegmentTreePoint(int _n) : n(_n), t(4 * n), lazy(4 * n, -1) {}
   void push(int v, int tl, int tr) {
      if (lazy[v] != -1) {
         t[v] = lazy[v];
         if (tl != tr) {
            lazy[v * 2] = lazy[v];
            lazy[v * 2 + 1] = lazy[v];
         }
         lazy[v] = -1;
      }
   }
   void update(int v, int tl, int tr, int l, int r, int val) {
      push(v, tl, tr);
      if (l > r) return;
      if (l == tl && r == tr) {
         lazy[v] = val;
         push(v, tl, tr);
         return;
      }
      int tm = (tl + tr) / 2;
      update(v * 2, tl, tm, l, min(r, tm), val);
      update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
   }
   int query(int v, int tl, int tr, int pos) {
      push(v, tl, tr);
      if (tl == tr) return t[v];
      int tm = (tl + tr) / 2;
      if (pos <= tm) return query(v * 2, tl, tm, pos);
      else return query(v * 2 + 1, tm + 1, tr, pos);
   }
};


void solve()
{
   int n, q;
   cin >> n >> q;
   vector<array<int, 3>> colors;
   vector<array<int, 2>> adds;
   SegmentTreePoint stp(n);
   SegmentTreeSum sts(n);
   unordered_map<int, int> cnt;
   while (q--) {
      string t;
      cin >> t;
      if (t == "Color") {
         int l, r, c;
         cin >> l >> r >> c;
         colors.clear();
         stp.update(1, 1, n, l, r, c);
      } else if (t == "Add") {
         int c, x;
         cin >> c >> x;
         adds.push_back({c, x});
      } else {

         adds.clear();
         colors.clear();
      }
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