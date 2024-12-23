

/*
  Code by: linvg
  Created: 26.11.2024 20:52:58
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
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int l = 0, r = *max_element(all(a)), ans = -1;
   int init = accumulate(all(a), 0ll);
   while (l <= r) {
      int m = (l + r) >> 1;
      bool ok = true;
      vector<int> b = a;
      for (int i = 0; i < 6 * n; ++i) {
         int id = i % n;
         int idx = (id + 1) % n;
         int idp = (id - 1 + n) % n;
         int d = abs(b[id] - m);
         if (b[id] > m) {
            b[id] -= d + (d % 2);
            b[idx] += (d + (d % 2)) / 2;
            if (b[id] < m) {
               b[id]++;
               b[idp] -= 2;
            }
         } else {
            b[id] += d;
            b[idp] -= 2 * d;
         }
      }
      for (auto &c : b) {
         if (c != m || c < 0) {
            ok = false;
            break;
         }
      }
      if (ok) {
         // dbg("final", a, b);
         l = m + 1;
         ans = m;
      } else {
         r = m - 1;
      }
   }
   cout << (ans == -1 ? -1 : init - ans * n) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}