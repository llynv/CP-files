
/*
  Code by: linvg
  Created: 20.10.2024 08:37:42
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

struct Triangle {
   long double x1, y1, x2, y2, x3, y3;
   Triangle() {}
   Triangle(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3) : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
   bool isInside(long double x, long double y) {
      long double A = 0.5 * (-y2 * x3 + y1 * (-x2 + x3) + x1 * (y2 - y3) + x2 * y3);
      long double sign = A < 0 ? -1 : 1;
      long double s = (y1 * x3 - x1 * y3 + (y3 - y1) * x + (x1 - x3) * y) * sign;
      long double t = (x1 * y2 - y1 * x2 + (y1 - y2) * x + (x2 - x1) * y) * sign;
      return s > 0 && t > 0 && (s + t) < 2 * A * sign;
   }
   bool isInLine(long double x, long double y) {
      return (x - x1) * (y2 - y1) == (y - y1) * (x2 - x1) || (x - x2) * (y3 - y2) == (y - y2) * (x3 - x2) || (x - x3) * (y1 - y3) == (y - y3) * (x1 - x3);
   }
};


void solve()
{
   long double x1, y1, x2, y2, x3, y3;
   cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
   long double xx1, yy1, xx2, yy2, xx3, yy3;
   cin >> xx1 >> yy1 >> xx2 >> yy2 >> xx3 >> yy3;
   Triangle t(x1, y1, x2, y2, x3, y3);
   if (t.isInside(xx1, yy1) || t.isInside(xx2, yy2) || t.isInside(xx3, yy3) || t.isInLine(xx1, yy1) || t.isInLine(xx2, yy2) || t.isInLine(xx3, yy3)) {
      cout << "YES\n";
   } else {
      cout << "NO\n";
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