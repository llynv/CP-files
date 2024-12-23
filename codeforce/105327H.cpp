
/*
  Code by: linvg
  Created: 16.10.2024 19:12:38
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

int fpow(int a, int b, int m)
{
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
   string a, b;
   cin >> a >> b;
   vector<int> bit_a, bit_b;
   int a_num = 0, b_num = 0;
   for (int i = 0; i < sz(b); ++i) {
      if (b[i] == '*') bit_b.push_back(i);
      if (b[i] == '1') {
         b_num += fpow(2, sz(b) - i - 1, MOD);
      }
   }
   for (int i = 0; i < sz(a); ++i) {
      if (a[i] == '*') bit_a.push_back(i);
   }
   dbg(a, b);
   string a_copy = a;
   for (int mask_b = 0; mask_b < (1 << sz(bit_b)); ++mask_b) {
      int id = 0, tb = b_num;
      for (auto c : bit_b) {
         if (mask_b >> (id++) & 1) tb += fpow(2, sz(b) - c - 1, MOD);
      }
      for (int mask_a = 0; mask_a < (1 << sz(bit_a)); ++mask_a) {
         id = 0;
         for (auto c : bit_a) {
            if (mask_a >> (id++) & 1) {
               a_copy[c] = '1';
            } else {
               a_copy[c] = '0';
            }
         }
         int ta = 0;
         for (int i = 0; i < sz(a); ++i) {
            if (a_copy[i] == '1') ta += fpow(2, sz(a) - i - 1, tb);
         }
         if (ta % tb == 0) {
            return void (cout << a_copy);
         }
         for (auto c : bit_a) {
            a_copy[c] = '*';
         }
      }
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}