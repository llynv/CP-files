/*
  Code by: linvg
  Created: 19.12.2024 15:40:32
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
   SegmentTree(int _n) : n(_n), t(4 * n, INF) {}
   void update(int v, int tl, int tr, int pos, int val) {
      if (tl == tr) {
         t[v] = val;
         return;
      }
      int tm = (tl + tr) >> 1;
      if (pos <= tm) update(v << 1, tl, tm, pos, val);
      else update(v << 1 | 1, tm + 1, tr, pos, val);
      t[v] = min(t[v << 1], t[v << 1 | 1]);
   }
   int get(int v, int tl, int tr, int l, int r) {
      if (l > r) return INF;
      if (l == tl && r == tr) return t[v];
      int tm = (tl + tr) >> 1;
      return min(get(v << 1, tl, tm, l, min(r, tm)), get(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
   }
};

void solve()
{
   int n;
   cin >> n;
   vector<array<int, 3>> a(n);
   for (auto &c : a) cin >> c[0] >> c[1] >> c[2];
   unordered_map<int, vector<array<int, 3>>> color_segment;
   set<array<int, 3>> colors_l, colors_r;
   vector<int> compress;
   for (int i = 0; i < n; ++i) {
      colors_l.insert({ a[i][0], a[i][1], a[i][2] });
      colors_r.insert({ a[i][1], a[i][0], a[i][2] });
      compress.push_back(a[i][0]);
      compress.push_back(a[i][1]);
   }
   sort(all(compress));
   compress.resize(unique(all(compress)) - compress.begin());  
   
   SegmentTree st(sz(compress));
   
   for (int i = 0; i < n; ++i) {
      int a_r = lower_bound(all(compress), a[i][1]) - compress.begin();
      int x = st.get(1, 0, sz(compress) - 1, a_r, a_r);
      if (x == INF) st.update(1, 0, sz(compress) - 1, a_r, a[i][0]);
      else st.update(1, 0, sz(compress) - 1, a_r, min(x, a[i][0]));
   }

   for (int i = 0; i < n; ++i) {
      color_segment[a[i][2]].push_back({ a[i][0], a[i][1], i });
   }
   vector<int> res(n, INF);
   for (auto [color, segments] : color_segment) {
      for (auto &s : segments) {
         if (colors_l.find({ s[0], s[1], color }) != colors_l.end()) {
            colors_l.erase({ s[0], s[1], color });
         }
         if (colors_r.find({ s[1], s[0], color }) != colors_r.end()) {
            colors_r.erase({ s[1], s[0], color });
         }
         int a_r = lower_bound(all(compress), s[1]) - compress.begin();
         st.update(1, 0, sz(compress) - 1, a_r, INF);
      }
      for (auto &[l, r, id] : segments) {
         auto itr = colors_l.lower_bound({ l, -1, color });
         auto itl = colors_r.lower_bound({ l, -1, color });
         dbg(l, r, color, itr->at(2), itl->at(2));
         if (itr != colors_l.end()) {
            dbg('1', itr->at(0), itr->at(1));
            res[id] = min(res[id], max({0ll, (*itr)[0] - r, l - (*itr)[1]}));
         }
         if (itl != colors_r.end()) {
            dbg('2', itl->at(0), itl->at(1));
            res[id] = min(res[id], max({0ll, l - (*itl)[0], (*itl)[1] - r}));
         }
         if (itr != colors_l.begin() && !colors_l.empty()) {
            --itr;
            dbg('3', itr->at(0), itr->at(1));
            res[id] = min(res[id], max({0ll, l - (*itr)[1], (*itr)[0] - r}));
         }
         if (itl != colors_r.begin() && !colors_r.empty()) {
            --itl;
            dbg('4', itl->at(0), itl->at(1));
            res[id] = min(res[id], max({0ll, (*itl)[1] - r, l - (*itl)[0]}));
         }
         int a_l = lower_bound(all(compress), l) - compress.begin();
         res[id] = min(res[id], max(0ll, st.get(1, 0, sz(compress) - 1, a_l, sz(compress) - 1) - r));
      }
      for (auto &c : segments) {
         colors_l.insert({ c[0], c[1], color });
         colors_r.insert({ c[1], c[0], color });
         int a_r = lower_bound(all(compress), c[1]) - compress.begin();
         st.update(1, 0, sz(compress) - 1, a_r, c[0]);
      }
   }
   for (auto &c : res) cout << c << ' ';
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}