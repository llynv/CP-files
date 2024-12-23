/*
  Code by: linvg
  Created: 24.11.2024 07:40:29
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
   int n, m;
   cin >> n >> m;
   vector<int> a(m);
   for (auto &c : a) cin >> c;
   sort(all(a), greater<int>());
   vector<int> b(n + 1);
   b[1] = a[0];
   set<int> s;
   for (int i = 2; i <= n; ++i) s.insert(i);
   int id = 1;
   while (s.size()) {
      int i = *s.begin();
      if (id == m) {
         cout << -1 << '\n';
         return;
      }
      b[i] = a[id];
      vector<int> f = {i};
      set<int> t;
      for (auto c : s) {
         for (int j = c + c; j <= n; j += c) {
            t.insert(j);
            s.erase(j);
         }         
         b[c] = a[id];
      }
      dbg(f);
      dbg(t);
      dbg(s);
      dbg(b);
      swap(s, t);
      ++id;
   }
   for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i == n];
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = i + 1; j <= n; ++j) {
   //       if (b[gcd(i, j)] == gcd(b[i], b[j])) {
   //          cerr << i << ' ' << j << ' ' << b[i] << ' ' << b[j] << ' ' << b[gcd(i, j)] << '\n';
   //       }
   //    }
   // } 
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}