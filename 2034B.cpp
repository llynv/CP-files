/*
  Code by: linvg
  Created: 30.11.2024 21:36:47
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
   int n, m, k;
   cin >> n >> m >> k;
   vector<char> a(n);
   vector<int> strong;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int pre = -1, res = 0;
   for (int i = 0; i < n; ++i) {
      if ((a[i] == '0' && i - pre >= m) || (a[i] == '1' && i - pre - 1 >= m)) {
         for (int j = i; j < min(n - 1, i + k); ++j) a[j] = '1';
         pre = i + k - 1;
         i += k - 1;
         res++;
         continue;
      }
      if (a[i] == '1') {
         pre = i;
      }
   }
   dbg(a);
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}