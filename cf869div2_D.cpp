#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

bool isCircle = false;
int vst[2011], par[2011];
vector<int> adj[2011];

void dfs_cycle(int u, int p, int color[], int par[], vector<vector<int>> &cycles)
{
    if (color[u] == 2) {
        return;
    }
 
    if (color[u] == 1) {
        vector<int> v;
           
        int cur = p;
        v.push_back(cur);

        while (cur != u) {
            cur = par[cur];
            v.push_back(cur);
        }
        cycles.push_back(v);
        return;
    }
    par[u] = p;
 
    color[u] = 1;
 
    for (int v : adj[u]) {
 
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cycles);
    }
 
    color[u] = 2;
}

void preset()
{
    memset(vst, 0, sizeof(vst));
    memset(adj, 0, sizeof(adj));
    memset(par, 0, sizeof(par));
    // for (auto &c : adj) c.clear();
}

void solve()
{
    preset();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    // for (auto c : vertexs)

    for (int vertex = 1; vertex <= n; ++vertex) {

        if (adj[vertex].size() >= 4) {

            vector<vector<int>> s;

            memset(vst, 0, sizeof(vst));
            memset(par, 0, sizeof(par));

            dfs_cycle(vertex, -1, vst, par, s);

            if (s.size() > 0) {
                
                vector<int> res;
                set<int> verx;

                for (auto c : s) {

                    set<int> tmp;
                    for (auto v : adj[vertex]) tmp.insert(v);

                    for (auto v : c) {
                        if (tmp.find(v) != tmp.end())
                            tmp.erase(v);
                    }

                    if (tmp.size() >= 2 && find(c.begin(), c.end(), vertex) != c.end()) {
                        res = c;
                        verx = tmp;
                        break;
                    }
                }

                if (!res.empty()) {
                    
                    res.emplace_back(res[0]);

                    cout << "YES\n" << res.size() + 1 << "\n";
                    cout << *verx.begin() << " " << vertex << "\n" << *prev(verx.end()) << " " << vertex << "\n";

                    for (int i = 0; i < res.size()-1; ++i) {
                        cout << res[i] << " " << res[i+1] << "\n";
                    }

                    return;
                }
            }
        }
    }

    cout << "NO\n";
}
