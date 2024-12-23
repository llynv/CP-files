/*
  Code by: linvg
  Created: 21.09.2024 21:47:28
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
   int n, d, k;
   cin >> n >> d >> k;
   vector<array<int, 2>> a(k);
   vector<int> open(n + 2), close(n + 2);
   for (auto &[l, r] : a) {
      cin >> l >> r;
      open[l]++;
      close[r + 1]--;
   }
   int bro = 0, broPos = 0, mom = INF, momPos = 0;
   int total = 0;
   for (int i = 1; i <= d; ++i) {
      total += open[i];
   }
   if (total > bro) {
      bro = total;
      broPos = 1;
   }
   if (total < mom) {
      mom = total;
      momPos = 1;
   }
   for (int i = 2; i + d - 1 <= n; ++i) {
      total += close[i];
      total += open[i + d - 1];
      if (total > bro) {
         bro = total;
         broPos = i;
      }
      if (total < mom) {
         mom = total;
         momPos = i;
      }
   }
   cout << broPos << ' ' << momPos << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}