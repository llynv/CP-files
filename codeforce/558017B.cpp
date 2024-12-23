
/*
  Code by: linvg
  Created: 14.10.2024 13:49:47
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

int compare(string a, string b) {
   if (sz(a) < sz(b)) return -1;
   if (sz(a) > sz(b)) return 1;
   for (int i = 0; i < sz(a); ++i) {
      if (a[i] < b[i]) return -1;
      if (a[i] > b[i]) return 1;
   }
   return 0;
}

int min (int a, char c) {
   return min(a, (int) (c - '0'));
}

int max (int a, char c) {
   return max(a, (int) (c - '0'));
}

int lucky(string s) {
   int mx = 0, mn = INF;
   for (auto &c : s) mx = max(mx, c), mn = min(mn, c); 
   return mx - mn;
}

void solve()
{
   string l, r;
   cin >> l >> r;
   if (sz(l) != sz(r)) return void (cout << "1\n");

   auto calc = [&] (int i, int prev, int range, int up_bound, int low_bound, auto&&calc) -> void {
      for (int j = max({1ll, prev - range, low_bound}); j <= min({9ll, prev + range, up_bound}); ++j) {
         calc(i + 1, j, max(low_bound, j), min(up_bound, j))
      }
   };
   
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}