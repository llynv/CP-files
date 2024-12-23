/*
  Code by: linvg
  Created: 09.12.2024 17:18:24
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
   int n, m, k, s;
   cin >> n >> m >> k >> s;
   vector<double> a(n + m + 1);
   for (int i = 1; i <= n + m; ++i) cin >> a[i];
   sort(all(a));
   vector<vector<double>> dp(n + m + 1, vector<double>(k + 1, 1e18));
   double sum = 0.0;
   cout << fixed << setprecision(9);
   for (int i = 1; i <= n + m; ++i) {
      sum += a[i];
      double avg = sum / i;
      double best = 0.0;
      for (int j = 1; j <= i; ++j) best += sqr(a[j] - avg); 
      dp[i][1] = best;
      double sumr = 0.0;
      for (int j = i; j >= 1; --j) {
         sumr += a[j];
         avg = sumr / (i - j + 1);
         double sub = 0.0;
         for (int q = j; q <= i; ++q) sub += sqr(a[q] - avg);
         for (int l = 2; l <= k; ++l) {
            dp[i][l] = min(dp[i][l], dp[j - 1][l - 1] + sub);
         }
      }
   }
   cout << dp[n + m][k] + (n + m) * sqr(1.0 * s / 2.0) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}