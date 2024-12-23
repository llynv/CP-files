/*
  Code by: linvg
  Created: 09.12.2024 08:05:25
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
   int a, b, q;
   cin >> a >> b >> q;
   bool isEq = gcd(a, b) == min(a, b);
   bool spec = gcd(a, b) == 1 && min(a, b) != 1;
   dbg(a, b, isEq, spec);
   for (int i = 1; i <= 200; ++i) {
      if (i % a % b != i % b % a) {
         dbg(i);
      }
   }
   while (q--) {
      int l, r;
      cin >> l >> r;
      if (isEq) {
         cout << 0 << ' ';
         continue;
      }
      if (spec) {
         if (r <= max(a, b)) {
            cout << 0 << ' ';
            continue;
         }
         cout << r - max(l, max(a, b)) + 1 - r / lcm(a, b) + (l - 1) / lcm(a, b) << ' ';
         continue;
      }
      cout << (r + 1) / max(a, b) - (l + 1) / max(a, b) << ' ';
   }
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}