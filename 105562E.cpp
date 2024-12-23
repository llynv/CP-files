/*
  Code by: linvg
  Created: 11.12.2024 22:08:23
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

int fpow (int a, int b, int m) {
   if (b == 0) return 1ll;
   if (b == 1) return a;
   int res = fpow(a, b / 2, m) % m, ex = 1;
   if (b % 2 != 0) ex = a;
   return ((res * res) % m * ex) % m;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   s = " " + s;
   int nxt = 1;
   for (int i = 1; i <= n - 1; ++i) {
      int r = fpow(2, k, n);      
      cout << s[nxt];
      nxt = (nxt + r) % n;
      if(nxt == 0) nxt = n;
   }
   cout << s[nxt];
   return;

   if (n % 2 != 0) {
      string tmp = s;
      k %= (n + 1) / 2;
      for (int i = 0; i < k; ++i) {
         for (int id = 0, i = 0; i < 2 * n; i += 2, id++)
            tmp[id] = s[i % n];
         swap(s, tmp);
      }
      cout << s << '\n';
   }
   else {
      int x = log2(n);
      k--;
      string tmp = s;
      for (int id = 0, i = 0; i < 2 * n; i += 2, id++)
         tmp[id] = s[i % n];
      swap(s, tmp);
      k %= x;
      for (int i = 0; i < k; ++i) {
         for (int id = 0, i = 0; i < 2 * n; i += 2, id++)
            tmp[id] = s[i % n];
         swap(s, tmp);
      }
      cout << s << '\n';
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