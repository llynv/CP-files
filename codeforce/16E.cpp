/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

void solve()
{
   int n;
   cin >> n;
   vector<vector<double>> a(n, vector<double>(n));
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> a[i][j];

   vector<double> ans(n, 0);
   vector<double> dp(1 << n, 0);
   dp[(1 << n) - 1] = 1;
   for (int mask = (1 << n) - 1; mask > 0; --mask) {
      int cnt = __builtin_popcount(mask);
      for (int j = 0; j < n; ++j) {
         if (mask >> j & 1) {
            for (int i = j+1; i < n; ++i) {
               if (mask >> i & 1) {
                  double p = 2.0 / (cnt * (cnt - 1));
                  dp[mask ^ (1 << j)] += dp[mask] * a[i][j] * p;
                  dp[mask ^ (1 << i)] += dp[mask] * a[j][i] * p;
               }
            }
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      cout << fixed << setprecision(6) << dp[1 << i] << " ";
   }
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}