#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()

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
const int N = 1e5 + 11;

vector<int> adj[N];
int vst[N];

void dfs_cycle(int u, int p, int color[], int par[], set<vector<int>> &cycles)
{
    if (color[u] == 2) {
        return;
    }
 
    if (color[u] == 1) {
        vector<int> v;
        int cur = p;
        bool isOk = false;
        v.emplace_back(cur);
        while (cur != u) {
            cur = par[cur];
            v.emplace_back(cur);
        }
        if (v.size() == 3) {
            sort(all(v));
            cycles.insert(v);
        }
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

void dfs(int u, int &edge, int &vertex)
{
    vst[u] = 1;
    vertex++;
    edge += adj[u].size();
    for (auto v : adj[u]) {
        if (!vst[v]) {
            dfs(v, edge, vertex);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m == 0) {
        cout << 3 << " " << n * (n - 1) * (n - 2) / 6;
        return;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    set<vector<int>> cycle;
    for (int i = 1; i <= n; ++i) {
        // memset(color, 0, sizeof(color));
        // memset(par, 0, sizeof(par));
        int color[n + 1] = {0}, par[n + 1] = {0};
        dfs_cycle(i, -1, color, par, cycle);
    }
    int res = 0, type = -1;
    // dbg(cycle);
    if (cycle.size() > 0) {
        //type 0
        cout << 0 << " " << cycle.size();
        return;
    }

    bool isTwo = true;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() >= 2) {
            isTwo = false;
            break;
        }
    }

    if (isTwo) {
        cout << 2 << " " << m*(n-2);
        return;
    }

    
}
