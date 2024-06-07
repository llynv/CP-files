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

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n), b(n), q(n);
   for (auto &c : q) cin >> c;
   for (auto &c : a) cin >> c;
   for (auto &c : b) cin >> c;

   int mx = *max_element(all(q));
   int res = 0;
   for (int i = 0; i <= mx; ++i) {
      int sum1 = INF, sum2 = INF;
      for (int j = 0; j < n; ++j) {
         if (a[j] * i <= q[j]) {
            if (b[j] != 0) {
               sum1 = min(i + (q[j] - a[j] * i) / b[j], sum1); 
            } else {
               sum1 = min(sum1, INF);
            }
            continue;
         }
         sum1 = 0;
         break;
      }
      dbg(i, sum1);
      res = max(res, sum1);
   }
   cout << res << "\n";
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}