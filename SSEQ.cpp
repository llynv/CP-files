#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

struct SSEQ
{
    int l;
    int r;
    int w;
};

bool cmp (SSEQ a, SSEQ b) {
    if (a.l <= b.l) return true;

    if (a.r < b.r) return false;
    return false;
}

void solve()
{
    // freopen("SSEQ.INP", "r", stdin);
    // freopen("SSEQ.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<SSEQ> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto ii : a) cout << ii.l << " " << ii.r << " " << ii.w << "\n";
    int res = 0, init = 0;
    for (int i = 0; i < n; ++i) {
        init += a[i].w;
        res = max(res, init);
    }
    for (int i = 1; i < n; ++i) {
        int tmp = 0;
        if (a[i].l != a[i-1].l) {
            for (int j = i; j < n; ++j) {
                tmp += a[j].w;
                res = max(res, tmp);
            }
        }
    }
    cout << res;
}