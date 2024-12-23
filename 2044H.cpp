/*
  Code by: linvg
  Created: 15.12.2024 22:59:39
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
   int n, q;
   cin >> n >> q;
   vector<vector<int>> a(n + 1, vector<int>(n + 1)), pref(n + 2, vector<int>(n + 2));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
         cin >> a[i][j];
      }
   }
   for (int i = n; i >= 1; --i) {
      for (int j = n; j >= 1; --j) {
         pref[i][j] = a[i][j] + pref[i][j + 1];
      }
   }
   for (int _ = 0; _ < q; ++_) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      int res = 0;
      cout << res << ' ';
   }
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