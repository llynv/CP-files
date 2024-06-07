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
   vector<int> a(n+2);
   for (int i = 1; i <= n; ++i) cin >> a[i];
   vector<int> pref(n+2);
   for (int i = 1; i <= n; ++i) pref[i] = pref[i-1] + a[i];

   vector<vector<int>> f(21, vector<int>(n+2, 0)), g(20, vector<int>(n+2, 0));
   for (int i = 1; i <= n; ++i) {
      f[0][i] = a[i];
      g[0][i] = a[i];
   }

   for (int i = 1; i <= 20; ++i) {
      for (int j = 1; j <= n; ++j) {
         if (j + (1 << i) - 1 <= n) {
            f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i-1))]);
            g[i][j] = min(g[i-1][j], g[i-1][j + (1 << (i-1))]);
         }
      }
   }

   auto get_max = [&](int l, int r) {
      int k = log2(r - l + 1);
      return max(f[k][l], f[k][r - (1 << k) + 1]);
   };

   auto get_min = [&](int l, int r) {
      int k = log2(r - l + 1);
      return min(g[k][l], g[k][r - (1 << k) + 1]);
   };

   auto check = [&](int l, int r, int target) {
      int sum = pref[r] - pref[l-1];
      int mx = get_max(l, r);
      int mn = get_min(l, r);
      if (sum <= target) return false;
      return mx != mn;
   };

   for (int i = 1; i <= n; ++i) {
      if (a[i] < a[i-1] || a[i] < a[i+1]) {
         cout << 1 << " ";
         continue;
      }

      int l = i+1, r = n, rPos = -1;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (check(i+1, mid, a[i])) {
            r = mid - 1;
            rPos = mid;
         }
         else l = mid + 1;
      }

      l = 1, r = i-1;
      int lPos = -1;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (check(mid, i-1, a[i])) {
            l = mid + 1;
            lPos = mid;
         }
         else r = mid - 1;
      }

      if (lPos == -1 && rPos == -1) {
         cout << -1 << " ";
         continue;
      }

      if (lPos == -1) {
         cout << rPos - i << " ";
         continue;
      }
      if (rPos == -1) {
         cout << i - lPos << " ";
         continue;
      }
      cout << min(i - lPos, rPos - i) << " ";
   }
   cout << "\n";
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