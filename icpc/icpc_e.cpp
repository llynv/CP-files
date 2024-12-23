#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e5 + 5, block_size = 316;

ll pw[N], ans[N], val[N];


struct Query {
   int l, r, idx;
   Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
   bool operator<(Query other) const
   {
      return make_pair(l / block_size, r) <
         make_pair(other.l / block_size, other.r);
   }
};

vector<Query> que[N];

int sub(int x, int y) {
   return (x + y) % x;
}


int sum[N], cnt[N], n;
int get_sum(int i) {
   int res = 0;
   for (; i; i -= i & -i) {
      res += sum[i];
   }
   return res;
}
int get_cnt(int i) {
   int res = 0;
   for (; i; i -= i & -i) {
      res += cnt[i];
   }
   return res;
}
void add_sum(int i, int v) {
   for (; i <= n; i += i & -i) {
      sum[i] += v;
   }
}
void add_cnt(int i, int v) {
   for (; i <= n; i += i & -i) {
      cnt[i] += v;
   }
}

int p;
int trau(int l, int r) {
   int res = 0;
   for (int i = l; i <= r; ++i) for (int j = i; j <= r; ++j) res += (val[i] - val[j + 1]) % p == 0;
   return res;
}

int trau0(int l, int r) {
   int res = 0;
   for (int i = l; i <= r; ++i) for (int j = i; j <= r; ++j) res += val[j];
   return res;
}

int32_t main() {
   cin.tie(0)->sync_with_stdio(0); cout.tie(0);

   string s;
   int q;

   cin >> p;
   cin >> s;
   n = s.size();
   s = ' ' + s;
   cin >> q;
   vector<Query> queries;
   for (int i = 0, l, r; i < q; ++i) {
      cin >> l >> r;
      queries.emplace_back(l, r, i);
      que[l].push_back(queries.back());
   }
   if (p == 2 || p == 5) {
      for (int i = n; i; --i) {
         val[i] = (s[i] - '0') % p == 0;
      }
      for (int i = n; i; --i) {
         if (val[i]) {
            add_sum(i, i);
            add_cnt(i, 1);
         }
         for (Query q : que[i]) {
            ans[q.idx] = get_sum(q.r) - (ll)get_cnt(q.r) * (q.l - 1);
         }
      }
      for (int i = 0; i < q; ++i) {
         cout << ans[i] << '\n';
      }
      return 0;
   }
   
   sort(queries.begin(), queries.end());
   pw[0] = 1;
   for (int i = 1; i <= n; ++i) {
      pw[i] = (pw[i - 1] * 10) % p;
   }
   val[n + 1] = 0;
   for (int i = n; i; --i) {
      // cerr << s[i] << ' ';
      val[i] = ((s[i] - '0') * pw[n - i] % p + val[i + 1]) % p;
      // cerr << (s[i] - '0') << ' ' << pw[n - i] % p << ' ' << val[i] << '\n';
   }
   // for (int i = 1; i <= n; ++i) {
   //    cerr << val[i] << ' ';
   // }
   // cerr << '\n';
   unordered_map<int, int> cnt;
   int cur_l = 1;
   int cur_r = 0;
   int cleared = 1;
   ll res = 0;
   for (Query q : queries) {
      while (cur_l > q.l) {
         cleared = 0;
         cur_l--;
         res += cnt[val[cur_l]];
         cnt[val[cur_l]]++;
      }
      while (cur_r < q.r) {
         cleared = 0;
         cur_r++;
         res += cnt[val[cur_r]];
         cnt[val[cur_r]]++;
      }
      while (cur_l < q.l) {
         cleared = 0;
         cnt[val[cur_l]]--;
         res -= cnt[val[cur_l]];
         cur_l++;
      }
      while (cur_r > q.r) {
         if (!cleared) {
            cnt.clear();
            res = 0;
            cleared = 1;
         }
         cur_r--;
      }
      ans[q.idx] = res + cnt[val[cur_r + 1]];
   }

   for (int i = 0; i < q; ++i) {
      cout << ans[i] << '\n';
   }
   for (Query q : queries) {
      int l = q.l, r = q.r;
      // if (ans[q.idx] != trau(l, r)) {
      //    cerr << l << ' ' << r << " wrong? " << trau(l, r) << ' ' << ans[q.idx] << '\n';
      // }
   }
}

