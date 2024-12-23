/*
  Code by: linvg
  Created: 19.12.2024 13:56:07
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
   vector<int> h(n), x(n);
   for (auto &c : h) cin >> c;
   for (auto &c : x) cin >> c;
   int res = INF;
   for (int i = 0; i < n; ++i) {
      int cnt = 0, mxTime = 0;
      for (int j = i; j <= min(n - 1, i + k); ++j) {
         int dmg = max(0ll, m - abs(x[i] - x[j]));
         if (dmg > 0) {
            cnt++;
            mxTime = max(mxTime, (h[j] + dmg - 1) / dmg);
         } else break;
      }
      if (cnt >= k) res = min(res, mxTime);
   }
   cout << (res == INF ? -1 : res) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}