#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

void solve() {
   string a, b, c;
   cin >> a >> b >> c;
   int n = a.size();
   int m = b.size();
   a.insert(a.begin(), ' ');
   b.insert(b.begin(), ' ');
   c.insert(c.begin(), ' ');
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
   dp[0][0] = 0;
   dp[1][0] = dp[0][1] = 1;
   if (a[1] == c[1]) dp[1][0] = 0;
   if (b[1] == c[1]) dp[0][1] = 0;
   for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
         if (i == j && j == 0) continue;
         if (i == 0) {
            dp[i][j] = dp[i][j - 1] + (c[i + j] != b[j]);
            continue;
         }
         if (j == 0) {
            dp[i][j] = dp[i - 1][j] + (c[i + j] != a[i]);
            continue;
         }
         if (c[i + j] == a[i] && c[i + j] == b[j]) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
         }
         if (c[i + j] == a[i] && c[i + j] != b[j]) {
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j]);
         }
         if (c[i + j] == b[j] && c[i + j] != a[i]) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + 1);
         }
         if (c[i + j] != b[j] && c[i + j] != a[i]) {
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
         }
         // cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
      }
   }
   cout << dp[n][m] << '\n';
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}