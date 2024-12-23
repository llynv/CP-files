
/*
  Code by: linvg
  Created: 15.08.2024 22:28:31
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e8;

map<string, vector<string>> validMove;
vector<string> f = {"BG", "BR", "BY", "GR", "GY", "RY"};

map<pair<string, string>, vector<vector<string>>> road;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    for (auto& c : a) cin >> c;
    unordered_map<char, int> mp;
    mp['B'] = 1;
    mp['G'] = 2;
    mp['R'] = 3;
    mp['Y'] = 4;
    unordered_map <string, vector<int>> pos; 
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }

    auto cmp = [&](string x, string y) {
        return x[0] == y[0] || x[1] == y[1] || x[0] == y[1] || x[1] == y[0];
    };

    auto cmp2 = [&] (pair<array<int, 3>, string> x, pair<array<int, 3>, string> y) {
        return (x.first[1] > y.first[1]);
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        if (u > v) swap(u, v);
        
        if (a[u][0] == a[v][0] || a[u][1] == a[v][1] || a[u][0] == a[v][1] || a[u][1] == a[v][0]) {
            cout << max(u, v) - min(u, v) << '\n';
            continue;
        }
        dbg(u, v, a[u], a[v]);
        int res = INF;
        
        for (auto move: road[{a[u], a[v]}]) {
            if (move.size() != 3) continue;
            string bridge = move[1];
            int p = lower_bound(all(pos[bridge]), u) - pos[bridge].begin();
            int q = p - 1;
            dbg(bridge, p, q);
            if (p < pos[bridge].size()) {
                res = min(res, abs(v - pos[bridge][p]) + abs(u - pos[bridge][p]));
            }
            if (q >= 0) {
                res = min(res, abs(v - pos[bridge][q]) + abs(u - pos[bridge][q]));
            }
        }

        cout << (res == INF ? -1 : res) << '\n';
    }
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


    for (int i = 0; i < f.size(); ++i) {
        for (int j = 0; j < f.size(); ++j) {
            if (i == j) continue;
            vector<string> tmp;
            bool ok = false;
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    if (f[i][k] == f[j][l]) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) validMove[f[i]].push_back(f[j]);
        }
    }

    // BG, BR, BY, GR, GY, or RY
    
    auto cmp = [&](string x, string y) {
        return x[0] == y[0] || x[1] == y[1] || x[0] == y[1] || x[1] == y[0];
    };

    unordered_map<string, bool> vis;
    auto dfs = [&] (string u, vector<string> path, auto&& dfs) -> void {
        vis[u] = true;
        if (path.size() > 1) {
            road[{path[0], u}].push_back(path);
        }
        for (auto& v : validMove[u]) {
            if (vis[v]) continue;
            bool isOk = (cmp(u, v));
            for (int i = 0; i < path.size() - 1; ++i) {
                isOk &= !cmp(path[i], v);
            }
            if (isOk) {
                path.push_back(v);
                dfs(v, path, dfs);
                path.pop_back();
            }
        }
        vis[u] = false;
    };
    for (auto& c : f) {
        vis.clear();
        dfs(c, {c}, dfs);
    }

    // for (auto& [k, v] : road) {
    //     cerr << k.first << " -> " << k.second << '\n';
    //     for (auto& c : v) {
    //         for (auto& d : c) cerr << d << " ";
    //         cerr << '\n';
    //     }
    // }
    // dbg();
    for (auto& [k, v] : validMove) {
        dbg(k, v);
        // for (auto& c : v) cerr << c << " ";
        // cerr << '\n';
    }

   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}