/*
  Code by: linvg
  Created: 25.11.2024 23:03:46
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
   int x, m;
   cin >> x >> m;
   int res = 0;
   for (int i = 1; i < min(m + 1, x); ++i) {
      res += ((x ^ i) % i == 0);
   }
   int last_bit = 62;
   int y = 0;
   while (last_bit >= 0) {
      if ((y | (1ll << last_bit)) <= m && !(x >> last_bit & 1)) {
         y |= 1ll << last_bit;
      }
      last_bit--;
   }
   y ^= x;
   unordered_map<int, bool> mp;
   for (int i = y; i > m; --i) {
      if ((x ^ i) % x == 0 || ((x ^ i) > m && i % x == 0)) {
         if ((x ^ i) > m) mp[i] = 1;
         else if ((x ^ i) % x == 0) mp[x ^ i] = 1;
      }
   }
   for (auto [i, v] : mp) res -= i % x == 0;
   cout << res + y / x << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}