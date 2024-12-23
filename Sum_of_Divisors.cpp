
/*
  Code by: linvg
  Created: 31.10.2024 11:56:12
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

const int MAXN = 50;
const int MAXM = 2000010;
const int MAXV = 20000010;

constexpr auto fast_div = [](const uint64_t& a, const uint32_t& b) ->uint64_t {return double(a) / b + 1e-9;};

int pi[MAXV];
uint64_t pi_sum[MAXV], dp[MAXN][MAXM];

vector<int> primes;
bitset<MAXV> is_prime;

void sieve() {
   is_prime[2] = true;
   for (int i = 3; i < MAXV; i += 2) is_prime[i] = true;

   for (int i = 3; i * i < MAXV; i += 2) {
      for (int j = i * i; is_prime[i] && j < MAXV; j += (i << 1)) {
         is_prime[j] = false;
      }
   }

   primes.push_back(-1);
   for (int i = 1; i < MAXV; i++) {
      pi[i] = pi[i - 1], pi_sum[i] = pi_sum[i - 1];
      if (is_prime[i]) {
         primes.push_back(i);
         pi[i]++, pi_sum[i] += i;
      }
   }
}

void gen() {
   sieve();
   for (int i = 0; i < MAXM; i++) dp[0][i] = (uint64_t)i * (i + 1) / 2;
   for (int i = 1; i < MAXN; i++) {
      for (int j = 1; j < MAXM; j++) {
         dp[i][j] = dp[i - 1][j] - dp[i - 1][fast_div(j, primes[i])] * primes[i];
      }
   }
}

typedef uint64_t int128;

template <typename T>
T phi(T m, int n) {
   if (!n) return (T)m * (m + 1) / 2;
   if (n < MAXN && m < MAXM) return dp[n][m];
   if (m < MAXV && (uint64_t)primes[n] * primes[n] >= m) return pi_sum[m] - pi_sum[primes[n]] + 1;
   return phi(m, n - 1) - phi((T)fast_div(m, primes[n]), n - 1) * primes[n];
}

template <typename T>
T lehmer(T n) {
   if (n < MAXV) return pi_sum[n];

   int s = sqrt(0.5 + n), c = cbrt(0.5 + n);
   T res = phi(n, pi[c]) + pi_sum[c] - 1;

   for (int i = pi[c] + 1; i <= pi[s]; i++) {
      T w = lehmer(fast_div(n, primes[i])) - pi_sum[primes[i] - 1];
      res -= w * primes[i];
   }

   return res;
}

__int128 prime_sum(long long n) {
   if (n <= UINT_MAX) return lehmer((uint64_t)n);
   return lehmer((__int128)n);
}

int fpow (int a, int n) {
   int res = 1;
   while (n) {
      if (n & 1) res = res * a % MOD;
      a = a * a % MOD;
      n >>= 1;
   }
   return res;
}

void solve()
{
   int n;
   cin >> n;
   int res = 0;
   for (int i = 1; i <= ceil(sqrt(n)); ++i) {
      res += n / i * i + (i != (int) ceil(1.0 * n / i) ? i * (n / i) : 0);
      dbg(i, n / i, (int) ceil(1.0 * n / i), i * (n / i));
      res %= MOD;
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