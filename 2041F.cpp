

/*
  Code by: linvg
  Created: 25.11.2024 22:37:34
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

int modmul(int a, int b, int mod) {
   int res = a * b - mod * (int)((long double)a * b / mod);
   return res + mod * (res < 0) - mod * (res >= (int)mod);
}

int modpow(int a, int b, int mod) {
   int res = 1;
   while (b > 0) {
      if (b & 1) res = modmul(res, a, mod);
      a = modmul(a, a, mod);
      b >>= 1;
   }
   return res;
}

bool miler_rabin(int n) {
   if (n < 2) return false;
   if (n < 4) return true;
   if (n % 2 == 0) return false;
   int d = n - 1, s = 0;
   while (d % 2 == 0) {
      d /= 2;
      s++;
   }
   for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
      if (a >= n) break;
      int x = modpow(a, d, n);
      if (x == 1 || x == n - 1) continue;
      bool ok = false;
      for (int i = 0; i < s - 1; i++) {
         x = modmul(x, x, n);
         if (x == 1) return false;
         if (x == n - 1) {
            ok = true;
            break;
         }
      }
      if (!ok) return false;
   }
   return true;
}

void solve()
{
   double l, r;
   cin >> l >> r;
   vector<int> primes;
   for (int i = l; i <= r; ++i) {
      if (miler_rabin(i)) {
         primes.push_back(i);
      }
   }

   map<double, int> cnt;
   auto go = [&] (double i, double j, auto&& go) -> void {
      if (i >= j) return;
      int pl = lower_bound(all(primes), i) - primes.begin();
      int pr = lower_bound(all(primes), j) - primes.begin() - 1;
      if (pl > pr) return;
      if (pl >= sz(primes) || pr >= sz(primes)) return;
      cnt[j - i + 1]++;
      dbg(i, j, pl, pr, primes[pl], primes[pr]);
      if (pl == pr && primes[pr] - l == r - primes[pl]) return;
      if (pl < sz(primes) && pr < sz(primes) && primes[pr] - l == r - primes[pl]) {
         go(i, (r + primes[pl]) / 2.0, go);
         go((primes[pr] + l) / 2.0, j, go);
      } else {
         if (pl == sz(primes) || primes[pr] + l > r + primes[pl]) {
            go(i, (r + primes[pl]) / 2.0, go);
         } else {
            go((primes[pr] + l) / 2.0, j, go);
         }
      }
   };  
   go(l, r, go);
   dbg(cnt);
   cout << cnt.begin()->second << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}