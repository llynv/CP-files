
/*
  Code by: linvg
  Created: 19.10.2024 09:39:45
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
         t[v] = a[l];
         return;
      }
      int m = (l + r) / 2;
      build(a, 2 * v, l, m);
      build(a, 2 * v + 1, m + 1, r);
      t[v] = max(t[2 * v], t[2 * v + 1]);
   }

   void push(int v, int l, int r) {
      if (lazy[v] == 0) return;
      if (l != r) {
         t[2 * v] = lazy[v];
         t[2 * v + 1] = lazy[v];
         lazy[2 * v] = lazy[v];
         lazy[2 * v + 1] = lazy[v];
      }
      lazy[v] = 0;
   }

   void update(int v, int l, int r, int ql, int qr, int x) {
      push(v, l, r);
      if (l > qr || r < ql) return;
      if (l >= ql && r <= qr) {
         t[v] = x;
         lazy[v] = x;
         push(v, l, r);
         return;
      }
      int m = (l + r) / 2;
      update(2 * v, l, m, ql, qr, x);
      update(2 * v + 1, m + 1, r, ql, qr, x);
      t[v] = max(t[2 * v], t[2 * v + 1]);
   }

   int query(int v, int l, int r, int ql, int qr) {
      push(v, l, r);
      if (l > qr || r < ql) return 0;
      if (l >= ql && r <= qr) {
         // dbg(t[v], l, r);
         return t[v];
      }
      int m = (l + r) / 2;
      int left = query(2 * v, l, m, ql, qr);
      int right = query(2 * v + 1, m + 1, r, ql, qr);
      return max(left, right);
   }
};


void solve()
{
   int n;
   cin >> n;
   vector<array<int, 2>> a(n);
   for (auto &c : a) cin >> c[0];
   for (auto &c : a) cin >> c[1];
   sort(all(a));
   auto maxi = [&] (int &x, int y) {
      x = max(x, y);
   };
   // vector<int> dp(a.back()[0] + 1, 0), stmx(a.back()[0] + 1, 0);
   // SegmentTree st(a.back()[0] + 1);
   // for (int i = 1; i <= n; ++i) {
   //    // dp[a[i - 1][0]] = max(dp[a[i - 1][0]], st.query(1, 0, a.back()[0], 0, a[i - 1][0] - 1) + a[i - 1][1]);
   //    for (int j = a[i - 1][0]; j >= max(1ll, a[i - 1][0] - 2); --j) {
   //       dp[j] = max(dp[j], dp[j - 1] + a[i - 1][1]);
   //    }
   //    stmx[a[i - 1][0]] = max(stmx[a[i - 1][0]], dp[a[i - 1][0]]);
   // }
   // dbg(dp);
   // cout << *max_element(all(dp)) << '\n';
   priority_queue<int> pq;
   int res = 0;
   for (int i = n - 1; i >= 0; --i) {
      if (a[i][0] >= i + 1) {
         res += a[i][1];
         continue;
      } else {
         pq.push(a[i][1]);
      }
      res += pq.top();
      pq.pop();
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}