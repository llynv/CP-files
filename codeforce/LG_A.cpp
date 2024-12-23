
/*
  Code by: linvg
  Created: 10.10.2024 10:59:51
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
   vector<int> s;
   for (int i = 1; i <= 9; ++i) {
      int x;
      cin >> x;
      for (int j = 0; j < x; ++j) {
         s.push_back((i == 6 ? 9 : i));
      }
   }
   sort(all(s), greater<int>());
   vector<int> ans(sz(s));
   for (int i = 0, j = 0; i < sz(s) / 2; i++, j += 2) {
      ans[i] = s[j];
      if (j + 1 < sz(s)) ans[sz(s) - i - 1] = s[j + 1];
   }
   if (ans[sz(s) / 2] == 0) ans[sz(s) / 2] = s.back();
   for (int x : ans) cout << x << " ";
   cout << "\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}