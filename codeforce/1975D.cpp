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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
    int a, b;
    cin >> a >> b;
    vector<vector<int>> adj(n+1);
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> vst(n+1), flag(n+1), ans(n+1);
    auto dfs = [&](int u, int p, auto&&dfs) {
        if (flag[u]) return;
        flag[u] = 1;
        int res = 0;
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, dfs);
            if (flag[v]) {
                ans[u] += ans[v] + 2;
                dbg(u, v, ans[u]);
            }
            flag[u] |= flag[v];
        }
    };

    int to_dist = 0, start_v = -1;
    unordered_map<int, int> mp;
    auto dfs_path = [&](int u, int p, int dist, auto&&dfs) {
        if (u == b) {
            to_dist = dist;
            for (int i = 0; i < dist / 2; ++i) {
                b = mp[b];
            }
            start_v = b;
            return;
        }
        for (auto v : adj[u]) {
            if (v == p) continue;
            mp[v] = u;
            dfs(v, u, dist + 1, dfs);
        }
    };
    dfs_path(a, -1, 1, dfs_path);

    a = start_v;
    dbg(a);
    dfs(a, -1, dfs);
    dbg(ans);

    vector<int> dist(n+1, INF);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    int mxd = 0;
    while (sz(q)) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            mxd = max(mxd, dist[v]);
            q.push(v);
        }
    }
    dbg(to_dist, mxd, ans[a]);

    cout << ans[a] + (to_dist - 1) / 2 - mxd + (to_dist % 2 == 0) << "\n";
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}