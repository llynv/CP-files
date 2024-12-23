
/*
  Code by: linvg
  Created: 06.10.2024 03:54:28
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
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
   vector<int> a(n), b(n);
   unordered_map<int, int> a_pos, b_pos;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a_pos[a[i]] = i + 1;
   }
   for (int i = 0; i < n; ++i) {
      cin >> b[i];
      b_pos[b[i]] = i + 1;
   }
   int res = n * (n + 1) / 2;
   int i_pos = a_pos[1], j_pos = b_pos[1];
   for (int i = 1; i < n; ++i) {
      int nxt_i_pos = a_pos[i + 1], nxt_j_pos = b_pos[i + 1];
      if (i_pos > j_pos) swap(i_pos, j_pos);
      if (nxt_i_pos > nxt_j_pos) swap(nxt_i_pos, nxt_j_pos);
      dbg(i, i_pos, j_pos, nxt_i_pos, nxt_j_pos);
      if (i_pos >= nxt_i_pos && j_pos >= nxt_j_pos) res -= max(1ll, nxt_i_pos - i_pos) * max(1ll, j_pos - nxt_j_pos);
      i_pos = min(i_pos, nxt_i_pos);
      j_pos = max(j_pos, nxt_j_pos);
   }
   res -= n - (a_pos[1] != b_pos[1] ? 2 : 1);
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