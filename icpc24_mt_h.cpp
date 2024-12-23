
/*
  Code by: linvg
  Created: 31.10.2024 15:36:58
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
const int N = 2e5 + 7;

struct Node {
   int maxVal;
   int sum;
};

struct SegmentTree {
   vector<Node> t;
   vector<int> lazy;
   int n;

   SegmentTree(int n) : n(n) {
      t.resize(4 * n);
      lazy.resize(4 * n);
   }

   SegmentTree(vector<int> a) : n(a.size()) {
      t.resize(4 * n);
      lazy.resize(4 * n);
      build(a, 1, 0, n - 1);
   }

   void build(vector<int>& a, int v, int l, int r) {
      if (l == r) {
         t[v].maxVal = a[l];
         return;
      }
      int m = (l + r) / 2;
      build(a, 2 * v, l, m);
      build(a, 2 * v + 1, m + 1, r);
      t[v].maxVal = max(t[2 * v].maxVal, t[2 * v + 1].maxVal);
   }

   void push(int v, int l, int r) {
      if (lazy[v] == 0) return;
      if (l != r) {
         t[2 * v].sum = lazy[v];
         t[2 * v + 1].sum = lazy[v];
         lazy[2 * v] = lazy[v];
         lazy[2 * v + 1] = lazy[v];
      }
      lazy[v] = 0;
   }

   void update(int v, int l, int r, int ql, int qr, int x) {
      push(v, l, r);
      if (l > qr || r < ql) return;
      if (l >= ql && r <= qr) {
         t[v].a = x;
         lazy[v] = x;
         push(v, l, r);
         return;
      }
      int m = (l + r) / 2;
      update(2 * v, l, m, ql, qr, x);
      update(2 * v + 1, m + 1, r, ql, qr, x);
      t[v] = min(t[2 * v], t[2 * v + 1]);
   }

   Node query(int v, int l, int r, int ql, int qr) {
      push(v, l, r);
      if (l > qr || r < ql) return Node(INF, 1);
      if (l >= ql && r <= qr) {
         dbg(t[v], l, r);
         return t[v];
      }
      int m = (l + r) / 2;
      Node left = query(2 * v, l, m, ql, qr);
      Node right = query(2 * v + 1, m + 1, r, ql, qr);
      return min(left, right);
   }
};


void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   cin >> a;

   dbg(a);

   while (q--) {
      int t, l, r;
      cin >> t >> l >> r;
      if (t == 1) {

      } else if (t == 2) {
          
      } else {

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