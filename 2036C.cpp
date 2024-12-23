
/*
  Code by: linvg
  Created: 02.11.2024 23:02:11
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

void add (int i, int v, vector<int>& fw) {
   for (; i < sz(fw); i += i & -i) {
      fw[i] += v;
   }
}

int get (int i, vector<int>& fw) {
   int res = 0;
   for (; i > 0; i -= i & -i) {
      res += fw[i];
   }
   return res;
}

void solve()
{
   string s;
   cin >> s;
   vector<int> fw(s.size() + 1);
   for (int i = 0; i < s.size() - 3; ++i) {
      if (s.substr(i, 4) == "1100") {
         add(i + 1, 1, fw);
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int i, v;
      cin >> i >> v;
      --i;
      if (s[i] == v + '0') {
         cout << (get(s.size() - 1, fw) ? "YES" : "NO") << '\n';
         continue;
      }
      int res = 0;
      for (int j = max(0ll, i - 3); j <= i; ++j) {
         if (s.substr(j, 4) == "1100") {
            add(j + 1, -1, fw);
         }
      }
      s[i] = v + '0';
      for (int j = max(0ll, i - 3); j <= i; ++j) {
         if (s.substr(j, 4) == "1100") {
            add(j + 1, 1, fw);
         }
      }
      cout << (get(s.size(), fw) ? "YES" : "NO") << '\n';
   }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}