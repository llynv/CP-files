/*
  Code by: linvg
  Created: 25.09.2024 19:41:22
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
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   unordered_map<int, int> cnt;
   for (auto& c : a) {
      cin >> c;
      cnt[c]++;
   }
   sort(all(a));
   a.erase(unique(all(a)), a.end());
   dbg(a);
   int l = 0, r = sz(a) - 1, mn = a[0], mx = a.back();
   while (l < r) {
      int d1 = a[l + 1] - a[l];
      int d2 = a[r] - a[r - 1];
      int inc = cnt[a[l]];
      int desc = cnt[a[r]];
      
      dbg(l, r, inc, desc, d1, d2, k);
      if (inc <= desc) {
         if (k >= inc * d1) {
            k -= inc * d1;
            cnt[a[l + 1]] += cnt[a[l]];
            l++;
            mn = a[l];
            continue;
         }
      } else {
         if (k >= desc * d2) {
            k -= desc * d2;
            cnt[a[r - 1]] += cnt[a[r]];
            r--;
            mx = a[r];
            continue;
         }
      }
      break;
   }
   dbg(mn, mx, k);
   dbg(cnt[mn], cnt[mx]);
   if (cnt[mn] <= cnt[mx]) {
      mn += k / cnt[mn];
      mn = min(mn, mx);
   } else {
      mx -= k / cnt[mx];
      mx = max(mn, mx);
   }
   dbg(mn, mx);
   cout << mx - mn << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}