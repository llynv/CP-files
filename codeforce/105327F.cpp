
/*
  Code by: linvg
  Created: 16.10.2024 18:17:30
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

struct fraction
{
   int num, den;
   fraction(int num, int den) : num(num), den(den) {}
   fraction operator+(const fraction &other) const
   {
      return fraction(num * other.den + other.num * den, den * other.den);
   }
   void simplify()
   {
      int g = gcd(num, den);
      num /= g;
      den /= g;
   }
   void _swap() {
      swap(num, den);
   }
};

void solve()
{
   int n;
   cin >> n;
   fraction res(1, 2);
   for (int i = 2; i <= n; ++i) {
      res = res + fraction(1, 1);
      res._swap();
      res.simplify();
   }
   cout << res.num << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}