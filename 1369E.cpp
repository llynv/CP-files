
/*
  Code by: linvg
  Created: 04.11.2024 16:05:05
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
   int n, m;
   cin >> n >> m;
   vector<int> a(n + 1), sup(n + 1);
   for (int i = 1; i <= n; ++i) cin >> a[i];
   vector<array<int, 3>> foods(m);
   vector<int> s(n + 1);
   vector<vector<int>> pos(n + 1);
   for (int i = 0; i < m; ++i) {
      cin >> foods[i][0] >> foods[i][1];
      foods[i][2] = i;
      s[foods[i][0]]++;
      s[foods[i][1]]++;
      pos[foods[i][0]].push_back(i);
      pos[foods[i][1]].push_back(i);
   }
   vector<int> valid;
   vector<int> ans, vst(m + 1);
   for (int i = 1; i <= n; ++i) {
      if (s[i] <= a[i]) {
         valid.push_back(i);
      }
   } 
   if (valid.empty()) {
      cout << "DEAD\n";
      return;
   }
   while (true) {
      vector<int> new_valid;
      for (auto i : valid) {
         dbg(i, pos[i]);
         for (auto p : pos[i]) {
            if (vst[p]) continue;
            s[foods[p][0]]--;
            s[foods[p][1]]--;
            if (s[foods[p][0]] <= a[foods[p][0]]) new_valid.push_back(foods[p][0]);
            if (s[foods[p][1]] <= a[foods[p][1]]) new_valid.push_back(foods[p][1]);
            vst[p] = 1;
            ans.push_back(p + 1);
         }
      }
      dbg(valid, new_valid, ans);
   sort(all(new_valid));
      new_valid.erase(unique(all(new_valid)), new_valid.end());
      if (new_valid.empty()) {
         reverse(all(ans));
         dbg(ans);
         if (ans.size() != m) {
            cout << "DEAD\n";
            return;
         }
         cout << "ALIVE\n";
         for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i] << " \n"[i == sz(ans) - 1];
         }
         return;
      }
      valid = new_valid;
   }
   dbg(s, a);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}