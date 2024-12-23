#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve()
{
   int n, m;
   cin >> n >> m;
   int ans = n;
   for (int i = 2; i <= m; ++i) {
      if (i * i > n + i) break;
      ans += ((n + i) / (i * i));
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