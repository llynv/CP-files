/*
  Code by: linvg
  Created: 21.12.2024 22:11:00
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
const int M = 1e6 + 7;

bitset<M> prime;
vector<int> primes;

void sieve() {
   prime[0] = prime[1] = 1;
   for (int i = 2; i * i < M; ++i) {
      if (prime[i] == 0) {
         prime[i] = i;
         primes.push_back(i);
         for (int j = i * i; j < M; j += i) {
            prime[j] = i;
         }
      }
   }
   for (int i = 3; i < M; i += 2) {
      if (prime[i] == 0) {
         prime[i] = i;  
         primes.push_back(i);
      }
   }
}


int pow(int a, int b, int mod) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
} 

bool miller_rabin (int n) {
   if (n < 2) return false;
   if (n == 2) return true;
   if (n % 2 == 0) return false;
   int d = n - 1;
   while (d % 2 == 0) d /= 2;
   for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
      if (a >= n) break;
      int t = d;
      int m = pow(a, t, n);
      while (t != n - 1 && m != 1 && m != n - 1) {
         m = m * m % n;
         t *= 2;
      }
      if (m != n - 1 && t % 2 == 0) return false;
   }
   return true;
}

void solve()
{

}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}