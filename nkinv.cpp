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
const int N = 6e4 + 11;

int a[N], fw[N], it[N];

void update(int start, int n, int value)
{
    int i = start + 1;
    while (i <= n) {
        fw[i] += value;
        i += _(i);
    }
}

int get(int n)
{
    int i = n + 1;
    int ret = 0;
    while (i > 0) {
        ret += fw[i];
        i -= _(i);
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    int cnt = 0, target = LONG_LONG_MAX, pos = 0;
    for (int i = 0; i < n; ++i) {
        update(i, n, a[i]);
        // cout << it[i] << " ";
    }
    for (int i = 0; i < n; ++i) {
        cout << get(i) << " ";
    }
    update(0, n, 10);
    cout << get(n);
    // for (int i = 0; i < n; ++i) cout << it[i] << ' ';
}
