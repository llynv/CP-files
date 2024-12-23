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
const int N = 511;

int a[N][N], vst[N][N];

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int n, g;

int dist[N][N];

bool dfs2(int u, int v, const int val, int prior)
{
    vst[u][v] = prior;
    if (vst[n][n] == prior) return true;

    rep(i, 0, 4) {
        int x = u + dx[i];
        int y = v + dy[i];
        if (x < 1 || x > n || y < 1 || y > n) continue;
        if (vst[x][y] == prior) continue;
        if (a[x][y] < val) continue;
        if (dfs2(x, y, val, prior)) return true;
    }
    return false;
}

void solve()
{
    int t;
    cin >> t;
    if (t == 1) {
        cin >> n >> g;
        rep (i, 1, n+1) {
            rep (j, 1, n+1) {
                cin >> a[i][j];
                if (a[i][j] >= g) a[i][j] = 0;
                else a[i][j] = 1;
                // cout << a[i][j] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
        
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> Q;
        Q.push({a[1][1], {1, 1}});
        rep (i, 1, n+1) rep (j, 1, n+1) dist[i][j] = -1;
        dist[1][1] = a[1][1];
        while (!Q.empty()) {
            pair<int, ii> cur = Q.top();
            int u = cur.se.fi;
            int v = cur.se.se;
            Q.pop();
            rep (i, 0, 4) {
                int x = u + dx[i];
                int y = v + dy[i];
                if (x < 1 || x > n || y < 1 || y > n) continue;
                if ((dist[x][y] == -1) || (dist[x][y] > cur.fi + a[x][y])) {
                    dist[x][y] = cur.fi + a[x][y];
                    Q.push({dist[x][y], {x, y}});
                }
            }
        }
        cout << dist[n][n];

    } else {
        cin >> n;
        rep (i, 1, n+1) rep (j, 1, n+1) cin >> a[i][j];

        int lo = 1, hi = 1e4 + 7, ans = -1, prior = 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;

            bool ok = dfs2(1, 1, mid, prior++);
            // dbg(mid, ok);
            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans;
    }
}
