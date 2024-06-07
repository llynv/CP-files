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
   vector<vector<char>> a(n, vector<char>(n));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         cin >> a[i][j];
      }
   }

   int res = 0;
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
         int mx = 0;
         unordered_map<int, int> cnt;
         cnt[a[i][j]]++;
         cnt[a[n - 1 - i][n - 1 - j]]++;
         cnt[a[j][n - i - 1]]++;
         cnt[a[n - 1 - j][i]]++;
         mx = max({a[i][j], a[n - 1 - i][n - 1 - j], a[j][n - i - 1], a[n - 1 - j][i]});
         int tmp = 0;
         for (auto& [k, v] : cnt) {
            tmp += (mx - k) * v;
         }
         dbg(mx);
         dbg(i, j, tmp);
         dbg(cnt);
         res += tmp;
      }
   }
   dbg(res);
   cout << res / 4 << '\n';
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