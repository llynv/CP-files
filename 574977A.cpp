/*
  Code by: linvg
  Created: 20.12.2024 18:20:57
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
   int n;
   cin >> n;
   vector<int> l(n), r(n), c(n);
   for (auto &x : l) cin >> x;
   for (auto &x : r) cin >> x;
   for (auto &x : c) cin >> x;
   sort(all(l));
   sort(all(r));
   sort(all(c));
   vector<pair<int, int>> res;
   for (int i = 0; i < n; ++i) {
      res.emplace_back(l[i], r[i]);
      assert(l[i] < r[i]);
   }
   sort(all(res), [&] (pair<int, int> a, pair<int, int> b) {
      return abs(a.first - a.second) >= abs(b.first - b.second);
   });
   dbg(res);
   int total = 0;
   for (int i = 0; i < n; ++i) {
      total += c[i] * (res[i].second - res[i].first);
   }
   cout << total << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}