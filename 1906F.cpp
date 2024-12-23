



/*
  Code by: linvg
  Created: 28.11.2024 23:51:25
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

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7;
const long double eps = 1e-8;

mt19937_64 randGen(std::chrono::_V2::system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
   cerr << "Error : " << errorCode << endl;
   exit(42);
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
   if (pow == 0) {
      return 0;
   }
   int hpow = 1 << (pow - 1);
   int seg = (x < hpow) ? (
      (y < hpow) ? 0 : 3
      ) : (
         (y < hpow) ? 1 : 2
         );
   seg = (seg + rotate) & 3;
   const int rotateDelta[4] = { 3, 0, 0, 1 };
   int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
   int nrot = (rotate + rotateDelta[seg]) & 3;
   int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
   int64_t ans = seg * subSquareSize;
   int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
   ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
   return ans;
}

struct Query {
   int l, r, idx;
   int64_t ord;

   inline void calcOrder() {
      ord = gilbertOrder(l, r, 21, 0);
   }
};

inline bool operator<(const Query& a, const Query& b) {
   return a.ord < b.ord;
}

// segment tree with lazy propagation update range and get max value in range
struct SegmentTree {
   int n;
   vector<int> t, lz;
   SegmentTree(int n) : n(n), t(4 * n), lz(4 * n) {}
   void push(int v, int l, int r) {
      if (lz[v] == 0) return;
      t[v] += lz[v];
      if (l != r) {
         lz[2 * v] += lz[v];
         lz[2 * v + 1] += lz[v];
      }
      lz[v] = 0;
   }
   void update(int v, int tl, int tr, int l, int r, int add) {
      push(v, tl, tr);
      if (l > r) return;
      if (l == tl && tr == r) {
         lz[v] += add;
         push(v, tl, tr);
         return;
      }
      int tm = (tl + tr) / 2;
      update(2 * v, tl, tm, l, min(r, tm), add);
      update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
      t[v] = max(t[2 * v], t[2 * v + 1]);
   }
   int get(int v, int tl, int tr, int l, int r) {
      push(v, tl, tr);
      if (l > r) return -llInfinity;
      if (l <= tl && tr <= r) return t[v];
      int tm = (tl + tr) / 2;
      return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
   }
};

#define inf INF

/* Node of the segment tree consisting of:
1. Maximum Prefix Sum,
2. Maximum Suffix Sum,
3. Total Sum,
4. Maximum Sub-Array Sum */
struct Node {
   int maxPrefixSum;
   int maxSuffixSum;
   int maxSubarraySum;
   int totalSum;

   Node()
   {
      maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
   }
};

/* Segment Tree consisting of Nodes */
struct SegmentTree {
   int n;
   vector<Node> t;

   SegmentTree(int n) : n(n), t(4 * n) {}

   Node combine(const Node& left, const Node& right)
   {
      Node res;
      res.maxPrefixSum = max(left.maxPrefixSum, left.totalSum + right.maxPrefixSum);
      res.maxSuffixSum = max(right.maxSuffixSum, right.totalSum + left.maxSuffixSum);
      res.totalSum = left.totalSum + right.totalSum;
      res.maxSubarraySum = max({ left.maxSubarraySum, right.maxSubarraySum, left.maxSuffixSum + right.maxPrefixSum });
      return res;
   }

   void build(const vector<int>& a, int v, int tl, int tr)
   {
      if (tl == tr)
      {
         t[v].maxPrefixSum = a[tl];
         t[v].maxSuffixSum = a[tl];
         t[v].maxSubarraySum = a[tl];
         t[v].totalSum = a[tl];
      }
      else
      {
         int tm = (tl + tr) / 2;
         build(a, 2 * v, tl, tm);
         build(a, 2 * v + 1, tm + 1, tr);
         t[v] = combine(t[2 * v], t[2 * v + 1]);
      }
   }

   void update(int v, int tl, int tr, int pos, int newVal)
   {
      if (tl == tr)
      {
         t[v].maxPrefixSum = newVal;
         t[v].maxSuffixSum = newVal;
         t[v].maxSubarraySum = newVal;
         t[v].totalSum = newVal;
      }
      else
      {
         int tm = (tl + tr) / 2;
         if (pos <= tm)
         {
            update(2 * v, tl, tm, pos, newVal);
         }
         else
         {
            update(2 * v + 1, tm + 1, tr, pos, newVal);
         }
         t[v] = combine(t[2 * v], t[2 * v + 1]);
      }
   }

   Node query(int v, int tl, int tr, int l, int r)
   {
      if (l > r)
      {
         return Node();
      }
      if (l == tl && r == tr)
      {
         return t[v];
      }
      int tm = (tl + tr) / 2;
      return combine(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
   }
};

void solve()
{
   int n, m;
   cin >> n >> m;
   vector<array<int, 3>> queries(m + 1);
   for (int i = 1; i <= m; ++i) {
      cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
   }
   int q;
   cin >> q;
   map<int, vector<Query>> qr;
   for (int i = 0; i < q; ++i) {
      int k, s, t;
      cin >> k >> s >> t;
      qr[k].push_back({ s, t, i });
   }
   for (auto& [k, queries] : qr) {
      for (auto& q : queries) {
         dbg(k, q.l, q.r);
      }
   }

   auto calc = [&](int x, int k) -> int {
      if (queries[x][0] <= k && k <= queries[x][1]) {
         return queries[x][2];
      }
      return 0;
   };
   vector<int> ans(q);
   int t[m] = {};
   SegmentTree st(m);
   for (auto [k, queries] : qr) {
      dbg(k);
      for (int i = 1; i <= m; ++i) {
         t[i - 1] = calc(i, k);
      }
      for (auto& q : queries) {
      }
   }
   for (int i = 0; i < q; ++i) {
      cout << ans[i] << '\n';
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