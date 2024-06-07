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
   vector<int> a(n);
   for (auto& c : a) cin >> c;

   vector<vector<int>> dp(n + 1, vector<int>(1LL << n));

   auto maxi = [&](int& a, int b) {
      a = max(a, b);
      };

   for (int mask = 0; mask < (1LL << n); ++mask) {
      for (int i = 0; i < n; ++i) {
         if (mask & (1LL << i)) continue;
         int cnt = __builtin_popcountll(mask);
         int rightMostBit = i + 1, leftMostBit = i - 1;
         while (rightMostBit < n && (mask & (1LL << rightMostBit))) ++rightMostBit;
         while (leftMostBit >= 0 && (mask & (1LL << leftMostBit))) --leftMostBit;

         int leftVal = (leftMostBit < 0 ? 1 : a[leftMostBit]);
         int rightVal = (rightMostBit >= n ? 1 : a[rightMostBit]);

         maxi(dp[cnt + 1][mask | (1LL << i)], dp[cnt][mask] + leftVal * rightVal * a[i]);
      }
   }

   cout << dp[n][(1LL << n) - 1] << '\n';
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