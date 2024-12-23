
/*
  Code by: linvg
  Created: 06.11.2024 21:37:46
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
   int n, x;
   cin >> n >> x;
   vector<array<int, 2>> a(n);
   for (auto &c : a) cin >> c[0];
   for (auto &c : a) cin >> c[1];
   sort(all(a), [] (array<int, 2> x, array<int, 2> y) {
      return x[1] - x[0] < y[1] - y[0];
   });
   int cnt = 0;
   for (int i = 0; i < n; ++i) {
      if (a[i][0] - a[i][1] > 0) {
         cnt++;
         continue;
      } 
      int t = min(x, a[i][1] - a[i][0] + 1);
      a[i][0] += t;
      x -= t;
      cnt += (a[i][0] > a[i][1]);
   }
   cout << (cnt > n / 2 ? "YES\n" : "NO\n");
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}