
/*
  Code by: linvg
  Created: 04.10.2024 22:15:23
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
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int cur = 1;
   vector<int> pref(n + 2, 1), suf(n + 2, 1);
   for (int i = 2; i <= n; ++i) {
      pref[i] = (a[i - 1] > a[i - 2] ? pref[i - 1] + 1 : 1);
      suf[n - i + 1] = (a[n - i] < a[n - i + 1] ? suf[n - i + 2] + 1 : 1);
   }
   dbg(pref);
   dbg(suf);
   int ans = *max_element(all(pref));
   for (int i = 2; i <= n - 1; ++i) {
      if (a[i] - a[i - 2] > 1) {
         ans = max(ans, pref[i - 1] + suf[i + 1] + 1);
      }
   }
   for (int i = 2; i <= n; ++i) ans = max(ans, pref[i - 1] + 1);
   for (int i = 1; i < n; ++i) ans = max(ans, suf[i + 1] + 1);
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}