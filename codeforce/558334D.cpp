
/*
  Code by: linvg
  Created: 15.10.2024 16:25:13
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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
const int N = 2e5 + 5;

int a[N], pref[205][N];
vector<int> pos[205];

void solve()
{
   int n;
   cin >> n;
   vector<int> sets;
   int res = 0;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      pos[a[i]].clear();
      sets.push_back(a[i]);
   }
   for (int i = 1; i <= n; ++i) {
      pos[a[i]].push_back(i);
      res = max(res, sz(pos[a[i]]));
   }
   sort(all(sets));
   sets.erase(unique(all(sets)), sets.end());
   for (int i = 0; i < sz(sets); ++i) {
      for (int j = 1; j <= n; ++j) {
         pref[i][j] = pref[i][j - 1] + (a[j] == sets[i]);
      }
   }
   for (int i = 0; i < sz(sets); ++i) {
      for (int j = 0; j < sz(sets); ++j) {
         if (i == j) continue;
         for (int k = 0; k < sz(pos[sets[i]]) / 2; ++k) {
            int l = pos[sets[i]][k], r = pos[sets[i]][sz(pos[sets[i]]) - k - 1];
            res = max(res, pref[i][n] - pref[i][r - 1] + pref[i][l] + pref[j][r - 1] - pref[j][l]);
         }
      }
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}