
/*
  Code by: linvg
  Created: 11.10.2024 22:37:07
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
   vector<int> sum(n + 1, 0);
   for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + a[i - 1];
   }
   dp[0][0] = 0;
   vector<multiset<int>> s(k + 1);
   for (int i = 1; i <= n; ++i) {
      dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i - 1]);
      s[0].insert(dp[i][0]);
      vector<int> tmp(k + 1);
      for (int l = 1; l <= k; ++l) {
         // for (int j = i; j >= 1; --j) {
            // dp[i][l] = max(dp[i][l], dp[j - 1][l - 1] + sum[j - 1]);
         // }
         dp[i][l] = max(dp[i][l], dp[i - 1][l] + a[i - 1]);
         if (s[l - 1].size()) dp[i][l] = max(dp[i][l], *s[l - 1].rbegin() - sum[i]);
         tmp[l] = max(tmp[l], dp[i][l] + sum[i]);
         s[l].insert(tmp[l]); 
      }
      for (int l = 0; l <= k; ++l) {
      }
   }
   for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
         cerr << dp[i][j] << ' ';
      }
      cerr << '\n';
   }
   int ans = -INF;
   for (int i = 0; i <= n; ++i) {
      ans = max(ans, *max_element(all(dp[i])));
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}