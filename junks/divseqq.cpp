#include <bits/stdc++.h>
#include <omp.h>
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

#pragma omp parallel num_threads(2)


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 1e5 + 7;

int f[N][18], sum[N], a[N];

void buildSparseTable(int n, int m)
{
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i-1] + a[i-1];
        int pos = lower_bound(sum, sum+i, sum[i]-m) - sum;
        f[i-1][0] = pos;
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i < n; ++i) {
            // f[i][j] = min(f[i][j-1], f[i - (1 << (j - 1))][j-1]);
            int t = f[i][j-1];
            f[i][j] = t;
            if (t == 0) continue;
            f[i][j] = f[t-1][j-1];
            // dbg (i, j, f[i][j]);
        }
    }
}

void solve()
{
    int n, q, m;
    cin >> n >> q >> m;
    rep (i, 0, n) cin >> a[i];
    buildSparseTable(n, m);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--;
        int t = (int) log2(v), res = f[u][t];
        while (u >= 0 && v > 0) {
            t = (int) log2(v);
            res = min(res, f[u][t]);
            u = f[u][t] - 1;
            v -= (1 << t);
        }
        cout << res + 1 << endl;
    }

    auto Sum = [&] (int a, int b, auto&& Sum) {
        if (b == 0) return a;
        return Sum(a, b - 1, Sum) + a;
    };
    cout << Sum(2, 5, Sum) << endl;
}
