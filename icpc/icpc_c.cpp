/*
Code by: linvg
Created: 27.10.2024 09:53:42
*/

#include <bits/stdc++.h>
using namespace std;


#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("O3")

#define int long long


const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e6 + 7;

int mp[N];

void solve() {
   int n, m, k;
   scanf("%lld %lld %lld", &n, &m, &k);
   vector<vector<int>> dp(n + 1, vector<int>(m + 1));
   fill(mp, mp + N, INF);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m;j++) {
         int x;
         scanf("%lld", &x);
         dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + x;
      }
   }
   int ans = 0;
   if (n <= m) {
      vector<int> tmp;
      for (int i = 1; i <= n; ++i) {
         for (int j = 0; j < i; ++j) {
            tmp.clear();
            mp[0] = 0;
            if (ans > dp[i][m] - dp[j][m]) break;
            for (int u = 0; u <= m; u++) {
               int col1 = i, col2 = j, row = u;
               int rem = (dp[col1][row] - dp[col2][row] + k) % k;
               int val = (dp[col1][row] - dp[col2][row]);
               if (mp[rem] != INF) {
                  ans = max(ans, val - mp[rem]);
               }
               else {
                  mp[rem] = val;
                  tmp.push_back(rem);
               }
            }
            for (auto x : tmp) {
               mp[x] = INF;
            }
         }
      }
   }
   else {
      vector<int> tmp;
      for (int i = 1; i <= m; ++i) {
         for (int j = 0; j < i; ++j) {
            tmp.clear();
            mp[0] = 0;
            if (ans > dp[n][i] - dp[n][j]) break;
            for (int u = 0; u <= n; u++) {
               int row1 = i, row2 = j, col = u;
               int rem = (dp[col][row1] - dp[col][row2] + k) % k;
               int val = (dp[col][row1] - dp[col][row2]);
               if (mp[rem] != INF) {
                  ans = max(ans, val - mp[rem]);
               }
               else {
                  mp[rem] = val;
                  tmp.push_back(rem);
               }
            }
            for (auto x : tmp) {
               mp[x] = INF;
            }
         }
      }

   }
   printf("%lld\n", ans);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}
