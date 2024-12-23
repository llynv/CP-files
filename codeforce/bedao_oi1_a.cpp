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
const int N = 2e5 + 7;

vector<int> adj[N], adj2[N];
int f[N][20], d[N];

int dist[5001][5001]; 

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start][start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[start][v] == -1) {
                dist[start][v] = dist[start][u] + 1;
                q.push(v);
            }
        }
    }
}

vector<ii> edges;

int numb[N], low[N], bridges, joints, vs[N], vertexOrder, check[N];

void dfs(int u, int father)
{
    vertexOrder++;
    vs[u] = true;
    numb[u] = vertexOrder;
    low[u] = vertexOrder;
    int numbChild = 0;
    for (auto v : adj2[u]) {
        if (v == father) continue;

        if (vs[v]) {
            low[u] = min(low[u], numb[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            numbChild++;
            // cout << u << " " << v << " " << father << " " << numbChild << "\n";
            if (numb[v] == low[v]) {
                // bridges++;
                edges.pb({u, v});
            }
        }
    }
}


void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    if (n > 5000 || m > 5000) return;
    rep (i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep (i, 1, 5001) {
        rep (j, 1, 5001) {
            dist[i][j] = -1;
        }
    }
    rep (i, 1, 5001) bfs(i);
    rep (i, 0, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rep (i, 1, n + 1) {
            adj2[i].clear();
            numb[i] = low[i] = 0;
            adj2[i] = adj[i];
        }
        adj2[a].pb(b);
        adj2[b].pb(a);
        dfs(a, a);
        int res = 0;
        for (auto e : edges) {
            int u = e.fi, v = e.se;
            // dbg(u, v, dist[c][u], dist[c][v], dist[u][d], dist[v][d], dist[c][d]);
            if (dist[c][u] + dist[v][d] + 1 == dist[c][d] || dist[c][v] + dist[u][d] + 1 == dist[c][d]) {
                res++;
            }
        }
        cout << res << "\n";
    }
}
