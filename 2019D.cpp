
/*
  Code by: linvg
  Created: 01.11.2024 19:14:33
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

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   int mn = n + 1, mx = -1;
   dbg(a);
   for (int i = 0; i <= n / 2; ++i) {
      dbg(a[i], a[n - i - 1], n - i);
      if (a[i] + i < n - i && n - i - a[n - i - 1] > i)  return void(cout << "0\n");
      dbg(mx, mn, i + a[i] - 1, n - i - a[n - i - 1]);
      if ((mx != -1 && mn != n + 1) && (mx < i + a[i] - 1 && mn > n - i - a[n - i - 1])) return void(cout << "0\n");
      mx = max(mx, n - i - a[n - i - 1]);
      mn = min(mn, i + a[i] - 1);
   }
   dbg(mx, mn);
   cout << max(0ll, mn - mx + 1) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}