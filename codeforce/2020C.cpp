/*
  Code by: linvg
  Created: 29.09.2024 22:41:16
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
   int b, c, d;
   cin >> b >> c >> d;

   int res = 0, extra = 0;
   for (int i = 0; i < 62; ++i) {
      int b_id = (b >> i) & 1;
      int c_id = (c >> i) & 1;
      int d_id = (d >> i) & 1;
      if (b_id == 0 && c_id == 1 && d_id == 1) return void(cout << -1 << '\n');
      if (b_id == 0 && c_id == 0 && d_id == 1) {
         res |= (1LL << i);
      }
      if (b_id == 1 && c_id == 0 && d_id == 0) {
         res |= (1LL << i);
      }
      if (b_id == 1 && c_id == 1 && d_id == 0) {
         res |= (1LL << i);
      }
   }
   dbg(res);
   if ((res | b) - (res & c) != d) return void(cout << -1 << '\n');
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}