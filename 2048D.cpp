/*
  Code by: linvg
  Created: 19.12.2024 22:02:11
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
   vector<int> a(n), prob(m);
   for (auto& c : a) cin >> c;
   for (auto& c : prob) cin >> c;
   int rank = a[0];
   vector<int> res(m + 1);
   sort(all(a));
   sort(all(prob));
   vector<int> rankProb(m + 1, 1);
   for (int i = 1; i <= m; ++i) {
      if (prob[i - 1] <= rank) continue;
      int p = lower_bound(all(a), prob[i - 1]) - a.begin();
      dbg(prob[i - 1], p, n - p + 1);
      rankProb[i] = n - p + 1;
   }
   sort(all(rankProb));
   dbg(rankProb);

   vector<vector<int>> f(20, vector<int>(m + 1));
   for (int i = 1; i <= m; ++i) f[0][i] = rankProb[i];
   for (int i = 1; i < 20; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= m; ++j) {
         f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
      }
   }
   auto get = [&] (int l, int r) -> int {
      int len = r - l + 1;
      int k = log2(len);
      return max(f[k][l], f[k][r - (1 << k) + 1]);
   };

   for (int k = 1; k <= m; ++k) {
      int totalRank = 0;
      for (int i = k; i <= m; i += k) {
         totalRank += get(i - k + 1, i);
      }  
      res[k] = totalRank;
   }
   for (int i = 1; i <= m; ++i) cout << res[i] << ' ';
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}