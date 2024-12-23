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

struct segment_tree {
   vector<int> it;
   segment_tree(int n) {
      it.assign(4 * n, 1e9);
   }

   void update(int id, int l, int r, int pos, int val) {
      if (pos > r || pos < l) return;
      if (l == r) {
         it[id] = val;
         return;
      }
      int mid = (l + r) / 2;
      update(id << 1, l, mid, pos, val);
      update(id << 1 | 1, mid + 1, r, pos, val);
      it[id] = min(it[id << 1], it[id << 1 | 1]);
   }

   int get_min(int id, int l, int r, int u, int v) {
      if (l > v || r < u) return 1e9;
      if (l >= u && r <= v) return it[id];
      int mid = (l + r) / 2;
      return min(get_min(id << 1, l, mid, u, v),
         get_min(id << 1 | 1, mid + 1, r, u, v));
   }
};

int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
   vector<vector<int>> dp(nums.size() + 1, vector<int>(andValues.size() + 1, 1e9));
   int n = nums.size(), m = andValues.size();

   vector<vector<int>> f(31, vector<int>(n + 1));
   for (int i = 1; i <= n; ++i) f[0][i] = nums[i - 1];
   for (int i = 1; i <= 30; ++i) {
      for (int j = 1; j + (1 << (i - 1)) <= n; ++j) {
         f[i][j] = f[i - 1][j] & f[i - 1][j + (1 << (i - 1))];
      }
   }

   auto get = [&](int l, int r) {
      int res = ~0;
      for (int i = 30; i >= 0; --i) {
         if ((1 << i) <= r - l + 1) {
            res &= f[i][l];
            l += (1 << i);
         }
      }
      return res;
      };

   auto findRange = [&](int pos, int val) -> pair<int, int> {
      int l = 1, r = pos, begin = 0, end = 0;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (get(mid, pos) < val) {
            l = mid + 1;
         }
         else {
            r = mid - 1;
         }
      }
      begin = l;
      if (get(begin, pos) != val) return { -1, -1 };
      l = 1, r = pos;
      while (l <= r) {
         int mid = (l + r) / 2;
         if (get(mid, pos) <= val) {
            l = mid + 1;
            end = mid;
         }
         else {
            r = mid - 1;
         }
      }
      return { begin - 1, end - 1 };
   };

   vector<segment_tree*> seg(m);
   for (int i = 0; i < m; ++i) {
      seg[i] = new segment_tree(n);
   }

   int cur = ~0;
   for (int i = 1; i <= n; ++i) {
      cur &= nums[i - 1];
      if (cur == andValues[0]) {
         dp[i][1] = nums[i - 1];
         seg[0]->update(1, 1, n, i, dp[i][1]);
      }

      for (int k = 2; k <= m; ++k) {
         int andVal = andValues[k - 1];
         pair <int, int> range = findRange(i, andVal);
         int l = range.fi, r = range.se;
         dbg(l, r);
         if (l == -1) continue;
         int minVal = seg[k-2]->get_min(1, 1, n, l, r);
         dbg(i, k, l, r, minVal, andVal);
         if (minVal != 1e9) {
            dp[i][k] = min(dp[i][k], minVal + nums[i - 1]);
            dbg(i, k, dp[i][k], minVal, nums[i - 1]);
            seg[k - 1]->update(1, 1, n, i, dp[i][k]);
         }
      }
   }
   // for (auto &c : dp) for (int i = 0; i < c.size(); ++i) cout << c[i] << " \n"[i == c.size()-1];
   return (dp[n][m] == 1e9 ? -1 : dp[n][m]);
}


void solve()
{
   //[1,3,2,4,7,5,3]
   //[2,3,5,7,7,7,5]
   vector<int> a = { 3, 1 }, b = { 3, 1 };
   cout << minimumValueSum (a, b);
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}