/*
  Code by: linvg
  Created: 09.12.2024 15:59:07
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
   vector<string> s(n);
   for (auto& c : s) cin >> c;
   map<pair<pair<int, int>, pair<string, string>>, int> cnt;
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         if (sz(s[i]) == sz(s[j])) {
            vector<int> dif;
            pair<string, string> g;
            for (int l = 0; l < sz(s[i]); ++l) {
               if (s[i][l] != s[j][l]) {
                  g.first += s[i][l];
                  g.second += s[j][l];
                  dif.push_back(l);
               }
            }
            if (dif.size() == 2 && dif.back() == dif.front() + 1) {
               if (g.first > g.second) swap(g.first, g.second);
               cnt[{{dif.front(), sz(s[i])}, g}]++;
            }
         }
      }
   }
   int res = 0;
   for (auto [u, v] : cnt) res += v == 1;
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}