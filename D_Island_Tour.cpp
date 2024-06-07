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

#define DBG

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, m;
   cin >> n >> m;

   vector<int> a(m);
   for (auto& c : a) cin >> c;
   int in = 0, out = 0;
   vector<int> pref(n + 2);
   for (int i = 1; i < m; ++i) {
      if (abs(a[i] - a[i - 1]) == n - abs(a[i] - a[i - 1])) {
         continue;
      }

      if (abs(a[i] - a[i - 1]) < n - abs(a[i] - a[i - 1])) {
         pref[min(a[i], a[i - 1])+1] += 1;
         pref[max(a[i], a[i - 1])] -= 1;
      }
      else {
         pref[min(a[i], a[i - 1])] -= 1;
         pref[max(a[i], a[i - 1])+1] += 1;
      }
   }
   partial_sum(all(pref), pref.begin());
   int idx = min_element(pref.begin()+1, pref.end()-1) - pref.begin();
   // dbg(pref);
   // cerr << "idx: " << idx.size() << "\n";
   int ans = 0;
   for (int i = 1; i < m; ++i) {
      if (min(a[i], a[i - 1]) < idx && idx <= max(a[i], a[i - 1])) {
         ans += n - abs(a[i] - a[i - 1]);
      }
      else {
         ans += abs(a[i] - a[i - 1]);
      }
   }
   // dbg(pref);
   cout << ans << "\n";
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