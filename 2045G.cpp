/*
  Code by: linvg
  Created: 03.12.2024 00:20:29
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
   int n, m, x;
   cin >> n >> m >> x;
   vector<vector<char>> a(n + 1, vector<char>(m + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cin >> a[i][j];
      }
   }

   auto calc = [](char a, char b, char c, char d, int exp) {
      int x = a - '0';
      int y = b - '0';
      int z = c - '0';
      int w = d - '0';
      return pow(y - x, exp) + pow(z - y, exp) + pow(w - z, exp) + pow(x - w, exp);
      };

   bool invalid = false;
   for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
         int k = calc(a[i][j], a[i][j + 1], a[i + 1][j + 1], a[i + 1][j], x);
         if (k != 0) {
            invalid = true;
            break;
         }
      }
   }

   vector<vector<vector<int>>> grid(2, vector<vector<int>>(n + 1, vector<int>(m + 1)));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         if (j > 1) grid[0][i][j] = pow((a[i][j - 1] - '0') - (a[i][j] - '0'), x) + grid[0][i][j - 1];
         if (i > 1) grid[1][i][j] = pow((a[i - 1][j] - '0') - (a[i][j] - '0'), x) + grid[1][i - 1][j];
      }
   }

   int q;
   cin >> q;
   while (q--) {
      int u, v, x, y;
      cin >> x >> y >> u >> v;
      if (invalid) {
         cout << "INVALID\n";
         continue;
      }
      int sumRow = 0, sumCol = 0;
      sumRow = grid[1][u][y] - grid[1][x][y];
      sumCol = grid[0][u][v] - grid[0][u][y];
      cout << sumRow + sumCol << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}