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
const int N = 2e5 + 7;

vector<int> adj[N];
int child[N], vst[N];
stack<int> topo;

void dfs (int u) {
   static int cnt = 0;
   vst[u] = 1;
   for (int v : adj[u]) {
      if (!vst[v]) dfs(v);
   }

   topo.push(u);
}

void reset(int n) {
   rep(i, 1, n+1) {
      adj[i].clear();
      vst[i] = 0;
   }
}

void solve()
{
   int n, m;
   cin >> n >> m;
   reset(n);

   vector<vector<int>> a(m, vector<int>(n));
   for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
         if (j > 1) {
            adj[a[i][j-1]].push_back(a[i][j]);
         }
      }
   }

   if (m == 1) return void (cout << "YES\n");

   for (int i = 1; i <= n; ++i) {
      if (!vst[i]) dfs(i);
   }

   int cnt = 0;
   vector<int> b;
   while (!topo.empty()) {
      int u = topo.top();
      topo.pop();
      b.push_back(u);
   }
   
   for (int i = 0; i < m; ++i) {
      int j = 0, k = 1;
      while (k < n && j < n) {
         if (b[j] == a[i][0]) {
            ++j;
            continue;
         }
         if (a[i][k] != b[j]) {
            // dbg(a);
            // dbg(b);
            return void (cout << "NO\n");
         }
         ++j;
         ++k;
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