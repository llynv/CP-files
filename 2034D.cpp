/*
  Code by: linvg
  Created: 30.11.2024 22:26:11
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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
const int MOD = 1e9 + 7;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   set<int> t_in_z, t_in_o, z_in_o, z_in_t, o_in_t, o_in_z;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
   }
   vector<int> b = a;
   sort(all(b));
   int o_in_o = -1;
   for (int i = 0; i < n; ++i) {
      if (a[i] == b[i]) {
         if (a[i] == 1) {
            o_in_o = i;
         }
         continue;
      }
      if (a[i] == 0) {
         if (b[i] == 1) {
            z_in_o.insert(i);
         } else {
            z_in_t.insert(i);
         }
      } else if (a[i] == 1) {
         if (b[i] == 0) {
            o_in_z.insert(i);
         } else {
            o_in_t.insert(i);
         }
      } else {
         if (b[i] == 0) {
            t_in_z.insert(i);
         } else {
            t_in_o.insert(i);
         }
      }
   }
   vector<array<int, 2>> res;
   dbg(a);
   while (sz(z_in_o) != 0 || sz(t_in_o) != 0) {
      while (sz(t_in_z) && sz(o_in_t)) {
         int x = *t_in_z.begin();
         int y = *o_in_t.begin();
         res.push_back({x + 1, y + 1});
         swap(a[x], a[y]);
         t_in_z.erase(x);
         o_in_t.erase(y);
         o_in_z.insert(x);
      }
      while (sz(t_in_o) && sz(o_in_t)) {
         int x = *t_in_o.begin();
         int y = *o_in_t.begin();
         res.push_back({x + 1, y + 1});
         o_in_o = x;
         swap(a[x], a[y]);
         t_in_o.erase(x);
         o_in_t.erase(y);
      }
      while (sz(z_in_o) && sz(o_in_z)) {
         int x = *z_in_o.begin();
         int y = *o_in_z.begin();
         res.push_back({x + 1, y + 1});
         o_in_o = x;
         swap(a[x], a[y]);
         z_in_o.erase(x);
         o_in_z.erase(y);
      }
      while(sz(o_in_z) && sz(z_in_t)) {
         int x = *o_in_z.begin();
         int y = *z_in_t.begin();
         res.push_back({x + 1, y + 1});
         swap(a[x], a[y]);
         o_in_z.erase(x);
         z_in_t.erase(y);
         o_in_t.insert(y);
      }
      dbg(a);
   }
   dbg("1", a);
   if (sz(t_in_z) && sz(z_in_t)) {
      while (sz(t_in_z) && sz(z_in_t)) {
         dbg(a);
         int x = *t_in_z.begin();
         int y = *z_in_t.begin();
         int o = o_in_o;
         res.push_back({x + 1, o + 1});
         swap(a[x], a[o]);
         res.push_back({x + 1, y + 1});
         swap(a[x], a[y]);
         t_in_z.erase(x);
         z_in_t.erase(y);
         o_in_o = y;
      }
      dbg(a);
   }
   if (!is_sorted(all(a))) {
      for (int i = 0; i < n; ++i) {
         if (a[i] == 2) {
            for (int j = n - 1; j > i; --j) {
               if (a[j] == 1) {
                  res.push_back({i + 1, j + 1});
                  swap(a[i], a[j]);
                  break;
               }
            }
            break;
         }
      }
      dbg(a);
   }
   // assert(sz(res) <= n);
   // assert(is_sorted(all(a)));
   cout << sz(res) << '\n';
   for (auto [x, y] : res) {
      cout << x << ' ' << y << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}