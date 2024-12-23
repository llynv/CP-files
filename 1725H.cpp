/*
  Code by: linvg
  Created: 04.12.2024 22:51:59
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
   int cnt[3] = {0, 0, 0};
   vector<vector<int>> pos(3);
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] %= 3;
      cnt[a[i]]++;
      pos[a[i]].push_back(i);
   }
   dbg(a);
   // for (int i = 0; i < n; ++i) {
   //    for (int j = i; j < n; ++j) {
   //       int x = (a[i] * a[j] + (a[i] + a[j]) * (a[i] + a[j]));
   //       dbg(a[i], a[j], x % 3);
   //    }
   // }
   //  0 0 0
   //  0 1 1
   //  0 2 1
   //  1 1 2
   //  1 2 2
   //  2 2 2

   // spe case Z = 1
   sort(all(a));
   if (a.front() == a.back()) {
      cout << "1\n";
      for (int i = 0; i < n; ++i) {
         cout << (i < n / 2) ? '1' : '0';
      }
      cout << '\n';
      return;
   }

   dbg(cnt[0], cnt[1], cnt[2]);

   if (cnt[0] == 0) {
      cout << "0\n";
      for (int i = 0; i < n; ++i) {
         cout << (i < n / 2) ? '1' : '0';
      }
      cout << '\n';
      return;
   }

   if (cnt[0] <= n / 2) {
      vector<char> s(n, '0');
      int cnt = 0;
      while (sz(pos[0]) && cnt < n / 2) {
         int x = pos[0].back();
         pos[0].pop_back();
         s[x] = '1';
         cnt++; 
      }
      int x = 0;
      while (cnt < n / 2) {
         if (sz(pos[1])) {
            x = pos[1].back();
            pos[1].pop_back();            
         } else {
            x = pos[2].back();
            pos[2].pop_back();
         }
         s[x] = '1';
         cnt++;
      }  
      cout << "0\n";
      for (auto c : s) cout << c;
      return;
   } else {
      vector<char> s(n, '0');
      int cnt = 0;
      while (sz(pos[0]) && cnt < n / 2) {
         int x = pos[0].back();
         pos[0].pop_back();
         s[x] = '1';
         cnt++; 
      }
      int x = 0;
      while (cnt < n / 2) {g
         if (sz(pos[1])) {
            x = pos[1].back();
            pos[1].pop_back();            
         } else {
            x = pos[2].back();
            pos[2].pop_back();
         }
         s[x] = '1';
         cnt++;
      }  
      cout << "2\n";
      for (auto c : s) cout << c;
      return;
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