/*
  Code by: linvg
  Created: 05.12.2024 01:13:13
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
const int MOD = 998244353;

int fpow(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}

const int N = 1e6 + 7;
vector<int> inv(N), fact(N), inv_fact(N);
void prepare() {
   inv[1] = 1;
   for (int i = 2; i < N; ++i) {
      inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
   }
   fact[0] = inv_fact[0] = 1;
   for (int i = 1; i < N; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
   }
}
int C(int n, int k) {
   if (k < 0 || k > n) return 0;
   return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}


void solve()
{
   unordered_map<int, int> mp;

   int n, m;
   cin >> n >> m;

   int nDia = 0, orc = 0;
   for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      mp[orc] = 1;
      orc += x;
   }
   if (orc % 2 == 0) {
      for (auto [u, v] : mp) {
         nDia += mp.count(u + orc / 2);
         dbg(u, v);
      }
   }

   if (n <= 1) return void(cout << m);
   dbg(nDia);

   auto calc = [] (int n, int m, int i, int MOD) {
      return ((((fpow(m, n - i * 2)) % MOD)) % MOD + MOD) % MOD;
   };


   int total = 0;
   for (int i = 1; i <= nDia; ++i) {
      if (i % 2 != 0) {
         total += ((C(m, i) * C(nDia, i)) % MOD * calc(n, m, i, MOD)) % MOD;
         total %= MOD;
      } else {
         total -= ((C(m, i) * C(nDia, i)) % MOD * calc(n, m, i, MOD)) % MOD;
         total = (total + MOD) % MOD;
      }
   }

   if (nDia > 0) {
      total += fpow(m * (m - 1), nDia);
      total %= MOD;
   }
   cout << total << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   prepare();
   solve();
   return 0;
}