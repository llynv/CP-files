/*
    Code by: KoKoDuDu
    Created: 13.10.2024 08:12:13
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
   int n;
   cin >> n;
   vector<int> w(n + 1), a(n + 1), b(n + 1), pos(n + 1), check(n + 1);
   vector<vector<int>>adj(n + 1, vector<int>());
   int goal_min = INF;
   for (int i = 1; i <= n; ++i) {
      cin >> w[i];
      goal_min = min(goal_min, w[i]);
   }
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pos[a[i]] = i;
   }
   for (int i = 1; i <= n; ++i) {
      cin >> b[i];
      adj[pos[b[i]]].push_back(i);
   }
   int sum = 0, minn = INF, cnt = 0;
   function< void(int)> dfs = [&](int x) {
      if (check[x] == 1) {
         return;
      }
      cnt++;
      // cout << x << ' ' << a[x] << " - - - ";
      check[x] = 1;
      sum += w[b[x]];
      minn = min(minn, w[b[x]]);
      for (int g : adj[x]) {
         dfs(g);
      }
      };
   int ans = 0;
   for (int i = 1; i <= n; i++) {
      if (check[i]) continue;
      sum = 0, minn = INF, cnt = 0;
      dfs(i);
      ans += min({sum + minn * (cnt - 2), sum + minn + (cnt + 1) * goal_min});
      // cerr << "A" << sum << " " << minn << " " << cnt << "\n";
   }
   cout << ans;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}