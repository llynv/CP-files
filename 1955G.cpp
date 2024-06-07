#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

const int dx[] = {0, 1};
const int dy[] = {1, 0};

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m));
      for (auto &c : a) for (auto &d : c) cin >> d;

      vector<vector<bool>> vst(n, vector<bool>(m, 0));
      vector<vector<int>> visit(n, vector<int>(m, 0));

      auto dfs = [&] (int x, int y, bool &isOk, auto&& dfs) {
         visit[x][y] = 1;
         if (x == n-1 && y == m-1) {
            isOk = 1;
            return;
         }
         for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && !visit[nx][ny] && ny < m && vst[nx][ny]) {
               dfs(nx, ny, isOk, dfs);
            }
         }
      };

      int _gcd = gcd(a[0][0], a[n-1][m-1]);
      vector<int> factors;
      for (int i = 1; i * i <= _gcd; ++i) {
         if (_gcd % i == 0) {
            factors.push_back(i);
            if (i * i != _gcd) factors.push_back(_gcd / i);
         }
      }
      sort(factors.begin(), factors.end(), greater<int>());
      int ans = 1;

      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

      for (auto &c : factors) {

         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               vst[i][j] = 0;
               visit[i][j] = 0;
               dp[i+1][j+1] = 0;
            }
         }

         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               if (a[i][j] % c == 0) vst[i][j] = 1;
            }
         }


         for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + vst[i-1][j-1];
            }
         }

         if (dp[n][m] == n + m - 1) {
            ans = c;
            break;
         }
      }

      cout << ans << '\n';
   }
}