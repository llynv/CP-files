/*
  Code by: linvg
  Created: 02.10.2024 18:37:30
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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
const int N = (int) ceil(sqrt(1e9)) + 1;

vector<int> primes;
vector<bool> is_prime(N, true);

void sieve()
{
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

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   sort(all(a));
   for (int i = 1; i < n; ++i) {
      if (gcd(a[i], a[i - 1]) != 1) {
         dbg(gcd(a[i], a[i - 1]));
         cout << "YES\n";
         return;
      }
   }
   for (auto c : primes) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
         cnt += (a[j] % c == 0);
      }
      if (cnt >= 2) {
         // dbg(c);
         cout << "YES\n";
         return;
      }
   }
   cout << "NO\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // freopen("template.inp", "r", stdin);
   // freopen("template.out", "w", stdout);
   sieve();

   dbg(sz(primes));

   int t;
   cin >> t;
   while (t--)
      solve();
   return 0;
}