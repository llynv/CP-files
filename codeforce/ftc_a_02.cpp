
/*
  Code by: linvg
  Created: 20.10.2024 09:09:31
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
   cin.ignore();
   vector<vector<int>> adj(n + 1), rev(n + 1);
   for (int i = 0; i < n; ++i) {
      string s;
      getline(cin, s);
      string token;
      stringstream ss(s);
      while (ss >> token) {   
         adj[i + 1].push_back(stoi(token));
         rev[stoi(token)].push_back(i + 1);
      }
   }

   int root = 1;
   for (int i = 1; i <= n; ++i) {
      if (rev[i].size()) {
         int cur = i;
         while (rev[cur].size() && cur != rev[cur].front()) {
            cur = rev[cur].front();
            root = cur;
         }
      }
   }
   int x;
   cin >> x;
   auto calc_height = [&] (int u, int p, int& height, auto&& calc_height, int depth = 0) -> void {
      if (u == x) {
         height = depth;
         return;
      }
      for (auto &c : adj[u]) {
         if (c != p) {
            calc_height(c, u, height, calc_height, depth + 1);
         }
      }
   };
   int height = 0;
   calc_height(root, 0, height, calc_height);
   unordered_map<int, vector<int>> sib;
   auto dfs = [&] (int u, int p, auto&&dfs, int depth = 0) -> void {
      if (u != x) sib[depth].push_back(u);
      for (auto &c : adj[u]) {
         if (c == p) continue;
         dfs(c, u, dfs, depth + 1);
      }
   };
   dfs(root, 0, dfs);
   if (sib[height].size() == 0) return void (cout << "-1\n");
   for (auto v : sib[height]) cout << v << ' '; 
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}