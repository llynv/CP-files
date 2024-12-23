/*
  Code by: linvg
  Created: 25.09.2024 22:49:49
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> x(n), y(m);
   for (int i = 0; i < n; ++i) cin >> x[i];
   for (int i = 0; i < m; ++i) cin >> y[i];
   sort(all(x));
   sort(all(y));
   unordered_map<int, vector<int>> x_p, y_p;
   vector<array<int, 2>> points(k), rev_points(k);
   for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      points[i] = { a, b };
      rev_points[i] = { b, a };
   }
   sort(all(points));
   sort(all(rev_points));
   for (int i = 0; i < k; ++i) {
      int a = points[i][0], b = points[i][1];
      x_p[a].push_back(b);
      y_p[b].push_back(a);
   }

   for (auto& [a, b] : x_p) {
      sort(all(b));
   }
   for (auto& [a, b] : y_p) {
      sort(all(b));
   }

   auto check_type = [&](int _x, int _y, int i) {
      int p = binary_search(all(x), _x);
      int q = binary_search(all(y), _y);
      if (p && q) return 1; // both x and y are present
      if (p) return 2; // only x is present
      return 3; // only y is present
      };

   int res = 0;

   for (int i = 0; i < k; ++i) {
      int type = check_type(points[i][0], points[i][1], i);
      if (type == 1) continue;
      if (type == 3) {
         int nxt = upper_bound(all(x), points[i][0]) - x.begin();
         int prv = lower_bound(all(x), points[i][0]) - x.begin() - 1;
         int line_nxt = x[nxt];
         int line_prv = x[prv];
         int p_nxt = lower_bound(all(points), array<int, 2>({ line_nxt, -1 })) - points.begin() - 1;
         int p_prv = upper_bound(all(points), array<int, 2>({ line_prv, INF })) - points.begin();

         int top_p = lower_bound(all(rev_points), array<int, 2>({ points[i][1], line_nxt })) - rev_points.begin() - 1;
         int bot_p = upper_bound(all(rev_points), array<int, 2>({ points[i][1], line_prv })) - rev_points.begin();

         res += p_nxt - p_prv - top_p + bot_p;
      }
      else {
         int nxt = upper_bound(all(y), points[i][1]) - y.begin();
         int prv = lower_bound(all(y), points[i][1]) - y.begin() - 1;
         int line_nxt = y[nxt];
         int line_prv = y[prv];
         int p_nxt = lower_bound(all(rev_points), array<int, 2>({ line_nxt, -1 })) - rev_points.begin() - 1;
         int p_prv = upper_bound(all(rev_points), array<int, 2>({ line_prv, INF })) - rev_points.begin();

         int top_p = lower_bound(all(points), array<int, 2>({ points[i][0], line_nxt })) - points.begin() - 1;
         int bot_p = upper_bound(all(points), array<int, 2>({ points[i][0], line_prv })) - points.begin();

         res += p_nxt - p_prv - top_p + bot_p;
      }
   }
   cout << res / 2 << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}