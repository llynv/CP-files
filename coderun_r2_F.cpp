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

int vst[N];
vector<int> adj[N];
set<int> ves;

// void getAllPairShortestDist(int n, vector<vector<int>> &dist, vector<vector<int>> &graph){
//     //floydd warshall:
//     for(int k=0;k<n;k++){
//         for(int source=0;source<n;source++){
//             for(int dest=0;dest<n;dest++){
//                 if(source == dest) continue;
//                 if(dist[source][k] != INT_MAX and dist[k][dest] != INT_MAX){
//                     if(dist[source][dest] > dist[source][k] + dist[k][dest])
//                         dist[source][dest] = dist[source][k] + dist[k][dest];
//                 }
//             }
//         }
//     }
// }

// vector<vector<int>> dp;
// int visitAll(int source, int n, int mask, vector<vector<int>> &dist){
//     if(dp[source][mask] != -1) return dp[source][mask];

//     bool allVisited = true;
//     int minDist = INT_MAX;

//     for(int nbr=0;nbr<n;nbr++){
//         if((mask & (1<<nbr))) continue;
//         allVisited = false;
//         int cur = visitAll(nbr, n, mask + (1<<nbr), dist);
//         if(cur != INT_MAX) minDist = min(minDist, dist[source][nbr] + cur);
//     }

//     // seen[source] = false;
//     if(allVisited) return dp[source][mask] = 0;
//     else return dp[source][mask] = minDist;
// }

// int shortestPathLength(vector<vector<int>>& graph) {
//     int n = graph.size();
//     vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
//     for(int i=0;i<n;i++) {
//         dist[i][i] = 0;
//         for(auto nbr: graph[i]) dist[i][nbr] = 1;
//     }

//     //shortest dist to all pairs:
//     getAllPairShortestDist(n, dist, graph);

//     //shortest path visiting all nodes:
//     int result = INT_MAX, MASK = (1<<(n+1));
//     dp = vector<vector<int>> (n+1, vector<int> (MASK+1, -1));
//     for(int source=0;source<n;source++){
//         result = min(result, visitAll(source, n, 0, dist));
//     }

//     return result;
// }

vector<int> ShortestPathVisitedAllNodes(int source, int n, vector<vector<int>> &cost)
{
    vector<int> dist(n, INF);
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                q.push(v);
            }
        }
    }
    return dist;
}

// void dfs(int u)
// {
//     tmp.emplace_back(u);
//     dbg(tmp, u);
//     if (sz(adj[u]) > 1) {
//         path.emplace_back(tmp);
//         return;
//     }
//     vst[u] = 1;
//     for (auto v : adj[u]) {
//         if (!vst[v]) {
//             dfs(v);
//         }
//     }
//     vst[u] = 2;
// }

// void init(int n)
// {
//     path.clear();
//     for (int i = 1; i <= n; ++i) {
//         vst[i] = 0;

//     }
// }

void solve()
{
    int n;
    cin >> n;
    int minA = INF;
    vector<vector<int>> cost(n+1);
    for (auto &c : cost) c.resize(n+1, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u][v] = w;
    }
    vector<int> res = ShortestPathVisitedAllNodes(1, n+1, cost);
    dbg(res);
}
