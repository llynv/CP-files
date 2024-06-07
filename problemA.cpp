
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

struct Node {
   int mx, mx2;
   int mi, mi2;
   Node(int _mx = LONG_LONG_MIN, int _mx2 = LONG_LONG_MIN, int _mi = LONG_LONG_MAX, int _mi2 = LONG_LONG_MAX) {
      mx = _mx;
      mx2 = _mx2;
      mi = _mi;
      mi2 = _mi2;
   }
};
struct SegmentTree {
   int n;
   vector<Node> nodes;

   SegmentTree(int _n) {
      n = _n;
      nodes.assign(4 * n, Node());
   }

   void build(int id, int l, int r, vector<int>& inp) {
      if (l == r) {
         nodes[id] = Node(inp[l], LONG_LONG_MIN, inp[l], LONG_LONG_MAX);
         return;
      }
      int mid = (l + r) / 2;
      build(id * 2, l, mid, inp);
      build(id * 2 + 1, mid + 1, r, inp);
      nodes[id] = merge(nodes[id * 2], nodes[id * 2 + 1]);
   }

   Node merge(Node& lef, Node& rig) {
      Node res;
      res.mx = max(lef.mx, rig.mx);
      res.mx2 = (lef.mx == rig.mx) ? rig.mx : max({ min(lef.mx, rig.mx), lef.mx2, rig.mx2 });
      res.mi = min(lef.mi, rig.mi);
      res.mi2 = (lef.mi == rig.mi) ? rig.mi : min({ max(lef.mi, rig.mi), lef.mi2, rig.mi2 });
      return res;
   }

   // void show(int id, int l, int r) {
   //     cout << id << " " << l << " " << r << " " << nodes[id].mx << " " << nodes[id].mx2 << " " << nodes[id].mi << " " << nodes[id].mi2 << "\n";
   //     if (l == r)
   //         return;
   //     int mid = (l + r) / 2;
   //     show(id * 2, l, mid);
   //     show(id * 2 + 1, mid + 1, r);
   // }
   Node getNode(int id, int l, int r, int u, int v) {
      if (v < l || r < u) return Node();
      if (u <= l && r <= v) return nodes[id];
      int mid = (l + r) / 2;
      Node left = getNode(id * 2, l, mid, u, v);
      Node right = getNode(id * 2 + 1, mid + 1, r, u, v);
      return merge(left, right);
   }
};
void solve() {
   int n, q;
   cin >> n >> q;
   vector<int> a(n + 1);
   fu(i, 1, n) cin >> a[i];
   SegmentTree st(n);
   st.build(1, 1, n, a);
   // st.show(1, 1, n);
   // cout << "\n";
   // Node node = st.getNode(1, 1, n, 2, 7);
   // cout << node.mx << " " << node.mx2 << " " << node.mi << " " << node.mi2 << "\n";
   fu(i, 1, q) {
      int l, r;
      cin >> l >> r;
      Node node = st.getNode(1, 1, n, l + 1, r - 1);
      int res = a[l] * a[r];
      int mul1 = node.mx * node.mx2 * res;
      int mul2 = node.mi * node.mi2 * res;
      int mul3 = node.mx * node.mi * res;
      cout << max({ mul1, mul2, mul3 }) << "\n";
   }
}
int32_t main() {
   
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
 
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   t = 1;
   auto start = chrono::steady_clock::now();
   while (t-- > 0) {
      solve();
   }
   auto end = chrono::steady_clock::now();
   auto diff = end - start;
   // cerr << "Time elapsed: " << chrono::duration<double, milli>(diff).count() << " ms\n";
}