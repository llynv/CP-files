
/*
  Code by: linvg
  Created: 11.10.2024 14:22:25
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

#define MAX 2147483647

const uint32_t block_size = 1048576;

uint32_t s, prime_cnt, sq[65536], sp[65536], primes[106000000];
uint64_t wheel[15015], is_composite[8192], mask[12][62][8192];

inline void setbit(uint64_t* ar, uint32_t bit) {
   ar[bit >> 6] |= (1ULL << (bit & 63));
}

inline uint32_t get_idx(uint32_t i, uint32_t j) {
   if (sq[j] > i) return (sq[j] - i) >> 1;
   uint32_t x = sp[j] - i % sp[j];
   if ((x & 1) ^ 1) x += sp[j];
   return x >> 1;
}

void small_sieve() {
   for (uint32_t i = 2; i * i < 65536; i++) {
      for (uint32_t j = i * i; j < 65536 && !sp[i]; j += i) {
         sp[j] = 1;
      }
   }
   for (uint32_t i = 2; i < 65536; i++) {
      if (!sp[i]) sp[s] = i, sq[s++] = i * i;
   }
}

void process_block(uint32_t i) {
   uint32_t j, k, l, d, m, x, lim = i + block_size, idx = i % 15015, chunk = 0;

   idx = (idx + ((idx * 105) & 127) * 15015) >> 7;
   for (j = 0; (j << 7) < block_size; j += chunk, idx = 0) {
      chunk = min(15015 - idx, (block_size >> 7) - j);
      memcpy(is_composite + j, wheel + idx, sizeof(uint64_t) * chunk);
   }
   if (!i) is_composite[0] = (is_composite[0] | 1) & ~110;

   l = block_size >> 1, m = block_size >> 7;
   for (j = 6; j < 18 && i; j++) {
      for (x = get_idx(i, j), k = 0, d = j - 6; k < m; k++) {
         is_composite[k] |= mask[d][x][k];
      }
   }

   for (j = (i == 0) ? 6 : 18; j < s && sq[j] < lim; j++) {
      for (x = get_idx(i, j); x < l; x += sp[j]) {
         setbit(is_composite, x);
      }
   }
}

void populate_primes(uint32_t i) {
   for (uint32_t j = 0; (j << 7) < block_size; j++) {
      uint64_t x = ~is_composite[j];
      while (x) {
         uint32_t p = i + (j << 7) + (__builtin_ctzll(x) << 1) + 1;
         if (p <= MAX) primes[prime_cnt++] = p;
         x ^= (-x & x);
      }
   }
}

void fast_sieve() {
   small_sieve();

   for (uint32_t i = 1; i <= 5; i++) {
      for (uint32_t j = i + (i > 3); j < 960960; j += sp[i]) {
         setbit(wheel, j);
      }
   }

   for (uint32_t i = 6; i <= 17; i++) {
      for (uint32_t j = 0; j < sp[i]; j++) {
         for (uint32_t k = j; k < (block_size >> 1); k += sp[i]) {
            setbit(mask[i - 6][j], k);
         }
      }
   }

   primes[prime_cnt++] = 2;
   for (uint32_t i = 0; i <= MAX; i += block_size) {
      process_block(i);
      populate_primes(i);
   }
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   unordered_map<int, int> cnt;
   for (auto& c : a) {
      cin >> c;
      cnt[c]++;
   }

   sort(all(a));
   a.erase(unique(all(a)), a.end());

   int ans = 0;
   for (int i = 0; i < sz(a); ++i) {
      int x = a[i];
      if (!is_sorte[x]) {
         sort(all(f[x]));
         is_sorte[x] = 1;
      }
      ans += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2);
      for (auto u : f[x]) {
         if (u == x) break;
         int b = x / u;
         if (u % b != 0) continue;
         int p = lower_bound(all(f[u]), u / b) - f[u].begin();
         if (p < sz(f[u]) && f[u][p] == u / b) {
            ans += cnt[x] * cnt[u] * cnt[u / b];
         }
      }
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   fast_sieve();
   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}