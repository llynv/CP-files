
/*
  Code by: linvg
  Created: 23.10.2024 20:56:21
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

struct Polygon {
   vector<pair<int, int>> points;
   Polygon() {}
   Polygon(vector<pair<int, int>> points) : points(points) {}
   double area() {
      double res = 0;
      for (int i = 0; i < sz(points); ++i) {
         int j = (i + 1) % sz(points);
         res += points[i].first * points[j].second - points[j].first * points[i].second;
      }
      return abs(res) / 2;
   }
   bool intersects(const Polygon& other) const {
      auto onSegment = [](pair<int, int> p, pair<int, int> q, pair<int, int> r) {
         return q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
                q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second);
      };

      auto orientation = [](pair<int, int> p, pair<int, int> q, pair<int, int> r) {
         int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
         if (val == 0) return 0; // collinear
         return (val > 0) ? 1 : 2; // clock or counterclock wise
      };

      auto doIntersect = [&](pair<int, int> p1, pair<int, int> q1, pair<int, int> p2, pair<int, int> q2) {
         int o1 = orientation(p1, q1, p2);
         int o2 = orientation(p1, q1, q2);
         int o3 = orientation(p2, q2, p1);
         int o4 = orientation(p2, q2, q1);

         if (o1 != o2 && o3 != o4) return true;

         if (o1 == 0 && onSegment(p1, p2, q1)) return true;
         if (o2 == 0 && onSegment(p1, q2, q1)) return true;
         if (o3 == 0 && onSegment(p2, p1, q2)) return true;
         if (o4 == 0 && onSegment(p2, q1, q2)) return true;

         return false;
      };

      for (int i = 0; i < sz(points); ++i) {
         for (int j = 0; j < sz(other.points); ++j) {
            int next_i = (i + 1) % sz(points);
            int next_j = (j + 1) % sz(other.points);
            if (doIntersect(points[i], points[next_i], other.points[j], other.points[next_j])) {
               return true;
            }
         }
      }
      return false;
   }
};

void solve()
{
   // [1, 2, 3, 4, 5]
   // 00000 -> 11111 : 0 -> 2^5 - 1
   // 00000 -> 00001 -> 00010 -> 00011
   // 2^i = (1 << i)
   // x <<= 1 <-> x *= 2
   // 2^x = (1 << x) = pow(2, x)
   // x / 2^i = (x >> i)
   // x * 2^i = (x << i)

   // kiểm tra bit thứ i của x có bằng 1 hay không
   // (x >> i) & 1

   int n = 5;
   vector<vector<int>> res;
   for (int mask = 0; mask < (1 << 5); ++mask) {
      vector<int> tmp;
      // 01111
      // 43210
      for (int j = 0; j < 5; ++j) {
         if (mask >> j & 1) {
            tmp.push_back(j + 1);   
         }
      }
      res.push_back(tmp);
   }
   for (auto v: res) cout << v << "\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}  