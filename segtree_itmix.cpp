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

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct Segment
{
    int val, plusUpdateVal, mulUpdateVal, resetUpdateVal;
};

int a[N];

Segment it[4 * N];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].val = a[L-1];
        return;
    }
    int mid = (L + R) / 2;
    build (index * 2, L, mid);
    build (index * 2 + 1, mid + 1, R);
    it[index].val = it[2 * index].val + it[2 * index + 1].val;
}

void lazyUpdate(int index, int L, int R)
{
    int k1 = it[index].plusUpdateVal;
    int k2 = it[index].mulUpdateVal;
    int k3 = it[index].resetUpdateVal;
    it[2 * index].plusUpdateVal += k1;
    it[2 * index].mulUpdateVal += k2;
    it[2 * index].resetUpdateVal += k3;
    it[2 * index + 1].plusUpdateVal += k1;
    it[2 * index + 1].mulUpdateVal += k2;
    it[2 * index + 1].resetUpdateVal += k3;
    int mid = (L + R) / 2;
    int left = (mid - L + 1), right = (R - mid);

    ((it[2 * index].val %= MOD) += left * k1) %= MOD;
    ((it[2 * index + 1].val %= MOD) += right * k1) %= MOD;

    if (k2 != 0) {
        ((it[2 * index].val %= MOD) *= k2) %= MOD;
        ((it[2 * index + 1].val %= MOD) *= k2) %= MOD;
    }
    if (k3 != 0) {
        it[2 * index].val = k3 * right;
        it[2 * index + 1].val = k3 * right;
    }
    it[index].plusUpdateVal = 0;
    it[index].mulUpdateVal = 0;
    it[index].resetUpdateVal = 0;
}

void update (int index, int L, int R, int l, int r, int type, int x)
{
    lazyUpdate(index, L, R);
    if (L > r || R < l) return;
    if (L >= l && R <= r) {
        if (type == 1) {
            it[index].val = ((it[index].val % MOD) + (R - L + 1) * x) % MOD;
            it[index].plusUpdateVal += x;
        } else if (type == 2) {
            it[index].val = ((it[index].val % MOD) * x) % MOD;
            it[index].mulUpdateVal += x;
        } else {
            it[index].val = (R - L + 1) * x;
            it[index].resetUpdateVal += x;
        }
        return;
    }

    int mid = (L + R) / 2;
    update (2 * index, L, mid, l, r, type, x);
    update (2 * index + 1, mid + 1, R, l, r, type, x);
    it[index].val = it[2 * index].val + it[2 * index + 1].val;
}

int get (int index, int L, int R, int l, int r)
{
    lazyUpdate(index, L, R);
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) {
        return (it[index].val % MOD);
    }
    int mid = (L + R) / 2;
    return (get (2 * index, L, mid, l, r) % MOD) + (get (2 * index + 1, mid + 1, R, l, r) % MOD) % MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    int type, l, r, x;
    build (1, 1, n);
    rep (i, 0, m) {
        cin >> type >> l >> r;
        if (type != 4) {
            cin >> x;
            update (1, 1, n, l, r, type, x);

            // rep (j, 1, n+1) {
            //     cout << get(1, 1, n, j, j) << " ";
            // }
            // cout << endl;
            // cout << get(1, 1, n, 1, n) << "\n";
        } else {
            cout << get(1, 1, n, l, r) % MOD << "\n";
        }
    } // 3 4 5 4 5
    // 3 16 20 16 5
}
