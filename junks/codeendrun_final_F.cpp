#include <bits/stdc++.h>
using namespace std;

#define LOCAL
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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

int a[N];

struct Segtree
{
    int val, updateVal;
};

Segtree it[4 * N];

void lazyUpdate (int index, int L, int R)
{
    int k = it[index].updateVal;
    it[2 * index].updateVal += k;
    it[2 * index + 1].updateVal += k;
    int mid = (L + R) / 2;
    it[2 * index].val += k * (mid - L + 1);
    it[2 * index + 1].val += k * (R - mid);
    it[index].updateVal = 0;
}

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].val = a[L-1];
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    it[index].val = it[index * 2].val + it[index * 2 + 1].val;
}

void update (int index, int L, int R, int l, int r, int val)
{
    if (l > R || r < L) return;
    lazyUpdate(index, L, R);
    if (l <= L && R <= r) {
        it[index].val += val * (R - L + 1);
        it[index].updateVal += val;
        return;
    }
    int mid = (L + R) / 2;
    update(index * 2, L, mid, l, r, val);
    update(index * 2 + 1, mid + 1, R, l, r, val);
    it[index].val = it[index * 2].val + it[index * 2 + 1].val;
}

int get (int index, int L, int R, int l, int r)
{
    if (l > R || r < L) return 0;
    lazyUpdate(index, L, R);
    if (l <= L && R <= r) return it[index].val;
    int mid = (L + R) / 2;
    lazyUpdate(index, L, R);
    return get(index * 2, L, mid, l, r) + get(index * 2 + 1, mid + 1, R, l, r);
}

void solve()
{
    int n;
    cin >> n;
    rep (i, 0, n) cin >> a[i];
    rep (i, 1, n) {
        a[i] += a[i-1];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            update(1, 1, n, l, n, r);
        } else {
            // cout << get(r) - get(l-1) << endl;
            cout << get(1, 1, n, l, r) << endl;
        }
    }
}
