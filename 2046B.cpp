/*
  Code by: linvg
  Created: 09.12.2024 07:35:10
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
   vector<int> a(n);
   for (auto &c : a) cin >> c;
   vector<int> min_right(n + 1, INF);
   for (int i = n - 1; i >= 0; --i) {
      min_right[i] = min(min_right[i + 1], a[i]);
   }
   multiset<int> new_a;
   vector<int> remain;
   for (int i = 0; i < n; ++i) {
      if (a[i] > min_right[i + 1]) new_a.insert(a[i] + 1);
      else remain.push_back(a[i]);
   }
   dbg(remain);
   dbg(new_a);
   while (!remain.empty() && !new_a.empty() && remain.back() > *new_a.begin()) {
      new_a.insert(remain.back() + 1);
      remain.pop_back();
   }
   for (auto &c : remain) cout << c << ' ';
   for (auto &c : new_a) cout << c << ' ';
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