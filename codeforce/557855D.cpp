
/*
  Code by: linvg
  Created: 13.10.2024 17:20:25
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
const int N = 1e3 + 7;

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
   int n, k;
   cin >> n >> k;
   map<int, int, greater<int>> mp;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      mp[x]++;
   }
   if (mp.begin()->second >= k) return void (cout << C(mp.begin()->second, k) << '\n');
   int total = 0;
   for (auto [v, cnt] : mp) {
      if (total + cnt >= k) {
         cout << C(cnt, k - total) << '\n';
         return;
      }
      total += cnt;
   }
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