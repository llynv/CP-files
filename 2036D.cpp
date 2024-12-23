
/*
  Code by: linvg
  Created: 02.11.2024 21:36:13
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
   vector<vector<char>> a(n, vector<char>(m));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
         cin >> a[i][j];
      }
   }
   int res = 0;
   string target = "1543";
   for (int i = 0; i < (min(n, m) + 1) / 2; ++i) {
      vector<char> v;
      int p = -1;
      for (int j = i; j < m - i; ++j) {
         v.push_back(a[i][j]);
         if (a[i][j] == '1' && p == -1) {
            p = v.size() - 1;
         }
      }
      for (int j = i + 1; j < n - i; ++j) {
         v.push_back(a[j][m - i - 1]);
         if (a[j][m - i - 1] == '1' && p == -1) {
            p = v.size() - 1;
         }
      }
      for (int j = m - i - 2; j >= i; --j) {
         v.push_back(a[n - i - 1][j]);
         if (a[n - i - 1][j] == '1' && p == -1) {
            p = v.size() - 1;
         }
      }
      for (int j = n - i - 2; j > i; --j) {
         v.push_back(a[j][i]);
         if (a[j][i] == '1' && p == -1) {
            p = v.size() - 1;
         }
      }
      int cnt = 0;
      for (int k = 0; k < v.size(); ++k, p = (p + 1) % v.size()) {
         if (v[p] == target[cnt % 4]) {
            ++cnt;
         } else {
            cnt = (v[p] == '1'); 
         }
         if (cnt == 4) {
            res++;
            cnt = 0;
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