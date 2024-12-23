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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<vector<int>> dp(n + 1, vector<int>(k + 1, -INF)); 
   dp[0][0] = 0;
   for (int i = 1; i <= n; ++i) {
      int total = 0;
      for (int j = 0; j <= k; ++j) dp[i][j] = dp[i - 1][j];
      for (int l = i - 1; l >= 0; --l) {
         total += a[l];
         for (int j = 1; j <= k; ++j) {
            dp[i][j] = max({dp[i][j], dp[l][j - 1] + total, 0ll});
         }
      }
   }
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
         cerr << dp[i][j] << ' ';
      }
      cerr << '\n';
   }
   cout << dp[n][k] << '\n';
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}