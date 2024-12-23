
/*
  Code by: linvg
  Created: 09.10.2024 20:59:56
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

bool is_prime(int n) {
   if (n < 2) return false;
   for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
   }
   return true;
}

int fast_pow(int a, int b) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % MOD;
      a = a * a % MOD;
      b >>= 1;
   }
   return res;
}

vector<int> inv, fact, invfact;
void prepare(int n) {
   fact.resize(n + 1);
   inv.resize(n + 1);
   invfact.resize(n + 1);
   fact[0] = invfact[0] = 1;
   fact[1] = invfact[1] = 1;
   inv[1] = 1;
   for (int i = 2; i <= n; ++i) {
      inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
      fact[i] = fact[i - 1] * i % MOD;
      invfact[i] = invfact[i - 1] * inv[i] % MOD;
   }
}

int C(int n, int k) {
   if (k < 0 || k > n) return 0;
   return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve()
{
   prepare(1e5 + 7);

   int n;
   cin >> n;
   vector<int> a(n), cnt(72);
   vector<vector<int>> cnt_mask(71, vector<int>(1 << 7));
   for (auto& c : a) cin >> c, cnt[c]++;
   for (int i = 2; i <= 70; ++i) {
      if (cnt[i] == 0) continue;
      int v = i;
      int mask = 0;
      for (int j = 2; j <= v; ++j) {
         int tmp = 0;
         if (v % j == 0 && is_prime(j)) {
            while (v % j == 0) {
               v /= j;
               tmp++;
            }
            if (tmp & 1) mask |= 1 << (j - 1);
         }
      }
      cnt_mask[v][mask] += cnt[i];
   }
   vector<int> dp(1 << 7, 1);
   int ans = 0;
   for (int i = 1; i <= 70; ++i) {
      for (int mask = 0; mask < (1 << 7); ++mask) {
         for (int mask2 = 0; mask2 < (1 << 7); ++mask2) {
            if (mask == mask2 || dp[mask] == 0) continue;
            dp[mask ^ mask2] += dp[mask] * cnt_mask[i][mask2] % MOD;
         }
      }
   }
   dbg(dp[0]);
   // dbg(cnt_mask); 
   ans += (fast_pow(2, cnt[1]) - 1);
   ans %= MOD;
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}