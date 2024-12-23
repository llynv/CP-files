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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int> fact(N), inv(N);

int fpow(int a, int b, int m) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % m;
      a = a * a % m;
      b >>= 1;
   }
   return res;
}

void pre() {
   fact[0] = 1;
   inv[0] = 1;
   for (int i = 1; i < N; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = fpow(fact[i], MOD - 2, MOD);
   }
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
   int n, m1, m2;
   cin >> n >> m1 >> m2;
   vector<int> a(m1), b(m2);
   for (auto& c : a) cin >> c;
   for (auto& c : b) cin >> c;

   if (m1 >= 2 && m2 >= 2) {
      if (find(all(a), b[m2 - 2]) != a.end() && find(all(a), b[m2 - 1]) != a.end()) {
         cout << "0\n";
         return;
      }
   }

   if (sz(a) && sz(b) && b.front() != a.back()) return void (cout << "0\n");

   int res = 1;
   for (int i = 1; i < m1; ++i) {
      res *= fact[a[i]-a[i-1]-1];
   }
   cout << res << '\n';
   dbg(res);
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   pre();
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}