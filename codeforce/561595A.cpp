
/*
  Code by: linvg
  Created: 26.10.2024 18:19:51
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define int unsigned long long
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
const int N = 111;

int a[N];

bool check_state (array<int, 10>& state, int c) {
   while (c) {
      int d = c % 10;
      state[d]++;
      if (state[d] > 2) return false;
      c /= 10;
   }
   return true;
}

struct Hash {
   size_t operator()(const array<int, 10>& a) const {
      size_t res = 0;
      for (int i = 0; i < 10; ++i) {
         res ^= a[i] + 0x9e3779b9 + (res << 6) + (res >> 2);
      }
      return res;
   }

   size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
   }
};

void solve()
{
   int n;
   cin >> n;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   int res = 0;
   unordered_map<array<int, 10>, int, Hash> dp, prev;
   array<int, 10> state = {0};
   dp[state] = 0;
   for (int i = 1; i <= n; ++i) {
      prev = dp;  
      array<int, 10> state = {0};
      if (!check_state(state, a[i - 1])) continue;
      dp[state] = max(dp[state], a[i - 1]);
      for (auto &[prev_state, val] : prev) {
         array<int, 10> new_state = prev_state;
         if (!check_state(new_state, a[i - 1])) continue;
         dp[new_state] = max(dp[new_state], val + a[i - 1]);
         res = max(res, val + a[i - 1]);
      }
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   clock_t start = clock();
   int t;
   cin >> t;
   while (t--)
   solve();
   cerr << fixed << setprecision(6) << "Time: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << " s.\n";
   return 0;
}