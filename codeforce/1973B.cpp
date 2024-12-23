/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (int &x : a) cin >> x;

   vector<vector<int>> f(20, vector<int>(n + 1, 0));

   for (int i = 0; i < n; ++i) {
      f[0][i] = a[i];
   }

   for (int i = 1; i < 20; ++i) {
      for (int j = 0; j < n; ++j) {
         if (j + (1 << i) > n) break; 
         f[i][j] = (f[i - 1][j] | f[i - 1][j + (1 << (i - 1))]);
      }
   }

   auto get = [&](int l, int r) {
      int res = 0;
      for (int i = 19; i >= 0; --i) {
         if (l + (1 << i) - 1 <= r) {
            res |= f[i][l];
            l += 1 << i;
         }
      }
      return res;
   };

   int l = 1, r = n, res = n;
   while (l <= r) {
      int m = (l + r) / 2;
      unordered_map<int, int> cnt;
      for (int i = 0; i + m - 1 < n; ++i) {
         int x = get(i, i + m - 1);
         dbg(i, i + m - 1, x);
         cnt[x]++;
      }
      dbg(m, cnt);
      if (sz(cnt) > 1) {
         l = m + 1;
      } else {
         r = m - 1;
         res = m;
      }
   }
   dbg(res);
   cout << res << endl;
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}