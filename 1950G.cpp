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
   vector<vector<string>> a(n);
   vector<string> g, w;
   for (int i = 0; i < n; i++) {
      a[i].resize(2);   
      cin >> a[i][0] >> a[i][1];
   }

   vector<vector<bool>> isG(n, vector<bool>(n, false)), isW(n, vector<bool>(n, false));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (a[i][0] == a[j][0]) {
            isG[i][j] = true;
         }
         if (a[i][1] == a[j][1]) {
            isW[i][j] = true;
         }
      }
   }

   vector<vector<bool>> dp(1 << n, vector<bool>(n, false));
   for (int i = 0; i < n; ++i) dp[1 << i][i] = true;
   for (int mask = 0; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
         if (mask >> i & 1) continue;
         for (int j = 0; j < n; ++j) {
            if (mask >> j & 1) {
               if (!dp[mask][j]) continue;
               if (isW[j][i] || isG[j][i]) {
                  dp[mask | (1 << i)][i] = true;
               }
            }
         }
      }
   }
   int res = n;
   for (int mask = 0; mask < (1 << n); ++mask) {
      for (int i = 0; i < n; ++i) {
         if (dp[mask][i]) {
            res = min(res, n - __builtin_popcount(mask));
         }
      }
   }
   dbg("END\n");
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