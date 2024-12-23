

/*
    Code by: KoKoDuDu
    Created: 12.10.2024 00:02:15
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
vector<int> inv(N), fact(N), inv_fact(N);
void prepare() {
   inv[1] = 1;
   for (int i = 2; i < N; ++i) {
      inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
   }
   fact[0] = inv_fact[0] = 1;
   for (int i = 1; i < N; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
   }
}
int C(int n, int k) {
   if (k < 0 || k > n) return 0;
   return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
int fpow(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}
void solve() {
   int n, m, k;
   cin >> n >> m >> k;
   vector<vector<pll>> adj(n + 1, vector<pll>());
   for (int i = 1; i <= m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      u++, v++;
      adj[u].push_back({ v,w });
      adj[v].push_back({ u,w });
   }
   vector<int> dist(n + 1, 2e9);
   dist[1] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({ 0, 1 });
   while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d != dist[u]) continue;
      for (auto [v, w] : adj[u]) {
         if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.push({ dist[v], v });
         }
      }
   }
   sort(dist.begin() + 2, dist.end());
   int ans = 0;
   for (int i = 2; i <= n; ++i) {
      ans += C(n - i, k - 1) * dist[i] % MOD;
      ans %= MOD;
   }
   cout << (ans * fpow(C(n - 1, k), MOD - 2)) % MOD;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   prepare();
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}