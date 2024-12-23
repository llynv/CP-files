
/*
  Code by: linvg
  Created: 20.10.2024 01:20:04
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
   int n = 6, m = 7;
   vector<vector<char>> a(n, vector<char>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<vector<char>> grid(n + 6, vector<char>(m + 6, '0'));

   auto simulate = [&](int turn, int games, vector<array<int, 2>> valid_moves, auto&& simulate, int nxt = 0) -> int {
      if (turn == games) {
         for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
               cerr << grid[i][j] << ' ';
            }
            cerr << '\n';
         }
         cerr << '\n';
         return 0;
      }
      int res = 0;
      for (auto [i, j] : valid_moves) {
         if (grid[i][j] == '0') {
            grid[i][j] = a[i][j];
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j] && grid[i][j] != '0') {
               if (grid[i][j] == 'C') {
                  res = 1;
               }
               else {
                  res = 2;
               }
            }
            if (grid[i][j] == grid[i + 1][j + 1] && grid[i][j] == grid[i + 2][j + 2] && grid[i][j] == grid[i + 3][j + 3] && grid[i][j] != '0') {
               if (grid[i][j] == 'C') {
                  res = 1;
               }
               else {
                  res = 2;
               }
            }
            if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3] && grid[i][j] != '0') {
               if (grid[i][j] == 'C') {
                  res = 1;
               }
               else {
                  res = 2;
               }
            }
            if (j >= 3 && grid[i][j] == grid[i + 1][j - 1] && grid[i][j] == grid[i + 2][j - 2] && grid[i][j] == grid[i + 3][j - 3] && grid[i][j] != '0') {
               if (grid[i][j] == 'C') {
                  res = 1;
               }
               else {
                  res = 2;
               }
            }
            if (j >= 3 && grid[i][j] == grid[i][j - 1] && grid[i][j] == grid[i][j - 2] && grid[i][j] == grid[i][j - 3] && grid[i][j] != '0') {
               if (grid[i][j] == 'C') {
                  res = 1;
               }
               else {
                  res = 2;
               }
            }
            if (res) {
               grid[i][j] = '0';
               return res;
            }
            if (i != 0) {
               valid_moves.push_back({i - 1, j});
            }
            res |= simulate(turn + 1, games, valid_moves, simulate, i + 1);
            grid[i][j] = '0';
            if (i != 0) {
               valid_moves.pop_back();
            }
            break;
         }
      }
      return res;
   };

   int l = 0, r = n * m, ans = 0;
   while (l <= r) {
      int mid = (l + r) / 2;
      grid.assign(n + 6, vector<char>(m + 6, '0'));
      vector<array<int, 2>> valid_moves;
      for (int i = 0; i < m; ++i) {
         valid_moves.push_back({n - 1, i});
      }
      if (simulate(0, mid, valid_moves, simulate)) {
         ans = mid;
         r = mid - 1;
      }
      else {
         l = mid + 1;
      }
   }
   vector<array<int, 2>> valid_moves;
   for (int i = 0; i < m; ++i) {
      valid_moves.push_back({n - 1, i});
   }
   grid.assign(n, vector<char>(m, '0'));
   int res = simulate(0, ans, valid_moves, simulate);
   cout << (res == 3 ? "?\n" : (res == 0 ? "0\n" : (res == 1 ? "C\n" : "F\n")));
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}