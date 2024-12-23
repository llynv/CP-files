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

const int INF = 1e15+7;

vector< pair<int, int> > adj[100005];
int V, E;
priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int dist[100005], road[100005], par[100005];

void dijktra(int start)
{
    pq.push(make_pair(0, start));
    dist[1] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        for (auto c : adj[cur.se]) {
            int v = c.fi;
            int w = c.se;
            if (dist[v] > dist[cur.se] + w) {
                road[v] = cur.se;
                dist[v] = dist[cur.se] + w;
                pq.push(make_pair(dist[v], v));
            } 
        }
    }
}

void solve()
{
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(make_pair(v, w));
        adj[v].emplace_back(make_pair(u, w));
    }
    for (int i = 0; i <= V; ++i) dist[i] = INF;
    dijktra(1);
    if (dist[V] == INF) {
        cout << -1;
        return;
    }
    int v = V;
    vector<int> res;
    res.pb(V);
    while (road[v] != 0) {
        res.pb(road[v]);
        v = road[v];

    }
    for (int i = res.size()-1; i >= 0; --i) cout << res[i] << " ";
}
