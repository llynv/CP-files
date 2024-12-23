
/*
  Code by: linvg
  Created: 04.11.2024 21:42:03
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
   for (auto& c : a) cin >> c;
   
   vector<int> first_left(n), first_right(n);
   stack<int> q;
   for (int i = 0; i < n; ++i) {
      while (!q.empty() && a[q.top()] <= a[i]) q.pop();
      first_left[i] = q.empty() ? -1 : q.top();
      q.push(i);
   }
   while (!q.empty()) q.pop();
   for (int i = n - 1; i >= 0; --i) {
      while (!q.empty() && a[q.top()] <= a[i]) q.pop();
      first_right[i] = q.empty() ? n : q.top();
      q.push(i);
   }
   dbg(first_left, first_right);

   map<int, vector<int>> pos;
   for (int i = 0; i < n; ++i) pos[a[i]].push_back(i);
   pos.erase(pos.rbegin()->first);
   for (auto [num, v] : pos) {
      dbg(num, v);
      int ans = 0;
      vector<int> tmp;
      for (int i = 0; i < sz(v); i++) {
         int l = first_left[v[i]] + 1;
         int r = first_right[v[i]] - 1;
         if ((r - l + 1) % 2 != 0) return void(cout << "NO\n");
      }
   }
   cout << "YES\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}