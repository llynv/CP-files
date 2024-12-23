
/*
  Code by: linvg
  Created: 02.11.2024 22:34:15
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
   int n, k, q;
   cin >> n >> k >> q;  
   vector<vector<int>> a(n + 1, vector<int>(k + 1));
   vector<vector<int>> reg(k, vector<int>(n));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
         cin >> a[i][j];
         a[i][j] |= a[i - 1][j]; 
         reg[j - 1][i - 1] = a[i][j];
      }
   }
   while (q--) {
      int m;
      cin >> m;
      int mx = 0, mn = INT_MAX;   
      for (int i = 0; i < m; ++i) {
         int x, c;
         char op;
         cin >> x >> op >> c;
         --x;
         if (op == '<') {
            int p = lower_bound(reg[x].begin(), reg[x].end(), c) - reg[x].begin() - 1;
            mx = max(mx, 0ll);
            mn = min(mn, p);
         } else {
            int p = upper_bound(reg[x].begin(), reg[x].end(), c) - reg[x].begin();
            mx = max(mx, p);
            mn = min(mn, n - 1);
         }
      }
      if (mx >= n || mn <= -1 || mx > mn) {
         cout << "-1\n";
         continue;
      }
      cout << mx + 1 << '\n';
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