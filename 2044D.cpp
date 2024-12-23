/*
  Code by: linvg
  Created: 15.12.2024 21:44:47
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
   int n;
   cin >> n;
   vector<int> a(n), b;
   unordered_map<int, int> ck;
   for (auto &c : a) cin >> c;
   set<int> s;
   for (int i = 1; i <= n; ++i) s.insert(i);
   for (int i = 0; i < n; ++i) {
      ck[a[i]]++;
      if (ck[a[i]] == 1) {
         b.push_back(a[i]);
         s.erase(a[i]);
      }
      else {
         b.push_back(0);
      }
   }
   for (int i = 0; i < n; ++i) {
      if (b[i] == 0) {
         b[i] = *s.begin();
         s.erase(s.begin());
      }
   }
   for (auto &c : b) cout << c << ' ';
   cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}