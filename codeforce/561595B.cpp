/*
   Code by: linvg
   Created: 26.10.2024 20:46:22
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("O3")

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

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int N = 2e6 + 7;
const int Nx = 1e6 + 7;

int prime[N];
int f[20][Nx], a[Nx];

void sieve() {
   prime[0] = prime[1] = 1;
   for (int i = 2; i < N; ++i) {
      if (!prime[i]) {
         prime[i] = i;
         for (long long j = 1ll * i * i; j < N; j += i) {
            prime[j] = i;
         }
      }
      prime[i] = max(prime[i], prime[i / prime[i]]);
   }
}

void solve()
{
   int n, q, mn = INF;
   scanf("%d %d", &n, &q);
   priority_queue<pair<int, int>> pq;
   unordered_map<int, int> pos;
   for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      pos[x]++;
      if (pos[x] == 1) {
         pq.push({ x, n - i });
      }
      mn = min(mn, x);
   }
   for (auto [x, v] : pos) {
   }
   vector<int> check_points(n + 1);
   int time = 0;
   while (pq.size() && pq.top().first != mn) {
      auto [val, idx] = pq.top();
      pq.pop();
      while ((val > pq.top().first) || (val == pq.top().first && idx > pq.top().second)) {
         time += pos[val];
         dbg(val, 1);
         val /= prime[val];
         pos[val] += pos[val * prime[val]];
      }
      if (val != 1) {
         pq.push({ val, idx });
         mn = min(mn, val);
      }
      else {
         check_points[n - idx] = time;
      }
   }
   dbg(check_points);
   if (pq.size()) {
      int time_to_one = 0, val = pq.top().first;
      while (val > 1) {
         val /= prime[val];
         time_to_one++;
      }
      time_to_one = pq.size() * (time_to_one - 1) + 1 + time;
      for (int i = 1; i <= n; ++i) {
         if (check_points[i] == 0) {
            check_points[i] += time_to_one++;
         }
         f[0][i] = check_points[i];
      }
   }
   else {
      for (int i = 1; i <= n; ++i) {
         f[0][i] = check_points[i];
      }
   }
   for (int k = 1; k < 20; ++k) {
      for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
         f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
      }
   }
   int len, k;
   while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      k = 31 - __builtin_clz(r - l + 1);
      printf("%d\n", max(f[k][l], f[k][r - (1 << k) + 1]));
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   sieve();
   solve();
   return 0;
}
