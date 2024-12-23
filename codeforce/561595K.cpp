
/*
  Code by: linvg
  Created: 26.10.2024 18:04:38
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
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n, vector<char>(m));
   vector<vector<vector<int>>> pos(n, vector<vector<int>>(26));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
         pos[i][a[i][j] - 'a'].push_back(j);
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      int res = 0;
      for (int i = 0; i < 26; ++i) {
         if (pos[x][i].empty() || pos[y][i].empty()) continue;
         res += max(0ll, min(pos[x][i].back(), pos[y][i].back()) - max(pos[x][i].front(), pos[y][i].front()) + 1);
      }
      cout << res << '\n';
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