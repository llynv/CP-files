#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = a-1; i >= b; --i)
#define trav(a, x) for (auto &a : x)

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
const int N = 2e3 + 7;

vector<pair<int,int> > adj[N], rev_adj[N];
priority_queue< pair<int,int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
int dist[N], rev_dist[N], app[N], total[N][N];

void dijkstra(int start)
{
    pq.push(make_pair(0, start));
    total[start][start] = 0;
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        for (auto u : adj[c.se]) {
            if (total[start][u.fi] > total[start][c.se] + u.se) {
                total[start][u.fi] = total[start][c.se] + u.se;
                // road[u.fi] = c.se;
                pq.push(make_pair(total[start][u.fi], u.fi));
            }
        }
    }
}

void rev_dijkstra(int start)
{
    pq.push(make_pair(0, start));
    total[start][start] = 0;
    while (!pq.empty())
    {
        auto c = pq.top();
        pq.pop();
        for (auto u : rev_adj[c.se]) {
            if (total[start][u.fi] > total[start][c.se] + u.se) {
                total[start][u.fi] = total[start][c.se] + u.se;
                // road[u.fi] = c.se;
                pq.push(make_pair(total[start][u.fi], u.fi));
            }
        }
    }
}

struct Graph
{
    int u, v, t;
};

bool cmp (Graph a, Graph b)
{
    return a.t < b.t;
}


void solve()
{
    vector<Graph> stg;

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].emplace_back(make_pair(v, t));
        rev_adj[v].emplace_back(make_pair(u, t));
        // cost[u][v] = cost[v][u] = t;
        stg.emplace_back(Graph{u, v, t});
    } 

    sort(stg.begin(), stg.end(), cmp);

    fill(dist, INF);
    // fill(total, INF);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            total[i][j] = INF;
        }
    }

    dijkstra(1);

    for (int i = 2; i <= n; ++i) {
        rev_dijkstra(i);
        // cout << total[i][1] << " ";
    }
    // cout << "\n";

    while (q--) {
        int s, t;
        cin >> s >> t;
        // fill(rev_dist, INF);
        // rev_dijkstra(s);
        int res = total[1][s];

        for (int i = sz(stg) - 1; i >= 0; --i) {
            
        }

        cout << res << "\n";
    }
}
