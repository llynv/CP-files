/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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

const int INF = 2e9;
const int MOD = 1e8;
const int N = 511;

vector<ii> adj[N];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({ v, w });
    }
    vector<vector<vector<ii>>> dist(n + 1, vector<vector<ii>>(n + 1));
    vector<vector<int>> store(n + 1);
    for (int i = 1; i <= n; ++i) {
        store[i].pb(i);
        dist[i][i].push_back({ 1, 0 });
    }
    vector<vector<int>> n_dist(n + 1, vector<int>(n + 1, -1));
    for (int i = 2; i <= n; ++i) {
        n_dist.assign(n + 1, vector<int>(n + 1, -1));
        for (int j = 1; j <= n; ++j) {
            vector<int> tmp;
            while (!store[j].empty()) {
                auto v = store[j].back();
                store[j].pop_back();
                for (auto [u, w] : adj[v]) {
                    if (dist[j][v].back().fi != i - 1) continue;
                    if (!dist[j][u].empty() && dist[j][u].back().se <= dist[j][v].back().se + w) continue;
                    if (n_dist[j][u] == -1) {
                        n_dist[j][u] = dist[j][v].back().se + w;
                        tmp.push_back(u);
                    } else {
                        n_dist[j][u] = min(n_dist[j][u], dist[j][v].back().se + w);
                    }
                }
            }
            store[j] = tmp;
        }
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (n_dist[j][k] != -1) {
                    dist[j][k].push_back({ i, n_dist[j][k] });
                }
            }
        }
    }

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        int ans = INF;
        for (auto [i, d] : dist[u][v]) {
            ans = min(ans, d + w * i);
        }
        cout << (ans == INF ? -1 : ans) << '\n';
    }
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