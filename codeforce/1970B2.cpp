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
   for (auto& c : a) cin >> c;

   vector<ii> pos(1);
   pos[0] = { 1, 1 };
   auto dist = [](int x, int y, int u, int v) {
      return abs(x - u) + abs(y - v);
      };
   vector<int> ans(n);
   ans[0] = 1;
   for (int i = 2; i <= n; ++i) {
      if (a[i-1] == 0) {
         pos.push_back({ i, 1 });
         ans[i - 1] = i;
         continue;
      }
      for (int j = max(0ll, i - a[i-1] - 1); j < sz(pos); ++j) {
         int x = pos[j].se;
         int y = j + 1;
         bool ok = 0;
         dbg(x, y);
         dbg(i, j, a[i - 1], dist(x, y, 1, i), dist(x, y, n, i));
         if (dist(x, y, 1, i) >= a[i - 1] && dist(x, y, x, i) <= a[i-1]) {
            int l = 1, r = x;
            while (l <= r) {
               int mid = (l + r) >> 1;
               if (dist(x, y, mid, i) > a[i - 1]) l = mid + 1;
               else {
                  r = mid - 1;
               }
            }
            pos.push_back({ i, l });
            ok = 1;
            ans[i - 1] = j + 1;
         }
         else if (dist(x, y, n, i) >= a[i - 1] && dist(x, y, x, i) <= a[i-1]) {
            int l = x, r = n;
            while (l <= r) {
               int mid = (l + r) >> 1;
               if (dist(x, y, mid, i) > a[i - 1]) r = mid - 1;
               else {
                  l = mid + 1;
               }
            }
            pos.push_back({ i, r });
            ok = 1;
            ans[i - 1] = j + 1;
         }
         if (ok) break;
      }
   }

   // if (sz(pos) != n) return void(cout << "NO\n");

   cout << "YES\n";
   // dbg(pos);
   for (int i = 0; i < n; ++i) {
      cout << pos[i].fi << " " << pos[i].se << '\n';
   }
   for (int i = 1; i <= n; ++i) {
      if (a[i - 1] == 0) cout << i << ' ';
      else {
         cout << ans[i - 1] << ' ';
      }
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