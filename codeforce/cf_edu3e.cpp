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
const int N = 2e5 + 11;

int root[N];

int FindRoot(int u)
{
    if (u == root[u]) {
        return u;
    } 
    return root[u] = FindRoot(root[u]);
}

void UnionSet(int u, int v)
{
    int rootu = FindRoot(u);
    int rootv = FindRoot(v);
    if (rootu != rootv) {
        root[rootu] = rootv;
    }
}

struct Graph
{
    int u, v, w;
};

bool cmp (Graph a, Graph b) {
    return a.w <= b.w;
}

vector<ii> adj[N];

int vs [N];

void dfs(int n, int u, int &val)
{
    if (vs[n] == -1) return;

    if (vs[n] == 1) {
        int x = 
    }

    vs[n] = 1;

    par[n] = u;

    for (auto c : adj[n]) {
        if (!vst[c]) dfs(u, c, val);        
    }

    vst[n] = -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) root[i] = i;
    vector<Graph> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    vector<Graph> b = a;
    int rmin = 0;
    map<ii, bool> vst;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        x = a[i].u;
        y = a[i].v;
        w = a[i].w;
        if (FindRoot(x) != FindRoot(y)) {
            rmin += w;
            UnionSet(x, y);
            vst[make_pair(x, y)] = 1;
            adj[x].emplace_back(make_pair(y, w));
            adj[y].emplace_back(make_pair(x, w));
            // cout << x << " " << y << "\n";
        }
    }
    for (int i = 0; i < m; ++i) {
        // cout << b[i].u << " " << b[i].v << "\n";
        if (vst[make_pair(b[i].u, b[i].v)]) {
            cout << rmin << "\n";
            continue;
        }
        int x = b[i].u;
        int y = b[i].v;
        int w = b[i].w;
        int tmp = 0;
        
        FindMaxValue(tmp);

        cout << rmin - tmp + b[i].w << "\n";
    }
}
