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

const int N = 2e2 + 7;
const int MOD = 1e9 + 7;

vector<int> fact(N), inv(N);

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
   fact[0] = 1;
   for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % MOD;
   inv[N - 1] = power(fact[N - 1], MOD - 2);
   for (int i = N - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int nCr(int n, int r) {
   if (r < 0 || r > n) return 0;
   return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int nPr(int n, int r) {
   if (r < 0 || r > n) return 0;
   return fact[n] * inv[n - r] % MOD;
}

void solve()
{
   int n, m;
   cin >> m >> n;
   vector<int> s(m), l(m);
   for (auto &c : s) cin >> c;
   for (auto &c : l) cin >> c;

   vector<int> type(2);
   for (int i = 0; i < m; ++i) {
      type[l[i] != 0]++;
   }

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
   pre();
   solve();
   return 0;
}