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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int prime[N+1];

void eratos() {
    // memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= N; i += 2) prime[i] = 2;
    for (int i = 3; i * i <= N; i += 2) {
        if (!prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = i;
            }
            prime[i] = i;
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (!prime[i]) prime[i] = i;
    }
}

vector<int> primeFactor(int n) {
    vector<int> res;
    while (n > 1) {
        res.emplace_back(prime[n]);
        n /= prime[n];
    }
    return res;
}

int a[N], vst[N], ans[N];
map<int, int> it [N];
vector<int> adj[N];

void dfs(int u)
{
    vector <int> tmp = primeFactor(a[u - 1]);
    for (auto &c : tmp) {
        it[u][c]++;
    }
    vst[u] = 1;
    for (auto c : adj[u]) {
        if (!vst[c]) {
            dfs(c);
            for (auto d : it[c]) {
                it[u][d.first] += d.second;
            }
        }
    }
    int tt = 1;
    for (auto c : it[u]) {
        tt = (tt * (c.second + 1)) % MOD;
    }
    ans[u] = tt;
}

void solve()
{
    eratos();
    int n, q;
    cin >> n >> q;
    rep (i, 0, n) cin >> a[i];
    // Node *p = root;
    rep (i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    vector<int> qs(q);
    rep (i, 0, q) cin >> qs[i];
    for (auto &c : qs) {
        // cout << c << " ";
        cout << ans[c] << " ";
        // cout << res << " ";
    }
}
