
/*
  Code by: linvg
  Created: 15.10.2024 17:28:36
*/

#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 1e9 + 7;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n + 1, vector<char>(m + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(4, 0)));
   int res = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         int cnt = 0;   
         if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1]) {
            dp[i][j][0] = min({dp[i - 1][j][0], dp[i][j - 1][0]}) + 1;
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = m - 1; j >= 1; --j) {
         int cnt = 0;
         if (a[i][j] == a[i - 1][j] && a[i][j] == a[i][j + 1]) {
            dp[i][j][1] = min({dp[i - 1][j][1], dp[i][j + 1][1]}) + 1;
         }
      }
   }
   for (int i = n - 1; i >= 1; --i) {
      for (int j = 1; j <= m; ++j) {
         int cnt = 0;
         if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j - 1]) {
            dp[i][j][2] = min({dp[i + 1][j][2], dp[i][j - 1][2]}) + 1;
         }
      }
   }
   for (int i = n - 1; i >= 1; --i) {
      for (int j = m - 1; j >= 1; --j) {
         int cnt = 0;
         if (a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1]) {
            dp[i][j][3] = min({dp[i + 1][j][3], dp[i][j + 1][3]}) + 1;
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         res += *min_element(all(dp[i][j])) + 1;
      }
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   clock_t start = clock();
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   cerr << fixed << setprecision(6) << "Time: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << " s.\n";
   return 0;
}