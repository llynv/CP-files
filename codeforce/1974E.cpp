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

void solve()
{
   int n, x;
   cin >> n >> x;
   vector<ii> a(n);
   for (auto& c : a) cin >> c.fi >> c.se;
   int sum = accumulate(all(a), 0LL, [](int u, ii v) { return u + v.se; });
   dbg(sum);
   vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
   dp[1][0] = x;
   if (a[0].fi == 0) dp[1][a[0].se] = x;

   for (int i = 2; i <= n; ++i) {
      for (int j = 0; j <= sum; ++j) {
         dp[i][j] = dp[i - 1][j];

         if (j < a[i - 1].se) continue;
         if (dp[i-1][j - a[i-1].se] < 0) continue;
         if (dp[i-1][j - a[i-1].se] >= a[i-1].fi) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1].se] - a[i - 1].fi);
      }
      for (int j = 0; j <= sum; ++j) {
         if (dp[i][j] >= 0) dp[i][j] += x;
      }
   }

   dbg(dp);

   int ans = 0;
   for (int i = sum; i >= 0; --i) {
      if (dp[n][i] > 0) {
         ans = i;
         break;
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