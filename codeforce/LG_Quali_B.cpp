
/*
  Code by: linvg
  Created: 12.10.2024 08:31:44
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
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void solve()
{
   int R, C, N, r, c;
   cin >> R >> C >> N >> r >> c;
   --r, --c;
   vector<pair<int, int>> start(N);
   for (int i = 0; i < N; ++i) {
      cin >> start[i].first >> start[i].second;
      --start[i].first, --start[i].second;
   }
   vector<vector<char>> a(R, vector<char>(C, ' '));
   vector<pair<int, int>> walls;
   for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
         cin >> a[i][j];
         if (a[i][j] == 'W') {
            walls.push_back({ i, j });
         }
      }
   }

   vector<vector<int>> d_walls(R, vector<int>(C, INF));
   queue<pair<int, int>> q_walls;
   q_walls.push({r, c});
   d_walls[r][c] = 0;
   while (q_walls.size()) {
      auto [x, y] = q_walls.front();
      q_walls.pop();
      for (int i = 0; i < 4; ++i) {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
         if (a[nx][ny] != 'W' && d_walls[nx][ny] == INF) {
            d_walls[nx][ny] = d_walls[x][y] + 1;
            q_walls.push({ nx, ny });
         }
         if (a[nx][ny] == 'W') {
            d_walls[nx][ny] = min(d_walls[nx][ny], d_walls[x][y] + 1);
         } 
      }
   }

   vector<vector<vector<int>>> dist(N, vector<vector<int>>(R, vector<int>(C, INF)));
   for (int i = 0; i < N; ++i) {
      queue<pair<int, int>> q;
      q.push(start[i]);
      dist[i][start[i].first][start[i].second] = 0;
      while (q.size()) {
         pair<int, int> cur = q.front();
         int x = cur.first, y = cur.second;
         q.pop();
         for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (a[nx][ny] != 'W' && dist[i][nx][ny] == INF) {
               dist[i][nx][ny] = dist[i][x][y] + 1;
               q.push({ nx, ny });
            }
            if (a[nx][ny] == 'W') {
               dist[i][nx][ny] = min(dist[i][nx][ny], dist[i][x][y] + 1);
            }
         }
      }
   }

   int init = 0, final_s = 0;
   for (int i = 0; i < N; ++i) {
      init += dist[i][r][c];
   }
   for (int i = 0; i < sz(walls); ++i) {
      int new_s = 0;
      int x = walls[i].first, y = walls[i].second;
      for (int j = 0; j < N; ++j) {
         new_s += min(dist[j][x][y] + d_walls[x][y], dist[j][r][c]);
      }
      final_s += max(0ll, init - new_s);
   }
   cout << init << ' ' << final_s << '\n';  
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}