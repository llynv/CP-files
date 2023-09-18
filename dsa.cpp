#include <bits/stdc++.h>
using namespace std;

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

map <string, int> mp;
map <string, vector<pair<string, int>> > adj;
map <string, int> dist;

void dijkstra(string start)
{
    priority_queue< pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>> > pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        pair<int, string> top = pq.top();
        pq.pop();
        cout << top << "\n";
        string u = top.second;
        int w = top.first;
        for (auto neighbor : adj[u]) {
            string v = neighbor.first;
            int w = neighbor.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pair<int, string> p = pair<int, string>(dist[v], v);
                pq.push(p);
            }
        }
    }
}

void solve()
{
    int m;
    cin >> m;
    set<string> s;
    for (int i = 0; i < m; ++i) {
        string a, b;
        int w;
        cin >> a >> b >> w;
        mp[a + " " + b] = w;
        s.insert(a);
        s.insert(b);
        pair<string, int> p = pair<string, int>(b, w);
        adj[a].push_back(p);
        p = pair<string, int>(a, w);
        adj[b].push_back(p);
    }
    for (auto c : s) {
        dist[c] = INF;
    }
    dijkstra("VN");
    for (auto c : s) {
        dbg(c, adj[c]);
        cout << "VN -> " << c << " : " << dist[c] << "\n";
    }
}
