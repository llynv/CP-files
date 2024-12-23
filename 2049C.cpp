/*
  Code by: linvg
  Created: 20.12.2024 22:01:00
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

int calc_mex(int a, int b) {
   if (a == 0 && b == 0) return 1;
   if (a == 0 && b == 1) return 2;
   if (a == 1 && b == 0) return 2;
   if (a == 0 && b == 2) return 1;
   if (a == 2 && b == 0) return 1;
   return 0;
}

void solve()
{
   int n, x, y;
   cin >> n >> x >> y;
   --x, --y;
   vector<int> a(n, -1);
   a[0] = 0;
   a[x] = 0;
   a[y] = 1;
   for (int i = 1; i < n - 1; ++i) {
      if (a[i] == -1) {
         a[i] = !a[i - 1];
      } 
   }
   dbg(a);
   for (int i = 0; i < 5 * n; ++i) {
      int prv = (i - 1 + n) % n;
      int nxt = (i + 1) % n;
      if (i % n == x || i % n == y) continue;
      a[i % n] = calc_mex(a[prv], a[nxt]);
   }
   for (auto x : a) cout << x << ' ';
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