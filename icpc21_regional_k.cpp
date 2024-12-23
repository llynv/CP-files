/*
  Code by: linvg
  Created: 27.11.2024 18:55:22
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2007;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int NM = 2e5 + 7;

int a[N], f[N][N];
int ans[NM];
array<int, 4> ques[NM];

#define mp make_pair
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

struct fenwick {
   OST bit[N];

   void insert(int x, int y)
   {
      for (int i = x; i < N; i += i & -i)
         bit[i].insert(mp(y, x));
   }
   void remove(int x, int y)
   {
      for (int i = x; i < N; i += i & -i)
         bit[i].erase(mp(y, x));
   }
   int query(int x, int y)
   {
      int ans = 0;
      for (int i = x; i > 0; i -= i & -i)
         ans += bit[i].order_of_key(mp(y + 1, 0));
      return ans;
   }
};

struct Fenwick2D {
   int bit[N][N];

   void update(int x, int y, int delta) {
      for (int i = x; i < N; i += i & -i) {
         for (int j = y; j < N; j += j & -j) {
            bit[i][j] += delta;
         }
      }
   }

   int query(int x, int y) {
      int sum = 0;
      for (int i = x; i > 0; i -= i & -i) {
         for (int j = y; j > 0; j -= j & -j) {
            sum += bit[i][j];
         }
      }
      return sum;
   }

   int rangeQuery(int x1, int y1, int x2, int y2) {
      return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
   }
};

Fenwick2D fw2;

fenwick fw;

void solve()
{
   int n;
   scanf("%lld", &n);
   for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
   vector<array<int, 3>> sets;
   for (int i = 1; i <= n; ++i) {
      for (int j = i; j >= 1; --j) {
         if (j == i) {
            f[j][i] = 0;
         } else {
            f[j][i] = f[j][i - 1] + abs(a[i] - a[j]) + f[j + 1][i] - f[j + 1][i - 1];
         }
         sets.push_back({ j, i, f[j][i] });
      }
   }
   sort(all(sets), [](array<int, 3> x, array<int, 3> y) {
      return x[2] < y[2];
      });

   int q, l, r, k;
   scanf("%lld", &q);
   for (int i = 0; i < q; ++i) {
      scanf("%lld%lld%lld", &l, &r, &k);
      ques[i] = { l, r, k, i };
   }
   sort(ques, ques + q, [](array<int, 4>& x, array<int, 4>& y) {
      return x[2] < y[2];
      });
   int start = 0;
   for (int i = 0; i < q; ++i) {
      auto [l, r, k, id] = ques[i];
      for (; start < sz(sets) and sets[start][2] <= k; ++start) {
         // fw.insert(sets[start][0], sets[start][1]);
         fw2.update(sets[start][0], sets[start][1], 1);
      }

      // ans[id] = fw.query(r, r) - fw.query(l - 1, r) - fw.query(r, l - 1) + fw.query(l - 1, l - 1);
      ans[id] = fw2.rangeQuery(l, l, r, r);
      // ans[id] = query(r, r) - query(l - 1, r) - query(r, l - 1) + query(l - 1, l - 1);
   }
   for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   
   // int n = rnd() % 50 + 1;
   // vector<int> a(n + 1);
   // for (int i = 1; i <= n; ++i) a[i] = rnd() % (int) (100) + 1;
   // dbg(n);
   // dbg(a);
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = i; j >= 1; --j) {
   //       if (j == i) {
   //          f[j][i] = 0;
   //       } else {
   //          f[j][i] = f[j][i - 1] + abs(a[i] - a[j]) + f[j + 1][i] - f[j + 1][i - 1];
   //       }
   //    }
   // }
   // for (int i = 1; i <= n; ++i) {
   //    for (int j = 1; j <= i; ++j) {
   //       int trau = 0;
   //       for (int l = j; l <= i; ++l) {
   //          for (int r = j; r <= l; ++r) {
   //             trau += abs(a[l] - a[r]);
   //          }
   //       }
   //       dbg(j, i, f[j][i], trau);
   //       assert(f[j][i] == trau);
   //    }
   // }
   
   solve();
   return 0;
}
