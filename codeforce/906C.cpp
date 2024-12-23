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
const int N = 25;

vector<int> adj[N];
int n, m;
int pmask[N], vst[N];

void dfs (int u, int mask, int path, int &res) {
    if (__builtin_popcount(mask) == n) {
        if (__builtin_popcount(res) > __builtin_popcount(path)) {
            res = path;
            return;
        }
    }

    vst[u] = 1;
    for (auto v : adj[u]) {
        if (vst[v] != 2 && (mask ^ pmask[v]) != 0 && (path & (1LL << (v-1))) == 0) {
            dfs(v, mask | pmask[v], path | (1LL << (v-1)), res);
        }
    }
    vst[u] = 2;
}

void solve()
{
    cin >> n >> m;

    rep (i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n * (n - 1) / 2 == m) return void (cout << "0\n");

    rep (i, 1, n+1) {
        pmask[i] = 1LL << (i-1);
        for (auto v : adj[i]) {
            pmask[i] |= 1LL << (v-1);
        }
    }

    // int res = (1ll << 60) - 1;

    // for (int i = 1; i <= n; ++i) dfs(i, pmask[i], (1ll << (i-1)), res);

    // cout << __builtin_popcount(res) << '\n';
    // for (int i = 0; i < n; ++i) {
    //     if (res >> i & 1) {
    //         cout << i+1 << ' ';
    //     }
    // }

    vector<tuple<int, int, int>> edges;
    vector<int> ver (1 << n, -1), best (1 << n, INF), path(1 << n, -1);
    for (int i = 1; i <= n; ++i) {
        edges.pb({pmask[i], i, 1});
        best[pmask[i]] = 1;
        ver [pmask[i]] = i;
        path[pmask[i]] = 0;
    }

    while (!edges.empty()) {
        auto c = edges.back();

        int mask, u, d;
        tie(mask, u, d) = c;
        edges.pop_back();
        if (best[mask] < d) continue;
        for (int i = 1; i <= n; ++i) {
            if (!(mask >> (i-1) & 1)) continue;
            if (i == u) continue;
            int nmask = mask | pmask[i];
            if (best[nmask] > d + 1) {
                best[nmask] = d + 1;
                ver[nmask] = i;
                path[nmask] = mask;
                edges.push_back({nmask, i, d+1});
            }
        }
    }

    int mask = (1 << n) - 1;
    vector<int> ans;
    cout << best[mask] << '\n';
    while (mask) {
        cout << ver[mask] << ' ';
        mask = path[mask];
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