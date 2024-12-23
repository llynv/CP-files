/*
  Code by: linvg
  Created: 15.12.2024 21:59:19
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
   int k, l1, r1, l2, r2;
   cin >> k >> l1 >> r1 >> l2 >> r2;

   int res = 0;
   for (int exp = 1; exp <= 1e9; exp *= k) {
      int l = l1, r = r1, top = 0, bot = 0;
      while (l <= r) {
         int mid = (l + r) >> 1;
         if (mid * exp > r2) {
            r = mid - 1;
            continue;
         }
         if (mid * exp < l2) {
            l = mid + 1;
            continue;
         }
         l = mid + 1;
         top = mid;
      }
      l = l1, r = r1;
      while (l <= r) {
         int mid = (l + r) >> 1;
         if (mid * exp > r2) {
            r = mid - 1;
            continue;
         }
         if (mid * exp < l2) {
            l = mid + 1;
            continue;
         }
         r = mid - 1;
         bot = mid;
      }
      if (top && bot) {
         res += (top - bot + 1);
      }
   }
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