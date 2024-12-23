

/*
  Code by: linvg
  Created: 26.11.2024 19:53:15
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

   auto ask = [] (string t) -> int {
      cout << "1 " << t << '\n';
      cout.flush();
      int ans;
      cin >> ans;
      return ans;
   };
   
   int o = ask("1"), oo = ask("11"), oz = ask("10");
   // 1, 11, 10, 01
   int z = n - o;
   int peak = o - oo;
   if (peak > oz) {
      cout << "0 " << n << " 1\n";
      cout.flush();
   } else {
      cout << "0 " << n << " 0\n";
      cout.flush();
   }
   int x;
   cin >> x;
   if (x == -1) exit(0);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}