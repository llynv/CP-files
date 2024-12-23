
/*
  Code by: linvg
  Created: 11.10.2024 15:17:14
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
const int N = 101;

int pow(int a, int b, int mod) {
   int res = 1;
   while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
}

bool miller_rabin(int n) {
   if (n < 2) return false;
   if (n < 4) return true;
   if (n % 2 == 0) return false;
   int d = n - 1, s = 0;
   while (d % 2 == 0) {
      d /= 2;
      s++;
   }
   auto test = [&](int a) {
      int x = pow(a, d, n);
      if (x == 1 || x == n - 1) return true;
      for (int i = 0; i < s - 1; ++i) {
         x = x * x % n;
         if (x == n - 1) return true;
      }
      return false;
   };
   for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
      if (a >= n) break;
      if (!test(a)) return false;
   }
   return true;
}

void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   vector<int> cnt(64 + 65);
   unordered_map<int, int> mp;
   for (auto &c : a) {
      cin >> c;
      mp[c]++;
   }
   auto _min_f = [](int x) {
      if (miller_rabin(x)) return x;
      for (int i = 2; i * i <= x; ++i) {
         if (x % i == 0) return i;
      }
      return x;
   };
 
   vector<int> b;
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         int dif = abs(a[i] - a[j]);
         if (dif == 0) continue;
         b.push_back(_min_f(dif));
      }
   }
   dbg(a);
   dbg(n * (n - 1) / 2);
   dbg(cnt);
   sort(all(b));
   b.erase(unique(all(b)), b.end());
   dbg(b);
   for (int i = 2; i < sz(b); ++i) {
      if (b[i] == b[i - 1] + b[i - 2]) return void (cout << "NO\n");
   }
   cout << "YES\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}