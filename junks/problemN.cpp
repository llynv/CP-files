/*
  Code by: linvg
  Created: 27.09.2024 16:36:52
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
   vector<int> fr(n), ba(n);
   for (auto& c : fr) cin >> c;
   for (auto& c : ba) cin >> c;
   int K, L;
   cin >> K >> L;
   multiset<int> sBaL1, sBaL2;
   int sumK = 0, sumL = 0;
   int res = 0;
   for (int i = 0; i < K; ++i) {
      if (sBaL1.size() < L) {
         sBaL1.insert(ba[i]);
         sumL += ba[i];
      }
      else {
         if (*sBaL1.begin() < ba[i]) {
            int x = *sBaL1.begin();
            sBaL1.erase(sBaL1.begin());
            sBaL1.insert(ba[i]);
            sumL += ba[i] - x;
            sBaL2.insert(x);
         }
         else {
            sBaL2.insert(ba[i]);
         }
      }
      sumK += fr[i];

      res = max(res, sumK + sumL);
      dbg(res, sumK, sumL);
   }
   for (int i = K - 1, j = n - 1; i >= 0; --i, --j) {
      sumK -= fr[i];
      sumK += fr[j];

      if (*sBaL1.begin() < ba[j]) {
         int x = *sBaL1.begin();
         sBaL1.erase(sBaL1.begin());
         sBaL1.insert(ba[j]);
         sumL += ba[j] - x;
         sBaL2.insert(x);
      } else {
         sBaL2.insert(ba[j]);
      }

      if (sBaL2.find(ba[i]) != sBaL2.end()) {
         sBaL2.erase(sBaL2.find(ba[i]));
      }
      else if (sBaL1.find(ba[i]) != sBaL1.end()) {
         sBaL1.erase(sBaL1.find(ba[i]));
         sumL -= ba[i];
         if (!sBaL2.empty()) {
            int x = *sBaL2.rbegin();
            sBaL2.erase(sBaL2.find(x));
            sBaL1.insert(x);
            sumL += x;
         }
      }

      dbg(sz(sBaL1), sz(sBaL2), sumK, sumL);
      dbg(sBaL1);

      res = max(res, sumK + sumL);
   }
   cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}