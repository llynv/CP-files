
/*
  Code by: linvg
  Created: 01.11.2024 15:35:00
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

template <class T>
void compress(vector<T>& v, bool make_sorted = true) {
   unordered_map <T, int> mp;

   if (!make_sorted) {
      for (auto&& x : v) x = mp.emplace(x, mp.size()).first->second;
      return;
   }

   vector<T> u = v;
   sort(u.begin(), u.end());
   for (auto&& x : u) mp.emplace(x, mp.size()).first->second;
   for (auto&& x : v) x = mp[x];
}

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
         t[2 * v] = max(t[2 * v], lazy[v]);
         t[2 * v + 1] = max(t[2 * v + 1], lazy[v]);
         lazy[2 * v] = max(lazy[2 * v], lazy[v]);
         lazy[2 * v + 1] = max(lazy[2 * v + 1], lazy[v]);
      }
      lazy[v] = 0;
   }

   void update(int v, int l, int r, int ql, int qr, int x) {
      push(v, l, r);
      if (l > qr || r < ql) return;
      if (l >= ql && r <= qr) {
         t[v] = max(t[v], x);
         lazy[v] = max(lazy[v], x);
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
   vector<array<int, 3>> a(n);
   vector<int> points;
   for (auto& [x, y, z] : a) {
      cin >> x >> y >> z;
      points.push_back(x);
      points.push_back(y);
   }
   sort(all(points));
   points.erase(unique(all(points)), points.end());
   dbg(points);
   for (auto& [x, y, z] : a) {
      x = lower_bound(all(points), x) - points.begin();
      y = lower_bound(all(points), y) - points.begin();
   }
   sort(all(a), [&] (array<int, 3> &x, array<int, 3> &y) {
      if (x[1] == y[1]) return x[0] < y[0];
      return x[1] < y[1];
   });
   vector<int> dp(points.size());
   SegmentTree s(points.size() + 1);
   for (int i = 1; i <= n; ++i) {
      auto &[x, y, z] = a[i - 1];
      dp[y] = max({s.query(1, 0, points.size(), 0, x - 1) + z, dp[y], s.query(1, 0, points.size(), 0, y)});
      s.update(1, 0, points.size(), y, y, dp[y]);
   }
   dbg(dp);
   cout << dp.back() << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}