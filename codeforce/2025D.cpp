
/*
  Code by: linvg
  Created: 14.10.2024 22:05:51
*/

#include <bits/stdc++.h>
using namespace std;

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
   int n, m;
   cin >> n >> m;
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) cin >> a[i];
   vector<int> dp_s(m + 1, 0), dp_i(m + 1, 0);
   int inc = 0;
   vector<int> new_i = dp_i, new_s = dp_s;
   for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) {
         inc++;
      }
      else if (a[i] < 0) {
         if (inc >= abs(a[i])) {
            dp_s[abs(a[i])] ++;
            for (int l = 1; l <= abs(a[i]); ++l) {
               dp_s[l] += dp_s[l - 1];
            }
         }
      } else {
         if (inc >= a[i]) {
            dp_i[a[i]]++;
            for (int l = 1; l <= inc; ++l) {
               dp_i[l] += dp_i[l - 1];
            }
         }
      }
      new_i = dp_i;
      new_s = dp_s;
   }
   dbg(dp_s);
   dbg(dp_i);
   int res = 0;
   for (int i = 0; i <= m; ++i) {
      res = max(res, dp_s[i] + dp_i[m - i]);
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}