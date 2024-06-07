#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxM = 1001;

struct SegmentTree {
    vector<bitset<maxM>> t;
    int n;
    SegmentTree(int n) : n(n), t(4 * n) {}
    SegmentTree(vector<int> a) : SegmentTree(a.size()) {
        build(a, 1, 0, n - 1);
    }
    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            t[id].set(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(a, id * 2, l, m);
        build(a, id * 2 + 1, m + 1, r);
        t[id] = (t[id * 2] ^ t[id * 2 + 1]);
    }
    bitset<maxM> query(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return bitset<maxM>();
        if (l >= u && r <= v) return t[id];
        int m = (l + r) / 2;
        return (query(id * 2, l, m, u, v) ^ query(id * 2 + 1, m + 1, r, u, v));
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    clock_t start = clock();

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    SegmentTree st(a);
    st.build(a, 1, 0, n - 1);

    vector<bitset<maxM>> pattern (maxM, bitset<maxM>());
    for (int i = 1; i <= 100; ++i) {
        for (int j = i; j <= 100; j += i) {
            pattern[i].set(j);
        }
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        cout << (st.query(1, 0, n-1, l, r) & pattern[x]).count() << '\n';
    }

    cerr << fixed << setprecision(3) << "Time: " << 1.0 * (clock() - start) / CLOCKS_PER_SEC << " s\n";

    return 0;
}