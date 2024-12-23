/*
  Code by: linvg
  Created: 30.11.2024 21:46:26
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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

pair<int, int> move(int x, int y, char dir) {
   if (dir == 'U') return {x - 1, y};
   if (dir == 'D') return {x + 1, y};
   if (dir == 'L') return {x, y - 1};
   if (dir == 'R') return {x, y + 1};
   return {x, y};
}

pair<int, int> rev_move (int x, int y, char dir) {
   if (dir == 'U') return {x + 1, y};
   if (dir == 'D') return {x - 1, y};
   if (dir == 'L') return {x, y + 1};
   if (dir == 'R') return {x, y - 1};
   return {x, y};
}

const int N = 1011;
char a[N][N];
int is_free[N][N];
bool vst[N][N];

void solve()
{
   int n, m;
   cin >> n >> m;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         is_free[i][j] = -1;
         vst[i][j] = false;
      }
   }  
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (!vst[i][j] && is_free[i][j] == -1 && a[i][j] != '?') {
            int x = i, y = j;
            while (x >= 0 && x < n && y >= 0 && y < m && !vst[x][y]) {
               vst[x][y] = 1;
               if (a[x][y] == '?') {
                  is_free[x][y] = 0;
                  int u = i, v = j;
                  while (u != x || v != y) {
                     is_free[u][v] = 0;
                     auto [nx, ny] = move(u, v, a[u][v]);
                     u = nx, v = ny;
                  }
                  break;
               }
               if (is_free[x][y] != -1) {
                  int u = i, v = j;
                  while (u != x || v != y) {
                     is_free[u][v] = is_free[x][y];
                     auto [nx, ny] = move(u, v, a[u][v]);
                     u = nx, v = ny;
                  }
                  break;
               }
               auto [nx, ny] = move(x, y, a[x][y]);
               if (nx < 0 || nx >= n || ny < 0 || ny >= m || vst[nx][ny]) {
                  if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                     is_free[x][y] = 1;
                  } else {
                     is_free[x][y] = (is_free[nx][ny] == -1 ? 0 : is_free[nx][ny]);
                  }
                  int u = i, v = j;
                  while (u != x || v != y) {
                     is_free[u][v] = is_free[x][y];
                     auto [nx, ny] = move(u, v, a[u][v]);
                     u = nx, v = ny;
                  }
                  break;
               }
               x = nx, y = ny;
            }
         }
      }
   }
   int res = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (is_free[i][j] == -1) {
            for (int d = 0; d < 4; ++d) {
               int nx = i + dx[d], ny = j + dy[d];
               if (nx >= 0 && nx < n && ny >= 0 && ny < m && (is_free[nx][ny] == 0 || a[nx][ny] == '?')) {
                  is_free[i][j] = 0;
                  break;
               }
            }
         }
         res += is_free[i][j] == 0;
         // cerr << is_free[i][j] << " \n"[j == m - 1];
      }
   }
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