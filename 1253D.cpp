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

struct DSU {
    vector<int> e, mxNode;
    int mx = 0;
    DSU(int N) { e = vector<int>(N, -1); mxNode = vector<int>(N, 0);}
    int get(int x) {
        if (e[x] < 0) {
            mxNode[x] = max(mxNode[x], x);
            return x;
        }
        return e[x] = get(e[x]);
    }
    int size(int x) { return -e[get(x)]; }
    int maxNode (int x) { 
        return mxNode[x];
    }
    bool unite(int a, int b) {
        a = get(a); b = get(b);
        mxNode[a] = max({a, b, mxNode[a], mxNode[b]});
        mxNode[b] = max({a, b, mxNode[a], mxNode[b]});
        // dbg(a, b, mxNode[a], mxNode[b]);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        mx = max(mx, -e[a]);
        return true;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    vector<int> top(n + 1);
    int mn = dsu.maxNode(dsu.get(1)), res = 0;
    for (int i = 1; i <= n; ++i) {
        mn = max(mn, dsu.maxNode(dsu.get(i)));
        // cout << i  << " " << dsu.maxNode(dsu.get(i)) << ' ' << mn << '\n';
        bool flag = dsu.unite(mn, i);
        if (flag) {
            res++;
        }
    }
    cout << res << '\n';
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