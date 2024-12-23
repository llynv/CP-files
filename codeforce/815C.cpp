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
   int n, d;
   cin >> n >> d;
   vector<array<int, 3>> a(n);

   vector<vector<int>> adj(n + 1);
   rep(i, 0, n) {
      if (i == 0) {
         cin >> a[i][0] >> a[i][1];
         a[i][2] = 0;
         continue;
      }
      cin >> a[i][0] >> a[i][1] >> a[i][2];
      adj[a[i][2]].push_back(i+1);
   }

   vector<vector<int>> dp(n + 1, vector<int>(2, INF));
   dp[0][0] = 0;
   dp[0][1] = 0;
   dp[1][0] = a[0][0];
   dp[1][1] = a[0][1];

   vector<int> pref(n + 1, 0);

   auto calc = [&] (int u, auto&& calc) -> void {
      pref[u] += a[u - 1][0] - a[u - 1][1];
      for (auto v : adj[u]) {
         calc(v, calc);
         pref[v] += pref[u];
      }
   };

   calc(1, calc);

   dbg(pref);

   auto dfs = [&](int u, int depth, int sum, auto&& dfs) -> void { 
      sum += a[u - 1][0] - a[u - 1][1];
      dbg(u, depth, sum);
      for (int i = depth; i <= n; ++i) {
         if (dp[i - depth][1] + sum <= d) {
            dp[i][1] = min(dp[i][1], dp[i - depth][1] + sum);
         }
      }
      for (auto v : adj[u]) {
         dfs(v, depth + 1, sum, dfs);
      }
      sum -= a[u - 1][0] - a[u - 1][1];
   };

   dfs(1, 1, 0, dfs);

   dbg(dp);
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