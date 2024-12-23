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
int a[N], vst[N];

void dfs1(int u)
{
    vst[u] = 1;
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        adj2[u].push_back(v);
        dfs1(v);
    }
}

int w[N], par[N], l[N], r[N];

void dfs(int u, int &cnt)
{
    l[u] = cnt;
    for (auto v : adj2[u]) {
        par[v] = u;
        cnt++;
        dfs(v, cnt);
    }
    r[u] = cnt;
}

int fw[N];

void upd (int i, int val)
{
    for (; i < N; i += i & -i) fw[i] += val;
}

int get (int i)
{
    int res = 0;
    for (; i > 0; i -= i & -i) res += fw[i];
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    rep (i, 1, n+1) {
        cin >> a[i];
    }
    rep (i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    int cnt = 1;
    dfs(1, cnt);
    rep (i, 1, n+1) upd(l[i], a[i]);
    // build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            upd (l[s], -a[s]);
            upd (l[s], x);
            a[s] = x;
        } else {
            int s;
            cin >> s;
            cout << get(r[s]) - get(l[s]-1) << "\n";
        }
    }
}
