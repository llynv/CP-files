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
   vector<pair<int, int>> a(n + 1);
   set<int> s;
   for (int i = 0; i <= n; ++i) {
      cin >> a[i].fi >> a[i].se;
      if (i > 0) s.insert(i);
   }

   auto ask = [&](int x) {
      cout << x << endl;
      cout.flush();
      int res;
      cin >> res;
      if (res == -1) exit(0);
      return res;
      };

   set<int> sets[2];
   bool is_oe = (a[0].fi & 1) != (a[0].se & 1);
   vector<int> state(n + 1);
   set<int> total;
   for (int i = 1; i <= n; ++i) {
      if ((a[i].fi & 1) != (a[i].se & 1)) {
         sets[1].insert(i);
         state[i] = 1;
      }
      else {
         sets[0].insert(i);
         state[i] = 0;
      }
      total.insert(i);
   }
   dbg(sets[0], sets[1]);
   int init = (a[0].fi & 1) != (a[0].se & 1);
   if ((is_oe && sz(sets[1]) >= sz(sets[0])) || (!is_oe && sz(sets[0]) >= sz(sets[1]))) {
      cout << "First" << endl;
      cout.flush();
      if (n == 1) {
         cout << 1 << endl;
         cout.flush();
         return;
      }
   }
   else {
      cout << "Second" << endl;
      cout.flush();
      int res;
      cin >> res;
      init = state[res];
      sets[init].erase(sets[init].find(res));
   }

   for (; sz(sets[0]) + sz(sets[1]) > 0;){
      init ^= 1;
      if (sz(sets[init]) == 0) {
         while (sz(sets[init ^ 1]) != 0) {
            int x = *sets[init ^ 1].begin();
            sets[init ^ 1].erase(sets[init ^ 1].begin());
            if (sets[init ^ 1].empty()) {
               cout << x << endl;
               cout.flush();
               return;
            }
            int res = ask(x);
            sets[init ^ 1].erase(sets[init ^ 1].find(res));
         }
         return;
      }
      int x = *sets[init].begin();
      sets[init].erase(sets[init].begin());
      if (sets[init].empty() && sets[init ^ 1].empty()) {
         cout << x << endl;
         cout.flush();
         return;
      }
      int res = ask(x);
      init = state[res];
      sets[init].erase(sets[init].find(res));
   }
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