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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, int> color;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i - 1];
        color[i] = a[i - 1];
    }
    vector<vector<int>> adj(n + 1);
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);   
    } 

    vector<int> adjNum(4, 0);

    unordered_map<int, int> ver_cnt, par;

    auto dfs = [&] (int u, int p, auto&& dfs) -> void {
        for (auto v : adj[u]) {
            if (v == p) continue;
            par[v] = u;
            dfs(v, u, dfs);
        }
    };
    
    dfs(1, 0, dfs);

    dbg(par);
    auto idx = [&](int x) -> int {
        return x > 3 ? 0 : x;
    };

    for (int i = 1; i <= n; ++i) {
        if (color[i]) {
            ver_cnt[i]++;
            ver_cnt[par[i]]++;
        }
    }

    set<int> threeNumNodes;

    for (int i = 1; i <= n; ++i) {
        if (color[i]) {
            dbg(i, ver_cnt[i]);
            if (ver_cnt[i] == 3) threeNumNodes.insert(i);
            adjNum[idx(ver_cnt[i])]++;
        }
    }

    dbg(adjNum);

    while (q--) {
        int x;
        cin >> x;
        color[x] ^= 1;
        dbg(adj[x], x);
        if (color[x]) {
            ver_cnt[x]++;
            if (ver_cnt[x] == 3) {
                threeNumNodes.insert(x);
            } else {
                if (threeNumNodes.count(x)) {
                    threeNumNodes.erase(x);
                }
            }
            adjNum[idx(ver_cnt[x])]++;
            ver_cnt[par[x]]++;
            if (color[par[x]]) {
                adjNum[idx(ver_cnt[par[x]] - 1)]--;
                adjNum[idx(ver_cnt[par[x]])]++;
                if (ver_cnt[par[x]] == 3) {
                    threeNumNodes.insert(par[x]);
                } else {
                    if (threeNumNodes.count(par[x])) {
                        threeNumNodes.erase(par[x]);
                    }
                }
            }
        }
        else {
            adjNum[idx(ver_cnt[x])]--;
            if (ver_cnt[x] == 3) {
                if (threeNumNodes.count(x)) {
                    threeNumNodes.erase(x);
                }
            }
            ver_cnt[x]--;
            if (color[par[x]]) {
                adjNum[idx(ver_cnt[par[x]])]--;
                adjNum[idx(ver_cnt[par[x]] - 1)]++;
                if (ver_cnt[par[x]] == 4) {
                    threeNumNodes.insert(par[x]);
                } else {
                    if (threeNumNodes.count(par[x])) {
                        threeNumNodes.erase(par[x]);
                    }
                }
            }
            ver_cnt[par[x]]--;
        }

        dbg(adjNum);
        if (adjNum.front() > 0) {
            cout << "No\n";
            continue;
        } 
        if (sz(threeNumNodes)) {
            if (adjNum[1] == 2 && sz(threeNumNodes) == 1) {
                if (color[par[*threeNumNodes.begin()]] == 0) {
                    cout << "Yes\n";
                }
                else { 
                    cout << "No\n";
                }
            } else {
                cout << "No\n";
            }
            continue;
        }
        if (adjNum[1] == 1 && threeNumNodes.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
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