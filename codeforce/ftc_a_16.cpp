/*
  Code by: linvg
  Created: 20.10.2024 10:31:13
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
   int n;
   cin >> n;
   vector<string> a(n);
   for (auto& c : a) cin >> c;
   if (n == 1) return void(cout << "1\n");
   vector<vector<int>> adj(n);
   vector<vector<bool>> can(n, vector<bool>(n, 0));
   for (int i = 0; i < n; ++i) {
      vector<bool> vst(26, 0);
      for (auto& c : a[i]) vst[c - 'A'] = 1;
      for (int j = 0; j < n; ++j) {
         if (i == j) continue;
         bool ok = false;
         for (auto& c : a[j]) if (vst[c - 'A']) ok = true;
         if (ok) {
            can[i][j] = can[j][i] = true;
            adj[i].push_back(j);
         }
      }
   }
   vector<int> res(n + 1, n + 1);
   string ans;
   ans.assign(1e6, 'z');
   vector<int> used(n);
   auto dfs = [&](int u, string cur, vector<int> path, auto&& dfs, int depth = 1) -> void {
      used[u] = 1;
      if (depth == n) {
         if (!can[u][path.front()]) return;
         if (ans >= cur) {
            if (ans > cur) {
               res = path;
            } else {
               res = min(res, path);
            }
            ans = cur;
         }
         return;
      }
      for (auto& c : adj[u]) {
         if (!used[c]) {
            path.push_back(c);
            dfs(c, cur + a[c], path, dfs, depth + 1);
            path.pop_back();
         }
      }
      used[u] = 0;
      };
   for (int i = 0; i < n; ++i) {
      dfs(i, a[i], { i }, dfs);
   }
   if (res.front() == n + 1)
      cout << "NO SOLUTION";
   for (auto c : res) cout << c + 1 << ' ';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}
