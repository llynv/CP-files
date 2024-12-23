/*
  Code by: linvg
  Created: 03.12.2024 16:36:55
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
   int one = 0, two = 0;
   priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
   for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == 1) {
         one++;
         continue;
      }
      if (x == 2) {
         two++;
         continue;
      }
      q.push({ x, {x} });
   }
   string s;
   for (int i = 0; i < min(one, two); ++i) {
      // q.push({ 3, {1, 1, 1} });
      // q.push({ 3, {1, 1, 1} });
      q.push({ 3, {1, 2} });
   }
   int tt = min(one, two);
   one -= tt;
   two -= tt;

   for (int i = 0; i < two; ++i) {
      q.push({ 2, {2} });
   }

   for (int i = 0; i < one / 6; ++i) {
      q.push({ 3, {1, 1, 1} });
      q.push({ 3, {1, 1, 1} });
   }

   one %= 6;
   for (int i = 0; i < one / 2; i++) {
      q.push({ 2, {1, 1} });
   }
   one %= 2;
   if (q.size() && one) {
      auto [x, v] = q.top();
      q.pop();
      v.push_back(one);
      q.push({ x + one, v });
   }
   else if (one) {
      q.push({ one, {one} });
   }
   while (q.size()) {
      auto [x, v] = q.top();
      q.pop();
      if (s.size()) s += '*';
      s += '(';
      for (int i = 0; i < v.size(); ++i) {
         s += to_string(v[i]) + '+';
      }
      s.pop_back();
      s += ')';
   }
   cout << s << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}