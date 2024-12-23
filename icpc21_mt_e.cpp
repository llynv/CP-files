/*
  Code by: linvg
  Created: 18.12.2024 14:40:54
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

struct Point {
   int64_t x, y; /// x*x or y*y should not overflow
   Point() {}
   Point(int64_t x, int64_t y) : x(x), y(y) {}
   inline bool operator < (const Point& p) const {
      return ((x < p.x) || (x == p.x && y < p.y));
   }
};
int64_t cross(const Point& O, const Point& A, const Point& B) {
   return ((A.x - O.x) * (B.y - O.y)) - ((A.y - O.y) * (B.x - O.x));
}
vector<Point> get_convex_hull(vector<Point> P) {
   int i, t, k = 0, n = P.size();
   vector<Point> H(n << 1);
   sort(P.begin(), P.end());
   for (i = 0; i < n; i++) {
      while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
   }
   for (i = n - 2, t = k + 1; i >= 0; i--) {
      while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0) k--;
      H[k++] = P[i];
   }
   H.resize(k - 1);
   return H;
}
/***
 *
 * Returns whether the polygon is convex or not
 * Points in P is given in clock-wise of anti-clockwise order
 *
***/
bool is_convex(vector <Point> P) {
   int n = P.size();
   if (n <= 2) return false; /// Line or point is not convex

   n++, P.push_back(P[0]);  /// Last point = first point
   bool flag1 = (cross(P[0], P[1], P[2]) > 0);
   for (int i = 1; (i + 1) < n; i++) {
      bool flag2 = (cross(P[i], P[i + 1], (i + 2) == n ? P[1] : P[i + 2]) > 0);
      if (flag1 ^ flag2) return false;
   }

   return true;
}

void solve()
{
   vector<Point> P(4);
   for (int i = 0; i < 4; ++i) {
      cin >> P[i].x >> P[i].y;
   }
   P = get_convex_hull(P);
   // for (auto& c : P) {
   //    cerr << c.x << ' ' << c.y << '\n';
   // }
   if (P.size() != 4) return void(cout << "NO\n");
   for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
         for (int k = 0; k < 4; ++k) {
            if (i == j || j == k || i == k) continue;
            if (cross(P[i], P[j], P[k]) == 0) {
               cout << "NO\n";
               return;
            }
         }
      }
   }
   cout << (P.size() == 4 ? "YES" : "NO") << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}