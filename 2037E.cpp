/*
  Code by: linvg
  Created: 19.12.2024 14:54:54
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

   auto ask = [&] (int l, int r) -> int {
      cout << "? " << l << ' ' << r << "\n";
      cout.flush();
      int res;
      cin >> res;
      return res;
   };

   int pivot = n;
   vector<char> s(n + 1);
   int pp = 0, one = 0;
   for (int i = n - 1; i >= 1; --i) {
      int x = ask(i, pivot);
      if (x == 0) continue;
      s[i] = '0';
      for (int j = i + 1; j <= i + x; ++j) s[j] = '1';
      for (int j = i + x + 1; j <= pivot; ++j) s[j] = '0';
      pivot = i - 1;
      --i;   
   }
   for (int i = n; i >= 1; --i) {
      one += s[i] == '1';
      pp += (s[i] == '0') * one;
   }
   dbg(pp, one);
   if (pivot == n) {
      cout << "! IMPOSSIBLE\n";
      cout.flush();
      return;
   }
   int fn = ask(1, n);
   dbg(pivot, fn);
   fn -= pp;
   for (int i = pivot; i >= 1; --i) {
      if (fn > 0) {
         s[i] = '0';
         fn -= one;
      } else {
         s[i] = '1'; 
      }
   }
   int check = count_if(s.begin() + 1, s.end(), [&] (char c) { return c == ' '; });
   if (check) {
      cout << "! IMPOSSIBLE\n";
      cout.flush();
      return;
   }
   cout << "! ";
   for (int i = 1; i <= n; ++i) cout << s[i];
   cout << '\n';
   cout.flush();
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}