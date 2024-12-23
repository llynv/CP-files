/*
  Code by: linvg
  Created: 29.09.2024 16:59:30
*/

#include <bits/stdc++.h>
using namespace std;

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

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int M = 101;

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<bitset<M>> a(n);
   for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
         int x;
         cin >> x;
         a[i][x] = 1;
      }
   }

   queue<pair<bitset<M>, int>> q;
   q.push({0, 1});
   q.push({a[0], 1});
   int res = INF;
   while (!q.empty()) {
      auto [mask, pos] = q.front();
      q.pop();
      if (pos == n) {
         int pin = 0;
         for (auto x : a) {
            bool sub = true;
            for (int i = 0; i < x.size(); ++i) {
               if (x[i] && !mask[i]) {
                  sub = false;
                  break;
               }
            }
            pin += !sub;
         }
         res = min(res, pin + (int) mask.count());
         continue;
      }
      q.push({mask | a[pos], pos + 1});
      q.push({mask, pos + 1});
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   freopen("template.inp", "r", stdin);
   freopen("template.out", "w", stdout);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}