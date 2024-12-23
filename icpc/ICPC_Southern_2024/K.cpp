
/*
  Code by: linvg
  Created: 13.10.2024 10:03:18
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void solve()
{
   int n, p, m;
   cin >> n >> p >> m;
   vector<array<int, 3>> pac(p);
   for (int i = 0; i < p; ++i) {
      cin >> pac[i][0] >> pac[i][1] >> pac[i][2];
      pac[i][2]--;
   }
   int dist = 0;
   int dir_rotate = 0;
   pair<int, int> init = { 0, 0 };
   bool is_reset = false;
   vector<vector<pair<int, int>>> extra(4);
   for (int i = 0; i < m; ++i) {
      char c;
      cin >> c;
      if (c == 'A') {
         int k;
         cin >> k;
         dist += k;
      }
      else if (c == 'R') {
         int k;
         cin >> k;
         for (int i = 0; i < 4; ++i) extra[i].push_back({ (i + dir_rotate) % 4, dist });
         dist = 0;
         dir_rotate += k;
      }
      else {
         int k;
         cin >> k;
         dist = 0;
         is_reset = true;
         for (int i = 0; i < 4; ++i) extra[i].clear();
         for (int i = 0; i < 4; ++i) extra[i].push_back({ (i + dir_rotate) % 4, dist });
         init = { k / n, k % n };
      }
   }
   if (dist != 0) for (int i = 0; i < 4; ++i) extra[i].push_back({ (i + dir_rotate) % 4, dist });
   if (is_reset) {
      for (auto& [x, y, z] : pac) {
         x = init.first;
         y = init.second;
      }
   }
   for (int i = 0; i < 4; ++i) {
      vector<int> dir_dist(4);
      int nx = 0, ny = 0;
      for (auto [dir, dist] : extra[i]) {
         dir = (dir + 4) % 4;
         nx += dx[dir] * dist;
         ny += dy[dir] * dist;
      }
      for (auto& [x, y, z] : pac) {
         if (z != i) continue;
         int nnx = nx % n, nny = ny % n;
         if (x + nnx < 0) {
            x = n - abs(x + nnx) % n;
         } else if (x + nnx >= n) {
            x = (x + nnx) % n;
         } else {
            x += nnx;
         }
         if (y + nny < 0) {
            y = n - abs(y + nny) % n;
         } else if (y + nny >= n) {
            y = (y + nny) % n;
         } else {
            y += nny;
         }
      }
   }

   for (int i = 0; i < p; ++i) {
      cout << pac[i][0] << ' ' << pac[i][1] << '\n';
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