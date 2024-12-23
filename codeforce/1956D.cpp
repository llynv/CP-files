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
   for (auto &c : a) cin >> c;

   vector<int> dp(1 << n, 0);
   set<int> init;
   for (int i = 0; i <= n + 1; ++i) init.insert(i);

   vector<ii> v;
   int res = 0;
   for (int mask = 0; mask < (1 << n); ++mask) {
      int sum = 0, l = 0, cur = 0;
      vector<ii> tmp;
      for (int i = 0; i < n; ++i) {
         if (mask >> i & 1) {
            cur = sqr(i - l + 1);
         } else {
            if (cur) tmp.pb({l+1, i});
            sum += cur;
            cur = 0;
            l = i + 1;
            sum += a[i];
         }
      }
      if (cur) {
         tmp.pb({l+1, n});
         sum += cur;
      } 
      if (sum > res) {
         res = sum;
         v = tmp;
      }
   }

   cout << res << ' ';

   vector<ii> ans;

   vector<vector<ii>> f(19);
   f[1] = {{0, 0}};
   f[2] = {{0, 0}, {0, 1}};
   vector<ii> st;
   st = {{0, 0}, {0, 1}, {0, 0}, {0, 0}};
   f[3] = st;
   f[3].pb({0, 2});
   f[4] = f[3];
   f[4].pb({0, 1});
   for (auto &c : st) f[4].pb(c);
   f[4].pb({0, 3});
   for (int i = 5; i <= 18; ++i) {
      f[i] = f[i-1];
      f[i].pb({0, i-3});
      for (auto &c : f[i-1]) f[i].pb(c);
      f[i].pop_back();
      f[i].pb({0, i-1});
   }

   for (auto &[l, r] : v) {
      if (l == r) {
         ans.pb({l, r});
         continue;
      }

      for (int i = l; i <= r; ++i) {
         if (a[i-1] != 0) {
            ans.pb({i, i});
         }
      }

      int range = (r - l + 1);
      for (auto &c : f[range]) {
         ans.pb({l + c.fi, l + c.se});
      }
   }

   cout << sz(ans) << '\n';
   for (auto &[l, r] : ans) {
      cout << l << " " << r << '\n';
   }
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