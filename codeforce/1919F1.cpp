#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;
const int N = 6e5 + 7;

int a[N], b[N], c[N];

struct SegmentTree {
    int n;
    vector<int> t, lazy;

    SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n + 7);
        lazy.resize(4 * n + 7);
    }

    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (l > tr || r < tl) return -INF;
        if (l <= tl && tr <= r) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
    }

    void update(int l, int r, int val) {
        update(1, 1, n, l, r, val);
    }

    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 1, n) cin >> c[i];

    int cur = 0;
    SegmentTree st(n);
    for (int i = 1; i <= n; ++i) {
        cur += a[i];
        // update(1, 1, n, i, pref[i], it1);
        // add(i, a[i] - b[i]);
        // pref[i] = pref[i + 1] + a[i] - b[i];
        st.update(1, i, a[i] - b[i]);
    }

    rep (i, 0, q) {
        int p, x, y, z;
        cin >> p >> x >> y >> z;
        
        cur -= a[p];
        st.update(1, p, b[p] - a[p]);
        st.update(1, p, x - y);
        a[p] = x;
        b[p] = y;
        cur += a[p];
        // dbg(st.t[1]);

        cout << cur - max(0LL, st.get(1, n)) << endl;
    }

}

int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}