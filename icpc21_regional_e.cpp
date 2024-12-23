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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

string rep(char c, int cnt) {
   string s;
   for (int i = 0; i < cnt; ++i) s += c;
   return s;
}

void print(vector<pair<pair<int, int>, char>> a) {
   for (auto [u, v] : a) {
      cout << u.first << ' ' << u.second << ' ' << v << '\n';
   }
}

char dir(int x, int y, int nx, int ny) {
   if (nx > x) return 'D';
   if (nx < x) return 'U';
   if (ny > y) return 'R';
   return 'L';
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
};

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n, vector<char>(m));
   for (auto& c : a) for (auto& d : c) cin >> d;
   vector<pair<pair<int, int>, char>> ans;
   vector<vector<bool>> vst(n, vector<bool>(m));
   vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, { -1, -1 }));

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (a[i][j] != '#' && !vst[i][j]) {
            vector<pair<int, int>> path;
            queue<pair<int, int>> q;
            q.push({ i, j });
            path.emplace_back(i, j);
            vst[i][j] = 1;
            while (!q.empty()) {
               auto [x, y] = q.front();
               q.pop();
               for (int d = 0; d < 4; ++d) {
                  int nx = x + dx[d], ny = y + dy[d];
                  if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#' || vst[nx][ny] == 1) continue;
                  vst[nx][ny] = 1;
                  parent[nx][ny] = { x, y };
                  path.emplace_back(nx, ny);
                  q.push({ nx, ny });
               }
            }
            while (path.size() > 1) {
               auto [x, y] = path.back();
               path.pop_back();
               if (a[x][y] != 'X') continue; 
               auto [px, py] = parent[x][y];
               a[px][py] = (a[px][py] == 'X' ? '.' : 'X');
               a[x][y] = (a[x][y] == 'X' ? '.' : 'X');
               ans.push_back({ {x + 1, y + 1}, dir(x, y, px, py) });
            }
            if (a[i][j] == 'X') return void(cout << -1 << '\n');
         }
      }
   }
   cout << sz(ans) << '\n';
   print(ans);
}

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}
