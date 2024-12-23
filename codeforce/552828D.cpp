/*
  Code by: linvg
  Created: 25.09.2024 20:26:42
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
const int N = 3e5 + 7;

vector<int> is_prime(N);
void sieve() {
   for (int i = 2; i < N; ++i) {
      if (!is_prime[i]) {
         for (int j = i * i; j < N; j += i) {
            is_prime[j] = 1;
         }
      }
   }
}

vector<int> factorize(int x) {
   vector<int> res;
   for (int i = 2; i * i <= x; ++i) {
      while (x % i == 0) {
         res.push_back(i);
         x /= i;
      }
   }
   if (x > 1) res.push_back(x);
   sort(all(res));
   res.erase(unique(all(res)), res.end());
   return res;
}


void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   sort(all(a));
   a.erase(unique(all(a)), a.end());
   vector<vector<int>> adj(n + 1);
   unordered_map<int, bitset<N>> store;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      vector<int> f = factorize(a[i]);

      for (int j = 0; j < sz(f); ++j) {
         for (int k = j + 1; k < sz(f); ++k) {
            adj[f[j]].push_back(f[k]);
         }
      }
   }
   int s, t;
   cin >> s >> t;

   vector<int> dist(n, INF);
   queue<int> q;
   for (auto x : factorize(a[s - 1])) {
      dist[x] = 0;
      dbg(x);
      q.push(x);
   }
   while (!q.empty()) {
      int u = q.front();
      q.pop();
      dbg(u, dist[u]);
      for (auto v : adj[u]) {
         if (dist[v] == INF) {
            dist[v] = dist[u] + 1;
            q.push(v);
         }
      }
   }
   int res = INF;
   for (auto x : factorize(a[t - 1])) {
      res = min(res, dist[x]);
   }
   cout << (res == INF ? -1 : res) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}