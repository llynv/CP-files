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

vector<int> adj[N];
int f[N][20], d[N];

void dfs(int u, int p) {
   f[u][0] = p;
   for (int i = 1; i < 20; ++i) {
      f[u][i] = f[f[u][i - 1]][i - 1];
   }
   for (int v : adj[u]) {
      if (v == p) continue;
      d[v] = d[u] + 1;
      dfs(v, u);
   }
}

int lca(int u, int v) {
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
}

int dist(int u, int v) {
   return d[u] + d[v] - 2 * d[lca(u, v)];
}


void solve()
{
   int n, t;
   cin >> n >> t;

   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   int x;
   cin >> x;

   dfs(1, 1);

   queue<ii> q;
   q.push({x, x});

   vector<vector<int>> corAdj(n+1);
   vector<int> vst(n+1);
   vst[x] = 1;
   while (!q.empty())
   {
      auto [u, cor] = q.front();
      q.pop();

      for (int v : adj[u]) {
         if (vst[v]) continue;
         vst[v] = 1;
         if (adj[v].size() != 2) {
            q.push({v, v});
            dbg(u, v, cor);
            corAdj[cor].push_back(v);
            corAdj[v].push_back(cor);
         }
         else q.push({v, cor});
      }
   }
   
   for (int i = 1; i <= n; ++i) {
      sort(all(corAdj[i]));
      corAdj[i].erase(unique(all(corAdj[i])), corAdj[i].end());
   }

   auto cmp = [&] (tuple<int, int, int> a, tuple<int, int, int> b) -> bool {
      return get<2>(b) % 2 == 0;
   };

   priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q2(cmp);
   vector<int> dd(n+1, INF);
   dd[x] = 0;
   q2.push({x, 0, 0});
   while (!q2.empty())
   {
      auto [u, choice, di] = q2.top();
      q2.pop();

      dbg(u, choice, di);

      if (sz(corAdj[u]) == 1 && choice == 0 && dd[u] % 2 == 1) {
         cout << "Ron\n";
         return;
      }
         
      for (int v : corAdj[u]) {
         if (dd[v] == INF) {
            dd[v] = dist(u, v) + dd[u];
            if (dist(u, v) % 2 != 0) q2.push({v, choice ^ (sz(adj[v]) != 1), dist(u, v)}); 
            else q2.push({v, choice, dist(u, v)});
         }
      }
   }

   cout << "Hermione\n";
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