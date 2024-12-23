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
// #define LOCAL
#endif

const int INF = 1e9;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

const int dx8[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy8[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

struct DSU {
    vector<int> e;
    int mx = 0;
    DSU(int N) { e = vector<int>(N, -1); }
    int get(int x) {
        if (e[x] < 0) return x;
        return e[x] = get(e[x]);
    }
    int size(int x) { return -e[get(x)]; }
    bool unite(int a, int b) {
        a = get(a); b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        mx = max(mx, -e[a]);
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> root(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (root[i][j] != -1) continue;
            queue<pair<int, int>> q;
            q.push({ i, j });
            int index = a[i][j];
            root[i][j] = i * n + j;
            while (!q.empty()) {
                auto [u, v] = q.front();
                q.pop();
                for (int k = 0; k < 8; ++k) {
                    int x = u + dx8[k];
                    int y = v + dy8[k];
                    if (x < 0 || x >= n || y < 0 || y >= n) continue;
                    if (root[x][y] != -1) continue;
                    if (a[x][y] != index) continue;
                    root[x][y] = i * n + j;
                    q.push({ x, y });
                }
            }
        }
    }

    vector<pair<int, int>> top, right, bottom, left;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0) top.push_back({ i, j });
            if (j == n - 1) right.push_back({ i, j });
            if (i == n - 1) bottom.push_back({ i, j });
            if (j == 0) left.push_back({ i, j });
        }
    }

    sort(all(top), [&](auto& x, auto& y) {
        return a[x.fi][x.se] < a[y.fi][y.se];
    });
    sort(all(right), [&](auto& x, auto& y) {
        return a[x.fi][x.se] < a[y.fi][y.se];
    });
    sort(all(bottom), [&](auto& x, auto& y) {
        return a[x.fi][x.se] < a[y.fi][y.se];
    });
    sort(all(left), [&](auto& x, auto& y) {
        return a[x.fi][x.se] < a[y.fi][y.se];
    });

    int res = 1;
    for (int i = 1; i <= n * n; ++i) {
        res = i;
        bool ok = false;
        int p = lower_bound(all(top), i, [&](auto& x, auto& y) {
            return a[x.fi][x.se] < y;
        }) - top.begin();
        int q = lower_bound(all(right), i, [&](auto& x, auto& y) {
            return a[x.fi][x.se] < y;
        }) - right.begin();
        int r = lower_bound(all(bottom), i, [&](auto& x, auto& y) {
            return a[x.fi][x.se] < y;
        }) - bottom.begin();
        int s = lower_bound(all(left), i, [&](auto& x, auto& y) {
            return a[x.fi][x.se] < y;
        }) - left.begin();
        // top bot
        for (int j = p; j < n; ++j) {
            if (a[top[j].fi][top[j].se] != i) break;
            for (int k = r; k < n; ++k) {
                if (a[bottom[k].fi][bottom[k].se] != i) break;
                if (root[top[j].fi][top[j].se] == root[bottom[k].fi][bottom[k].se]) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) continue;
        // top left
        for (int j = p; j < n; ++j) {
            if (a[top[j].fi][top[j].se] != i) break;
            for (int k = s; k < n; ++k) {
                if (a[left[k].fi][left[k].se] != i) break;
                if (root[top[j].fi][top[j].se] == root[left[k].fi][left[k].se]) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) continue;
        // left right
        for (int j = s; j < n; ++j) {
            if (a[left[j].fi][left[j].se] != i) break;
            for (int k = q; k < n; ++k) {
                if (a[right[k].fi][right[k].se] != i) break;
                if (root[left[j].fi][left[j].se] == root[right[k].fi][right[k].se]) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) continue;
        // right bot
        for (int j = q; j < n; ++j) {
            if (a[right[j].fi][right[j].se] != i) break;
            for (int k = r; k < n; ++k) {
                if (a[bottom[k].fi][bottom[k].se] != i) break;
                if (root[right[j].fi][right[j].se] == root[bottom[k].fi][bottom[k].se]) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) continue;
        break;
    }
    cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
    freopen("template.inp", "r", stdin);
    freopen("template.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
