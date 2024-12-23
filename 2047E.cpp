/*
  Code by: linvg
  Created: 04.12.2024 18:44:04
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
   int n;
   cin >> n;
   vector<array<int, 2>> a(n);
   for (auto &c : a) cin >> c[0] >> c[1];
   sort(all(a), [](array<int, 2> a, array<int, 2> b) { return a[1] < b[1]; });
   unordered_map<int, vector<int>> comp;
   vector<int> nums;
   for (auto &c : a) comp[c[1]].push_back(c[0]);
   for (auto &c : comp) sort(all(c.second)), nums.push_back(c.first);
   sort(all(nums));
   nums.erase(unique(all(nums)), nums.end());
   int res = 0;
   array<int, 2> ans;
   dbg(a);
   for (int i = 0; i < n; ++i) {
      int l = 0, r = sz(nums) - 1;
      while (l <= r) {
         int m = (l + r) >> 1;
         int cnt[4] = {0, 0, 0, 0};
         // for (auto &d : a) {
         //    cnt[0] += (a[i][0] <= d[0] && a[m][1] <= d[1]);
         //    cnt[1] += (a[i][0] > d[0] && a[m][1] <= d[1]);
         //    cnt[2] += (a[i][0] <= d[0] && a[m][1] > d[1]);
         //    cnt[3] += (a[i][0] > d[0] && a[m][1] > d[1]);
         // }
         int val = nums[m];
         for (auto &[u, v] : comp) {
            int p = lower_bound(all(v), a[i][0]) - v.begin();
            cnt[0] += (val <= u) * p;
            cnt[1] += (val <= u) * (sz(v) - p);
            cnt[2] += (val > u) * p;
            cnt[3] += (val > u) * (sz(v) - p);
         }

         int mn = min({cnt[0], cnt[1], cnt[2], cnt[3]});
         if (res < mn) {
            res = mn;
            ans = {a[i][0], val};
         }
         // dbg(a[i], m, cnt[0], cnt[1], cnt[2], cnt[3]);
         if (cnt[0] + cnt[1] > cnt[2] + cnt[3]) {
            l = m + 1;
         } else {
            r = m - 1;
         }
      }  
   }
   cout << res << '\n';
   cout << ans[0] << ' ' << ans[1] << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}