/*
    Code by: KoKoDuDu
    Created: 22.10.2024 16:40:29
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;
void solve() {
   int r, c, n;
   cin >> r >> c >> n;
   vector<vector<int>> a(r + 1, vector<int>(c + 1));
   vector<vector<int>> check(r + 1, vector<int>(c + 1));
   int cnt = 0;
   for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
         char t;
         cin >> t;
         if (t == '#') {
            a[i][j] = 2;
         }
         if (t == 'S') {
            a[i][j] = 1;
            check[i][j] = cnt;
            cnt++;
         }
      }
   }
   vector<vector<vector<bitset<15>>>> dp(r + 1, vector<vector<bitset<15>>>(c + 1, vector<bitset<15>>(INF)));
   queue<array<int, 4>>que;
   que.push({ 1,1,0,0, });
   int ans = INF;
   int dx[] = { 0,0,-1,1 };
   int dy[] = { 1,-1,0,0 };
   // dp[1][1][0] = 0;
   while (!que.empty()) {
      auto state = que.front();
      int x = state[0], y = state[1], z = state[2], w = state[3];
      que.pop();
      // cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
      if (dp[x][y][z] <= w) {
         continue;
      }
      dp[x][y][z] = w;
      if (__builtin_popcount(z) == n) {
         ans = min(ans, dp[x][y][z]);
         continue;
      }
      for (int i = 0; i < 4; ++i) {
         int xx = x + dx[i];
         int yy = y + dy[i];
         if (1 <= xx && xx <= r && 1 <= yy && yy <= c && a[xx][yy] != 2) {
            int zz = z;
            if (a[xx][yy] == 1) {
               zz |= (1 << check[xx][yy]);
            }
            que.push({ xx,yy,zz,w + 1 });
         }
      }
   }
   if (ans == INF) {
      ans = -1;
   }
   cout << ans;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}