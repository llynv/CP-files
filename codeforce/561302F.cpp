
/*
  Code by: linvg
  Created: 25.10.2024 21:48:02
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
const int MOD = 998244353;

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>((1 << 2), 0)));
   for (int msk = 0; msk < (1 << 2); ++msk) {
      int cnt = __builtin_popcount(msk);
      if (cnt > k) continue;
      dp[1][cnt][msk] = 1;
   }
   for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
         for (int msk = 1; msk < (1 << 2); ++msk) {
            for (int submsk = 1; submsk < (1 << 2); ++submsk) {
               int cnt = __builtin_popcount(submsk);
               if (j >= cnt) {
                  dp[i][j][msk] += dp[i - 1][j - cnt][submsk];
                  dp[i][j][msk] %= MOD;
               }
            }
         }
      }
   }
   dbg(dp);
   cout << accumulate(all(dp[n][k - 1]), 0ll) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}