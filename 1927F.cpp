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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 5;

vector<int> adj[N], sloop;
int vs[N];
bool isCircle = false;

void dfs_cycle(int u, int p, int color[], int par[], vector<vector<int>>& cycles)
{
   if (color[u] == 2) {
      return;
   }

   if (color[u] == 1) {
      vector<int> v;

      int cur = p;
      v.push_back(cur);

      while (cur != u) {
         cur = par[cur];
         v.push_back(cur);
      }
      cycles.push_back(v);
      return;
   }
   par[u] = p;

   color[u] = 1;

   for (int v : adj[u]) {

      if (v == par[u]) {
         continue;
      }
      dfs_cycle(v, u, color, par, cycles);
   }

   color[u] = 2;
}

int par[N], color[N];

void solve()
{
   int n, m;
   cin >> n >> m;

   memset(par, -1, sizeof(par[0]) * (n + 1));
   memset(color, 0, sizeof(color[0]) * (n + 1));

   rep(i, 0, n+1) {
      adj[i].clear();
   }

   vector<vector<ii>> dist(n + 1);
   dbg("HIHI");


   vector<tuple<int, int, int>> edges(m);
   vector<int> cost(m);
   rep(i, 0, m) {
      int u, v, w;
      cin >> u >> v >> w;
      dist[u].push_back({ v, w });
      dist[v].push_back({ u, w });
      edges[i] = { u, v, w };
   }
   dbg("HIHI");


   rep(i, 1, n + 1) {
      sort(all(dist[i]));
   }


   dbg("dist");

   if (edges.size() > 1) {
      sort(all(edges), [&](auto a, auto b) {
         return get<2>(a) < get<2>(b);
         });
   }

   dbg("HIHI");

   for (auto c : edges) {
      int u, v, w;
      tie(u, v, w) = c;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<vector<int>> cycles;
   for (auto c : edges) {
      int u, v, w;
      tie(u, v, w) = c;
      if (color[u] == 0) {
         dfs_cycle(u, -1, color, par, cycles);
      }
   }

   int mn = INF, pos = 0;
   for (int i = 0; i < cycles.size(); ++i) {
      auto c = cycles[i];
      if (sz(c) > 2) {
         dbg(c);
         int cur = lower_bound(all(dist[c[0]]), ii{c.back(), -1LL}) - dist[c[0]].begin();
            cur = dist[c[0]][cur].se;
            for (int i = 1; i < sz(c); ++i) {
               int next = lower_bound(all(dist[c[i]]), ii{c[i - 1], -1LL}) - dist[c[i]].begin();
                  cur = min(cur, dist[c[i]][next].se);
            }
         if (cur < mn) {
            mn = cur;
            pos = i;
         }
      }
   }
 
   cout << mn << ' ' << sz(cycles[pos]) << '\n';
   for (auto c : cycles[pos]) {
      cout << c << ' ';
   }
   cout << '\n';
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