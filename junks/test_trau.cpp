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
#define LOCAL

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   int sum = accumulate(all(a), 0LL);
   vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1));
   int res = 0;
   dp[0][0] = 1;
   for (int i = 1; i <= n; ++i) {
      dp[i][0] = 1;
      for (int j = 1; j <= sum / 2; ++j) {
         if (j - a[i-1] >= 0) {
            dp[i][j] = (dp[i - 1][j] | dp[i - 1][j - a[i-1]]);
         }
         else {
            dp[i][j] = dp[i - 1][j];
         }
         if (dp[i][j]) {
            res = max(res, j);
         }
      }
   }
   cout << abs(sum - 2 * res);
}

int32_t main() {

#ifdef LOCAL
   freopen("test.inp", "r", stdin);
   freopen("test.ans", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}