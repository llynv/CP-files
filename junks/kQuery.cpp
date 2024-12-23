#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define _(x) ((x) & (-x))

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

const int N = 2e5 + 7;
const int IMX = 1e9 + 7;

vector<int> it[N];
vector<int> a;

void merge(vector<int> &res, vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            res.pb(a[i]);
            i++;
        } else {
            res.pb(b[j]);
            j++;
        }
    }
    while (i < a.size()) {
        res.pb(a[i]);
        i++;
    }
    while (j < b.size()) {
        res.pb(b[j]);
        j++;
    }
}

void build(int index, int L, int R)
{
    if (L == R) {
        it[index].pb(a[L-1]);
        return;
    }
    int mid = (L + R) / 2;
    build(index << 1, L, mid);
    build(index << 1 | 1, mid + 1, R);
    merge(it[index], it[index << 1], it[index << 1 | 1]);
    // dbg(it[index]);
}

int get(int index, int L, int R, int u, int v, int k)
{
    if (L > v || R < u) {
        return 0;
    }
    if (L >= u && R <= v) {
        return it[index].end() - upper_bound(it[index].begin(), it[index].end(), k);
    }
    int mid = (L + R) / 2;
    return get(index << 1, L, mid, u, v, k) + get(index << 1 | 1, mid + 1, R, u, v, k);
}

void solve()
{
    int n;
    cin >> n;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    build(1, 1, n);
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << get(1, 1, n, l, r, k) << '\n';
    }
}
