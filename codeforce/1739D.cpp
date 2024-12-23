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
   int n, k;
   cin >> n >> k;
   std::vector<vector<int>> adj(n+1);
   for (int i = 2; i <= n; ++i) {
      int x;
      cin >> x;
      adj[x].push_back(i);
   }

   vector<int> vst(n+1, 0), height;
   auto dfs = [&] (int u, int depth, auto&& dfs) -> void {
      if (vst[u]) return;
      height.push_back(depth);
      vst[u] = 1;
      for (auto &c : adj[u]) {
         if (vst[c]) continue;
         dfs(c, depth + 1, dfs);
      }
   };

   dfs(1, 1, dfs);
   dbg(height);
   sort(all(height), greater<int>());
   int l = 1, r = n, ans = 0;
   while (l <= r) {
      int m = (l + r) / 2;
      int cnt = 0, mx = 0;
      for (auto &c : height) {
         if (c > m) {
            cnt += c / m;
            mx = max({mx, c / m, c % m});
         } else {
            mx = max(mx, c);
         }
      }
      dbg(cnt, mx, m);
      if (cnt <= k) {
         r = m - 1;
         ans = mx;
      } else {
         l = m + 1;
      }
   }
   cout << ans << '\n';
}


int32_t main() {

#ifdef ONLINE_JUDGE
#else
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