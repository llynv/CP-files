
/*
  Code by: linvg
  Created: 24.10.2024 21:39:55
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
   vector<vector<int>> a(n, vector<int>(n));
   for (auto &c : a) for (auto &v : c) cin >> v;
   int res = 0;
   for (int i = 0; i < n; ++i) {
      int j = 0, ti = i;
      int sum = 0;
      while (ti < n && j < n) {
         if (a[ti][j] < 0) sum = max(sum, abs(a[ti][j]));
         ti++;
         j++;
      }
      res += sum;
   }
   for (int j = 1; j < n; ++j) {
      int i = 0, tj = j;
      int sum = 0;
      while (i < n && tj < n) {
         if (a[i][tj] < 0) sum = max(sum, abs(a[i][tj]));
         i++;
         tj++;
      }
      res += sum;
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}