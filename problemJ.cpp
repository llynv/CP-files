/*
  Code by: linvg
  Created: 08.12.2024 01:36:15
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
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> point(m + 1);
   int currentLevel = -1;
   vector<int> solveForLevel(n + 1);
   map<pair<int, int>, bool> cache;
   for (int i = 0; i < q; ++i) {
      int type;
      cin >> type;
      if (type == 1) {
         cin >> currentLevel;
      } else if (type == 2) {
         int id, x;
         cin >> id >> x;
         if (currentLevel == -1 || x != currentLevel) continue;
         if (cache.count({id, currentLevel})) {
            continue;
         }
         point[id] += m - solveForLevel[currentLevel];
         solveForLevel[currentLevel]++;
         cache[{id, currentLevel}] = true;
      } else {
         int id, x;
         cin >> id >> x;
         if (currentLevel == -1 || x != currentLevel) continue;
         if (cache.count({id, currentLevel})) {
            continue;
         }
         cache[{id, currentLevel}] = true;
      }
   }
   vector<pair<int, int>> res;
   for (int i = 1; i <= m; ++i) res.emplace_back(point[i], m - i);
   sort(all(res), greater<pair<int, int>>());
   for (auto &[u, v] : res) cout << m - v << ' ' << u << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}