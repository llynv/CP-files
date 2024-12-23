/*
  Code by: linvg
  Created: 02.11.2024 21:58:45
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
   map<pair<int, int>, int> mp;

   auto ask = [&](int l, int r) {
      if (mp.count({ l, r })) {
         return mp[{l, r}];
      }
      cout << "xor " << l << ' ' << r << '\n';
      cout.flush();
      int res;
      cin >> res;
      mp[{l, r}] = res;
      return res;
   };

   int t = ask(1, n);
   if (t != 0) {
      int l = 1, r = n;
      int first, second, third;
      int p1 = 0, p2 = 0;
      while (l <= r) {
         int m = l + (r - l) / 2;
         int x = ask(1, m);
         if (x != 0) {
            r = m - 1;
            first = x;
            p1 = m;
         }
         else {
            l = m + 1;
         }
      }
      l = p1 + 1, r = n;
      while (l <= r) {
         int m = l + (r - l) / 2;
         int x = ask(p1 + 1, m);
         if (x != 0) {
            r = m - 1;
            second = x;
         }
         else {
            l = m + 1;
         }
      }
      third = t ^ second ^ first;
      cout << "ans " << first << ' ' << (second) << ' ' << third << '\n';
      cout.flush();
   }
   else {
      int start = 1;
      int x = 0;
      while (start <= n) {
         x = ask(1, start);
         if (x != 0) {
            break;
         }
         start = start << 1 | 1;
      }
      dbg(x, start);
      int l = 1, r = start;
      int first = 0;
      while (l <= r) {
         int m = l + (r - l) / 2;
         int y = ask(1, m);
         if (y != 0) {
            first = y;
            r = m - 1;
         }
         else {
            l = m + 1;
         }
      }
      int second = 0;
      if (first != x) {
         second = x;
         cout << "ans " << (int)first << ' ' << (int)second << ' ' << (int)(first ^ second) << '\n';
         cout.flush();
      }
      else {
         l = start + 1, r = n;
         int third = 0;
         while (l <= r) {
            int m = l + (r - l) / 2;
            int y = ask(start + 1, m);
            if (y == 0) {
               l = m + 1;
            }
            else {
               r = m - 1;
               second = y;
            }
         }
         cout << "ans " << first << ' ' << second << ' ' << (int)(first ^ second) << '\n';
         cout.flush();
      }
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