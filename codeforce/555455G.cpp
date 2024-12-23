
/*
  Code by: linvg
  Created: 05.10.2024 01:09:00
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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
   int d12, d13, d23;
   cin >> d12 >> d23 >> d13;
   set<int> s;
   for (int i = 4; i <= n; ++i) {
      s.insert(i);
   }
   if (d12 + d23 == d13) {
      cout << "YES\n";
      for (int i = 1; i < n; ++i) {
         cout << i << ' ' << i + 1 << '\n';
      }
   } else if (d12 + d13 == d23) {
      cout << "YES\n";
      int prev = 1;
      for (int i = 1; i < d12; ++i) {
         cout << prev << ' ' << *s.begin() << '\n';
         prev = *s.begin();
         s.erase(s.begin());
      }
      cout << prev << ' ' << 2 << '\n';
      prev = 1;
      for (int i = 1; i < d13; ++i) {
         cout << prev << ' ' << *s.begin() << '\n';
         prev = *s.begin();
         s.erase(s.begin());
      }
      cout << prev << ' ' << 3 << '\n';
      prev = 3;
      for (auto &c : s) {
         cout << prev << ' ' << c << '\n';
         prev = c;
      }
   } else if (d13 + d23 == d12) {
      cout << "YES\n";
      for (int i = 1; i < n; ++i) {
         cout << i << ' ' << i + 1 << '\n';
      }
   } else {
      cout << "NO\n";
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}