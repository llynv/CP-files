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
const int MOD = 1e8;

const int N = 2e5 + 11;

int a[N], k = 1;

// segment tree with lazy propagation for assign all elements in range [l, r] that equal to x to y
// query 1 l r x y: assign all elements in range [l, r] that equal to x to y
// query 2 x: get value at position x
struct SegmentTree {
    int n;
    vector<int> lazy_x, lazy_y, val;

    SegmentTree(int size) {
        n = size;
        val.resize(4 * n);
        lazy_x.resize(4 * n);
        lazy_y.resize(4 * n);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            val[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
    }

    void push(int node, int start, int end, int wei = 0) {
        if (lazy_x[node] == 0 || lazy_y[node] == 0) return;
        if (wei > k) return;
        if (start != end) {
            if (lazy_x[node * 2] != 0) push(node * 2, start, (start + end) / 2, wei + 1);
            if (lazy_x[node * 2 + 1] != 0) push(node * 2 + 1, (start + end) / 2 + 1, end, wei + 1);
            if (lazy_y[node * 2] == lazy_x[node] || lazy_y[node * 2] == 0) {
                lazy_y[node * 2] = lazy_y[node];
                if (lazy_x[node * 2] == 0) lazy_x[node * 2] = lazy_x[node];
            }
            if (lazy_y[node * 2 + 1] == lazy_x[node] || lazy_y[node * 2 + 1] == 0) {
                lazy_y[node * 2 + 1] = lazy_y[node];
                if (lazy_x[node * 2 + 1] == 0) lazy_x[node * 2 + 1] = lazy_x[node];
            }
        } else {
            if (val[node] == lazy_x[node] || lazy_x[node] == 0) {
                val[node] = lazy_y[node];
            }
        }
        lazy_x[node] = 0;
        lazy_y[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, int x, int y) {
        push(node, start, end);
        if (start > r || end < l) return;
        push(node, start, end);
        if (start >= l && end <= r) {
            lazy_x[node] = x;
            lazy_y[node] = y;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, x, y);
        update(2 * node + 1, mid + 1, end, l, r, x, y);
    }

    int query(int node, int start, int end, int x) {
        push(node, start, end);
        if (start == end) return val[node];
        int mid = (start + end) / 2;
        if (x <= mid) return query(2 * node, start, mid, x);
        return query(2 * node + 1, mid + 1, end, x);
        lazy_x[node] = 0;
        lazy_y[node] = 0;
    }

    // count number of elements in range [l, r] that equal to x
    int count(int node, int start, int end, int l, int r, int x) {
        push(node, start, end);
        if (start > r || end < l) return 0;
        if (start >= l && end <= r) {
            return val[node] == x;
        }
        int mid = (start + end) / 2;
        return count(2 * node, start, mid, l, r, x) + count(2 * node + 1, mid + 1, end, l, r, x);
    }

};


void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    SegmentTree st(n);
    st.build(1, 1, n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            st.update(1, 1, n, l, r, x, y);
            ++k;
        }
        else if (t == 2) {
            int x;
            cin >> x;
            cout << st.query(1, 1, n, x) << '\n';
            k = 1;
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            int cnt = 0;
            for (int i = l; i <= r; ++i) {
                cnt += st.query(1, 1, n, i) == x;
            }
            cout << cnt << '\n';
        }
    }
    int sum = 0;
    // cerr << "final: \n";
    for (int i = 1; i <= n; ++i) {
        sum += st.query(1, 1, n, i);
        // cerr << st.query(1, 1, n, i) << ' ';
    }
    // cerr << '\n';
    cout << sum << '\n';
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