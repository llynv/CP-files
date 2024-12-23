
/*
  Code by: linvg
  Created: 05.11.2024 17:43:39
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
   int n;
   vector<int> t;
   SegmentTree(int _n) : n(_n), t(4 * n) {}
   void update(int v, int tl, int tr, int pos, int val) {
      if (tl == tr) {
         t[v] = val;
         return;
      }
      int tm = (tl + tr) / 2;
      if (pos <= tm) update(v * 2, tl, tm, pos, val);
      else update(v * 2 + 1, tm + 1, tr, pos, val);
      t[v] = max(t[v * 2], t[v * 2 + 1]);
   }
   int query(int v, int tl, int tr, int l, int r) {
      if (l > r) return 0;
      if (l == tl && r == tr) return t[v];
      int tm = (tl + tr) / 2;
      return max(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
   }
};

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 2);
   a[0] = -INF;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   a[n + 1] = INF;
   vector<int> b(k);
   for (auto& c : b) cin >> c;
   b.insert(b.begin(), 0);
   b.push_back(n + 1);
   int ans = 0;

   for (int i = 1; i < sz(b); ++i) {
      if (b[i] - b[i - 1] - 1 > a[b[i]] - a[b[i - 1]] - 1) return void(cout << "-1\n");
      int len = b[i] - b[i - 1] - 1;
      SegmentTree st(len + 4);
      vector<int> pos;
      for (int j = b[i - 1] + 1, t = 0; j < b[i]; ++j, ++t) {
         if (a[j] - t > a[b[i - 1]] && a[j] + len - t - 1 < a[b[i]]) {
            pos.push_back(a[j] - t);
         }
      }
      sort(all(pos));
      pos.erase(unique(all(pos)), pos.end());
      for (int j = b[i - 1] + 1, t = 0; j < b[i]; ++j, ++t) {
         if (a[j] - t > a[b[i - 1]] && a[j] + len - t - 1 < a[b[i]]) {
            int x = lower_bound(all(pos), a[j] - t) - pos.begin();
            int val = st.query(1, 0, len + 3, 0, x) + 1;
            st.update(1, 0, len + 3, x, val);
         }
      }
      ans += len - st.t[1];
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}