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
const int N = 2e5 + 7;

void solve()
{
   int n, m;
   cin >> n >> m;
   
   unordered_map<int, int> mark;
   int start = -1;
   for (int i=  0; i < m; ++i) {
      int x;
      cin >> x;
      start = x;
      mark[x] = 1;
   }

   vector<vector<int>> adj(n+1);

   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
   }

   vector<int> vst(n+1, 0);
   int start2 = -1, curDist = 0;
   auto dfs = [&] (int u, int dist, auto&& dfs) {
      if (mark[u]) {
         if (dist >= curDist) {
            curDist = dist;
            start2 = u;
         }
      }
      if (vst[u]) return;
      vst[u] = 1;
      for (auto& v : adj[u]) {
         if (vst[v] == 0) {
            dfs(v, dist + 1, dfs);
         }
      }
   };

   dfs(1, 0, dfs);

   fill(all(vst), 0);
   curDist = 0;
   int prev = start2;
   dfs(start2, 0, dfs);

      // int f[N][20], d[N];
   vector<vector<int>> f(n+1, vector<int>(20));
   vector<int> d(n+1);

   function<void(int, int)> dfs2 = [&] (int u, int p) {
      f[u][0] = p;
      for (int i = 1; i < 20; ++i) {
         f[u][i] = f[f[u][i - 1]][i - 1];
      }
      for (int v : adj[u]) {
         if (v == p) continue;
         d[v] = d[u] + 1;
         dfs2(v, u);
      }
   };

   function<int(int, int)> lca = [&] (int u, int v) {
      if (d[u] < d[v]) swap(u, v);
      for (int i = 19; i >= 0; --i) {
         if (d[f[u][i]] >= d[v]) u = f[u][i];
      }
      if (u == v) return u;
      for (int i = 19; i >= 0; --i) {
         if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
         }
      }
      return f[u][0];
   };

   auto dist = [&] (int u, int v) {
      return d[u] + d[v] - 2 * d[lca(u, v)];
   };

   dfs2(start2, start2);

   int res = INF;
   for (int i = 1; i <= n; ++i) {
      res = min(res, max(dist(i, start2), dist(i, prev)));
   }
   cout << res << '\n';
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