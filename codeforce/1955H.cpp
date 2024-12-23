/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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

const int maxR = 12;

struct Tower
{
   int x, y, damage;
};

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<char>> a(n, vector<char>(m));
   vector<ii> path;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         if (a[i][j] == '#') {
            path.push_back({i, j});
         }
      }
   }

   vector<int> p3(16);
   p3[0] = 1;
   for (int i = 1; i < 16; ++i) {
      p3[i] = p3[i-1] * 3;
   }

   vector<Tower> towers(k);
   for (int i = 0; i < k; ++i) {
      cin >> towers[i].x >> towers[i].y >> towers[i].damage;
      --towers[i].x, --towers[i].y;
   }

   vector<vector<int>> dp(towers.size()+1, vector<int>(1 << maxR));
   
   for (int id = 1; id <= towers.size(); ++id) {
      dp[id] = dp[id-1];
      for (int i = 0; i < maxR; ++i) {
         if (i != 0) {
            auto c = towers[id - 1];
            int tmp = 0, cnt = 0;
            for (auto &d : path) {
               int x = d.fi, y = d.se;
               if (sqr(x - c.x) + sqr(y - c.y) <= sqr(i)) {
                  tmp += c.damage;
               }
            }
            for (int mask = 0; mask < (1 << maxR); ++mask) {
               if (mask >> i & 1) continue;
               for (int j = 1; j < maxR; ++j) {
                  dp[id][mask | (1 << i)] = max(dp[id][mask | (1 << i)], dp[id-1][mask] + tmp - p3[i]);
               }
            }
         }
      }
   }

   int res = 0;
   for (int i = 0; i < (1 << maxR); ++i) {
      res = max(res, dp[sz(towers)][i]);
   }
   cout << res << '\n';

   // cout << *max_element(all(dp[sz(towers)])) << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}