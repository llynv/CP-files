#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

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
const int MINF = -0x3f3f3f3f;

int res = LONG_LONG_MIN;

const int dx[] = {0, 0, 1};
const int dy[] = {-1, 1, 0}; 
const int N = 1e3 + 11;

int n, m;
int a[N][N], vst[N][N];
int mxn[N][N];

void dfs(int u, int v, int val)
{
    vst[u][v] = 1;
    mxn[u][v] = max(mxn[u][v], val);
    // cout << u << " " << v << " : " << val << "\n";
    for (int i = 0; i < 3; ++i) {
        int xx = dx[i] + u;
        int yy = dy[i] + v;
        // dbg(xx, yy);
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && !vst[xx][yy]) {
            dfs(xx, yy, val + a[xx][yy]);
            vst[xx][yy] = 0;
        }
    }
}

void solve()
{
    cin >> n >> m;
    memset(mxn, MINF, sizeof(mxn));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        dfs(0, i, a[0][i]);
        memset(vst, 0, sizeof(vst));
    }
    for (int i = 0; i < m; ++i) {
        res = max(res, mxn[n-1][i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << mxn[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << res;
}
