#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> adj(n + 1);
   vector<int> deg(n + 1, 0);

   fu(i, 1, n - 1)
   {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      deg[v]++;
   }

   int root = 1;
   fu(i, 1, n)
   {
      if (deg[i] == 0)
      {
         root = i;
         break;
      }
   }

   // lca
   vector<vector<int>> dp(n + 1, vector<int>(20, -1));
   vector<int> depth(n + 1, 0);
   function<void(int, int, int)> dfs = [&](int u, int p, int d)
      {
         dp[u][0] = p;
         depth[u] = d;
         for (int i = 1; i < 20; i++)
         {
            if (dp[u][i - 1] != -1)
            {
               dp[u][i] = dp[dp[u][i - 1]][i - 1];
            }
         }
         for (int v : adj[u])
         {
            if (v != p)
            {
               dfs(v, u, d + 1);
            }
         }
      };
   dfs(root, -1, 0);
   function<int(int, int)> lca = [&](int u, int v)
      {
         if (depth[u] < depth[v])
         {
            swap(u, v);
         }
         for (int i = 19; i >= 0; i--)
         {
            if (depth[u] - (1 << i) >= depth[v])
            {
               u = dp[u][i];
            }
         }
         if (u == v)
         {
            return u;
         }
         for (int i = 19; i >= 0; i--)
         {
            if (dp[u][i] != dp[v][i])
            {
               u = dp[u][i];
               v = dp[v][i];
            }
         }
         return dp[u][0];
      };
   int t;
   cin >> t;
   while (t-- > 0)
   {
      int u, v;
      cin >> u >> v;
      int p = lca(u, v);
      if (p == u)
      {
         cout << "Yes\n";
      }
      else
      {
         cout << "No\n";
      }
   }
}
int32_t main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   t = 1;
   while (t-- > 0)
   {
      solve();
   }
}