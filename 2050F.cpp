/*
  Code by: linvg
  Created: 05.12.2024 21:56:14
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
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   vector<int> new_a(n);
   for (int i = 1; i < n; ++i) new_a[i] = abs(a[i] - a[i - 1]);

   vector<vector<int>> f(20, vector<int>(n + 1));
   for (int i = 1; i <= n; ++i) f[0][i] = new_a[i];
   for (int i = 1; i < 20; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
         f[i][j] = gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
      }
   }

   auto get = [&](int l, int r) {
      int len = r - l + 1;
      int k = 31 - __builtin_clz(len);
      return gcd(f[k][l], f[k][r - (1 << k) + 1]);
      };

   while (q--) {
      int l, r;
      cin >> l >> r;
      if (l == r) { cout << 0 << ' '; continue; }
      cout << get(l, r - 1) << ' ';
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