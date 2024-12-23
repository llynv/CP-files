/*
  Code by: linvg
  Created: 21.09.2024 05:33:20
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
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int res = 0, sup = 0;
   bool is_first = false;
   vector<bool> is_up(n, false);
   for (int i = 0; i < n; ++i) {
      if (sup > 0) {
         if (!is_up[i - 1]) {
            a[i] -= sup;
         }
         if (is_up[i - 1] && a[i] > 2) {
            a[i] -= sup;
         }
         sup = 0;
         if (a[i] > 2) {
            res++;
            is_first = false;
         } else if (a[i] > 0) {
            is_up[i] = !is_up[i - 1];
            res++;
            sup = 2;
         } else {
            is_first = false;
         }
      } else {
         if (a[i] > 2) {
            res++;
            is_first = false;
         } else if (a[i] > 0) {
            res++;
            if (!is_first) {
               is_first = true;
            } else {
               is_up[i] = !is_up[i - 1];
            }
            sup = 2;
         } else {
            is_first = false;
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