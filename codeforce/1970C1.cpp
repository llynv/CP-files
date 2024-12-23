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

void solve()
{
   int n, t;
   cin >> n >> t;
   vector<vector<int>> adj(n+1);
   for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   int x;
   cin >> x;
   int leaf = -1;
   for (int i = 1; i <= n; ++i) {
      if (sz(adj[i]) == 1) {
         leaf = i;
         break;
      }
   }

   vector<int> vst(n+1);
   vector<int> path;
   auto dfs = [&] (int u, auto&& dfs) {
      if (vst[u]) return;
      vst[u] = 1;
      path.push_back(u);
      for (auto &v : adj[u]) {
         if (vst[v]) continue;
         dfs(v, dfs);
      }
   };
   dfs (leaf, dfs);
   for (int i = 1; i <= n; ++i) {
      if (path[i] == x) {
         if ((i - 1) % 2 == 0 || (n-i) % 2 == 0) return void (cout << ("Ron\n"));
         return void (cout << ("Hermione\n"));
      }
   }
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