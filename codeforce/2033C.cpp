
/*
  Code by: linvg
  Created: 24.10.2024 21:46:31
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

const int INF = 1e18;
const int MOD = 1e9 + 7;


void solve() {
   int n;
   cin >> n;
   vector<int> a(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   vector<vector<int>> dp(n + 1, vector<int>(2, INF));
   dp[1][0] = dp[1][1] = 0;
   for (int i = 2; i <= (n) / 2; ++i) {
      int u = (a[i] == a[i - 1]) + (a[n - i + 1] == a[n - i + 2]);
      int v = (a[i] == a[n - i + 2]) + (a[n - i + 1] == a[i - 1]);
      dp[i][0] = min({ dp[i - 1][0] + u, dp[i - 1][1] + v });
      dp[i][1] = min({ dp[i - 1][0] + v, dp[i - 1][1] + u });
      // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
   }
   int bonus = 0;
   if (n % 2 == 0) {
      bonus = (a[n / 2] == a[(n) / 2 + 1]);
   }
   else {
      bonus = (a[(n + 1) / 2] == a[n / 2]) + (a[(n + 1) / 2] == a[(n + 1) / 2 + 1]);
   }
   cout << min(dp[(n) / 2][0], dp[(n) / 2][1]) + bonus << '\n';
}

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}