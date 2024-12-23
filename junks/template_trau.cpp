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

fenwick fw;

void solve()
{
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    vector<array<int, 3>> sets;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[j][i] += abs(a[i] - a[j]) + f[j][i - 1];
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
            fw.insert(sets[start][0], sets[start][1]);
        }

        ans[id] = fw.query(r, r) - fw.query(l - 1, r) - fw.query(r, l - 1) + fw.query(l - 1, l - 1);
        // ans[id] = query(r, r) - query(l - 1, r) - query(r, l - 1) + query(l - 1, l - 1);
    }
    for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("TEMPLATE.inp", "r", stdin);
    freopen("TEMPLATE.ans", "r", stdin);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}
