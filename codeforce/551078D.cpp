/*
  Code by: linvg
  Created: 20.09.2024 16:39:13
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
   map<array<int, 4>, int> mp;
   vector<array<int, 2>> a(n);
   for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      a[i] = {l, r};
      mp[{l, 0, r - l + 1, i}]++;
      mp[{r, 1, r - l + 1, i}]--;
   }
   
   unordered_map<int, int> cnt, vst;
   vector<int> st;
   int cur = 0, res = -1, pre = -1;
   for (auto [k, v] : mp) {
      auto [x, is_close, _, i] = k;
      cur += v;
      dbg(x, pre, i, is_close, cur);
      dbg(st);
      if (x > pre && !is_close && !vst[x]) {
         vst[x] = 1;
         sort(all(st), [&](int i, int j) {
            return a[i][1] < a[j][1];
         });
         while (!st.empty() && a[st.back()][1] < x) {
            cnt[st.back()] = 0;
            st.pop_back();
         }
      }
      if (is_close) pre = x + 1;
      else st.push_back(i);
      if (cur > 0) {
         cnt[i]++;
         if (cnt[i] > 1) {
            res = i + 1;
         }
      }
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