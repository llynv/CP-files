#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
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


void solve();

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5+7;

int a[N];
struct Segtree
{
    int val, updVal;
    bool isChange;
} it[2000111];

void build (int i, int l, int r)
{
    if (l == r) {
        it[i].val = a[l];
        it[i].isChange = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
    it[i].val = max(it[i<<1].val, it[i<<1|1].val);
    it[i].isChange = 0;
}

void lazy(int i, int l, int r)
{
    if (it[i].updVal == 0) return;
    int k = it[i].updVal;
    if (l != r) {
        it[i<<1].updVal += k;
        it[i<<1|1].updVal += k;
        if (!it[i<<1].isChange) {
            it[i<<1].isChange = (k >= it[i<<1].val);
            it[i<<1].val = abs(it[i<<1].val - k);
        } else {
            it[i<<1].val += k;
        }
        if (!it[i<<1|1].isChange) {
            it[i<<1|1].isChange = (k >= it[i<<1|1].val);
            it[i<<1|1].val = abs(it[i<<1|1].val - k);
        } else{
            it[i<<1|1].val += k;
        }
    }
    it[i].updVal = 0;
}

void update(int i, int l, int r, int u, int v, int val)
{
    lazy(i, l, r);
    if (l > v || r < u) return;
    lazy(i, l, r);
    if (u <= l && r <= v) {
        if (!it[i].isChange) {
            it[i].isChange = (val >= it[i].val);
            it[i].val = abs(it[i].val - val);
            it[i].updVal += val;
            return;
        }
        it[i].val += val;
        it[i].updVal += val;
        return;
    }
    int m = (l + r) >> 1;
    update(i<<1, l, m, u, v, val);
    update(i<<1|1, m+1, r, u, v, val);
    it[i].val = max(it[i<<1].val, it[i<<1|1].val);
}

int get(int i, int l, int r, int u, int v)
{
    lazy(i, l, r);
    if (l > v || r < u) return -INF;
    lazy(i, l, r);
    if (u <= l && r <= v) return it[i].val;
    int m = (l + r) >> 1;
    return max(get(i<<1, l, m, u, v), get(i<<1|1, m+1, r, u, v));
}

const int LOG = 20;

void solve()
{
    int n;
    cin >> n;
    rep(i, 0, n)
        cin >> a[i];

    int tmp = 1e9 - 1;

    build(1, 0, n-1);
    int mx = 0, sum = 0, tt = 0;
    for (int i = 1; i < n; ++i) {
        // int x = get(1, 0, n-1, i, i);
        // mx = get(1, 0, n-1, 0, i-1);
        // if (x < mx) {
        //     sum += (x + mx + 1) / 2;
        //     update(1, 0, n-1, 0, n-1, (x + mx + 1) / 2);

        //     // cerr << "update " << x << " " << (int) ceil((x + mx) / 2.0) << "\n";
        //     // for (int i = 0; i < n; ++i) {
        //     //     a[i] = get(1, 0, n-1, i, i);
        //     //     cerr << a[i] << " \n"[i==n-1];
        //     // }
        // } else {
        //     sum += x;
        //     update(1, 0, n-1, 0, n-1, x);
        // }
        if (a[i] < a[i-1]) {
            sum += (a[i-1] + a[i] + 1) / 2;
            tt = max(tt, (a[i-1] + a[i] + 1) / 2);
            // a[i] = a[i-1];
        } else if (a[i] > a[i-1]) {
            sum -= (a[i] + a[i-1] + 1) / 2;
        }
    }
    cout << (sum >= 0 ? tt : -1) << "\n";
}
