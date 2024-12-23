/*
  Code by: linvg
  Created: 21.09.2024 00:27:35
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

void solve(int test)
{
   int n, k;
   cin >> n >> k;
   int mn = INF;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      mn = min(mn, x);
   }
   if (n == 1) return cout << "Case #" << test << ": " << (mn <= k ? "YES\n" : "NO\n"), void();
   int time = mn * 2 * (n - 2) + mn;
   cout << "Case #" << test << ": " << (time <= k ? "YES\n" : "NO\n");
}


int32_t main() {
   #ifdef ONLINE_JUDGE
   #else
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif   
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   for (int i = 1; i <= t; i++)
      solve(i);
   return 0;
}