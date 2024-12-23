

/*
  Code by: linvg
  Created: 15.11.2024 20:28:58
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

struct DSU
{
   vector<int> counter, parent;

   DSU(int n)
   {
      parent.resize(n + 1);
      counter.resize(n + 1, 1);
      for (int i = 0; i <= n; i++)
         parent[i] = i;
   }

   int find_root(int i)
   {
      while (i != parent[i])
      {
         parent[i] = parent[parent[i]];
         i = parent[i];
      }
      return parent[i];
   }

   void connect(int a, int b)
   {
      int c = find_root(a), d = find_root(b);
      if (c != d)
      {
         parent[c] = d;
         counter[d] += counter[c], counter[c] = 0;
      }
   }

   bool is_connected(int a, int b)
   {
      return find_root(a) == find_root(b);
   }

   int component_size(int i)
   {
      int p = find_root(i);
      return counter[p];
   }
};

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

struct Segment_Tree_Max
{
   vector<int> tree;
   int n;

   Segment_Tree_Max(int size)
   {
      n = size;
      tree.assign(4 * n, -INF);
   }

   void update(int node, int start, int end, int idx, int val)
   {
      if (start == end)
      {
         tree[node] = max(tree[node], val);
      }
      else
      {
         int mid = (start + end) / 2;
         if (idx <= mid)
         {
            update(2 * node, start, mid, idx, val);
         }
         else
         {
            update(2 * node + 1, mid + 1, end, idx, val);
         }
         tree[node] = max(tree[2 * node], tree[2 * node + 1]);
      }
   }

   int getMax(int node, int start, int end, int l, int r)
   {
      if (r < start || end < l)
      {
         return -INF;
      }
      if (l <= start && end <= r)
      {
         return tree[node];
      }
      int mid = (start + end) / 2;
      return max(getMax(2 * node, start, mid, l, r), getMax(2 * node + 1, mid + 1, end, l, r));
   }
};

const int N = 5e5 + 5;

int f[20][N], maxRightIndex[N], minLeftIndex[N], root_ans[N], maxRightRoot[N], minLeftRoot[N], a[N];

void solve()
{
   int n;
   cin >> n;
   for (int i = 1; i <= n; ++i) cin >> a[i];
   for (int i = 1; i <= n; ++i) {
      f[0][i] = a[i];
   }
   for (int i = 1; i < 20; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
         f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
      }
   }
   auto get_max = [&](int l, int r) {
      int k = 31 - __builtin_clz(r - l + 1);
      return max(f[k][l], f[k][r - (1 << k) + 1]);
   };
   minLeftIndex[1] = 1;
   for (int i = 1; i <= n; ++i) {
      root_ans[i] = 0;
      minLeftIndex[i] = minLeftIndex[i - 1];
         if (a[i] > a[minLeftIndex[i]]) {
            minLeftIndex[i] = i;
         }
      }
   Segment_Tree_Max stMax(n);
   for (int i = n; i >= 1; --i) {
      int val = stMax.getMax(1, 1, n, 1, a[i] - 1);
      if (val == -INF) {
         maxRightIndex[i] = i;
      } else {
         maxRightIndex[i] = val;
      }
      stMax.update(1, 1, n, a[i], i);
   }
   DSU dsu(n);
   vector<int> vst(n + 1), ans(n + 1);
   for (int i = 1; i <= n; ++i) {
      int mxR = i, mnL = i;
      int cur = i;
      vst[cur] = 1;  
      while (true) {
         int nxt = maxRightIndex[cur];
         mxR = max(mxR, nxt);
         dsu.connect(cur, nxt);
         cur = nxt;
         vst[cur] = 1;
         int prev = minLeftIndex[cur];
         mnL = min(mnL, prev);
         dsu.connect(cur, prev);
         cur = prev;
         if (vst[cur]) break;
         vst[cur] = 1;
      }
      int root = dsu.find_root(i);
      mxR = max(mxR, maxRightIndex[root]);
      mnL = min(mnL, minLeftIndex[root]);
      root_ans[root] = max(root_ans[root], get_max(mnL, mxR));
      ans[i] = root_ans[root];
      maxRightRoot[root] = max(maxRightRoot[root], mxR);
      minLeftRoot[root] = min(minLeftRoot[root], mnL);
   }
   for (int i = 1; i <= n; ++i) {
      cout << ans[i] << ' ';
   }
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

// rng rand(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(all(v), rand);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());