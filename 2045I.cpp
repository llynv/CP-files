/*
  Code by: linvg
  Created: 03.12.2024 01:22:18
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

const int N = 3e5 + 7;

int fw[N];

void add(int i, int x) {
   for (; i < N; i += i & -i) {
      fw[i] += x;
   }
}

int get(int i) {
   int res = 0;
   for (; i > 0; i -= i & -i) {
      res += fw[i];
   }
   return res;
}

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   unordered_map<int, bool> pos;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      pos[a[i]] = 1;
   }
   unordered_map<int, int> last;
   int res = 0;
   for (int i = 0; i < n; i++) {
      if (last.count(a[i]) == 0) {
         res += get(i + 1);
         last[a[i]] = i + 1;
         add(last[a[i]], 1);
         continue;
      }
      res += get(n) - get(last[a[i]]);
      if (last.count(a[i]) != 0) add(last[a[i]], -1);
      last[a[i]] = i + 1;
      add(last[a[i]], 1);
   }
   res += 1ll * sz(last) * (sz(last) - 1) / 2;
   res += sz(pos) * (m - sz(pos));
   cout << res << '\n';

}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}