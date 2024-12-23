

/*
  Code by: linvg
  Created: 26.11.2024 18:22:38
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

int calc(int x, int y, int z, int k) {
   int t[4] = {x, y, z, k};
   sort(t, t + 4);
   return max((t[3] - t[0]) * (t[2] - t[1]), (t[3] - t[1]) * (t[2] - t[0]));
}

array<int, 8> points (int x, int y, int z, int k) {
   int t[4] = {x, y, z, k};
   sort(t, t + 4);
   int area1 = (t[3] - t[0]) * (t[2] - t[1]);
   int area2 = (t[3] - t[1]) * (t[2] - t[0]);
   // return {t[3], t[1], t[3], t[2], t[0], t[1], t[0], t[2]};
   if (area1 > area2) return {t[3], t[1], t[3], t[2], t[0], t[1], t[0], t[2]};
   return {t[0], t[1], t[0], t[3], t[2], t[3], t[2], t[1]};
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   map<int, int> cnt;
   for (auto& c : a) {
      cin >> c;
      cnt[c]++;
   }
   int area = -1;
   int cnt2 = 0, cnt4 = 0, cnt6 = 0, cnt8 = 0;
   for (auto [u, v] : cnt) cnt2 += (v >= 2), cnt4 += (v >= 4), cnt6 += (v >= 6), cnt8 += (v >= 8);
   if (cnt2 < 4 && cnt4 < 2 && (cnt6 < 1 || cnt2 < 1) && cnt8 < 1) return void(cout << "NO\n");
   vector<int> tw, tr, ts, te;
   for (auto [u, v] : cnt) {
      if (v >= 2) tw.push_back(u);
      if (v >= 4) tr.push_back(u);
      if (v >= 6) ts.push_back(u);
      if (v >= 8) te.push_back(u);
   }
   array<int, 8> ans;
   sort(all(tw));
   sort(all(tr));
   sort(all(ts));
   sort(all(te));

   if (sz(tw) >= 4) {
      if (area < calc(tw[0], tw[1], tw[sz(tw) - 2], tw[sz(tw) - 1])) {
         ans = points(tw[0], tw[1], tw[sz(tw) - 2], tw[sz(tw) - 1]);
         area = calc(tw[0], tw[1], tw[sz(tw) - 2], tw[sz(tw) - 1]);
      }
   }
   if (sz(tr) >= 2) {
      if (area < calc(tw[0], tw[0], tw.back(), tw.back())) {
         ans = points(tw[0], tw[0], tw.back(), tw.back());
         area < calc(tw[0], tw[0], tw.back(), tw.back());
      }
   }
   if (sz(ts) >= 1 && sz(tw) >= 1) {
      if (area < calc(ts[0], ts[0], ts[0], tw.back())) {
         ans = points(ts[0], ts[0], ts[0], tw.back());
         area = calc(ts[0], ts[0], ts[0], tw.back());
      }
      if (area < calc(ts.back(), ts.back(), ts.back(), tw[0])) {
         ans = points(ts.back(), ts.back(), ts.back(), tw[0]);
         area = calc(ts.back(), ts.back(), ts.back(), tw[0]);
      }
   }
   if (sz(te) >= 1) {
      if (area < calc(te[0], te[0], te[0], te[0])) {
         ans = points(te[0], te[0], te[0], te[0]);
         area = calc(te[0], te[0], te[0], te[0]);
      }
      if (area < calc(te.back(), te.back(), te.back(), te.back())) {
         ans = points(te.back(), te.back(), te.back(), te.back());
         area = calc(te.back(), te.back(), te.back(), te.back());
      }
   }
   if (area == -1) return void (cout << "NO\n");
   // dbg(a);
   cout << "YES\n";
   for (int i = 0; i < 8; ++i) cout << ans[i] << ' ';
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