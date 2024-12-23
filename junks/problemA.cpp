/*
  Code by: linvg
  Created: 29.09.2024 16:23:25
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
   vector<string> cards(n);
   unordered_map<char, vector<int>> suits;
   set<int> pos;
   unordered_map<char, int> idx;
   idx['S'] = 0;
   idx['W'] = 1;
   idx['E'] = 2;
   idx['R'] = 3;
   idx['C'] = 4;
   // {S, W, E, R, C}
   for (int i = 0; i < n; ++i) {
      cin >> cards[i];
      pos.insert(i);
      suits[cards[i][0]].push_back(i);
   }

   vector<char> orders = {'S', 'W', 'E', 'R', 'C'};

   int res = INF;

   for (int mask = 0; mask < (1 << 5); ++mask) {
      vector<int> order;
      for (int i = 0; i < 5; ++i) {
         if (mask & (1 << i)) {
            order.push_back(orders[i]);
         }
      }
      vector<string> remain;
      vector<pair<string, int>> sorted[5];
      for (int i = 0; i < n; ++i) {
         if (find(all(order), cards[i][0]) != order.end()) {
            remain.push_back(cards[i]);
         } else {
            sorted[idx[cards[i][0]]].push_back({cards[i], i});
         }
      }

      // check if the remain cards are in increasing order 
      bool is_inc = true;
      int dif = !remain.empty();
      unordered_map<char, bool> num;
      if (remain.size()) num[remain[0][0]] = 1;
      for (int i = 1; i < sz(remain); ++i) {
         num[remain[i][0]] = 1;
         if (remain[i][0] != remain[i - 1][0]) {
            dif++;
            continue;
         }
         if (stoll(remain[i].substr(1)) <= stoll(remain[i - 1].substr(1))) {
            is_inc = false;
            break;
         }
      }
      if (dif != sz(num) || !is_inc) {
         continue;
      }

      int total = 0;
      for (int i = 0; i < 5; ++i) {
         dbg(orders[i], sorted[i]);
         if (sz(sorted[i]) == 0) continue;
         int cnt = 1, mx = 1;
         int _last = 0;
         for (int j = 1; j < sz(sorted[i]); ++j) {
            if (stoll(sorted[i][j].first.substr(1)) > stoll(sorted[i][j - 1].first.substr(1))
               && sorted[i][j].second - sorted[i][j - 1].second == 1
               ) {
               cnt++;
               mx = max(mx, cnt);
               _last = max(_last, sorted[i][j].second);
            } else {
               cnt = 1;
            }
         }
         // total += sz(sorted[i]) - mx + );
      }
      res = min(res, total);  
      dbg(order);
      dbg(remain);
      dbg(total);
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