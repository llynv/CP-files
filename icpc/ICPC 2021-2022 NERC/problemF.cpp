/*
  Code by: linvg
  Created: 01.10.2024 15:04:38
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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e9 + 7;

double fpow(int x, int y) {
   double res = 1;
   for (int i = 0; i < y; ++i) {
      res *= x;
      if (res > 1e9) {
         return 1e10;
      }
   }
   return res;
}

int find_element(int x, int eps) {
   int l = 1, r = 1e9;
   while (l <= r) {
      int mid = (l + r) / 2;
      double step = fpow(mid, eps);
      if (step > 1e9) {
         r = mid - 1;
         continue;
      }
      int total = (int)step;
      if (total == x) {
         return mid;
      }
      if (total > x) {
         r = mid - 1;
      }
      else {
         l = mid + 1;
      }
   }
   return (r != x ? -1 : r);
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   unordered_map<int, int> total;
   int res = 0;
   map<int, int> mp;
   int ans = 0;
   for (auto& c : a) {
      cin >> c;
      mp[c] += c;
      ans = max(ans, mp[c]);
   }

   for (int x = 2; x < 1e5; ++x) {
      int cnt = 0;
      for (int j = x; j <= 1e9; j *= x) {
         cnt += mp[j];
      }
      ans = max(ans, cnt);
   }

   cout << ans << "\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}