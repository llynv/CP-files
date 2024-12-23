
/*
  Code by: linvg
  Created: 30.10.2024 21:30:59
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

struct rect {
   int x1, y1, x2, y2;
};

void solve()
{
   int n, l, r;
   cin >> n >> l >> r;

   vector<rect> a(n);

   int mx = 0, my = 0;

   for (int i = 0; i < n; ++i) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ++x2, ++y2;
      ++x1, ++y1;
      a[i] = {x1, y1, x2, y2};
      mx = max({mx, x1, x2});
      my = max({my, y1, y2});
   }

   vector<vector<int>> pref(mx + 1, vector<int>(my + 1));

   auto add = [&](int x1, int y1, int x2, int y2) {
      pref[x2][y2]++;
      pref[x1 - 1][y1 - 1]++;
      pref[x1 - 1][y2]--;
      pref[x2][y1 - 1]--;
   };

   for (int i = 0; i < n; ++i) {
      add(a[i].x1, a[i].y1, a[i].x2, a[i].y2);
   }

   for (int i = 1; i <= mx; ++i) {
      for (int j = 1; j <= my; ++j) {
         pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
      }
   }

   int res = 0;
   for (int i = 0; i <= mx; ++i) {
      for (int j = 0; j <= my; ++j) {
         if (pref[i][j] >= l && pref[i][j] <= r) {
            res++;
         }
      }
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   freopen("rect.inp", "r", stdin);
   freopen("rect.out", "w", stdout);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}