/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&] (int u, int p, ii &mx, auto&& dfs, int depth = 1) -> void {  
        mx = max(mx, { depth, u });
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, mx, dfs, depth+1);
        }
    };

    vector<vector<int>> childs (2, vector<int>(n+1, 0));

    auto dfs2 = [&] (int u, int p, int id, auto&& dfs2) -> void {
        childs[id][u] = 1;
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs2(v, u, id, dfs2);
            childs[id][u] += childs[id][v];
        }
    };

    vector<int> st;
    ii mx = { 0, 0 };
    dfs(1, 1, mx, dfs);
    st.push_back(mx.se);
    int farthest = mx.se;
    mx = { 0, 0 };
    dfs(farthest, farthest, mx, dfs);
    st.push_back(mx.se);

    vector<vector<int>> dist(2, vector<int> (n+1, INF));
    vector<unordered_map<int, vector<int>>> vers(2);

    int maxDist = 0;

    auto bfs = [&] (int u, int id) -> void {
        queue<int> q;
        q.push(u);
        dist[id][u] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                if (dist[id][v] == INF) {
                    dist[id][v] = dist[id][u] + 1;
                    maxDist = max(maxDist, dist[id][v]);
                    vers[id][dist[id][v]].push_back(v);
                    q.push(v);
                }
            }
        }
    };

    unordered_map<int, int> tmp, app;
    auto dfs_path = [&] (int u, int p, auto&&dfs_path) -> void {
        if (u == st[1]) {
            for (auto [k, v] : tmp) {
                if (v) app[k] = 1;
            }
            return;
        }
        for (auto v : adj[u]) {
            if (v == p) continue;
            tmp[v] = 1;
            dfs_path(v, u, dfs_path);
            tmp[v] = 0;
        }
    };

    dfs_path(st[0], st[0], dfs_path);

    bfs(st[0], 0);
    bfs(st[1], 1);

    vector<int> ans(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        dbg(i, maxDist / 2);
        if (i <= (maxDist + 1) / 2) {
            ans[i] = 1;
            continue;
        }
        if (i > maxDist) {
            ans[i] = n;
            continue;
        }
        int sum = 0, cnt = 0;

        vector<ii> tmp;
        unordered_map<int, int> road;
        for (int id = 0; id < 2; ++id) {
            for (auto x : vers[id][i]) {
                dbg(x, childs[id][x]);
                if (app[x]) {
                    road[x] = 1;
                    sum += childs[id][x];
                } else {
                    if (dist[id][x] > dist[id^1][x]) {
                        sum += childs[id][x];
                    }
                }
            }
        }
        for (auto x : vers[0][i]) if (dist[0][x] == dist[1][x]) sum += childs[0][x];

        ans[i] = n - sum + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}