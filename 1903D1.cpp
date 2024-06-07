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

int safePlus(int a, int b) {
   if (a > 2e18 - b) return 2e18;
   return a + b;
}

void solve()
{
   int n, q;
   cin >> n >> q;
   vector<int> a(n);
   for (auto& c : a) cin >> c;

   vector<int> b = a;
   vector<int> init(64, 0);
   for (int i = 61; i >= 0; --i) {
      int tmp = ((1ll << i) & a[0]);
      for (int j = 0; j < n; ++j) {
         tmp &= ((1ll << i) & a[j]);
      }
      init[i] = init[i + 1] | tmp;
      // dbg(i, init[i]);
   }

   while (q--) {
      int k;
      cin >> k;
      b = a;
      int ans = 0, mx = -1;
      int xVal = ~0ll;
      for (int i = 61; i >= 0; --i) {
         xVal ^= (1LL << i);
         int sum = 0;
         for (int j = 0; j < n; ++j) {
            if (!(b[j] >> i & 1)) {
               b[j] &= xVal;
               // sum += (1LL << i) - b[j];
               sum = safePlus(sum, (1LL << i) - b[j]);
            }
         }
         if (sum <= k) {
            dbg(i, sum, k);
            k -= sum;
            ans |= (1LL << i);
            for (int j = 0; j < n; ++j) {
               if (!(b[j] >> i & 1)) {
                  b[j] = 0;
               }
            }
            dbg(i, ans);
            mx = max(mx, i);
         }
      }
      dbg(k, ans, mx);
      if (mx != -1) {
         ans |= init[mx + 1];
      }
      cout << ans << endl;
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