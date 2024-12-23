/*
  Code by: linvg
  Created: 21.09.2024 22:26:53
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;

void solve()
{
   int n, m, k;
   cin >> n >> m >> k;
   vector<int> a(k);
   unordered_map<int, bool> horse_pos;
   for (auto &c : a) cin >> c, horse_pos[c] = true;
   vector<vector<array<int, 2>>> adj(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
   }

   vector<vector<int>> dist(n + 1, vector<int> (2, INF)), rev_dist(n + 1, vector<int> (2, INF));
   dist[1][0] = 0;
   rev_dist[n][0] = 0;
   if (horse_pos[1]) dist[1][1] = 0;
   if (horse_pos[n]) rev_dist[n][1] = 0;
   priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
   pq.push({0, 1, horse_pos[1]});
   while (!pq.empty()) {
      auto [d, u, has_horse] = pq.top();
      pq.pop();

      if (dist[u][has_horse] < d) continue;

      for (auto [v, w] : adj[u]) {
         w = has_horse ? w / 2 : w;
         if (dist[v][has_horse] > dist[u][has_horse] + w) {
            dist[v][has_horse] = dist[u][has_horse] + w;
            if (horse_pos[v]) dist[v][1] = min(dist[v][1], dist[v][0]);
            pq.push({dist[v][has_horse], v, has_horse || horse_pos[v]});
         }
      }
   }
   pq.push({0, n, horse_pos[n]});
   while (!pq.empty()) {
      auto [d, u, has_horse] = pq.top();
      pq.pop();
      
      if (rev_dist[u][has_horse] < d) continue;

      for (auto [v, w] : adj[u]) {
         w = has_horse ? w / 2 : w;
         if (rev_dist[v][has_horse] > rev_dist[u][has_horse] + w) {
            rev_dist[v][has_horse] = rev_dist[u][has_horse] + w;
            if (horse_pos[v]) rev_dist[v][1] = min(rev_dist[v][1], rev_dist[v][0]);
            pq.push({rev_dist[v][has_horse], v, has_horse || horse_pos[v]});
         }
      }
   }

   int ans = INF;
   for (int i = 1; i <= n; ++i) {
      // dbg(i, dist[i], rev_dist[i]);
      ans = min(ans, max(min(dist[i][0], dist[i][1]), min(rev_dist[i][0], rev_dist[i][1])));
   }

   cout << (ans == INF ? -1 : ans) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}