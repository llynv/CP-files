
/*
  Code by: linvg
  Created: 30.10.2024 17:43:57
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

vector<int> base10toK(int n, int k) {
   vector<int> res;
   while (n) {
      res.push_back(n % k);
      n /= k;
   }
   reverse(all(res));
   return res;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> digits;
   dbg(n, k);
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      auto d = base10toK(x, k);
      digits.push_back(d.back());
   }
   sort(all(digits));
   digits.resize(unique(all(digits)) - digits.begin());
   dbg(digits);
   vector<int> dp(k + 1);
   dp[0] = 1;
   for (int i = 0; i < sz(digits); ++i) {
      dp[digits[i]] |= dp[0];
      for (int j = 1; j <= k; ++j) {
         dp[(j + digits[i]) % k] |= dp[j];
         if ((j + digits[i]) % k == digits[i]) continue;
      }
   }
   vector<int> res;
   for (int i = 0; i < k; ++i) {
      if (dp[i]) {
         res.push_back(i);
      }
   }
   cout << sz(res) << '\n';
   for (int i = 0; i < sz(res); ++i) {
      cout << res[i] << " \n"[i == sz(res) - 1];
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