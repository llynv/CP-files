
/*
  Code by: linvg
  Created: 20.10.2024 10:57:39
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
   vector<vector<long double>> a(n, vector<long double>(n + 1));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cin >> a[i][j];
      cin >> a[i][n];
   }
   for (int i = 0; i < n; ++i) {
      int mx = i;
      for (int j = i + 1; j < n; ++j) {
         if (abs(a[j][i]) > abs(a[mx][i])) {
            mx = j;
         }
      }
      swap(a[i], a[mx]);
      for (int j = i + 1; j <= n; ++j) {
         if (a[i][i] == 0) return void (cout << "ERROR\n");
         a[i][j] /= a[i][i];
      }
      for (int j = 0; j < n; ++j) {
         if (i != j) {
            for (int k = i + 1; k <= n; ++k) {
               a[j][k] -= a[j][i] * a[i][k];
            }
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      cout << fixed << setprecision(6) << a[i][n] << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}