
/*
  Code by: linvg
  Created: 05.10.2024 05:15:25
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

   vector<vector<array<int, 2>>> bit_pos(31);
   for (int j = 0; j < 31; ++j) {
      for (int i = 0; i < n; ++i) {
         if (a[i] >> j & 1) {
            if (bit_pos[j].size() >= 1 && bit_pos[j].back()[1] + 1 == i) {
               bit_pos[j].back()[1] = i;
            } else {
               bit_pos[j].push_back({ i, i });
            }
         }
      }
   }

   int res = 0;
   for (int i = 30; i >= 0; --i) {
      if (bit_pos[i].empty()) continue;
      int l = bit_pos[i][0][0], r = bit_pos[i][0][1];
      for (int j = 1; j < sz(bit_pos[i]); ++j) {
         if (bit_pos[i][j][0] == r + 1) {
            r = bit_pos[i][j][1];
         } else {
            res = max(res, r - l + 1);
            l = bit_pos[i][j][0];
            r = bit_pos[i][j][1];
         }
      }
      res = max(res, r - l + 1);
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