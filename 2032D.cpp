
/*
  Code by: linvg
  Created: 01.11.2024 22:42:06
*/

#include <bits/stdc++.h>
using namespace std;

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

   auto ask = [] (int a, int b) -> bool {
      cout << "? " << a << ' ' << b << '\n';
      cout.flush();
      int res;
      cin >> res;
      return res;
   };

   vector<int> p(n + 1);
   vector<int> child(n + 1);
   iota(all(child), 0ll);
   set<int> s;
   s.insert(1);
   p[0] = 1;
   for (int i = 2; i < n; ++i) {
      int x = ask(1, i);
      if (!x) break;
      s.insert(i);
      p[i] = 0;
      child[0] = i;
   }

   auto it = s.begin();
   auto inc = [&] () -> void {
      ++it;
      if (it == s.end()) it = s.begin();
   };

   p[*s.rbegin() + 1] = 1;
   child[1] = *s.rbegin() + 1;
   inc();

   for (int i = *s.rbegin() + 2; i < n; ++i) {
      int x = ask(*it, i);
      while (x) {
         int t = *it;
         inc();
         s.erase(s.find(t));
         x = ask(*it, i);
      } 
      p[i] = child[*it];
      child[*it] = i;
      inc(); 
   }
   cout << "! ";
   for (int i = 1; i < n; ++i) cout << p[i] << ' ';
   cout << '\n';
   cout.flush();
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}