
/*
  Code by: linvg
  Created: 13.10.2024 17:33:18
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
   int n, k;
   cin >> n >> k;
   int total = 0;
   vector<int> a(n);
   for (auto &c : a) cin >> c, total += c;
   sort(all(a));
   dbg(a);
   for (int i = 0; i < n; ++i) {
      multiset<int> q;
      for (int j = i; j < n; ++j) q.insert(a[j]);
      for (int j = i - 1; j >= 0; --j) {
         int c = *q.begin();
         q.erase(q.begin());
         q.insert(c + a[j]);
      }
      int need = 0;
      for (auto v : q) need += *q.rbegin() - v;
      dbg(i, need, q);
      if (need <= k) {
         cout << sz(q) << '\n';
         return;
      }
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