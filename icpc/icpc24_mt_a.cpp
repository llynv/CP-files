/*
  Code by: linvg
  Created: 22.10.2024 14:50:21
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
   int n, w, h;
   cin >> n >> w >> h;
   vector<array<int, 2>> a(n);
   int maxV = 0;
   for (auto& c : a) cin >> c[0] >> c[1], maxV += c[1];
   int res = 0;
   vector<int> dp(maxV + 1, INF);
   dp[0] = 0;
   for (int k = 1; k <= n; ++k) {
      for (int j = maxV; j >= 1; --j) {
         if (j - a[k - 1][1] >= 0 && dp[j - a[k - 1][1]] + a[k - 1][0] <= w) {
            dp[j] = min(dp[j], dp[j - a[k - 1][1]] + a[k - 1][0]);
            res = max(res, j);
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      if (a[i][0] > h) continue;
      dp.assign(maxV + 1, INF);
      dp[0] = 0;
      int mx = 0;
      for (int k = 1; k <= n; ++k) {
         if (k == i + 1) continue;
         for (int j = maxV; j >= 1; --j) {
            if (j - a[k - 1][1] >= 0 && dp[j - a[k - 1][1]] + a[k - 1][0] <= w) {
               dp[j] = min(dp[j], dp[j - a[k - 1][1]] + a[k - 1][0]);
               mx = max(mx, j);
            }
         }
      }
      res = max(res, mx + a[i][1]);
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
