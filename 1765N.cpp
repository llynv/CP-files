/*
  Code by: linvg
  Created: 06.12.2024 23:44:20
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
   string s;
   int k;
   cin >> s >> k;
   vector<set<int>> pos(10);
   for (int i = 0; i < sz(s); ++i) {
      pos[s[i] - '0'].insert(i);
   }
   string res;
   int n = sz(s);
   k = n - k;
   int mock = n - k, last = 0;
   for (int l = 1; l <= 9; ++l) {
      auto it = pos[l].lower_bound(last);
      if (it != pos[l].end() && *it <= mock) {
         res += l + '0';
         last = *it;
         mock++;
         pos[l].erase(it);
         break;
      }
   }
   for (int i = 1; i < k; ++i) {
      for (int l = 0; l <= 9; ++l) {
         auto it = pos[l].lower_bound(last);
         if (it != pos[l].end() && *it <= mock) {
            res += l + '0';
            last = *it;
            mock++;
            pos[l].erase(it);
            break;
         }
      }
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}