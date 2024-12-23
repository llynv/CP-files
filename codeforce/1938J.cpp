#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
using namespace std;

void solve()
{

    // Read input
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n + 1, vector<pii>());
    fu(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra from 1 to n
    vector<int> d1(n + 1, LONG_LONG_MAX);
    vector<int> pre(n + 1, -1);

    d1[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > d1[u])
            continue;
        for (auto road : adj[u])
        {
            int v = road.ff;
            int w = road.ss;
            if (d1[v] > d1[u] + w)
            {
                d1[v] = d1[u] + w;
                pre[v] = u;
                pq.push({d1[v], v});
            }
        }
    }
    if (d1[n] == LONG_LONG_MAX)
    {
        cout << -1;
        return;
    }

    // Dijkstra from n to 1
    vector<int> dn(n + 1, LONG_LONG_MAX);
    while (!pq.empty())
        pq.pop();
    dn[n] = 0;
    pq.push({0, n});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dn[u])
            continue;
        for (auto road : adj[u])
        {
            int v = road.ff;
            int w = road.ss;
            if (dn[v] > dn[u] + w)
            {
                dn[v] = dn[u] + w;
                pq.push({dn[v], v});
            }
        }
    }

    // Find the shortest path from 1 to n
    vector<int> path;
    int last = n;
    while (pre[last] != -1)
    {
        path.push_back(last);
        last = pre[last];
    }
    path.push_back(1);

    vector<bool> inPath(n + 1, false);
    for (int u : path)
    {
        inPath[u] = true;
    }

    // Find the answer
    int bonus = LONG_LONG_MAX;
    int ans2 = LONG_LONG_MAX;
    for( int i = 0 ; i < path.size() ; i ++ )
    {
        int x = path[i];
//        cout<<x<<" ";
        for( auto v : adj[x])
        {
            if(inPath[v.first]) continue;
            bonus = min(bonus,v.second);
            ans2 = min({ans2,d1[x] + dn[v.first] + v.second,dn[x] + d1[v.first] + v.second});
        }
    }
    if(bonus == LONG_LONG_MAX && ans2 == LONG_LONG_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<d1[n] + min(ans2,d1[n]+bonus*2);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}
