
/*
  Code by: linvg
  Created: 16.10.2024 18:26:14
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
   auto rotate = [] (vector<vector<int>> &a) -> void {
      int n = sz(a);
      for (int i = 0; i < n / 2; ++i) {
         for (int j = i; j < n - i - 1; ++j) {
            int tmp = a[i][j];
            a[i][j] = a[n - j - 1][i];
            a[n - j - 1][i] = a[n - i - 1][n - j - 1];
            a[n - i - 1][n - j - 1] = a[j][n - i - 1];
            a[j][n - i - 1] = tmp;
         }
      }
   };
   auto check = [] (vector<vector<int>> &a) -> bool {
      for (int i = 0; i < sz(a); ++i) {
         bool row_inc = true;
         for (int j = 1; j < sz(a); ++j) {
            if (a[i][j] < a[i][j - 1]) {
               row_inc = false;
               break;
            }
         }
         if (!row_inc) return false;
      }
      for (int i = 0; i < sz(a); ++i) {
         bool col_inc = true;
         for (int j = 1; j < sz(a); ++j) {
            if (a[j][i] < a[j - 1][i]) {
               col_inc = false;
               break;
            }
         }
         if (!col_inc) return false;
      }
      return true;
   };
   if (check(a)) {
      cout << "0\n";
      return;
   }
   for (int i = 1; i <= 3; ++i) {
      rotate(a);
      if (check(a)) {
         cout << 4 - i << '\n';
         return;
      }
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