
/*
  Code by: linvg
  Created: 30.10.2024 20:06:27
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

int fpow (int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}

const int N = 2e5 + 5;

__int128_t fw_d[N], fw_n[N];

void add_d(int i, int x) {
   for (; i < N; i += i & -i) {
      fw_d[i] *= x;
      fw_d[i] %= MOD;
   }
}

void add_n(int i, int x) {
   for (; i < N; i += i & -i) {
      fw_n[i] *= x;
      fw_n[i] %= MOD;
   }
}

__int128_t get_d(int i) {
   __int128_t res = 1;
   for (; i; i -= i & -i) {
      res *= fw_d[i];
      res %= MOD;
   }
   return res;
}

__int128_t get_n(int i) {
   __int128_t res = 1;
   for (; i; i -= i & -i) {
      res *= fw_n[i];
      res %= MOD;
   }
   return res;
}

void solve()
{
   fill(fw_d, fw_d + N, 1);
   fill(fw_n, fw_n + N, 1);

   int n;
   cin >> n;
   vector<__int128_t> num(n + 2, 1), den(n + 2, 1);
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   for (int i = 0; i < n; ++i) {
      int l, r;
      cin >> l >> r;
      if (l <= r) {
         // den[l] += (r - l + 1) ;
         // den[r + 1] *= fpow(r - l + 1, MOD - 2);
         // den[l] %= MOD;
         // den[r + 1] %= MOD;
         // num[l] *= r - l;
         // num[r + 1] = fpow(r - l, MOD - 2);
         // num[l] %= MOD;
         // num[r + 1] %= MOD;

         add_d(l, r - l + 1);
         add_n(l, r - l);
         add_d(r + 1, fpow(r - l + 1, MOD - 2));
         add_n(r + 1, fpow(r - l, MOD - 2));

      } else {
         // den[l] *= (n - l + r + 1);
         // den[l] %= MOD;
         // den[n + 1] *= fpow(n - l + r + 1, MOD - 2);
         // den[n + 1] %= MOD;
         // den[1] *= (n - l + r + 1);
         // den[1] %= MOD;
         // den[r + 1] *= fpow(n - l + r + 1, MOD - 2);
         // den[r + 1] %= MOD;

         // num[l] *= n - l + r;
         // num[l] %= MOD;
         // num[n + 1] *= fpow(n - l + r, MOD - 2);
         // num[n + 1] %= MOD;
         // num[1] *= n - l + r;
         // num[1] %= MOD;
         // num[r + 1] *= fpow(n - l + r, MOD - 2);
         // num[r + 1] %= MOD;

         add_d(l, n - l + r + 1);
         add_n(l, n - l + r);
         add_d(n + 1, fpow(n - l + r + 1, MOD - 2));
         add_n(n + 1, fpow(n - l + r, MOD - 2));
         add_d(1, n - l + r + 1);
         add_n(1, n - l + r);
         add_d(r + 1, fpow(n - l + r + 1, MOD - 2));
         add_n(r + 1, fpow(n - l + r, MOD - 2));

      }
   }
   __int128_t res = 0;
   for (int i = 1; i <= n; ++i) {
      __int128_t n = get_n(i);
      __int128_t d = get_d(i);
      res += (((d - n) * a[i - 1]) % MOD) * fpow(d, MOD - 2) % MOD;
      res -= ((n * a[i - 1]) % MOD) * fpow(d, MOD - 2) % MOD;
      res = (res + MOD) % MOD;
   }
   res = (res + MOD) % MOD;
   int ans = res;
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // freopen("oneshot.inp", "r", stdin);
   // freopen("oneshot.out", "w", stdout);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}