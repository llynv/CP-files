
/*
  Code by: linvg
  Created: 04.11.2024 09:58:39
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
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
   vector<int> a((n + 1) / 2), pref(n + 1);
   int total = 0, ans = 0;
   set<int> s;
   for (int i = 0; i < (n + 1) / 2; ++i) {
      cin >> a[i];
      total += a[i];
      pref[i + 1] = pref[i] + a[i];
      if (pref[i + 1] > 0) {
         ans = i + 1;
         s.insert(i);
      }
   }
   int x;
   cin >> x;
   if (x > 0) {
      total += x * (n - (n + 1) / 2);
      cout << (total <= 0 ? -1 : n) << '\n';
      return;
   }
   else {
      for (int i = (n + 1) / 2; i < n; ++i) {
         a.push_back(x);
         pref[i + 1] = pref[i] + x;
         if (pref[i + 1] > 0) {
            ans = i + 1;
            s.insert(i);
         }
      }
      if (ans == n) return void(cout << n << '\n');
      vector<int> st;
      for (int i = 2; i <= (n + 1) / 2; ++i) {
         dbg(i, s);
         if (s.size() && i + *s.rbegin() > n) {
            return void(cout << *s.rbegin() + 1 << '\n');
         }
         while (s.size() && (pref[*s.rbegin() + i] - pref[i - 1] <= 0)) {
            s.erase(prev(s.end()));
         }
         dbg(i, s);
      }
      cout << ((s.empty() || *s.rbegin() == 0) ? -1 : *s.rbegin() + 1) << '\n';
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