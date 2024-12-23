/*
  Code by: linvg
  Created: 17.12.2024 14:24:23
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
   vector<string> s(2);
   cin >> s[0] >> s[1];
   int flag = count_if(all(s[0]), [](char c) { return c == '.'; }) + count_if(all(s[1]), [](char c) { return c == '.'; });
   if (flag % 2 != 0) return void (cout << "None\n");
   for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < 2; ++j) {
         if (s[j][i] == '.' && s[j][i + 1] == '.' && s[j ^ 1][i] == '#') {
            s[j][i] = s[j][i + 1] = '#';
         }
      }
   }
   for (int i = n - 1; i > 0; --i) {
      for (int j = 0; j < 2; ++j) {
         if (s[j][i] == '.' && s[j][i - 1] == '.' && s[j ^ 1][i] == '#') {
            s[j][i] = s[j][i - 1] = '#';
         }
      }
   }
   for (int i = 0; i < n - 1; ++i) {
      int cnt = (s[0][i] == '.') + (s[0][i + 1] == '.') + (s[1][i] == '.') + (s[1][i + 1] == '.');
      if (cnt == 1) return void (cout << "None\n");
      if (cnt == 2) {
         if (s[0][i] != s[1][i]) return void (cout << "None\n");
      }
   }
   for (int i = 0; i < n - 1; ++i) {
      int cnt = (s[0][i] == '.') + (s[0][i + 1] == '.') + (s[1][i] == '.') + (s[1][i + 1] == '.');
      if (cnt == 4) return void (cout << "Multiple\n");
   }
   cout << "Unique\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}