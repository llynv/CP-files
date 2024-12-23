

/*
  Code by: linvg
  Created: 13.10.2024 19:32:28
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
   int n, d;
   cin >> n >> d;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<int> max_right(n + 2, -INF), pref(n + 1);
   for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
   for (int i = n; i >= 1; --i) max_right[i] = max(max_right[i + 1], pref[i]);
   int ans = 0, up = 0;
   for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + a[i];
      if (a[i] == 0) {
         int cur = pref[i + 1];
         dbg(i, cur, up, max_right[i + 1]);
         if (cur < 0) {
            int mx = up + max_right[i + 1] - pref[i];
            up += - cur + min(d, d - mx);
            pref[i + 1] += - cur + min(d, d - mx);
            ++ans;
            if (pref[i + 1] < 0) {
               cout << "-1\n";
               return;
            }
         }
      }
      if (pref[i + 1] > d) {
         cout << "-1\n";
         return;
      }
   }
   dbg(a);
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}