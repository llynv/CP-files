/*
  Code by: linvg
  Created: 19.12.2024 21:36:03
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
   string s = to_string(n);
   bool ok = false;
   auto go = [] (string s, auto&& go, bool& ok) -> void {
      bool rev = false;
      for (int i = 0; i < sz(s) - 1; ++i) {
         if (s[i] == '3' && s[i + 1] == '3' && s != "33") {
            string tmp = s;
            tmp.erase(i, 2);
            rev = true;
            go(tmp, go, ok);
         }
      }
      if (!rev) {
         int x = stoll(s);
         if (x % 33 == 0) {
            ok = true;
            return;
         }
      }
      if (s == "33") {
         ok = true;
         return;
      }
   };
   go(s, go, ok);
   cout << (ok ? "YES" : "NO") << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}