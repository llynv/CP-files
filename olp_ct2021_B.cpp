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
#define endl '\n'
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

const int INF = LONG_LONG_MAX;

struct segtree
{
    int sum, minVal;
};

const int N = 1e6 + 11;

segtree it[4 * N];
int a[N];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].sum = a[L-1];
        it[index].minVal = a[L-1];
        return;
    }

    int mid = (L + R) / 2;
    build (index * 2, L, mid);
    build (index * 2 + 1, mid + 1, R);
    it[index].sum = it[index * 2].sum + it[index * 2 + 1].sum;
    it[index].minVal = min(it[index * 2].minVal, it[index * 2 + 1].minVal);
}

bool isFound = false;

void update (int index, int L, int R, int l, int r, int p, int minval)
{
    if (R < l || L > r || it[index].minVal > minval) return;
    if (L == R) {
        if (!isFound) {
            a[L-1] = p;
            it[index].sum = a[L-1];
            it[index].minVal = a[L-1];
            isFound = true;
        }
        return;
    }

    int mid = (L + R) / 2;
    update (index * 2, L, mid, l, r, p, minval);
    update (index * 2 + 1, mid + 1, R, l, r, p, minval);
    it[index].sum = it[index * 2].sum + it[index * 2 + 1].sum;
    it[index].minVal = min(it[index * 2].minVal, it[index * 2 + 1].minVal);
}

int get_sum (int index, int L, int R, int l, int r)
{
    if (L > r || R < l) return 0;
    if (L >= l && R <= r) {
        return it[index].sum;
    }

    int mid = (L + R) / 2;
    return get_sum (2 * index, L, mid, l, r) + get_sum (2 * index + 1, mid + 1, R, l, r);
}

int get_min(int index, int L, int R, int l, int r)
{
    if (L > r || R < l) return INF;
    if (L >= l && R <= r) {
        return it[index].minVal;
    }

    int mid = (L + R) / 2;
    return min(get_min(2 * index, L, mid, l, r), get_min(2 * index + 1, mid + 1, R, l, r));
}

void solve()
{
    int n, q;
    cin >> n >> q;
    rep (i, 0, n) cin >> a[i];
    build (1, 1, n);
    int shift = 0;
    // cout << get(1, 1, n, 2, 4) << "\n";
    rep (i, 0, q) {
        int type, l, r, d;
        cin >> type;

        shift %= n;

        if (type == 3) {
            cin >> l >> r;

            l = (l - shift < 1 ? n - shift + l : l - shift);
            r = (r - shift < 1 ? n - shift + r : r - shift);

            if (l > r) {
                cout << get_sum (1, 1, n, l, n) + get_sum (1, 1, n, 1, r) << "\n";
            } else {
                cout << get_sum(1, 1, n, l, r) << "\n";
            }

        } else if (type == 2) {
            cin >> l >> r >> d;

            l = (l - shift < 1 ? n - shift + l : l - shift);
            r = (r - shift < 1 ? n - shift + r : r - shift);

            int x;
            isFound = false;
            if (l > r) {
                x = min(get_min(1, 1, n, l, n), get_min(1, 1, n, 1, r));
                update (1, 1, n, l, n, d, x);
                update (1, 1, n, 1, r, d, x);
            } else {
                x = get_min(1, 1, n, l, r);
                update (1, 1, n, l, r, d, x);
            }
        } else {
            cin >> d;
            shift += d;
        }
    }
    // rep (i, 0, n) cout << a[i] << " ";
}
