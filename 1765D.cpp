/*
  Code by: linvg
  Created: 07.12.2024 00:07:38
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
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   int total = 0;
   multiset<int> s;
   for (auto &c : a) cin >> c, s.insert(c);
   auto it = s.lower_bound(m - *s.begin());
   if (it == s.end() || (it != s.begin() && *it > m - *s.begin())) --it;
   int watch = *it;
   int res = watch + 1;
   s.erase(it);
   while (sz(s)) {
      it = s.lower_bound(m - watch);
      if (it == s.end() || (it != s.begin() && *it > m - watch)) --it;
      if (*it + watch > m) {
         it = prev(s.end());
      }
      res += *it + (*it + watch > m);
      watch = *it;
      s.erase(it);
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