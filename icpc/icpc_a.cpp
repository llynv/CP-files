
/*
  Code by: linvg
  Created: 27.10.2024 08:08:46
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

const int INF = 1e18;
const int MOD = 1e9 + 7;

struct Segment_Tree {
   vector<int> tree;
   int n;

   Segment_Tree(int size) {
      n = size;
      tree.assign(4 * n, INF);
   }

   void update(int node, int start, int end, int idx, int val) {
      if (start == end) {
         tree[node] = val;
      } else {
         int mid = (start + end) / 2;
         if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
         } else {
            update(2 * node + 1, mid + 1, end, idx, val);
         }
         tree[node] = min(tree[2 * node], tree[2 * node + 1]);
      }
   }

   int getMin(int node, int start, int end, int l, int r) {
      if (r < start || end < l) {
         return INF;
      }
      if (l <= start && end <= r) {
         return tree[node];
      }
      int mid = (start + end) / 2;
      return min(getMin(2 * node, start, mid, l, r), getMin(2 * node + 1, mid + 1, end, l, r));
   }
};

void solve()
{
   int n, D, H;
   cin >> n >> D >> H;
   vector<int> a(n);
   for (auto& c : a) cin >> c;
   vector<int> dp(n + 1, INF);
   multiset<pair<int, int>> s;
   Segment_Tree st(10011);
   dp[1] = a[0];
   unordered_map<int, multiset<int>> mp;
   mp[a[0]].insert(dp[1]);
   st.update(1, 1, 10010, a[0], dp[1]);
   for (int i = 2; i <= n; ++i) {
      int it = st.getMin(1, 1, 10010, max(1ll, a[i - 1] - H), min(10010ll, a[i - 1] + H));
      if (it != INF) {
         dp[i] = it + a[i - 1];
      }
      mp[a[i - 1]].insert(dp[i]);
      st.update(1, 1, 10010, a[i - 1], *mp[a[i - 1]].begin());
      if (i > D) {
         int x = a[i - D - 1];
         mp[x].erase(mp[x].find(dp[i - D]));
         st.update(1, 1, 10010, a[i - D - 1], mp[x].empty() ? INF : *mp[x].begin());
      }
   }
   cout << (dp[n] == INF ? -1 : dp[n]) << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}