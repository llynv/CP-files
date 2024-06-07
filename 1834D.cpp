/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

vector<int> compressLeft, compressRight;
vector<ii> compress;

struct Segment_Tree
{
   vector<int> it, sign;
   vector<ii> lazy;
   Segment_Tree(int n)
   {
      it.assign(4 * n, 0);
      sign.assign(4 * n, 0);
      lazy.assign(4 * n, {0, 0});
   }

   void push(int id, int l, int r) {
      if (lazy[id].first == INF) return;
      int mid = (l + r) / 2;
      int bleft = lazy[id].first, bright = lazy[id].second;
      if (sign[id] == 0) {
         it[id << 1] = mid - l + 1;
         it[id << 1 | 1] = r - mid;
         lazy[id << 1] = {bleft, bright};
         lazy[id << 1 | 1] = {bleft, bright};
         sign[id << 1] = sign[id << 1 | 1] = sign[id];
      } else {
         it[id << 1] = mid - l + 1 - max(0ll, max(bleft, l) - max(bright, mid + 1));
         it[id << 1 | 1] = r - mid - max(0ll, max(bleft, mid + 1) - max(bright, r + 1));
         lazy[id << 1] = {bleft, bright};
         lazy[id << 1 | 1] = {bleft, bright};
         sign[id << 1] = sign[id << 1 | 1] = sign[id];
      }
   }

   void update(int id, int l, int r, int u, int val, int bleft = INF, int bright = -1) {
      if (l > u || r < u) return;
      if (l >= u && r <= u) {
         int dist = compress[u].se - compress[u].fi + 1;
         if (val == 0) {
            it[id] = dist;
            lazy[id] = {bleft, bright};
            sign[id] = 0;
         } else {
            if (u >= bleft || u + dist <= bright) {
               it[id] = dist - max(0ll, max(bleft, u) - max(bright, u + dist));
               lazy[id] = {bleft, bright};
               sign[id] = 1;
            }
         }
         return;
      }
      int mid = (l + r) / 2;
      update(id << 1, l, mid, u, val);
      update(id << 1 | 1, mid + 1, r, u, val);
      it[id] = max(it[id << 1], it[id << 1 | 1]);
   }

   int get (int id, int l, int r, int u, int v) {  
      if (l > v || r < u) return 0;
      push(id, l, r);
      if (l >= u && r <= v) return it[id];
      int mid = (l + r) / 2;
      return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
   }  
};


void solve()
{
   int n, m;
   cin >> n >> m;
   vector<ii> a(n);
   unordered_map<int, vector<int>> end;
   for (auto& c : a) {
      cin >> c.fi >> c.se;
      end[c.fi].push_back(c.se);
   }


   for (auto& c : a) {
      compressLeft.push_back(c.fi);
      compressRight.push_back(c.se);
   }

   sort(all(compressLeft));
   sort(all(compressRight));
   compressLeft.resize(unique(all(compressLeft)) - compressLeft.begin());
   compressRight.resize(unique(all(compressRight)) - compressRight.begin());

   for (int i = 0; i < n; ++i) {
      // compress[i].fi = lower_bound(all(compressLeft), a[i].fi) - compressLeft.begin() + 1;
      // compress[i].se = lower_bound(all(compressRight), a[i].se) - compressRight.begin() + 1;
      compress.push_back({lower_bound(all(compressLeft), a[i].fi) - compressLeft.begin(), lower_bound(all(compressRight), a[i].se) - compressRight.begin()});
   }  

   Segment_Tree st(sz(compress));

   for (int i = 0; i < n; ++i) {
      st.update(1, 0, sz(compress) - 1, compress[i].fi, compress[i].se, 1);
   }

   int ans = 0;
   for (int i = 0; i < n; ++i) {
      st.update(1, 0, sz(compress) - 1, compress[i].fi, compress[i].se, -1);
      int dist = compressRight[compress[i].se - 1] - compressLeft[compress[i].fi - 1] + 1;
      ans = max(ans, dist + st.it[1]);
      st.update(1, 0, sz(compress) - 1, compress[i].fi, compress[i].se, 1);
   }

   cout << ans << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}