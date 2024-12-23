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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
const int N = 10011;

vector<int> adj[N];
int numb[N], low[N], bridges, joints, vs[N], vertexOrder, check[N];

void dfs(int u, int father)
{
    vertexOrder++;
    vs[u] = true;
    numb[u] = vertexOrder;
    low[u] = vertexOrder;
    int numbChild = 0;
    for (auto v : adj[u]) {
        if (v == father) continue;

        if (vs[v]) {
            low[u] = min(low[u], numb[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            numbChild++;
            // cout << u << " " << v << " " << father << " " << numbChild << "\n";
            bridges += (numb[v] == low[v]);
            // if (numb[v] == low[v]) cout << v << "\n";
            dbg(u, v, father, numbChild);
        }
    }
    if (numb[u] == low[u] && numbChild > 1) {
        check[u] = true;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vs[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= n; ++i) {
        // joints += (check[i]);

        if (check[i]) cout << i << "\n";
        // cout << i << " {" << numb[i] << ", " << low[i] << "}\n"; 
    }

    cout << bridges;
}