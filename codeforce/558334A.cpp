
/*
  Code by: linvg
  Created: 15.10.2024 14:50:26
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

string state_s[] = {"0X00", "00X0", "000X", "X000"};
bool is_fit(string s, int x)
{
   int cnt = 0;
   for (int j = 0; j < 4; ++j) {
      cnt += s[j] == '0' && state_s[x][j] == '0';
   }
   return (cnt >= 3);
}
int neat[] = {-1, 0, -1 , 2};
// X0
// 00

void solve()
{
   string s[2];
   cin >> s[0] >> s[1];
   int n = sz(s[0]);
   vector<vector<int>> dp(n + 1, vector<int>(4, 0));
   for (int i = 2; i <= n; ++i) {
      string str = s[0].substr(i - 2, 2) + s[1].substr(i - 2, 2);
      dp[i] = dp[i - 1];
      int _mx = 0;
      for (int j = 0; j < 4; ++j) _mx = max(_mx, dp[i - 2][j]);
      for (int j = 0; j < 4; ++j) {
         if (is_fit(str, j)) {
            dbg(i, j, str);
            dp[i][j] = max({dp[i][j], (neat[j] == -1 ? 0 : dp[i - 1][neat[j]]) + 1, _mx + 1});
         }
      }
      if (str == "0000") {
         for (int j = 0; j < 4; ++j) {
            dp[i][j] = max({dp[i][j], (neat[j] == -1 ? 0 : dp[i - 1][neat[j]]) + 1, _mx + 1});
         }
      }
   }
   dbg(dp);
   cout << *max_element(all(dp[n])) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}