/*
  Code by: linvg
  Created: 28.09.2024 15:55:00
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

const int INF = 1e18;
const int MOD = 1e9 + 7;

void solve()
{
   int n, k, x, y;
   cin >> n >> k >> x >> y;
   vector<vector<int>> a(2);
   for (int i = 0; i < n; ++i) {
      char c;
      cin >> c;
      int x;
      cin >> x;
      a[c - 'A'].push_back(x);   
   }
   sort(all(a[0]), greater<int>());
   sort(all(a[1]), greater<int>());

   vector<vector<int>> pref(2);
   pref[0].resize(sz(a[0]) + 1);
   pref[1].resize(sz(a[1]) + 1);
   for (int i = 1; i <= sz(a[0]); ++i) {
      pref[0][i] = pref[0][i - 1] + a[0][i - 1];
   }
   for (int i = 1; i <= sz(a[1]); ++i) {
      pref[1][i] = pref[1][i - 1] + a[1][i - 1];
   }

   int ans = -INF;
   for (int i = 0; i <= sz(a[0]); ++i) {
      int extra = 2 * k - i;
      if (extra > sz(a[1])) continue;
      if (extra < 0) break;
      int sum = pref[0][i] + pref[1][extra];
      if (i > k) {
         sum -= (i - k) * x;
      }
      if (extra > k) {
         sum -= (extra - k) * y;
      }
      dbg(i, extra, sum);
      ans = max(ans, sum);
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

   // freopen("template.inp", "r", stdin);
   // freopen("template.out", "w", stdout);

   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}