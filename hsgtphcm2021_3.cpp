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
const int N = 511;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0 ,0};

int vst[N][N], n, a[N][N];

void dfs (int u, int v, int val)
{
    vst[u][v] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = u + dx[i];
        int ny = v + dy[i];
        // dbg(nx, ny, a[nx][ny] - a[u][v], val);
        if (nx < 1 || nx > n || ny < 1 || ny > n || vst[nx][ny] || abs(a[nx][ny] - a[u][v]) > val) continue;
        dfs(nx, ny, val);
    } 
}

void init() {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) vst[i][j] = 0;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];

    int l = 1, r = 1e6 + 7, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        init();
        dfs(1, 1, mid);
        // for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cout << vst[i][j] << " \n"[j == n];
        // dbg(mid, vst[n][n]);
        if (vst[n][n]) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans;
}
