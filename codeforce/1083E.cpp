/*
  Code by: linvg
  Created: 04.10.2024 16:56:48
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;

int mul (int a, int b) {
  int res = (__int128_t(a) * b) % MOD;
  return res;
}

void solve()
{
   int n;
   cin >> n;
   vector<array<int, 3>> a(n);
   for (int i = 0; i < n; ++i) {
      cin >> a[i][0] >> a[i][1] >> a[i][2];
   }
   sort(all(a), [](array<int, 3> x, array<int, 3> y) {
      if (x[0] < y[0]) return true;
      if (x[0] == y[0] && x[1] > y[1]) return true;
      return false;
      });

   dbg(a);

   auto calc = [&](array<int, 3> x, array<int, 3> y) {
      return (y[0] - x[0]) * y[1] - y[2];
      };

   vector<int> dp(n + 1);
   multiset<array<int, 2>, greater<array<int, 2>>> s;
   for (int i = 1; i <= n; ++i) {
      dp[i] = calc({ 0, 0, 0 }, a[i - 1]);
      dbg(s);
      if (sz(s)) {
         auto it = *s.begin();
         dbg(it);
         dp[i] = max(dp[i], it[1] + calc(a[n - it[0] - 1], a[i - 1]));
      }
      s.insert({ n - i, dp[i] });
   }
   int ans = *max_element(all(dp));
   cout << ans << "\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}