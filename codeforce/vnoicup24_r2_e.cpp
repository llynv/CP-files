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

struct DSU {
vector<int> e;
   int mx = 0;
   int comp = 0;
   DSU(int N){ e = vector<int>(N, -1);}
   int get(int x){
       if(e[x] < 0) return x;
       return e[x] = get(e[x]);
   }
   int size(int x){return -e[get(x)];}
   bool unite(int a, int b){
       a = get(a); b = get(b);
       if (a == b) return false;
       if (e[a] > e[b]) swap(a, b);
       e[a] += e[b]; e[b] = a;
       mx = max(mx, -e[a]);
       comp++;
       return true;
   }
};

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }

    friend ostream &operator<<(ostream &os, const Edge &e)
    {
        os << e.u << ' ' << e.v << ' ' << e.w;
        return os;
    }
};


void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Edge>> edges(k);
    vector<pair<int, Edge>> all_edges;
    rep(i, 0, m)
    {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        edges[c-1].push_back(Edge(u, v, w));
        all_edges.push_back({c-1, Edge(u, v, w)});
    }

    vector<int> s(k);
    rep(i, 0, k) cin >> s[i];

    for (auto &e : edges)
    {
        sort(all(e));
        dbg(e);
    }

    vector<int> ans(k);
    vector<int> idx(k);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) { return s[i] < s[j]; });

    for (int i = 0; i < k; ++i)
    {
        DSU dsu(n + 1); 
        for (auto &e : edges[idx[i]])
        {
            if (dsu.unite(e.u, e.v)) {
                ans[idx[i]] += e.w;
            } 
        }
        dbg(dsu.comp, n - 1, ans[idx[i]]);
        if (dsu.comp != n - 1) ans[idx[i]] = INF;
    }



    dbg(ans);
    int res = INF;
    for (int i = 0; i < k; ++i)
    {
        res = min(res, ans[i] * 2 - max(0ll, ans[i] - s[i]));
    }

    DSU dsu2(n + 1);
    ans.clear();
    for (auto [id, e] : all_edges)
    {
        if (dsu2.unite(e.u, e.v)) {
            ans[id] += e.w;
        }
    }

    int res2 = 0;
    for (int i = 0; i < k; ++i)
    {
        res2 += ans[i] * 2 - max(0ll, ans[i] - s[i]);
    }


    cout << min(res, res2) << '\n';
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