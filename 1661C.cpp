/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   int top = *max_element(all(a));
   int l = top, r = 2 * top;
   
   auto f = [&] (int mx) -> int {
      int cnt2 = 0, cnt1 = 0;
      // dbg(mx);
      for (auto &c : a) {
         int dist = mx - c;
         if (dist % 3 == 0) {
            if (cnt1 > cnt2 + 1) {
               cnt1 += dist / 3 - 2;
               cnt2 += dist / 3 + 1;
            } else if (cnt1 < cnt2 + 1) {
               cnt1 += dist / 3 + 2;
               cnt2 += dist / 3 - 1;
            } else {
               cnt1 += dist / 3;
               cnt2 += dist / 3;
            }
         }
         if (dist % 3 == 1) {
            if (cnt1 > cnt2 && dist >= 2) {
               cnt1 += dist / 3 - 1;
               cnt2 += dist / 3 + 1;
            } else {
               cnt1 += dist / 3 + 1;
               cnt2 += dist / 3;
            }
         }
         if (dist % 3 == 2) {
            if (cnt1 < cnt2) {
               cnt1 += dist / 3 + 2;
               cnt2 += dist / 3;
            } else {
               cnt1 += dist / 3;
               cnt2 += dist / 3 + 1;
            }
         }
      }
      dbg(cnt1, cnt2);
      return max(cnt2 * 2, cnt1 * 2 - 1);
   };

   while (l < r) {
      int m1 = l + (r - l) / 3;
      int m2 = r - (r - l) / 3;
      int f1 = f(m1);
      int f2 = f(m2);
      if (f1 <= f2) r = m2 - 1;
      else l = m1 + 1;
   }
   dbg(l, r);
   cout << f(l) << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}