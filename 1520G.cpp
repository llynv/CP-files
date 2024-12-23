
/*
  Code by: linvg
  Created: 05.11.2024 17:08:06
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

const int INF = LONG_LONG_MAX;
const int MOD = 1e9 + 7;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve()
{
   int n, m, w;
   cin >> n >> m >> w;
   vector<vector<int>> a(n + 1, vector<int>(m + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cin >> a[i][j];
      }
   }
   vector<vector<int>> rev_d(n + 1, vector<int>(m + 1, -1));
   queue<pair<int, int>> q;
   q.push({n, m});
   int min_portal = INF;
   rev_d[n][m] = 0;
   if (a[n][m]) {
      min_portal = a[n][m];
   }
   while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && rev_d[nx][ny] == -1 && a[nx][ny] != -1) {
            rev_d[nx][ny] = rev_d[x][y] + w;
            if (a[nx][ny]) {
               min_portal = min(min_portal, rev_d[nx][ny] + a[nx][ny]);
            }
            q.push({nx, ny});
         }
      }
   }
   priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
   pq.push({0, 1, 1});  // {d, x, y}
   vector<vector<int>> d(n + 1, vector<int>(m + 1, INF));
   int res = INF;
   d[1][1] = 0;
   if (a[1][1] && min_portal != INF) {
      res = min(res, a[1][1] + min_portal);
   }
   while (!pq.empty()) {
      auto [dist, x, y] = pq.top();
      pq.pop();
      if (dist != d[x][y]) {
         continue;
      }
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != -1) {
            if (d[nx][ny] > d[x][y] + w) {
               d[nx][ny] = d[x][y] + w;
               if (a[nx][ny] && min_portal != INF) {
                  res = min(res, d[nx][ny] + a[nx][ny] + min_portal);
               }
               pq.push({d[nx][ny], nx, ny});
            }
         }
      }
   }
   cout << (min(res, d[n][m]) == INF ? -1 : min(res, d[n][m])) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}