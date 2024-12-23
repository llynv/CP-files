/*
    Code by: KoKoDuDu
    Created: 27.10.2024 08:13:59
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

struct info {
   int a, b, c;
};
bool cmp(info x, info y) {
   if (x.a == y.a) {
      return x.b < y.b;
   }
   return x.a < y.a;
}

struct Segment_Tree
{
   vector<int> st;
   int n;
   Segment_Tree()
   {
   }
   Segment_Tree(int n)
   {
      this->n = n;
      st.assign(4 * n + 37, 0);
   }
   void update(int id, int l, int r, int pos, int val)
   {
      int mid = (l + r) >> 1;
      if (l == r)
      {
         st[id] = max(val, st[id]);
         return;
      }
      if (pos <= mid)
      {
         update(id * 2, l, mid, pos, val);
      }
      else
      {
         update(id * 2 + 1, mid + 1, r, pos, val);
      }
      st[id] = max(st[id * 2], st[id * 2 + 1]);
   }
   int getMax(int id, int l, int r, int u, int v)
   {
      if (l > v || r < u)
      {
         return 0;
      }
      if (u <= l && r <= v)
      {
         return st[id];
      }
      int mid = (l + r) >> 1;
      ;
      int s1 = getMax(id * 2, l, mid, u, v);
      int s2 = getMax(id * 2 + 1, mid + 1, r, u, v);
      return max(s1, s2);
   }
};
void solve() {
   int n;
   cin >> n;
   int sz = 10010;
   vector<info> s(n + 1);
   for (int i = 1; i <= n; ++i) {
      cin >> s[i].a >> s[i].b >> s[i].c;
   }
   sort(s.begin() + 1, s.end(), cmp);
   // for (int i = 1; i <= n; ++i) {
   //     cout << s[i].a << ' ' << s[i].b << ' ' << s[i].c << '\n';
   // }
   int ans = 0;
   int maxx = 0;
   Segment_Tree tree(sz);
   vector<int>dp(n + 1);
   for (int i = 1; i <= n; ++i) {
      // maxx = max(maxx, s[i].c);
      dp[i] = s[i].c;
      int val = tree.getMax(1, 1, sz, 1, s[i].b);
      // for (int j = 1; j <= i; ++j) {
      //     if (i == j) continue;
      //     if (s[i].b >= s[j].b) {
      //         dp[i] = max(dp[i], dp[j] + s[i].c);
      //         // dp[i] = max(dp[i - 1], dp[i]);
      //         // ans = max(ans, s[i].c + s[j].c);
      //     }
      // }
      dp[i] = max(dp[i], val + s[i].c);
      tree.update(1, 1, sz, s[i].b, dp[i]);
      ans = max(ans, dp[i]);
      // cout << dp[i] << ' ';
   }
   cout << ans;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t = 1;
   while (t--) {
      solve();
   }
   return 0;
}