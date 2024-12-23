
/*
  Code by: linvg
  Created: 20.10.2024 10:10:39
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{
   int n, k, s;
   cin >> n >> k >> s;
   vector<vector<int>> a(n, vector<int>(n));
   for (auto &c : a) for (auto &u : c) cin >> u;
   dbg(a); 
   vector<vector<vector<vector<int>>>> st(8, vector<vector<vector<int>>>(8, vector<vector<int>>(n, vector<int>(n))));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         st[0][0][i][j] = a[i][j];
      }
   }
   for (int i = 1; i <= 7; ++i) {
      for (int j = 0; j < n; ++j) {
         for (int k = 0; k < n; ++k) {
            st[0][i][j][k] = st[0][i - 1][j][k];
            if (j + (1 << (i - 1)) < n) {
               st[0][i][j][k] = max(st[0][i][j][k], st[0][i - 1][j + (1 << (i - 1))][k]);
            }
            if (k + (1 << (i - 1)) < n) {
               st[0][i][j][k] = max(st[0][i][j][k], st[0][i - 1][j][k + (1 << (i - 1))]);
            }
            if (j + (1 << (i - 1)) < n && k + (1 << (i - 1)) < n) {
               st[0][i][j][k] = max(st[0][i][j][k], st[0][i - 1][j + (1 << (i - 1))][k + (1 << (i - 1))]);
            }
         }
      }
   }
   auto get_max = [&] (int x, int y, int u, int v) -> int {
      int len = log2(u - x + 1);
      int res = st[0][len][x][y];
      res = max(res, st[0][len][u - (1 << len) + 1][y]);
      res = max(res, st[0][len][x][v - (1 << len) + 1]);
      res = max(res, st[0][len][u - (1 << len) + 1][v - (1 << len) + 1]);
      return res;
   };

   vector<vector<int>> res;
   for (int i = 0; i + k <= n; i += s) {
      vector<int> tmp;
      for (int j = 0; j + k <= n; j += s) {
         tmp.push_back(get_max(i, j, i + k - 1, j + k - 1));
      }
      res.push_back(tmp);
   }
   // dbg(res);
   for (auto &c : res) {
      for (auto &u : c) cout << u << ' ';
      cout << '\n';
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