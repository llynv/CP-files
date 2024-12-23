#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
// #define fill(x, y) memset(x, y, sizeof(x))
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

void dfs (int u, int val, vector<vector<int>> &adj, vector<int> &vst, vector<ii> &a) {
    vst[u] = 1;
    for (auto &v : adj[u]) {
        if (!vst[v] && a[v-1].x <= val && val <= a[v-1].y) dfs(v, val, adj, vst, a);
    }
};

void solve()
{
    int n, m, s, e, k;
    cin >> n >> m >> s >> e >> k;
    vector<vector<int>> adj(n+1);
    vector<ii> a(n);
    vector<int> vst(n+1);
    for (auto &c : a) cin >> c.x >> c.y;
    vector<int> v;
    v.push_back(0);
    for (auto &c : a) {
        v.push_back(c.x-1);
        v.push_back(c.y);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    v.push_back(k);
    sort(all(v));
    // dbg(v);
    vector<ii> pa;
    for (int i = 1; i < sz(v); ++i) {
        if (v[i] - v[i-1] >= 1) pa.push_back({v[i-1] + 1, v[i]});
    }
    // dbg(pa);
    int res = 0;
    for (auto &c : pa) {
        int val = c.x;
        for (auto &v : vst) v = 0;
        dfs(s, val, adj, vst, a);
        if (vst[e]) {
            res += c.y - c.x + 1;
            // return;
            // dbg(c);
        }
    }
    cout << res << "\n";
}
