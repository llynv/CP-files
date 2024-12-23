/*
  Code by: linvg
  Created: 18.12.2024 15:16:59
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
typedef long double fType;

const fType EPS = 1e-9;
const fType PI = 2 * acos(0);

struct Point {
   fType x, y;

   Point() {}
   Point(fType x, fType y) : x(x), y(y) {}

   fType get_dis(const Point& other) {
      fType d1 = x - other.x, d2 = y - other.y;
      return sqrt(d1 * d1 + d2 * d2);
   }
};

struct Circle {
   Point centre;
   fType radius;

   Circle() {}
   Circle(Point centre, fType radius) : centre(centre), radius(radius) {}

   fType get_area() {
      return PI * radius * radius;
   }
};

/// Returns true if circle B is inside of circle A
bool is_inside(Circle A, Circle B) {
   fType x = A.centre.get_dis(B.centre) + B.radius;
   return (abs(x - A.radius) < EPS) || (x < A.radius);
}

fType intersection_area(Circle A, Circle B) {
   if (is_inside(A, B)) return B.get_area();
   if (is_inside(B, A)) return A.get_area();

   fType x = A.radius + B.radius;
   fType y = A.centre.get_dis(B.centre);
   if ((abs(x - y) < EPS) || (y > x)) return 0;

   fType c = y, r0 = A.radius, r1 = B.radius;
   x = (r1 * r1 - r0 * r0 + c * c) / (2 * r1 * c);
   fType CBD = acos(x) * 2;
   y = (r0 * r0 - r1 * r1 + c * c) / (2 * r0 * c);
   fType CAD = acos(y) * 2;

   fType res = CBD * r1 * r1 - r1 * r1 * sin(CBD) + CAD * r0 * r0 - r0 * r0 * sin(CAD);
   return 0.5 * res;
}

void solve()
{
   Circle C;
   Point A, B;
   cin >> A.x >> A.y >> B.x >> B.y >> C.centre.x >> C.centre.y >> C.radius;
   double k;
   cin >> k;
   fType d = A.get_dis(B);
   fType h = C.radius * C.radius - (d / 2) * (d / 2);
   fType dist_to_line = abs((A.y - B.y) * C.centre.x - (A.x - B.x) * C.centre.y + A.x * B.y - A.y * B.x) / d;
   dbg(dist_to_line);
   h = abs(h);
   dbg(d, h);
   if (dist_to_line == 0) {
      cout << (50 - k <= 5 ? "YES" : "NO") << endl;
      return;
   }
   if (dist_to_line - C.radius >= EPS) {
      cout << "NO" << endl;
      return;
   }
   h = sqrtf(h);
   dbg(C.radius, h, d, d / 2.0 / C.radius);

   // d / 2.0 / C.radius could be greater than 1 or less than -1
   // acos() is not defined for values greater than 1 or less than -1
   // so we need to clamp the value between -1 and 1
   d = min(d / 2.0 / C.radius, fType(1));
   d = max(d, -fType(-1));

   fType theta = 2 * acos(d);
   dbg(theta);
   fType segment_area = 0.5 * C.radius * C.radius * (theta - sin(theta));
   fType triangle_area = 0.5 * d * h;
   dbg(segment_area);
   fType area = min(segment_area, C.get_area() - segment_area);
   double percent = area / C.get_area() * 100;
   dbg(area, percent);
   dbg(percent, k);
   cout << (abs(percent - k) <= 5 + EPS ? "YES" : "NO") << endl;
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}