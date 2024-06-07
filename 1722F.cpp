/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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

vector<vector<vector<int>>> check[3] = {
   {
      {{0, 0}, {0, 1}, {1, 1}},
      {{0, 0}, {-1, 0}, {-1, 1}},
      {{0, 0}, {0, -1}, {-1, -1}},
      {{0, 0}, {1, 0}, {1, -1}}
   },
   {
      {{0, 0}, {0, 1}, {-1, 1}},
      {{0, 0}, {1, 0}, {1, 1}},
      {{0, 0}, {0, -1}, {1, -1}},
      {{0, 0}, {-1, 0}, {-1, -1}},
   },
   {
      {{0, 0}, {-1, 0}, {0, 1}},
      {{0, 0}, {1, 0}, {0, -1}},
      {{0, 0}, {-1, 0}, {0, -1}},
      {{0, 0}, {1, 0}, {0, 1}}
   }, 
};

vector<vector<int>> corner = {
   {1, 1},
   {1, -1},
   {-1, 1},
   {-1, -1}
};

const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void solve()
{
   dbg("END\n");


   int n, m;
   cin >> n >> m;
   vector<vector<int>> vst(n, vector<int>(m, 0));

   vector<vector<char>> a(n, vector<char>(m));
   rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];


   auto dfs = [&](int x, int y, int &cnt, auto&& dfs) {
      if (x < 0 || x >= n || y < 0 || y >= m || vst[x][y] || a[x][y] != '*') return;
      vst[x][y] = 1;
      ++cnt;
      for (int i = 0; i < 8; ++i) {
         dfs(x + dx[i], y + dy[i], cnt, dfs);
      }
   };

   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         if (a[i][j] != '*') continue;

         dbg(i, j, a[i][j]);
         int ok = 0;

         
         int res = 0;
         dfs(i, j, res, dfs);
         dbg(res);
         fill(all(vst), vector<int>(m, 0));
         if (res != 3) return void(cout << "NO\n");

         for (int state = 0; state < 3; ++state) {
            for (int k = 0; k < 4; ++k) {
               int cnt = 0;
               for (int l = 0; l < 3; ++l) {
                  int x = i + check[state][k][l][0];
                  int y = j + check[state][k][l][1];
                  if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*') {
                     cnt++;
                  }
               }
               ok += (cnt == 3);
            }
         }

         if (ok > 1 || ok == 0) dbg(i, j, ok);
         if (ok > 1 || ok == 0) return void(cout << "NO\n");
      }
   }
   cout << "YES\n";
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}