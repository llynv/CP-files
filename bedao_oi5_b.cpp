
/*
  Code by: linvg
  Created: 30.10.2024 22:18:11
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

class Edge {

public:

   // from - The source of an edge
   // to - destination of an edge
   // wt - distance between two nodes
   int from;
   int to;
   int wt;

   Edge(int a, int b, int w)
   {
      from = a;
      to = b;
      wt = w;
   }
};

const int N = 5007;

int val[N];

// Method to add an edge between two nodes
void add_edge(vector<vector<Edge>>& adj_lis,
   int to, int from, int wt)
{
   adj_lis[from].push_back(Edge(from, to, wt));
   adj_lis[to].push_back(Edge(to, from, wt));
}

// DFS method to find distance
// between node 1 to other nodes
void dfs(vector<vector<Edge>>& adj_lis,
   int v, int par,
   int sum, bool visited[])
{
   val[v] = sum;
   visited[v] = true;

   for (Edge e : adj_lis[v])
   {
      if (!visited[e.to])
         dfs(adj_lis, e.to,
            v, sum + e.wt, visited);
   }
}



void solve()
{
   int n;
   cin >> n;
   vector<vector<Edge>> adj(n + 1);
   int sum = 0;
   for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      add_edge(adj, u, v, w);
      sum += 2 * w;
   }
   vector<int> del;
   bool visited[n + 1];
   for (int k = 2; k <= n; ++k) {
      dbg(k, del);
      int cur_vertex = -1, cur_sum = 0;
      for (int j = 2; j <= n; ++j) {
         if (visited[j]) continue;
         fill(val, val + n + 1, 0);
         visited[j] = true;
         dfs(adj, 1, -1, 0, visited);
         visited[j] = false;
         int large = -INF;
         for (int i = 1; i <= n; ++i) {
            large = max(large, val[i]);
         }
         if (cur_sum < sum - large) {
            cur_sum = sum - large;
            cur_vertex = j;
         }
      }
      cout << cur_vertex << ' ' << cur_sum << '\n';
      visited[cur_vertex] = true;
      del.push_back(cur_vertex);
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}