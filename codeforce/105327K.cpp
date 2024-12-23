
/*
  Code by: linvg
  Created: 16.10.2024 18:47:32
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
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int sum = accumulate(all(a), 0LL);
   if (sum % 2 != 0) return void (cout << "-1\n");
   sum /= 2;
   vector<int> dp(sum + 1, 0), trace(sum + 1, -1);
   dp[0] = 1;
   for (int j = 0; j < n; ++j) {
      for (int i = sum; i >= 0; --i) {
         if (i - a[j] >= 0) {
            dp[i] |= dp[i - a[j]];
            if (dp[i] && trace[i] == -1) trace[i] = j;
         }
      }
   }
   if (!dp[sum]) return void (cout << "-1\n");
   int cur = sum;
   vector<int> store;
   while (trace[cur] != -1) {
      store.push_back(trace[cur]);
      dbg(cur, trace[cur]);
      cur -= a[trace[cur]];
   } 
   dbg(store);
   sort(all(store));
   vector<int> s_a, s_b;
   for (auto &c : store) s_a.push_back(a[c]);
   for (int i = 0; i < n; ++i) {
      if (find(all(store), i) == store.end()) s_b.push_back(a[i]);
   }
   dbg(s_a);
   dbg(s_b);
   sort(all(s_a));
   sort(all(s_b));
   int i = 0, j = 0;
   vector<int> res;
   int sum_a = 0, sum_b = 0;
   while (i < sz(s_a) && j < sz(s_b)) {
      if (sum_a <= sum_b) {
         res.push_back(s_a[i]);
         sum_a += s_a[i];
         ++i;
      } else {
         res.push_back(s_b[j]);
         sum_b += s_b[j];
         ++j;
      }
   }
   while (i < sz(s_a)) {
      res.push_back(s_a[i]);
      ++i;
   }
   while (j < sz(s_b)) {
      res.push_back(s_b[j]);
      ++j;
   }
   // dbg(res);
   for (auto c : res) cout << c << ' ';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}