#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

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
const int N = 1e4 + 7;

int dist[N], revDist[N];
vector<ii> adj[N], revAdj[N];

void dijsktra(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        int d = cur.fi, u = cur.se;
        for (auto c : adj[u]) {
            int v = c.fi, w = c.se;
            if (dist[v] > dist[u] + w || dist[v] == -1) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void revDijsktra(int s) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    revDist[s] = 0;
    while (!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        int d = cur.fi, u = cur.se;
        for (auto c : revAdj[u]) {
            int v = c.fi, w = c.se;
            if (revDist[v] > revDist[u] + w || revDist[v] == -1) {
                revDist[v] = revDist[u] + w;
                pq.push({revDist[v], v});
            }
        }
    }
}

void solve()
{
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    rep (i, 0, m) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].pb({v, x});
        revAdj[v].pb({u, x});
    }

    memset(dist, -1, sizeof(dist));
    memset(revDist, -1, sizeof(revDist));
    dijsktra(s);
    revDijsktra(t);

    int ans = (dist[t] == -1 ? INF : dist[t]);

    rep (i, 0, k) {
        int u, v, x;
        cin >> u >> v >> x;
        if (dist[u] != -1 && revDist[v] != -1)
            ans = min(ans, dist[u] + x + revDist[v]);
        if (dist[v] != -1 && revDist[u] != -1)
            ans = min(ans, dist[v] + x + revDist[u]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}
