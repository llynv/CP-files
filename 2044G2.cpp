/*
  Code by: linvg
  Created: 15.12.2024 22:22:38
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
const int N = 2e5 + 7;

vector<int> adj[N];
vector<vector<int>> cycles;
int vis[N], par[N];

void dfs_cycle(int u, int p, vector<int>& path) {
   vis[u] = 1;
   par[u] = p;
   path.push_back(u);
   for (auto v : adj[u]) {
      if (vis[v] == 0) {
         dfs_cycle(v, u, path);
      }
      else if (vis[v] == 1) {
         vector<int> cycle;
         int cur = u;
         while (cur != v) {
            cycle.push_back(cur);
            cur = par[cur];
         }
         cycle.push_back(v);
         cycles.push_back(cycle);
      }
   }
   vis[u] = 2;
   path.pop_back();
}

void solve()
{
   int n;
   cin >> n;
   vector<int> child(n + 1);
   vector<vector<int>> par(n + 1);
   for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      child[i] = x;
      par[x].push_back(i);
      adj[i].clear();
      adj[i].push_back(x);
      vis[i] = 0;
   }
   cycles.clear();
   
   for (int i = 1; i <= n; ++i) {
      if (vis[i] == 0) {
         vector<int> path;
         dfs_cycle(i, -1, path);
      }
   }
   
   vector<int> is_cycle(n + 1, 0), vst(n + 1), amount(n + 1, 1), date(n + 1, 1);
   for (auto& cycle : cycles) {
      for (auto& c : cycle) {
         is_cycle[c] = 1;
      }
   }
   
   auto dfs = [&] (int u, auto&& dfs) -> void { 
      vst[u] = 1;
      int mxD = 0;
      amount[u] = 1;
      for (auto v : par[u]) {
         if (is_cycle[v]) continue;
         if (!vst[v]) {
            dfs(v, dfs);
            amount[u] += amount[v];
         }
         mxD = max(mxD, amount[v]);
      }
      date[u] += mxD;
   };
 
   for (int i = 1; i <= n; ++i) {
      if (is_cycle[child[i]] && !vst[child[i]]) {
         dfs(child[i], dfs);
      }
   }
   cout << *max_element(all(date)) + 1 << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}