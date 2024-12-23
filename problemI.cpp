/*
  Code by: linvg
  Created: 09.12.2024 15:14:01
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

void solve()
{
   string s;
   cin >> s;

   vector<int> hyp;
   int sumcheck = 0, inc = 10;
   for (int i = 0; i < sz(s); ++i) {
      if ((s[i] >= '0' && s[i] <= '9') || s[i] == 'X') {
         sumcheck += (s[i] == 'X' ? 10 : (s[i] - '0')) * inc;
         --inc;
      } 
      if (s[i] == '-') {
         hyp.push_back(i);
      }
   }
   if (inc) {
      cout << "invalid\n";
      return;
   }
   for (int i = 0; i < sz(s) - 1; ++i) if (s[i] == 'X') {
      cout << "invalid\n";
      return;
   }
   if (sumcheck % 11 != 0) {
      cout << "invalid\n";
      return;
   }
   for (int i = 1; i < sz(s); ++i) if (s[i] == s[i - 1] && s[i] == '-') {
      cout << "invalid\n";
      return;
   }
   if (s[0] == '-' || s.back() == '-') {
      cout << "invalid\n";
      return;
   }
   if (sz(hyp) == 3 && s[sz(s) - 2] != '-') {
      cout << "invalid\n";
      return;
   } 
   s = "978-" + s;
   s.pop_back();
   sumcheck = 0, inc = 1;
   for (int i = 0; i < sz(s); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
         sumcheck += (s[i] - '0') * (inc % 2 == 0 ? 3 : 1);
         ++inc;
      }
   }
   int r = (10 - sumcheck % 10) % 10;
   s += r + '0';
   cout << s << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}