
/*
  Code by: linvg
  Created: 31.10.2024 21:49:56
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
const int N = 1e6 + 7;

int prime[N];

void sieve() {
   prime[0] = prime[1] = 1;
   for (int i = 2; i < N; ++i) {
      if (prime[i]) continue;
      for (int j = i; j < N; j += i) {
         prime[j] = i;
      }
   }
}

int _lcm[N];

unordered_map<int, int> get_factors(int x) {
   unordered_map<int, int> cnt;
   while (x > 1) {
      int p = prime[x], c = 0;
      while (x % p == 0) {
         x /= p;
         c++;
      }
      cnt[p] = c;
   }
   return cnt;
}

int fpow (int a, int b, int m) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % m;
      a = a * a % m;
      b >>= 1;
   }
   return res;
}

void solve()
{  
   sieve();
   int n, k;
   cin >> n >> k;
   if (k == 1) return void (cout << "Yes\n");
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      unordered_map<int, int> cnt = get_factors(x);
      for (auto [f, c] : cnt) {
         _lcm[f] = max(_lcm[f], c);
      }
   }

   int _l = 1;
   for (int i = 1; i < N; ++i) {
      if (_lcm[i] == 0) continue;
      _l = _l * fpow(i, _lcm[i], k) % k;
   }
   cout << (_l ? "No" : "Yes") << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}