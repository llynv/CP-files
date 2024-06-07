#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
// #define double long double
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> a(n + 3);
   vector<int> pref(n + 3);
   fu(i, 1, n) {
      cin >> a[i];
      pref[i] = pref[i - 1] + a[i];
   }
   pref[n+1] = pref[n];
   int pos = -1;
   fu(i, 2, n) {
      if (a[i] > a[i - 1]) {
         pos = i - 1;
         break;
      }
   }

   double res = 0;

   auto f = [&](int x) {
      double ans = 0;

      int l = max(pos + 1, x), r = min(n, pos + x - 2);

      while (l <= r) {
         int m1 = l + (r - l) / 3;
         int m2 = r - (r - l) / 3;
         double s1 = (double)(pref[m1] - pref[m1 - x]) / x;
         double s2 = (double)(pref[m2] - pref[m2 - x]) / x;
         if (s1 <= s2) {
            l = m1 + 1;
            ans = max(ans, s2);
         }
         else {
            r = m2 - 1;
            ans = max(ans, s1);
         }
      }

      return ans;
   };


   for (int i = 3; i <= n; ++i) {
      // cerr << f(i) << " \n"[i == n];
      res = max(res, f(i));
   }

   cout << fixed << setprecision(9) << res << "\n";
}
int32_t main() {
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   // freopen("template.inp", "r", stdin);
   // freopen("template.out", "w", stdout);

   int t;
   cin >> t;
   while (t-- > 0) {
      solve();
   }
}