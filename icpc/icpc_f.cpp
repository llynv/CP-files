
/*
  Code by: linvg
  Created: 29.10.2024 15:41:27
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("O3")

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

void solve()
{
   int n;
   scanf("%lld", &n);
   vector<Point> P(n);
   for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &P[i].x, &P[i].y);  
   }
   int m;
   scanf("%lld", &m);
   vector<Point> polygon = get_convex_hull(P);
   int res = 0, side, d;
   for (int i = 0; i < m; ++i) {
      int64_t a, b, c;
      scanf("%lld %lld %lld", &a, &b, &c);
      side = a * polygon[0].x + b * polygon[0].y + c > 0;
      for (int j = 0; j < sz(polygon); ++j) {
         d = a * polygon[j].x + b * polygon[j].y + c;
         if (side != (d > 0) || d == 0) {
            side = -1;
            break;
         }
      }
      res += (side != -1);
   }
   printf("%lld\n", res);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   scanf("%lld", &t);
   while (t--)
      solve();
   return 0;
}