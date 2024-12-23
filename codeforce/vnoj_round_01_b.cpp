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

#define DBG

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 311;

struct Graph {
   int e, w;
};

vector<int> vis(N);
vector<Graph> g[N];

bitset<N> db;

void dfs2 (int u, int target, bitset<N> wei) {

   if (u == target) {
      // dbg(wei);
      db = wei;
      return;
   }
   vis[u] = 1;
   for (auto &c : g[u]) {
      if (!vis[c.e]) {
         wei[c.w] = 1;
         dfs2(c.e, target, wei);
         wei[c.w] = 0;
      }
   }
}

void solve()
{
   int n;
   cin >> n;
   rep (i, 0, n-1) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
   }

   int res = 0;
   for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
         vis.clear();
         bitset<N> d;
         db.reset();
         dfs2(i, j, d);
         res += db.count();
      }
   }
   cout << res << '\n';
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}