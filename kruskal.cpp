#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

const int N = 1e5 + 7;
int root[N];

int FindRoot(int u)
{
    if (u == root[u]) {
        return u;
    }
    return root[u] = FindRoot(root[u]);
}

void UnionSet(int u, int v)
{
    int rootu = FindRoot(u);
    int rootv = FindRoot(v);
    if (rootu != rootv) {
        root[rootu] = rootv;
    }
}

struct krus
{
    int w, u, v;
};

bool cmp (krus a, krus b) {
    return a.w <= b.w;
}

void solve()
{   
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i) root[i] = i;
    
    vector<krus> a(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {w, u, v};
    }
    sort(a.begin(), a.end(), cmp);
    int res = 0;
    for (auto c : a) {
        if (FindRoot(c.u) != FindRoot(c.v)) {
            res += c.w;
            cout << c.u << " " << c.v << "\n";
            UnionSet(c.u, c.v);
        }
    }
    cout << res;
}
