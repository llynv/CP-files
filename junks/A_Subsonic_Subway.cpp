
/*
  Code by: linvg
  Created: 06.10.2024 00:36:04
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

void solve(int test_case)
{
   int n;
   cin >> n;
   double top = 0, bottom = 1e18;
   vector<array<int, 2>> a(n);
   bool flag = false;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i - 1][0] >> a[i - 1][1];
      if (a[i-1][0] != 0 && 1.0 * i / a[i - 1][0] < top) flag = true;
      if (bottom < 1.0 * i / a[i - 1][1]) flag = true;
      top = max(top, 1.0 * i / a[i - 1][1]);
      if (a[i - 1][0] != 0) bottom = min(bottom, 1.0 * i / a[i - 1][0]);
   }
   if (flag) {
      cout << "Case #" << test_case << ": -1\n";
      return;
   }
   cout << "Case #" << test_case << ": " << fixed << setprecision(10) << top << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

   freopen("subsonic_subway_input (1).txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   int t;
   cin >> t;
   for (int i = 1; i <= t; ++i) {
      solve(i);
   }
   return 0;
}