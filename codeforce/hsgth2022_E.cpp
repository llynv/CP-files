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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, x, k;
   cin >> n >> x >> k;
   vector<ii> a(n); 
   for (auto &c : a) cin >> c.first >> c.second;
   sort(all(a));

   vector<int> pref(n+1);
   for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i-1] + a[i-1].second;
   }

   int currentPos = lower_bound(all(a), ii(x, -1)) - a.begin();
   int res = 0;
   
   for (int i = currentPos; i < n; ++i) {
      if (abs(x - a[i].first) > k) break;
      int d = abs(x - a[i].first);
      int minPos = lower_bound(all(a), ii(x - k + 2 * d, -1)) - a.begin();
      dbg(i, minPos, pref[i+1], pref[minPos]);
      res = max(res, pref[i+1] - pref[minPos]);
   }

   currentPos -= (currentPos > 0);
   for (int i = currentPos; i >= 0; --i) {
      if (abs(x - a[i].first) > k) break;
      int d = abs(x - a[i].first);
      int maxPos = upper_bound(all(a), ii(x + k - 2 * d, INF)) - a.begin();
      res = max(res, pref[maxPos] - pref[i]);
   }

   cout << res << "\n";
}

#define LOCAL

int32_t main() {

#ifdef LOCAL
   freopen("MARIO.INP", "r", stdin);
   freopen("MARIO.OUT", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}