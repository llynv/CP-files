/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ii pair<int, int>
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
const int MOD = 1e8;

struct segment_tree {
    vector<int> t;
    int n;
    segment_tree(int n) : n(n) {
        t.assign(4 * n, 0);
        build();
    }

    // build the tree beginning node is INF

    void build() {
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = INF;
        }
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    // update value at index i
    void update(int i, int x) {
        update(1, 0, n - 1, i, x);
    }

    void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = x;
        }
        else {
            int tm = (tl + tr) / 2;
            if (i <= tm) {
                update(v * 2, tl, tm, i, x);
            }
            else {
                update(v * 2 + 1, tm + 1, tr, i, x);
            }
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }

    // get min value in range [l, r]
    int get(int l, int r) {
        return get(1, 0, n - 1, l, r);
    }
    int get(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INF;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(get(v * 2, tl, tm, l, min(r, tm)),
            get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

vector<int> pos;

segment_tree seg(2e6 + 5);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for (auto& c : a) cin >> c, st.insert(c);
    for (auto c : pos) {
        seg.update(c, INF);
    }
    pos.clear();

    multiset<ii> s;
    map<int, multiset<int>> mp;

    if (a[0] != 1) {
        s.insert({ a[0] - 1, 1 });
        mp[a[0] - 1].insert(1);
        seg.update(a[0] - 1, *mp[a[0] - 1].begin());
        pos.pb(a[0] - 1);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 1) {
            s.insert({ a[i] - a[i - 1] - 1, a[i - 1] + 1 });
            mp[a[i] - a[i - 1] - 1].insert(a[i - 1] + 1);
            seg.update(a[i] - a[i - 1] - 1, *mp[a[i] - a[i - 1] - 1].begin());
            pos.pb(a[i] - a[i - 1] - 1);
        }
    }

    dbg(s);
    int m;
    cin >> m;
    int mx = 0;
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        int x;
        cin >> x;
        if (c == '?') {
            dbg(st);
            int ans = seg.get(x, 2e6 + 2);
            dbg(x);
            if (ans == INF) {
                cout << (st.size() ? *st.rbegin() + 1 : 1) << ' ';
                continue;
            }
            cout << ans << ' ';
        }
        else if (c == '+') {
            dbg(c);
            st.insert(x);
            auto it = st.find(x);
            int spot = (it == st.begin() ? 0 : *prev(it));
            int nxt = (next(it) == st.end() ? 2e6 - 5 : *next(it));
            if (mp[nxt - spot - 1].find(spot + 1) != mp[nxt - spot - 1].end()) {
                mp[nxt - spot - 1].erase(mp[nxt - spot - 1].find(spot + 1));
                if (mp[nxt - spot - 1].empty()) {
                    seg.update(nxt - spot - 1, INF);
                } else {
                    seg.update(nxt - spot - 1, *mp[nxt - spot - 1].begin());
                }
                pos.pb(nxt - spot - 1);
            }
            
            mp[nxt - x - 1].insert(x + 1);
            mp[x - spot - 1].insert(spot + 1);
            seg.update(nxt - x - 1, *mp[nxt - x - 1].begin());
            seg.update(x - spot - 1, *mp[x - spot - 1].begin());
            pos.pb(nxt - x - 1);
            pos.pb(x - spot - 1);
        }
        else {
            dbg(c);
            auto it = st.find(x);
            int spot = (it == st.begin() ? 0 : *prev(it));
            int nxt = (next(it) == st.end() ? 2e6 - 5 : *next(it));

            if (mp[nxt - x - 1].find(x + 1) != mp[nxt - x - 1].end()) mp[nxt - x - 1].erase(mp[nxt - x - 1].find(x + 1));
            if (mp[x - spot - 1].find(spot + 1) != mp[x - spot - 1].end()) mp[x - spot - 1].erase(mp[x - spot - 1].find(spot + 1));
            pos.pb(nxt - x - 1);
            pos.pb(x - spot - 1);
            if (mp[nxt - x - 1].empty()) {
                seg.update(nxt - x - 1, INF);
            } else {
                seg.update(nxt - x - 1, *mp[nxt - x - 1].begin());
            }
            if (mp[x - spot - 1].empty()) {
                seg.update(x - spot - 1, INF);
            } else {
                seg.update(x - spot - 1, *mp[x - spot - 1].begin());
            }

            mp[nxt - spot - 1].insert(spot + 1);
            seg.update(nxt - spot - 1, *mp[nxt - spot - 1].begin());
            pos.pb(nxt - spot - 1);
            st.erase(it);
        }
    }
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    cout << '\n';
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