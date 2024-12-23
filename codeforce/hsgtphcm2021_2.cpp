#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


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

void solve()
{
    int n, p, a, b, r;

    cin >> n >> p >> a >> b >> r;

    int n1 = (n + a) % p, n2 = (n + b) % p, n3 = (n + a + b) % p;

    vector<int> exst(p + 3);
    vector<vector<int>> adj(p + 3);
    queue<int> q;

    // dbg(adj);

    q.push(n1);
    q.push(n2);
    q.push(n3);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (exst[u]) continue;
        exst[u] = true;
        adj[u].pb((u + a) % p);
        adj[u].pb((u + b) % p);
        adj[u].pb((u + a + b) % p);
        q.push((u + a) % p);
        q.push((u + b) % p);
        q.push((u + a + b) % p);
    }

    // dbg(adj);

    n = p + 1;
    vector<int> dist(p + 3, -1);
    dist[n] = 0;
    q.push(n);
    adj[n].pb(n1);
    adj[n].pb(n2);
    adj[n].pb(n3);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &v : adj[u]) {
            if (dist[v] > dist[u] + 1 || dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    // dbg(dist);
    cout << dist[r] << endl;
}
