#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;
const int N = 1e7 + 2;

bitset<N> isPrime;
vector<int> primes;

void sieve() {
   isPrime.set();
   isPrime[0] = isPrime[1] = 0;
   for (int i = 2; i * i < N; ++i) {
      if (isPrime[i]) {
         for (int j = i * i; j < N; j += i) {
            isPrime[j] = 0;
         }
      }
   }
   for (int i = 7; i < N; ++i) {
      if (isPrime[i]) primes.pb(i);
   }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
   unordered_map<int, int> mp;
   vector<int> res, tmp;
   bitset<177> isEven;
   tmp.push_back(7);
   int total = 7;
   int step = rng() % 10900;
   // cerr << step << '\n';
   //10245
   for (int i = 3; i < sz(primes); (i < 4973 ? i += 2 : i += 1)) {
      tmp.push_back(primes[i]);
      total += primes[i];

      if (total % sz(tmp) == 0 && isPrime[total / sz(tmp)]) {
         for (int j = sz(res); j < sz(tmp); ++j) {
            res.push_back(tmp[j]);
            mp[tmp[j]] = 1;
         }
      }
   }

   // int sum = 0;
   // for (auto &c : res) {
   //    sum += c;
   // }
   // for (auto &c : primes) {
   //    if (!mp[c] && (sum + c) % (sz(res) + 1) == 0 && isPrime[(sum + c) / (sz(res) + 1)]) {
   //       res.push_back(c);
   //       mp[c] = 1;
   //    }
   // }

   cout << sz(res) << '\n';
   // // int sum = 0;
   for (auto &c : res) {
      // sum += c;
      cout << c << ' ';
   }
   // cerr << sum / sz(res) << '\n';
}



int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif

   // ios_base::sync_with_stdio(0ls); cin.tie(NULL); cout.tie(NULL);
   sieve();
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}