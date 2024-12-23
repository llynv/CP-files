/*
  Code by: linvg
  Created: 23.10.2024 01:04:52
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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int M = 1e4 + 7;

void solve()
{
   int n;
   cin >> n;
   int nx[3];
   cin >> nx[0] >> nx[1] >> nx[2];
   unordered_map<int, int> depend;
   vector<vector<int>> m(3);
   bitset<M> mask[3];
   for (auto& c : m) {
      int x;
      cin >> x;
      for (int i = 0; i < x; ++i) {
         int y;
         cin >> y;
         c.push_back(y);
         depend[y]++;
         mask[&c - &m[0]][y] = 1;
      }
   }
   auto cmp = [&](int a, int b) {
      if (depend[a] == depend[b]) return a < b;
      return depend[a] < depend[b];
   };
   vector<set<int, decltype(cmp)>> v(3, set<int, decltype(cmp)>(cmp));
   int init[3] = { 0, 0, 0 };
   for (int i = 0; i < 3; ++i) {
      v[i].insert(-1);
      for (int j = 0; j < m[i].size(); ++j) {
         if (depend[m[i][j]] != 1) v[i].insert(m[i][j]);
         else {
            init[i] += (i == 0 ? (init[i] < nx[0]) : (i == 1 ? init[i] < nx[1] : init[i] < nx[2]));
            mask[i][m[i][j]] = 0;
         }
      }
   }
   dbg(v);
   set<int> merged;
   merged.insert(all(v[1]));
   merged.insert(all(v[2]));
   int res = 0;
   int cnt = min(nx[0], init[0]);
   auto it = v[0].begin();
   for (; it != v[0].end(); ++it) {
      cnt += (*it != -1);
      if (merged.find(*it) != merged.end()) merged.erase(*it);
      dbg(*it, merged);
      int total = min(init[1] + init[2] + sz(merged), nx[1] + nx[2]);
      dbg(cnt, total);
      res = max(res, total + cnt);
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
