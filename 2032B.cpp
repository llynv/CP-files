
/*
  Code by: linvg
  Created: 01.11.2024 21:46:41
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
   int n, k;
   cin >> n >> k;
   if (k == 1 && n == 1) return void (cout << "1\n1\n");
   if (k == 1 || k == n) return void (cout << "-1\n");
   // cout << "3\n";
   // cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
   vector<int> ans(3);
   if (k % 2 != 0) {
      ans[0] = 1;
      ans[1] = k - 1;
      ans[2] = k + 2;
   } else {
      ans[0] = 1;
      ans[1] = k;
      ans[2] = k + 1;
   }
   if (*min_element(all(ans)) <= 0 || *max_element(all(ans)) > n) return void (cout << "-1\n");
   cout << 3 << '\n';
   for (auto &c : ans) cout << c << ' ';
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