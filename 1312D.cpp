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
const int MOD = 998244353;

vector<int> fact(200005, 1), inv(200005, 1);

int power(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}

void pre() {
   for (int i = 1; i < 200005; ++i) fact[i] = fact[i - 1] * i % MOD;
   inv[200004] = power(fact[200004], MOD - 2);
   for (int i = 200003; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int ncr(int n, int r) {
   if (n < r) return 0;
   return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void solve()
{
   int n, m;
   cin >> n >> m;

   int res = 0;
   
   for (int i = 2; i <= n - 1; ++i) {

      if (i == 2 || i == n-1) {
         res = (res + ncr(m, n - 1) * (n - 2)) % MOD;
         continue;   
      }

      int mx = max(i - 1, n - i), mn = min(i - 1, n - i);
      res += ncr(m, n - 1) % MOD * ncr(n - 2, mx - 1) % MOD * mn % MOD;
   }
   cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   pre();
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}