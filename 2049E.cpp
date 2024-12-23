/*
  Code by: linvg
  Created: 20.12.2024 22:43:20
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
   int i_pos = 0;

   map<pair<int, int>, int> cache;

   int query = 0;
   
   auto ask = [&] (int l, int r) -> int {
      if (cache.count({l, r})) return cache[{l, r}];
      assert(query <= 36);
      query++;
      cout << "? " << l << ' ' << r << "\n";
      cout.flush();
      int res;
      cin >> res;
      cache[{l, r}] = res;
      return res;
   };

   int l = 1, r = n;
   while (l <= r) {
      int m = (l + r) >> 1;
      int len = n - m + 1;
      int res = ask(m, m + len / 2 - (len % 2 == 0)) + ask(m + len / 2, n);
      if (len % 2 != 0 && res == 0) res += ask(m + len / 2 - (len % 2 == 0), m + len / 2 - (len % 2 == 0));
      if (res == 0) {
         r = m - 1;
      } else {
         l = m + 1;
         i_pos = m;
      }
   }

   int mnLen = n, mxLen = 1;
   for (auto &[pp, sum] : cache) {
      auto [l, r] = pp;
      if (l <= i_pos && i_pos <= r) {
         if (sum == 0) mnLen = min(mnLen, r - l + 1); 
         else mxLen = max(mxLen, r - l + 1);
      }
   }

   dbg(i_pos);
   l = mxLen, r = mnLen;
   int len = 0;
   while (l <= r) {
      int m = (l + r) >> 1;
      int res = 0;
      if (m >= i_pos) res = ask(1, m);
      else {
         int xl = i_pos, xr = i_pos + m - 1;
         int offset = max(0ll, xr - n);
         xl -= offset;
         xr -= offset;
         res = ask(xl, xr);
      } 
      if (res == 0) {
         r = m - 1;
         len = m;
      } else {
         l = m + 1;
      }  
   }
   cout << "! " << len << '\n';
   cout.flush();
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}