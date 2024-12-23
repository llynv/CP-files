/*
  Code by: linvg
  Created: 15.12.2024 22:48:40
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

const int N = 2e5 + 7;
const int M = 2e5 + 7;

vector<int> f[N];
void sieve() {
   for (int i = 1; i < N; ++i) {
      for (int j = i; j < N; j += i) {
         f[j].push_back(i);
         f[j].push_back(-i);
      }
   }
}

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
      // http://xorshift.di.unimi.it/splitmix64.c
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
   }
};

void solve()
{
   int n, m, q;
   cin >> n >> m >> q;
   vector<int> a(n), b(m);
   int sa = 0, sb = 0;
   unordered_map<int, bool, custom_hash> cka, ckb;
   for (auto& c : a) cin >> c, sa += c, cka[c] = 1;
   for (auto& c : b) cin >> c, sb += c, ckb[c] = 1;

   while (q--) {
      int x;
      cin >> x;
      for (auto& c : f[abs(x)]) {
         int r = x / c;
         if (cka[sa - r] && ckb[sb - c]) {
            cout << "YES\n";
            goto end;
         }
         if (cka[sa - c] && ckb[sb - r]) {
            cout << "YES\n";
            goto end;
         }
      }

      cout << "NO\n";
   end:;
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