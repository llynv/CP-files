
/*
  Code by: linvg
  Created: 05.11.2024 16:08:03
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
   int q;
   cin >> q;
   multiset<array<int, 2>> s;
   s.insert({1, n});
   int remain = n;
   while (q--) {
      int l, r, k;
      cin >> l >> r >> k;
      if (k == 1) {
         auto it = s.upper_bound({l, INF});
         if (it != s.begin()) --it;
         int mx = r, mn = l;
         dbg(1, 'p', remain, s);
         while (it != s.end() && it->at(0) <= r) {
            if (it->at(1) < l) {
               ++it;
               continue;
            }
            mx = max(mx, it->at(1));
            mn = min(mn, it->at(0));
            remain -= it->at(1) - it->at(0) + 1;
            it = s.erase(it);
         }
         if (l > mn) s.insert({mn, l - 1});
         if (r < mx) s.insert({r + 1, mx});
         remain += l - mn + mx - r;
         dbg(1, remain, s);
         cout << remain << '\n'; 
      } else {
         auto it = s.upper_bound({l, INF});
         if (it != s.begin()) --it;
         int mx = r, mn = l;
         while (it != s.end() && it->at(0) <= r) {
            if (it->at(1) < l) {
               ++it;
               continue;
            }
            mx = max(mx, it->at(1));
            mn = min(mn, it->at(0));
            remain -= it->at(1) - it->at(0) + 1;
            it = s.erase(it);
         }
         s.insert({mn, mx});
         remain += mx - mn + 1;
         dbg(2, remain, s);
         cout << remain << '\n';
      }
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}