
/*
  Code by: linvg
  Created: 06.11.2024 21:42:45
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

vector<int> primes;
vector<bool> is_prime(N, true);

struct Hash {
   size_t operator()(const int &x) const {
      return hash<int>()(x);
   }
};

void sieve() {
   is_prime[0] = is_prime[1] = false;
   for (int i = 2; i < N; ++i) {
      if (is_prime[i]) {
         primes.push_back(i);
         for (int j = i * i; j < N; j += i) {
            is_prime[j] = false;
         }
      }
   }
}

vector<int> factorize(int n) {
   vector<int> mp;
   for (int i = 0; i < sz(primes) and primes[i] * primes[i] <= n; ++i) {
      while (n % primes[i] == 0) {
         mp.push_back(primes[i]);
         n /= primes[i];
      }
   }
   if (n > 1) {
      mp.push_back(n);
   }
   return mp;
}

void solve()
{
   int n, k;
   cin >> n >> k;
   int facs = 1, mx = 1, fans = 0;
   while (k > 1) {
      k /= 2;
      fans++;
   }
   vector<int> ans = factorize(n);
   sort(all(ans));
   cout << sz(ans) + fans << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   sieve();
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}