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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 3e5 + 7;

int n, k, a[N]; 

vector<int> it[4*N];

void build(int i, int l, int r)
{
    if (l == r) {
        it[i].pb(a[l]);
        return;
    }
    int m = (l + r) >> 1;
    build(i<<1, l, m);
    build(i<<1|1, m+1, r);
    merge(all(it[i<<1]), all(it[i<<1|1]), back_inserter(it[i]), greater<int>{});
    // accumulate(all(it[i]), it[i].begin());
}

// void bset(int i, int l, int r)
// {
//     if (l == r) {
//         return;
//     }
//     int m = (l + r) >> 1;
//     bset(i<<1, l, m);
//     bset(i<<1|1, m+1, r);
//     partial_sum(all(it[i]), it[i].begin());
//     dbg(i, l, r, it[i]);
// }

int pos = -1;

int get (int i, int L, int R, int l, int r)
{
    if (l > R || r < L) return 0;

    if (pos == 0) return 0;

    if (l <= L && R <= r) {
        if (sz(it[i]) <= pos) {
            pos -= sz(it[i]);
            dbg(i, L, R, it[i], pos);
            return it[i].back();
        }
        int x = it[i][pos-1];
        dbg(i, L, R, it[i], pos);
        pos = 0;
        return x;
    }
    int m = (L + R) >> 1;
    return get(i<<1, L, m, l, r) + get(i<<1|1, m+1, R, l, r);
}

void sub12()
{
    vector<int> pre(n+1);
    rep (i, 1, n+1) pre[i] = pre[i-1] + a[i-1];
    int res = -INF, dist = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+k-1; j < n; ++j) {
            int sum = pre[j+1] - pre[i];
            pos = k;
            int miss = get(1, 0, n-1, i, j);
            dbg(i, j, sum, miss);
            res = max(res, sum - miss);
        }
    }
    cout << res << "\n";
}

void solve()
{
    cin >> n >> k;
    rep (i, 0, n) cin >> a[i];

    if (n <= 2000) {
        build(1, 0, n-1);
        bset(1, 0, n-1);
        sub12();
        return;
    }
}
