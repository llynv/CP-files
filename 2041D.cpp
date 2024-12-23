

/*
  Code by: linvg
  Created: 24.11.2024 15:02:19
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

struct Data
{
   int x, y;
   int cost;
   int dir, t;
};

bool cmp (const Data& a, const Data& b) {
   if (a.cost == b.cost) return a.t > b.t;
   return a.cost > b.cost;
}

struct Hash {
   size_t operator()(const array<int, 10>& a) const {
      size_t res = 0;
      for (int i = 0; i < 10; ++i) {
         res ^= a[i] + 0x9e3779b9 + (res << 6) + (res >> 2);
      }
      return res;
   }
   size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
   }
   size_t operator()(const array<int, 4>& a) const {
      size_t res = 0;
      for (int i = 0; i < 4; ++i) {
         res ^= a[i] + 0x9e3779b9 + (res << 6) + (res >> 2);
      }
      return res;
   }
};

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n, vector<char>(m));
   pair<int, int> S,T;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         if (a[i][j] == 'S') S = {i, j};
         else if (a[i][j] == 'T') T = {i, j};
      }
   }
   unordered_map<array<int, 4>, int, Hash> dist;
   priority_queue<Data, vector<Data>, decltype(&cmp)> q(cmp);
   q.push({S.first, S.second, 0, 0, 0});
   dist[{S.first, S.second, 0}] = 0;
   int res = 1e18;
   while (!q.empty()) {
      auto c = q.top();
      q.pop();
      int x = c.x, y = c.y, d = c.cost, pt = c.t, dir = c.dir;
      if (d > dist[{x, y, pt, dir}]) continue;
      if (x == T.first && y == T.second) {
         res = min(res, d);
         continue;
      } 
      for (int k = 0; k < 4; ++k) {
         int nx = x + dx[k];
         int ny = y + dy[k];
         int t = (dir == k ? pt : 0) + 1, ex = 0;
         if (t > 3) {
            if (k < 2 && ((x > 0 && a[x - 1][y] != '#') || (x < n - 1 && a[x + 1][y] != '#'))) t = 1;
            else if (k >= 2 && ((y > 0 && a[x][y - 1] != '#') || (y < m - 1 && a[x][y + 1] != '#'))) t = 1; 
            else t = 2;
            ex = 2;
         }
         if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#') {
            if (dist.count({nx, ny, t, k}) == 0 || dist[{nx, ny, t, k}] > d + 1 + ex) {
               dist[{nx, ny, t, k}] = d + 1 + ex;
               q.push({nx, ny, dist[{nx, ny, t, k}], k, t});
            }
         }
      }
   }
   cout << (res == 1e18 ? -1 : res) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}