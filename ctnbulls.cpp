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
const int MOD = 2111992;

void back (int n, int k, int j, string s, int &res)
{
   if (sz(s) == n) {
      res++;
      cout << s << '\n';
      return;
   }
   for (char i = '0'; i <= '1'; ++i) {
      s += i;
      int cnt = 0;
      bool ok = 1;
      int pos = 0;
      while (pos < sz(s) && s[pos] == '1') ++pos;
      ++pos;
      for (int l = pos; l < sz(s); ++l) {
         if (s[l] == '1') ++cnt;
         else {
            if (cnt < k) {
               ok = 0;
               break;
            }
            cnt = 0;
         }
      }
      if (ok) {
         back(n, k, j, s, res);
      }
      s.pop_back();
   }
}

void solve()
{
   int n, k;
   cin >> n >> k;
   vector<int> dp (n+1), pref(n+1);
   dp[1] = 1;
   pref[1] = 1;
   for (int i = 2; i <= n; ++i) {
      dp[i] = 1;
      dp[i] %= MOD;

      if (i - k - 1 >= 0) {
         dp[i] += pref[i - k - 1];
         dp[i] %= MOD;
      }

      pref[i] = pref[i-1] + dp[i];
      pref[i] %= MOD;
   }
   int ans = 0;
   for (int i = n; i >= 1; --i) {
      ans += dp[i];
      ans %= MOD;
   }
   cout << (ans + 1) % MOD << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}