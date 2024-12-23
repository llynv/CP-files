
/*
  Code by: linvg
  Created: 13.10.2024 16:35:56
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
   int a, b, p, q;
   cin >> a >> b >> p >> q;
   int _g = gcd(p, q);
   p /= _g, q /= _g;
   _g = gcd(a, b);
   a /= _g, b /= _g;
   if (a > b) swap(a, b);
   dbg((1.0 * b / q * p));
   a *= max(p, q), b *= max(p, q);
   int x = max(1ll, min(a / p, b / q));
   p *= x, q *= x;
   if (a != p) swap(a, b), swap(p, q);
   dbg(a, b, p, q);
   q = b - q;
   _g = gcd(b, q);
   b /= _g, q /= _g;
   dbg(_g);
   cout << q << '/' << b << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}