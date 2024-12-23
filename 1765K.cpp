#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
   int n;
   cin >> n;
   vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
   int sum = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int x;
         cin >> x;
         a[i][j] = x;
         sum += x;
      }
   }

   int res = 0;
   for (int x = 1; x <= n; x++) {
      // dbg(x, n - (x - 1), a[x][n - (x - 1)]);
      res = max(res, sum - a[x][n - (x - 1)]);
   }
   cout << res;
}
int32_t main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   t = 1;
   while (t-- > 0) {
      solve();
   }
}