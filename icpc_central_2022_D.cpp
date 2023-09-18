#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 7;

vector<int> it[4 * N];
int a[N], imax[N];

void build(int index, int L, int R)
{
    if (L == R) {
        it[index].emplace_back(a[L-1]);
        return;
    }

    int mid = (L + R) / 2;
    build(index << 1, L, mid);
    build(index << 1 | 1, mid + 1, R);
    // it[index].resize(it[index << 1].size() + it[index << 1 | 1].size());
    it[index].assign(R - L + 1, 0);
    merge(it[index << 1].begin(), it[index << 1].end(), it[index << 1 | 1].begin(), it[index << 1 | 1].end(), it[index].begin());
}

int get(int index, int L, int R, int l, int r, int x)
{
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) {
        if (it[index].front() >= x) return 0;
        if (it[index].back() < x) return it[index].size();
        return lower_bound(it[index].begin(), it[index].end(), x)- it[index].begin();
    }

    int mid = (L + R) / 2;
    return get(index << 1, L, mid, l, r, x) + get(index << 1 | 1, mid + 1, R, l, r, x);
}

void solve()
{
    int n, q; 
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 1, n);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;

        int med = (r - l) / 2 + 1;
        int lo = it[1].front(), hi = it[1].back(), mid, val;

        while (lo <= hi) {
            mid = (lo + hi) / 2;

            val = get(1, 1, n, l, r, mid);

            if (val < med) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        // dbg(med, ans);
        cout << lo-1 << "\n";
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

