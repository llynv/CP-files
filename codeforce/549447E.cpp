/*
  Code by: linvg
  Created: 29.09.2024 20:11:49
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e9 + 7;

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<vector<char>> a(n, vector<char>(m)); 
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }

   for (int j = 0; j < m; ++j) {
      int stone = 0, empty = 0, prev = 0;
      for (int i = 0; i < n; ++i) {
         empty += (a[i][j] == '.');
         stone += (a[i][j] == '*');
         if (a[i][j] == 'o' || i == n - 1) {
            for (int k = prev; k < empty + prev; ++k) a[k][j] = '.';
            for (int k = empty + prev; k < empty + stone + prev; ++k) a[k][j] = '*';
            empty = stone = 0;   
            prev = i + 1;
            continue;
         }
      }
   }
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cout << a[i][j];
      }
      cout << '\n';
   }
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}