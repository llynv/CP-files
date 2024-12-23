/*
  Code by: linvg
  Created: 29.09.2024 19:56:03
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

void solve()
{
   int n, k;
   cin >> n >> k;
   if (n < k) return void(cout << "NO\n");
   if ((n - k + 1) % 2 != 0) {
      cout << "YES\n";
      for (int i = 1; i < k; ++i) cout << 1 << ' ';
      cout << n - k + 1 << '\n';
   }
   else if (n - 2 * (k - 1) > 0 && (n - 2 * (k - 1)) % 2 == 0) {
      cout << "YES\n";
      for (int i = 1; i < k; ++i) cout << 2 << ' ';
      cout << n - 2 * (k - 1) << '\n';
   }
   else cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}