/*
  Code by: linvg
  Created: 05.12.2024 21:48:10
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
   string s;
   cin >> s;
   int n = s.size();
   int cnt2 = 0, cnt3 = 0;
   int digit = 0;
   for (int i = 0; i < n; ++i) {
      if (s[i] == '2') cnt2++;
      else if (s[i] == '3') cnt3++;
      digit += s[i] - '0';
   }
   digit %= 9;
   // 2 up = (+ 2)
   // 3 up = (+ 6)

   // x = 0 => k = 0
   // x = 3 => k = 1
   // x = 6 => k = 2

   for (int i = 0; i <= cnt2; ++i) {
      int addup = 2 * i;
      int remain = (digit + addup) % 9;
      if (remain == 0) {
         cout << "YES\n";
         return;
      }
      if (remain == 3) {
         if (cnt3 > 0) {
            cout << "YES\n";
            return;
         }
      }
      if (remain == 6) {
         if (cnt3 > 1) {
            cout << "YES\n";
            return;
         }
      }
   }
   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}