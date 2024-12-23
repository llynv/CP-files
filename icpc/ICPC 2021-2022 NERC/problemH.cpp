/*
  Code by: linvg
  Created: 01.10.2024 16:19:41
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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve()
{
   int a, b, c;
   cin >> a >> b >> c;

   auto sorted = [&](int& a, int& b, int& c) {
      if (a < b) swap(a, b);
      if (b < c) swap(b, c);
      if (a < b) swap(a, b);
      };

   int res = 0;

   sorted(a, b, c);
   dbg(a, b, c);

   while (a != b || a != c || b != c) {

      if (b == c && a - b == 1) return void(cout << "-1\n");

      int dif = ((a + b + 1) / 2 - c + 1) / 2;
      a -= dif;
      b -= dif;
      c += dif;

      sorted(a, b, c);
      dbg(a, b, c, dif);
      if (b <= 0) return void(cout << "-1\n");

      res += dif;
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}