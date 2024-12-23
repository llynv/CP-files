/*
  Code by: linvg
  Created: 01.12.2024 13:01:12
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

tuple<int, int, char> move(int x, int y, char dir, char mirror) {
   if (mirror == '/') {
      if (dir == 'D') {
         return { x, y - 1, 'L' };
      }
      else if (dir == 'U') {
         return { x, y + 1, 'R' };
      }
      else if (dir == 'R') {
         return { x - 1, y, 'U' };
      }
      else {
         return { x + 1, y, 'D' };
      }
   }
   else if (mirror == '\\') {
      if (dir == 'D') {
         return { x, y + 1, 'R' };
      }
      else if (dir == 'U') {
         return { x, y - 1, 'L' };
      }
      else if (dir == 'R') {
         return { x + 1, y, 'D' };
      }
      else {
         return { x - 1, y, 'U' };
      }
   }
   else {
      if (dir == 'R') return { x, y + 1, dir };
      else if (dir == 'L') return { x, y - 1, dir };
      else if (dir == 'U') return { x - 1, y, dir };
      else return { x + 1, y, dir };
   }
}

unordered_map<char, int> dirIdx;

void solve()
{
   dirIdx['D'] = 0, dirIdx['U'] = 1, dirIdx['R'] = 2, dirIdx['L'] = 3;

   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n + 2, vector<char>(m + 2));
   int total_mirror = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         cin >> a[i][j];
         total_mirror += a[i][j] != '.';
      }
   }

   auto is_valid = [](int x, int y, int n, int m) -> bool {
      return x >= 1 && x <= n && y >= 1 && y <= m;
      };

   vector<vector<int>> vst(n + 2, vector<int>(m + 2));
   vector<vector<vector<int>>> total_in_dir(n + 2, vector<vector<int>>(m + 2, vector<int>(4)));
   vector<pair<char, int>> res;
   dbg("Down");
   for (int j = 1; j <= m; ++j) {
      for (int i = 1; i <= n; ++i) {
         if (a[i][j] != '.' && total_in_dir[i][j][0] == 0) {
            int x = i, y = j;
            char idir = 'D';
            map<pair<int, int>, int> cnt;
            int last = 0;
            while (is_valid(x, y, n, m)) {
               dbg(x, y, idir, cnt);
               if (a[x][y] != '.') cnt[{x, y}] = 1;
               if (total_in_dir[x][y][dirIdx[idir]]) {
                  last += total_in_dir[x][y][dirIdx[idir]];
                  // dbg(x, y, idir, cnt, total_in_dir[x][y][dirIdx[idir]]);
                  break;
               }
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            x = i, y = j;
            idir = 'D';
            while (is_valid(x, y, n, m)) {
               if (total_in_dir[x][y][dirIdx[idir]]) break;
               total_in_dir[x][y][dirIdx[idir]] = last + cnt.size();
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            dbg(last + cnt.size());
            if (last + cnt.size() >= total_mirror) {
               res.push_back({'N', j});
            }
            break;
         }
      }
   }
   dbg("Up");
   for (int j = m; j >= 1; --j) {
      for (int i = n; i >= 1; --i) {
         if (a[i][j] != '.' && total_in_dir[i][j][1] == 0) {
            int x = i, y = j;
            char idir = 'U';
            map<pair<int, int>, int> cnt;
            int last = 0;
            while (is_valid(x, y, n, m)) {
               if (a[x][y] != '.') cnt[{x, y}] = 1;
               if (total_in_dir[x][y][dirIdx[idir]]) {
                  last += total_in_dir[x][y][dirIdx[idir]];
                  break;
               }
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            x = i, y = j;
            idir = 'U';
            while (is_valid(x, y, n, m)) {
               if (total_in_dir[x][y][dirIdx[idir]]) break;
               total_in_dir[x][y][dirIdx[idir]] = last + cnt.size();
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            if (last + cnt.size() >= total_mirror) {
               res.push_back({'S', j});
            }
            break;
         }
      }
   }
   dbg("Right");
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         if (a[i][j] != '.' && total_in_dir[i][j][2] == 0) {
            int x = i, y = j;
            char idir = 'R';
            map<pair<int, int>, int> cnt;
            int last = 0;
            while (is_valid(x, y, n, m)) {
               if (a[x][y] != '.') cnt[{x, y}] = 1;
               if (total_in_dir[x][y][dirIdx[idir]]) {
                  last += total_in_dir[x][y][dirIdx[idir]];
                  break;
               }
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            x = i, y = j;
            idir = 'R';
            while (is_valid(x, y, n, m)) {
               if (total_in_dir[x][y][dirIdx[idir]]) break;
               total_in_dir[x][y][dirIdx[idir]] = last + cnt.size();
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            if (last + cnt.size() >= total_mirror) {
               res.push_back({'W', i});
            }
            break;
         }
      }
   }
   dbg("Left");
   for (int i = n; i >= 1; --i) {
      for (int j = m; j >= 1; --j) {
         if (a[i][j] != '.' && total_in_dir[i][j][3] == 0) {
            int x = i, y = j;
            char idir = 'L';
            map<pair<int, int>, int> cnt;
            int last = 0;
            while (is_valid(x, y, n, m)) {
               if (a[x][y] != '.') cnt[{x, y}] = 1;
               if (total_in_dir[x][y][dirIdx[idir]]) {
                  last += total_in_dir[x][y][dirIdx[idir]];
                  break;
               }
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            x = i, y = j;
            idir = 'L';
            while (is_valid(x, y, n, m)) {
               if (total_in_dir[x][y][dirIdx[idir]]) break;
               total_in_dir[x][y][dirIdx[idir]] = last + cnt.size();
               auto [nx, ny, dir] = move(x, y, idir, a[x][y]);
               x = nx, y = ny;
               idir = dir;
            }
            if (last + cnt.size() >= total_mirror) {
               res.push_back({'E', i});
            }
            break;
         }
      }
   }
   dbg(res);
   cout << sz(res) << '\n';
   for (auto p : res) {
      cout << p.first << p.second << ' ';
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