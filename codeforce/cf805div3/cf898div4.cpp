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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

vector<int> adj[N], sloop;
int vs[N];
vector<vector<int>> cycles;
bool isCircle = false;
int par[N];
 
void dfs_cycle(int u, int p, int color[], int par[], vector<vector<int>> &cycles)
{
    if (color[u] == 2) {
        return;
    }
 
    if (color[u] == 1) {
        vector<int> v;
           
        int cur = p;
        v.push_back(cur);
 
        while (cur != u) {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    color[u] = 1;
 
    for (int v : adj[u]) {
 
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cycles);
    }
 
    color[u] = 2;
}


int dist[2][N];

void bfs(int u, int id)
{
    queue<int> q;
    q.push(u);
    dist[id][u] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (dist[id][v] == -1) {
                dist[id][v] = dist[id][u] + 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    sloop.clear();
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dist[0][i] = dist[1][i] = -1;
        vs[i] = false;
        // numb[i] = low[i] = 0;
        par[i] = 0;
    }
    cycles.clear();

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int cycle_id = 0;
    vector<int> cycle;
    dfs_cycle(1, 0, vs, par, cycles);

    for (auto c : cycles) {
        if (c.size() > 2) {
            for (auto v : c) {
                // cout << v << " ";
                sloop.emplace_back(v);
            }
        }
    }

    bfs(a, 0);
    bfs(b, 1);

    for (auto c : sloop) {
        if (dist[1][c] < dist[0][c]) {
            return void (cout << "YES\n");
        }
    }
    cout << "NO\n";
}
