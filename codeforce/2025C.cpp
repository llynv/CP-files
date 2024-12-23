
/*
  Code by: linvg
  Created: 14.10.2024 21:49:03
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
   vector<int> a(n);
   map<int, int> cnt;
   for (auto &c : a) cin >> c, cnt[c]++;
   sort(all(a));
   a.erase(unique(all(a)), a.end());
   vector<int> pref(sz(a) + 1);
   for (int i = 1; i <= sz(a); ++i) pref[i] = pref[i-1] + cnt[a[i-1]];
   int res = 0, cur = cnt[a[0]], num = 1;
   dbg(a);
   for (int i = 1; i <= sz(a); ++i) {
      int l = 0, r = min(k - 1, sz(a) - i), pos = i;
      while (l <= r) {
         int m = (l + r) / 2;
         dbg(i, l, r, m, a[i + m - 1], a[i - 1]);
         if (a[i + m - 1] != a[i - 1] + m) {
            r = m - 1;
         }
         else {
            pos = m;
            l = m + 1;
         }
      }
      int x = pref[i + pos] - pref[i - 1];
      res = max(res, x);
   }
   dbg(res);
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