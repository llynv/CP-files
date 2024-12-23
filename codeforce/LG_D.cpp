
/*
  Code by: linvg
  Created: 10.10.2024 16:22:14
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
const int N = (1 << 18) + 1;

vector<int> fact(N);

void prepare() {
   fact[0] = 1;
   for (int i = 1; i < N; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
   }
}

int modmul(int a, int b) {
   int res = 0;
   while (b) {
      if (b & 1) {
         res += a;
         res %= MOD;
      }
      a += a;
      a %= MOD;
      b >>= 1;
   }
   return res;
}

void solve()
{
   int n, m, x, C, D;
   cin >> n >> m >> x >> C >> D;
   vector<int> a(n), b(m);
   for (auto &c : a) cin >> c;
   for (auto &c : b) cin >> c;

   auto gen = [&] (int sum, int j, vector<int> &ar, map<array<int, 2>, int>&ct, auto&&gen, int sz = 0) -> void {
      if (sum && sz) {
         ct[{sum, sz}] += fact[sz];
         ct[{sum, sz}] %= MOD;
      }
      if (j == n) {
         return;
      }
      for (int i = j + 1; i < sz(ar); ++i) {
         gen(sum + ar[i], i, ar, ct, gen, sz + 1);
      }
   };
   map<array<int, 2>, int> cnt1, cnt2;

   gen(0, -1, a, cnt1, gen);
   gen(0, -1, b, cnt2, gen);
   vector<array<int, 3>> store_a, store_b;
   unordered_map<int, vector<array<int, 2>>> p_a, p_b;
   int ans = 0;
   for (auto [key, num] : cnt1) {
      store_a.push_back({key[1], key[0], num});
      ans += (key[1] == 1 && key[0] >= C && key[0] <= D ? num : 0);
      ans %= MOD;
   }
   for (auto [key, num] : cnt2) {
      store_b.push_back({key[1], key[0], num});
      ans += (key[1] == 1 && key[0] >= C && key[0] <= D ? num : 0);
      ans %= MOD;
   }

   sort(all(store_b));

   for (auto [sz, sum, num] : store_b) {
      if (p_b[sz].empty()) {
         p_b[sz].push_back({0, 0});
      } 
      p_b[sz].push_back({sum, (num + p_b[sz].back()[1]) % MOD});
   }

   auto find_range = [&] (vector<array<int, 2>>&ar, int low, int high) -> int {
      int p = upper_bound(all(ar), array<int, 2>{high, (int) 1e18}) - ar.begin() - 1;
      int q = lower_bound(all(ar), array<int, 2>{low, -1}) - ar.begin() - 1;
      if (p < q) return 0;
      if (ar.empty()) return 0;
      q = max(q, 0LL);
      p = max(p, 0LL);
      return (ar[p][1] - ar[q][1] + MOD) % MOD;
   };

   for (auto [sz, sum, val] : store_a) {
      int lower = find_range(p_b[sz - 1], C - (2 * sz - 2) * x - sum, D - (2 * sz - 2) * x - sum);
      ans += modmul(val, lower);
      ans %= MOD;
      int equal = find_range(p_b[sz], C - (2 * sz - 1) * x - sum, D - (2 * sz - 1) * x - sum);
      ans += 2 * modmul(val, equal);
      ans %= MOD;
      int upper = find_range(p_b[sz + 1], C - (2 * sz) * x - sum, D - (2 * sz) * x - sum);
      ans += modmul(val, upper);  
      ans %= MOD;
   }
   cout << ans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   prepare();
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}