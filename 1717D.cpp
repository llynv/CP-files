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
const int mod = 1e9 + 7;

vector<int> fact(1e5 + 5, 1), inv(1e5 + 5, 1);

int fpow(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
}
void sieve() {
   for (int i = 1; i < 1e5 + 5; ++i) {
      fact[i] = fact[i - 1] * i % mod;
      inv[i] = fpow(fact[i], mod - 2);
   }
}

int ncr(int n, int r) {
   if (n < r) return 0;
   return fact[n] * inv[r] % mod * inv[n - r] % mod;
}



void solve()
{
   sieve();
   int n, k;
   cin >> n >> k;
   if (n <= k) return void(cout << fpow(2, n) << "\n");
   int res = 0;
   for (int i = 0; i <= k; ++i) {
      res = (res + ncr(n, i)) % mod;
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