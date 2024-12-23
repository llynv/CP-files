
/*
  Code by: linvg
  Created: 09.11.2024 22:06:05
*/

#include <bits/stdc++.h>
using namespace std;

#define okay(msg, ...) printf("[+] " msg "\n", ##__VA_ARGS__)
#define fail(msg, ...) printf("[-] " msg "\n", ##__VA_ARGS__)
#define warn(msg, ...) printf("[!] " msg "\n", ##__VA_ARGS__)
#define info(msg, ...) printf("[*] " msg "\n", ##__VA_ARGS__)

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
   vector<int> a(n + 1);
   vector<int> points(n + 1), minRight(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   minRight[n] = a[n];
   for (int i = n - 1; i >= 1; --i) {
      minRight[i] = minRight[i + 1];
      minRight[i] = min(minRight[i], a[i]); 
   }
   int res = 0;
   for (int i = 0; i < n; ++i) {
      if (i > 0) points[i] = points[i - 1];
      points[i] += ((points[i] < a[i]) ? 1 : ((points[i] == a[i]) ? 0 : -1));
      int l = i + 2, r = n, pos = n + 1;
      while (l <= r) {
         int mid = (l + r) >> 1;
         if (minRight[mid] < points[i]) {
            l = mid + 1;
         } else {
            pos = mid;
            r = mid - 1;
         }
      }
      int x = points[i];
      for (int j = pos; j <= n; ++j) {
         x += ((x < a[j]) ? 1 : ((x == a[j]) ? 0 : -1));
      }
      res = max(res, x);
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