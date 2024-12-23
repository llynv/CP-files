

/*
  Code by: linvg
  Created: 15.11.2024 19:52:17
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
   if (n % 2 != 0 && n < 27) {
      cout << "-1\n";
      return;
   }
   vector<int> a(n);
   if (n % 2 != 0) {
      a[0] = 1;
      a[9] = 1;
      a[25] = 1;
      a[22] = 2;
      a[26] = 2;
      int id = 3;
      for (int i = 2; i <= n; ++i) {
         if (a[i] == 0 && a[i - 1] == 0) {
            a[i] = id;
            a[i - 1] = id;
            ++id;
         }
      }
   } else {
      int id = 1;
      for (int i = 1; i < n; i += 2) {
         a[i] = id;
         a[i - 1] = id;
         ++id;
      }
   }
   for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
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