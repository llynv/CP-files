/*
  Code by: linvg
  Created: 22.09.2024 09:58:54
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
   int n, m, k;
   cin >> n >> m >> k;
   vector<array<int, 2>> a(n);
   unordered_map<int, int> open, close;
   vector<int> lines;
   for (int i = 0; i < n; ++i) {
      cin >> a[i][0] >> a[i][1];
      open[a[i][0]] += a[i][1];
      close[a[i][0] + k] += a[i][1];
      lines.push_back(a[i][0]);
      lines.push_back(a[i][0] + k);
   }
   sort(all(lines));
   lines.resize(unique(all(lines)) - lines.begin());
   int ans = 0, cur = 0;
   dbg(lines);
   vector<int> avail;
   for (int i = 0; i < sz(lines); ++i) {
      cur += open[lines[i]];
      cur -= close[lines[i]];
      avail.push_back(cur);
   }
   dbg(avail);
   int res = 0;
   for (int i = 1; i < sz(lines); ++i) {
      if (avail[i - 1] >= m) {
         res += lines[i] - lines[i - 1];
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