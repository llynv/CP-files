/*
  Code by: linvg
  Created: 07.12.2024 01:51:42
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

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<int> p(n + 1);
   for (int i = 1; i <= n; ++i) cin >> p[i];
   vector<vector<int>> adj(n + 1), par(n + 1);
   for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      par[v].push_back(u);
   }
   vector<int> ans(n + 1);
   for (int i = 1; i <= n; ++i) {
      vector<int> deg(n + 1);
      for (int j = 1; j <= n; ++j) {
         for (int k : par[j]) {
            deg[k]++;
         }
      }
      priority_queue<pair<int, int>> q;
      for (int j = 1; j <= n; ++j) {
         if (deg[j] == 0 && j != i) {
            q.push({p[j], j});
         }
      }

      for (int j = n; j >= 1; --j) {
         if (q.empty() || q.top().first < j) {
            if (deg[i] == 0 && j <= p[i])  {
               ans[i] = j; 
            }
            break;
         }
         int u = q.top().second;
         q.pop();
         for (int v : par[u]) {
            if (--deg[v] == 0 && v != i) {
               q.push({p[v], v});
            }
         }
      }
   }

   for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}