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

const int INF = 0x3f3f3f3f3f;

vector<ii> adj[107];
int dist[107], road[107];

void dijkstra (int n)
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push(make_pair(0, n));
    dist[n] = 0;
    road[n] = 1;
    while (!q.empty())
    {
        ii cur = q.top();
        q.pop();
        
        for (auto c : adj[cur.se]) {
            if (dist[c.fi] > cur.fi + c.se) {
                road[c.fi] = max(road[cur.se] + 1, road[c.fi]);
                dist[c.fi] = cur.fi + c.se;
                q.push(make_pair(dist[c.fi], c.fi));
            }
        }
    }
}

void init(int n)
{
    for (int i = 1; i <= n; ++i) {
        dist[i] = LONG_LONG_MAX;
        road[i] = 0;
    }
}

void solve()
{   
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(make_pair(v, w));
        adj[v].emplace_back(make_pair(u, w));
    }

    int cnt = 0;
    double res = 8000000000;
    if (adj[1].size() < 2) {
        cout << -1;
        return;
    }
    vector<ii> ves;
    for (auto c : adj[1]) {
        ves.emplace_back(c);
    }
    for (auto c : ves) {
        adj[1].erase(adj[1].begin());
        init(n);
        dijkstra(1);
        if (road[c.fi] == 0) {
            cout << -1;
            return;
        }
        res = min(res, (dist[c.fi] + c.se) / double(road[c.fi]));
        adj[1].emplace_back(c);
        // cout << cnt << " "; 
    }
    if (res == 8000000000) {
        cout << -1;
        return;
    }
    cout << (fixed) << setprecision(2) << res;
}
