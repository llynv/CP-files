/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

// const int INF = 0x3f3f3f3f3f;
const int N = 1e6 + 7;


void solve()
{

   int n, m;
   cin >> n >> m;
   vector<pair<vector<int>, int>> a(n);
   for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      a[i].second = i;
      a[i].first.assign(k, 0);
      for (auto& x : a[i].first) {
         cin >> x;
      }
   }
   sort(all(a), [&](auto& x, auto& y) {
      return sz(x.first) < sz(y.first);
      });

   a.push_back({ {1}, n });

   int pre = 0;
   unordered_map<int, int> mp, good;
   for (int i = 1; i <= n; ++i) {
      if (sz(a[i].first) != sz(a[i - 1].first)) {
         for (int j = pre; j < i; ++j) {
            for (auto& x : a[j].first) {
               if (mp.find(x) != mp.end()) {
                  good[mp[x]]++;
               }
               mp[x] = j;
            }
         }

         dbg(good);

         for (auto [pos, cnt] : good) {
            if (cnt != sz(a[pos].first)) {
               cout << "YES\n";
               for (auto x : a[pos].first) {
                  if (mp[x] != pos) {
                     cout << a[pos].second + 1 << " " << a[mp[x]].second + 1 << "\n";
                     break;
                  }
               }
               return;
            }
         }

         pre = i;
      }
   }

   cout << "NO\n";
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