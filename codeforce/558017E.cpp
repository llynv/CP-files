
/*
  Code by: linvg
  Created: 14.10.2024 14:50:08
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
template<class T> T gcd(vector<T> a) { int res = 0; for (auto x : a) res = gcd(res, x); return res; }
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

long long modInverse(long long a, long long m) {
   long long m0 = m, t, q;
   long long x0 = 0, x1 = 1;
   if (m == 1) return 0;

   while (a > 1) {
      // q is quotient
      q = a / m;
      t = m;
      // m is remainder now, process same as Euclid's algorithm
      m = a % m;
      a = t;
      t = x0;
      x0 = x1 - q * x0;
      x1 = t;
   }

   // Make x1 positive
   if (x1 < 0) x1 += m0;

   return x1;
}

long long solveForXi(long long a_i, long long k, long long p) {
   long long rhs = (-a_i % p + p) % p;  // Ensure the right-hand side is positive
   long long inv_k = modInverse(k, p);  // Find the modular inverse of k mod p

   if (inv_k == 0) {
      // If k has no inverse, check if the equation is consistent
      if (rhs % p == 0) return 0;  // Any x_i satisfies the equation mod p
      else return -1;  // No solution
   }

   return (inv_k * rhs) % p;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   int res = INF;
   int _g = 0;
   for (auto &c : a) _g = gcd(_g, c);
   dbg(_g, a);
   if (_g > 1) {
      int _r = 0;
      for (auto& c : a) _r += c / _g - 1;
      res = min(res, _r);
   }
   sort(all(a));
   vector<int> x;
   int ans = 0;
   for (int i = 1; i < n; ++i) {
      if (gcd()) 
      }
   }
   cout << ans << '\n';
   dbg(x);
   dbg('\n');
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}