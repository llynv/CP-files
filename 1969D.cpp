/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define LOCAL
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n, k;
   cin >> n >> k;
   std::vector<ii> prod(n);
   for (auto &c : prod) cin >> c.fi;
   for (auto &c : prod) cin >> c.se;

   vector<ii> tmp;
   for (auto &c : prod) if (c.fi <= c.se) tmp.push_back(c);
   swap(prod, tmp);

   sort(all(prod), [&] (ii a, ii b) {
      return (a.fi < b.fi);
   });

   // dbg(prod);
   int res = 0, total = 0, sum = 0;
   ordered_set s;
   for (int j = 0; j < sz(prod); ++j) {
      auto c = prod[j];
      total += c.se - c.fi;
      s.insert({c.se, j});
      int pos = s.order_of_key({c.se, j});
      if (pos < k) {
         sum += c.se;
         if (sz(s) >= k) {
            sum -= (*s.find_by_order(k)).fi;
         }
      }
      dbg(total, sum);
      res = max(res, total - sum);
   }
   dbg(s);
   cout << res << '\n';   
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