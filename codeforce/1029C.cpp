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
const int N = 3e5 + 7;

struct Segment
{
    int maxLeft, minRight = 1e9, cntLeft, cntRight;
} it[N * 4];

void lazy(int i, int l, int r) {
    if (l != r) {
        if (it[i << 1].maxLeft == 0) it[i << 1].maxLeft = it[i].maxLeft;
        if (it[i << 1 | 1].maxLeft == 0) it[i << 1 | 1].maxLeft = it[i].maxLeft;
        if (it[i << 1].minRight == 1e9) it[i << 1].minRight = it[i].minRight;
        if (it[i << 1 | 1].minRight == 1e9) it[i << 1 | 1].minRight = it[i].minRight;
    }
}

void update(int i, int l, int r, int L, int R, bool add = true) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {

        // dbg(i, l, r, it[i].maxLeft, it[i].minRight, it[i].cntLeft, it[i].cntRight, add, '\n');

        if (add) {
            it[i].maxLeft = max({it[i].maxLeft, L, it[i << 1].maxLeft, it[i << 1 | 1].maxLeft});
            it[i].minRight = min({it[i].minRight, R, it[i << 1].minRight, it[i << 1 | 1].minRight});
            it[i].cntLeft += (l == L);
            it[i].cntRight += (r == R);

            lazy(i, l, r);
        } else {
            it[i].cntLeft -= (l == L);
            it[i].cntRight -= (r == R);
            if (it[i].cntLeft <= 0) {
                if (it[i << 1].cntLeft > 1) {
                    it[i].maxLeft = it[i << 1].maxLeft;
                } else if (it[i << 1 | 1].cntLeft > 1){
                    it[i].maxLeft = it[i << 1 | 1].maxLeft;
                } else {
                    it[i].maxLeft = 0;
                }
            }
            if (it[i].cntRight <= 0) {
                if (it[i << 1].cntRight > 1) {
                    it[i].minRight = it[i << 1].minRight;
                } else if (it[i << 1 | 1].cntRight > 1){
                    it[i].minRight = it[i << 1 | 1].minRight;
                } else {
                    it[i].minRight = 1e9;
                }
            }

            lazy(i, l, r);
        }

        // dbg(i, l, r, it[i].maxLeft, it[i].minRight, it[i].cntLeft, it[i].cntRight, add);

        return;
    }
    int m = (l + r) >> 1;
    update(i << 1, l, m, L, R, add);
    update(i << 1 | 1, m + 1, r, L, R, add);
    
    it[i].maxLeft = max(it[i << 1].maxLeft, it[i << 1 | 1].maxLeft);
    it[i].minRight = min(it[i << 1].minRight, it[i << 1 | 1].minRight);

    // dbg(i, l, r, it[i].maxLeft, it[i].minRight, it[i].cntLeft, it[i].cntRight, add);
}

void solve()
{
    int n;
    cin >> n;
    vector<ii> a(n);
    vector<int> compress;
    rep (i, 0, n) {
        cin >> a[i].fi >> a[i].se;
        compress.pb(a[i].fi);
        compress.pb(a[i].se);
    }

    sort(all(compress));
    compress.resize(unique(all(compress)) - compress.begin());
    for (auto &c : a) {
        c.fi = lower_bound(all(compress), c.fi) - compress.begin();
        c.se = lower_bound(all(compress), c.se) - compress.begin();
    }

    vector<int> cnt(sz(compress) + 1, 0);
    for (auto &c : a) {
        update(1, 0, sz(compress), c.fi, c.se);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        dbg(a[i]);
        update(1, 0, sz(compress), a[i].fi, a[i].se, false);
        res = max(res, compress[it[1].minRight] - compress[it[1].maxLeft]);

        cerr << compress[it[1].minRight] << ' ' << compress[it[1].maxLeft] << endl;

        update(1, 0, sz(compress), a[i].fi, a[i].se);

    }
    cout << res << endl;

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