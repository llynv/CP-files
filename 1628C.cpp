
/*
  Code by: linvg
  Created: 05.11.2024 22:09:24
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
   int n;
   cin >> n;
   int up = n / 2;
   up += (up % 2 != 0);
   int down = n - up;
   vector<vector<int>> a(n, vector<int>(n));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
      }
   }
   // vector<vector<int>> grid(n + 2, vector<int>(n + 2));
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = 1; j <= n; ++j) {
   //       grid[i][j] = a[i - 1][j - 1];
   //    }
   // }
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = 1; j <= n; ++j) {
   //       a[i - 1][j - 1] = grid[i - 1][j] ^ grid[i][j - 1] ^ grid[i - 1][j - 1] ^ grid[i + 1][j + 1];
   //    }
   // }
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = 1; j <= n; ++j) {
   //       cerr << a[i - 1][j - 1] << " \n"[j == n];
   //    }
   // }
   int init = n;  
   int res = 0;
   for (int i = 0, step = (n % 4 == 0); step < n / 2; i += 2, ++step) {
      for (int j = step; j < n - i - 1; j += 4) {
         dbg(i, j);
         res ^= a[i][j] ^ a[i][j + 1];
      }
   }
   for (int j = 0; j < down; j += 2) {
      for (int i = j + (n % 4 == 0) + 1; i < n - j - 1; i += 4) {
         dbg(i, j);
         res ^= a[i][j] ^ a[i + 1][j];
         res ^= a[i][n - j - 1] ^ a[i + 1][n - j - 1];
      }
   }
   for (int i = n - 1, step = (n % 4 != 0 ? 2 : 3); i >= up; i -= 2, ++step) {
      for (int j = step; j < n - step - 1; j += 4) {
         dbg(i, j);
         res ^= a[i][j] ^ a[i][j + 1];
      }  
   }
   dbg(res);
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}