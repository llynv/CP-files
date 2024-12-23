/*
  Code by: linvg
  Created: 25.09.2024 17:10:59
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   vector<int> pref(n + 1);
   for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
   int l, r;
   cin >> l >> r;
   int total = 0;
   map<int, vector<int>> mp;
   for (int i = 1; i <= n; ++i) {
      int cur = 0;
      if (i < r - l) {
         cur = pref[i] + pref[n] - pref[n - r + l + i];
      } else {
         cur = pref[i] - pref[i - r + l];
      }
      mp[cur].push_back(i - r + l);
      total = max(total, cur);
      dbg(i, cur);
   }
   dbg(mp[total], total);
   int res = INF;
   for (auto v : mp[total]) {
      int init = l;
      int dist = v;
      while (dist) {
         int t = min(dist, init);
         init -= t;
         dist -= t;
         if (init == 0) init = n;
      }
      dbg(v, init);
      res = min(res, init);
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