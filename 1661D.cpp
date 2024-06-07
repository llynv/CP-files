/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

struct LazySegmentTree {
   vector<int> t, lz, cof;
   int n;
   LazySegmentTree(int n) : n(n), t(4 * n), lz(4 * n), cof(4 * n) {}
   LazySegmentTree(vector<int> a) : LazySegmentTree(a.size()) {
      build(a, 1, 0, n - 1);
   }
   void build(vector<int>& a, int v, int tl, int tr) {
      if (tl == tr) {
         t[v] = a[tl];
      }
      else {
         int tm = (tl + tr) / 2;
         build(a, v * 2, tl, tm);
         build(a, v * 2 + 1, tm + 1, tr);
         t[v] = t[v * 2] + t[v * 2 + 1];
      }
   }
   int total (int n) {
      return n * (n + 1) / 2;
   }
   void push(int v, int tl, int tr) {
      if (lz[v] == -1) return;
      if (tl != tr) {
         int tm = (tl + tr) / 2;
         lz[v * 2] = lz[v];
         lz[v * 2 + 1] = lz[v];
         t[v * 2] -= total(tm - lz[v] + 1) * cof[v];
         t[v * 2 + 1] -= (total(tr - lz[v] + 1) - total(tm - lz[v] + 1)) * cof[v];
         cof[v * 2] = cof[v * 2 + 1] = cof[v];
      } 
      lz[v] = -1;
      cof[v] = 1;
   }
   int sum(int v, int tl, int tr, int l, int r) {
      push(v, tl, tr);
      if (l > r) return 0;
      push(v, tl, tr);
      if (l == tl && r == tr) {
         return t[v];
      }
      int tm = (tl + tr) / 2;
      return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
   }
   void update(int v, int tl, int tr, int l, int r, int addend, int coff) {
      push(v, tl, tr);
      if (l > r) return;
      if (l == tl && r == tr) {
         t[v] -= total(tr - addend + 1) - total(tl - addend + 1);
         lz[v] = addend;
         cof[v] = coff;
      }
      else {
         push(v, tl, tr);
         int tm = (tl + tr) / 2;
         update(v * 2, tl, tm, l, min(r, tm), addend, coff);
         update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend, coff);
         t[v] = t[v * 2] + t[v * 2 + 1];
      }
   }
};

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> b(n);
   for (auto& c : b) cin >> c;
   LazySegmentTree st(b);
   int res = 0;
   for (int i = k - 1; i < n; ++i) {
      dbg(i, st.sum(1, 0, n-1, i - k + 1, i - k + 1));
      int cof = st.sum(1, 0, n-1, i - k + 1, i - k + 1);
      if (cof <= 0) continue;
      dbg(i, st.sum(1, 0, n-1, i - k + 1, i - k + 1), cof);
      st.update(1, 0, n - 1, max(i - k + 1, 0ll), min(i + 1, n - 1), max(i - k + 1, 0ll), cof);
      res += cof;
   }
   for (int i = n - k; i < n; ++i) {
      dbg(i, st.sum(1, 0, n-1, i, i));
      int cof = st.sum(1, 0, n-1, i, i);
      if (cof <= 0) continue;
      st.update(1, 0, n - 1, i, n - 1, i - k + 1, cof);
      res += cof;
   }
   cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}