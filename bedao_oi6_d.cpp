



/*
  Code by: linvg
  Created: 28.11.2024 21:59:28
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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (int i = 0; i < n; ++i) cin >> a[i];
   vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
   int mn = INF, mx = -INF;
   for (int i = 1; i <= n; ++i) {
      mx = max(mx, a[i - 1]);
      mn = min(mn, a[i - 1]);
      dp[i][1] = mx + mn;
      for (int j = 2; j <= k; ++j) {
         mx = -INF, mn = INF;
         for (int l = i - 1; l >= 0; --l) {
            mx = max(mx, a[l]);
            mn = min(mn, a[l]);
            dp[i][j] = max(dp[i][j], dp[l][j - 1] + mx + mn);
         }
      }
   }
   dbg(dp);
   cout << dp[n][k] << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}