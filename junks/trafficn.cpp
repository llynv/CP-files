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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 1e15 + 7;

vector<pair<int,int> > adj[10007], rev_adj[10007];
priority_queue< pair<int,int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int dist[10007], rev_dist[10007];

void dijkstra(int start, int end)
{
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        for (auto u : adj[c.se]) {
            if (dist[u.fi] > dist[c.se] + u.se) {
                dist[u.fi] = dist[c.se] + u.se;
                // road[u.fi] = c.se;
                pq.push(make_pair(dist[u.fi], u.fi));
            }
        }
    }
}

void rev_dijkstra(int start, int end)
{
    pq.push(make_pair(0, start));
    rev_dist[start] = 0;
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        for (auto u : rev_adj[c.se]) {
            if (rev_dist[u.fi] > rev_dist[c.se] + u.se) {
                rev_dist[u.fi] = rev_dist[c.se] + u.se;
                // road[u.fi] = c.se;
                pq.push(make_pair(rev_dist[u.fi], u.fi));
            }
        }
    }
}


void init (int n)
{
    for (int i = 0; i <= n; ++i) dist[i] = rev_dist[i] = INF;
}

void solve()
{
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        rev_adj[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(make_pair(v, w));
        rev_adj[v].emplace_back(make_pair(u, w));
    }
    init(n);
    dijkstra(s, t);
    rev_dijkstra(t, s);

    int ans = INF;
    if (dist[t] != INF) ans = dist[t];
    for (int i = 0; i < k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // init(n);
        // dijkstra(s, v);
        // rev_dijkstra(t, u);
        if (dist[u] != INF && rev_dist[v] != INF) {
            // cout << min(dist[v], dist[u]) << " " << min(rev_dist[u], rev_dist[v]) << "\n";
            ans = min(ans, dist[u] + rev_dist[v] + w);
        }
        if (dist[v] != INF && rev_dist[u] != INF) {
            ans = min(ans, dist[v] + rev_dist[u] + w);
        }
    }
    cout << (ans == INF ? -1 : ans)  << "\n";

    // dbg(rd);
}
