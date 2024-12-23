
/*
  Code by: linvg
  Created: 13.10.2024 18:45:39
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

const int INF = LONG_LONG_MAX;
const int MOD = 1e9 + 7;

struct SegmentTree {
   int n;
   vector<int> tree;
   SegmentTree(int size) : n(size), tree(4 * size, -INF) {}
   void update(int idx, int l, int r, int pos, int val) {
      if (l == r) {
         tree[idx] = val;
      } else {
         int mid = (l + r) / 2;
         if (pos <= mid) {
            update(2 * idx + 1, l, mid, pos, val);
         } else {
            update(2 * idx + 2, mid + 1, r, pos, val);
         }
         tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
      }
   }

   void update(int pos, int val) {
      update(0, 0, n - 1, pos, val);
   }

   int query(int idx, int l, int r, int ql, int qr) {
      if (ql > r || qr < l) {
         return -INF;
      }
      if (ql <= l && qr >= r) {
         return tree[idx];
      }
      int mid = (l + r) / 2;
      return max(query(2 * idx + 1, l, mid, ql, qr), query(2 * idx + 2, mid + 1, r, ql, qr));
   }

   int query(int ql, int qr) {
      return query(0, 0, n - 1, ql, qr);
   }
};

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> sum(n + 1);
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      sum[i] = sum[i - 1] + x;
   }
   vector<vector<int>> dp(n + 1, vector<int>(k + 1));
   vector<int> st(k + 1);
   for (int i = m; i <= n; ++i) {
      dp[i][1] = sum[i] - sum[i - m];
      st[1] = max(st[1], dp[i - m][1]);
      for (int l = 2; l <= k; ++l) {
         dp[i][l] = max(dp[i - 1][l], st[l - 1] + sum[i] - sum[i - m]);
         st[l] = max(st[l - 1], dp[i - m][l]);
      }
   }
   int res = 0;
   for (int i = 1; i <= n; ++i) res = max(res, dp[i][k]);
   cout << res;
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}