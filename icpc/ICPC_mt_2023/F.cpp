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

int w[N], vst[N];

vector<int> adj[N];
int in[N], ou[N], cnt = 0, par[N], dep[N];

void dfs(int u)
{
    vst[u] = 1;
    ++cnt;
    in[u] = cnt;

    for (auto v : adj[u]) {
        if (!vst[v]) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
    }
    ++cnt;
    ou[u] = cnt;
}
 
bool query(int u, int v)
{
    return ((in[u]<in[v] && ou[u]>ou[v]) 
        || (in[v]<in[u] && ou[v]>ou[u]));
}

map<ii, int> mp[3];
map<ii, int> st;

int pre[N];

void dfs2(int u)
{
    vst[u] = 1;
    int tt = 0;
    for (auto v : adj[u]) {
        if (!vst[v]) {
            dfs2(v);
            tt += st[{v, u}];
        }
    }
    st[{u, par[u]}] += tt;
}

int f[N][20], d[N];

void dfslca(int u, int p) {
    f[u][0] = p;
    for (int i = 1; i < 20; ++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfslca(v, u);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (d[f[u][i]] >= d[v]) u = f[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

void solve()
{
    int n;
    cin >> n;
    rep (i, 0, n-1) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[1][{u, v}] = mp[1][{v, u}] = c1;
        mp[2][{u, v}] = mp[2][{v, u}] = c2;
    }
    dfs(1);
    memset(vst, 0, sizeof(vst));
    dfslca(1, 1);
    rep (i, 1, n) {
        if (query(i, i+1)) {
            int u = i, v = i+1;
            if (dep[u] > dep[v]) swap(u, v);
            st[{v, par[v]}] += 1;
            st[{u, par[u]}] -= 1;
        } else {
            int l = lca(i, i+1);
            st[{i, par[i]}] += 1;
            st[{i+1, par[i+1]}] += 1;
            st[{l, par[l]}] -= 2;
        }
    }
    memset(vst, 0, sizeof(vst));
    dfs2(1);
    int ans = 0;
    rep (i, 1, n) {
        int u = i, v = i+1;
        // dbg(v, par[v], st[{v, par[v]}]);
        ans += min(mp[1][{v, par[v]}] * st[{v, par[v]}], mp[2][{v, par[v]}]);
    } 
    cout << ans;
}
