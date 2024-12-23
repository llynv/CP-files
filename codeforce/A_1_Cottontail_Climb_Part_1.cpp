
/*
  Code by: linvg
  Created: 20.10.2024 00:48:52
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
   int a, b, m;
   cin >> a >> b >> m;
   int kl = (to_string(a).size() + 1) / 2;
   int kr = (to_string(b).size() + 1) / 2;
   vector<int> nums;
   for (int i = kl; i <= kr; ++i) {
      // generate all numbers with 2 * i + 1 digits that the first i + 1 digits are increase by 1 and the last i digits are decrease by 1 that in range[a, b]
      for (int x = 1; x <= 9; ++x) {
         string s = to_string(x);
         int num = 0;
         for (int j = 1; j < i; ++j) {
            if (x + j > 9) {
               goto END;
            }
            s += to_string(x + j);
         }
         for (int j = i - 1; j >= 1; --j) {
            s += to_string(x + j - 1);
         }
         num = stoll(s);
         if (num >= a && num <= b) {
            nums.push_back(num);
         }
         END:;
      }
   }
   sort(all(nums));
   int res = 0;
   for (auto &c : nums) {
      res += (c % m == 0);
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   freopen("cottontail_climb_part_1_validation_input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int t;
   cin >> t;
   // while (t--)
   // solve();
   for (int i = 1; i <= t; ++i) {
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
}