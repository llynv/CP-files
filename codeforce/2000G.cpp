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
const int MOD = 1e8;

struct Edge {
   int v, w1, w2;
};

void solve()
{
   int n, m;
   cin >> n >> m;
   int t0, t1, t2;
   cin >> t0 >> t1 >> t2;
   vector<vector<Edge>> adj(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v, w1, w2;
      cin >> u >> v >> w1 >> w2;
      adj[u].push_back({ v, w1, w2 });
      adj[v].push_back({ u, w1, w2 });
   }

   priority_queue<ii, vector<ii>, greater<ii>> pq;
   vector<int> dist(n + 1, INF), wait(n + 1, -1);

   auto calc = [&](int mid) -> int {
      fill(all(dist), INF);
      pq.push({ mid, 1 });
      dist[1] = mid;
      bool over = false;
      vector<int> wait;
      while (!pq.empty()) {
         auto [d, u] = pq.top(); pq.pop();
         if (d > dist[u]) continue;
         for (auto [v, w1, w2] : adj[u]) {
            if (d + w1 > t1 && d < t2) {
               if (dist[v] > d + w2 && d + w2 <= t0) {
                  dist[v] = d + w2;
                  pq.push({ dist[v], v });
               }
               if (d + w2 > t2 && t2 + w1 < d + w2) over = true;
            }
            else {
               if (dist[v] > d + w1 && d + w1 <= t0) {
                  dist[v] = d + w1;
                  pq.push({ dist[v], v });
               }
            }
         }
         if (over) {
            if (d + t2 - d < t0 && d < t2) {
               wait.push_back(u);
            }
         }
      }
      sort(all(wait));
      wait.resize(unique(all(wait)) - wait.begin());
      for (int i = 0; i < sz(wait); ++i) {
         pq.push({ t2, wait[i] });
         dist[wait[i]] = t2;
      }
      while (!pq.empty()) {
         auto [d, u] = pq.top(); pq.pop();
         if (d > dist[u]) continue;
         for (auto [v, w1, w2] : adj[u]) {
            if (dist[v] > d + w1) {
               dist[v] = d + w1;
               pq.push({ dist[v], v });
            }
         }
      }
      return dist[n];
      };

   int l = 0, r = t0, ans = -1;
   while (l <= r) {
      int mid = (l + r) >> 1;
      int dist = calc(mid);
      if (dist <= t0) {
         l = mid + 1;
         ans = mid;
      }
      else {
         r = mid - 1;
      }
   }

   cout << ans << '\n';

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