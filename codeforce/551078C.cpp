/*
  Code by: linvg
  Created: 20.09.2024 15:50:14
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
const int MOD = 1e8;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<vector<int>> f(20, vector<int>(n + 1));
   for (int i = 1; i <= n; ++i) f[0][i] = a[i - 1];
   for (int i = 1; i < 20; ++i) {
      for (int j = 1; j + (1 << (i - 1)) <= n; ++j) {
         f[i][j] = gcd(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
      }
   }
   auto get = [&](int l, int r) {
      int len = r - l + 1;
      int k = 31 - __builtin_clz(len);
      return gcd(f[k][l], f[k][r - (1 << k) + 1]);
   };
   unordered_map<int, int> mp;
   for (int i = 0; i < n; ++i) {
      int cur = i;
      while (cur < n) {
         int l = cur, r = n - 1, ed = -1;
         int st = get(i + 1, cur + 1);
         while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(i + 1, mid + 1) == st) {
               l = mid + 1;
               ed = mid;
            } else {
               r = mid - 1;
            }
         }
         mp[st] += ed - cur + 1;
         cur = ed + 1;
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int x;
      cin >> x;
      cout << mp[x] << '\n';
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