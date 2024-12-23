/*
  Code by: linvg
  Created: 09.12.2024 07:55:05
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

const int N = 1e5 + 7;

int fw[26][N];

void add(int i, int j, int v) {
   for (; i < N; i += i & -i) fw[j][i] += v;
}

int get(int i, int j) {
   int res = 0;
   for (; i; i -= i & -i) res += fw[j][i];
   return res;
}

void solve()
{  
   string s;
   cin >> s;
   int n = sz(s);
   for (int i = 1; i <= n; ++i) {
      add(i, s[i - 1] - 'a', 1);
   }
   int q;
   cin >> q;
   while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
         int id;
         char c;
         cin >> id >> c;
         add(id, s[id - 1] - 'a', -1);
         add(id, c - 'a', 1);
         s[id - 1] = c;
      } else {
         int l, r;
         cin >> l >> r;
         int ans = 0;
         for (int i = 0; i < 26; ++i) {
            ans += get(r, i) - get(l - 1, i) > 0;
         }
         cout << ans << '\n';
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