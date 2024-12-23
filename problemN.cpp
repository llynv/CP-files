/*
  Code by: linvg
  Created: 05.12.2024 17:14:24
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

void solve()
{
   string s1, s2;
   cin >> s1 >> s2;

   int h, m, a_h, a_m;
   h = m = a_h = a_m = 0;

   h = (s1[0] - '0') * 10 + s1[1];
   m = (s1[3] - '0') * 10 + s1[4];

   a_h = (s2[0] - '0') * 10 + s2[1];
   a_m = (s2[3] - '0') * 10 + s2[4];

   int diff = (a_h * 60 + a_m) - (h * 60 + m);

   int res = -1;
   if (diff == 0) {
      res = 0;
   } else if (diff > 0) {
      if (m == a_m) res = a_h - h;
      else if (m > a_m) res = (a_h - h - 1) + (60 - m + a_m);
      else res = (a_h - h) + (a_m - m);
   } else {
      if (m == a_m) res = (24 - h + a_h);
      else if (m > a_m) res = (24 - h + a_h - 1) + (60 - m + a_m);
      else res = (24 - h + a_h) + (a_m - m);
   }
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