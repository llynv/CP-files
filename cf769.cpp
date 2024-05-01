#include <bits/stdc++.h>
using namespace std;

#define LINVG
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
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
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

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 3011;

vector<int> adj[N], adj2[N];
int dist[N][N], vst[N];
struct Mark
{
    int mxDist, edges;

    Clear() {
        mxDist = 0;
        edges = 0;
    }
};

Mark mx[N];

void dfs(int n)
{
    vst[n] = 1;
    for (auto c : adj[n]) {
        if (vst[c]) continue;
        dfs(c);
        adj2[n].pb(c);
    }
}

void solve()
{
    int n;
    cin >> n;
    rep (i, 1, n+1) {
        adj[i].clear();
        mx[i].Clear();
        vst[i] = 0;
    }
    rep (i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    rep (i, 1, n+1) {
        rep (j, 1, n+1) {
            dist[i][j] = -1; 
        }
    }
    rep (i, 1, n+1) {
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto c : adj2[cur]) {
                if (dist[i][c] == -1 || dist[i][c] > dist[i][cur] + 1) {
                    dist[i][c] = dist[i][cur] + 1;
                    if (mx[i].mxDist < dist[i][c]) {
                        mx[i].mxDist = dist[i][c];
                        mx[i].edges = c;
                    }
                    q.push(c);
                }
            }
        }
        
    }
    // for (auto c : mx) dbg(c);
    // dbg("end");
    rep (i, 1, n+1) {
        if (i >= mx[1].mxDist) {
            cout << mx[1].mxDist << " ";
            dbg(mx[1].mxDist, 1);
            continue;
        }
        int target = INF;
        rep (j, 1, n+1) {
            target = min(target, i + mx[j].mxDist);
        }
        int cnt = 0, dmax = 0;
        rep (j, 1, n+1) {
            if (target == i + mx[j].mxDist) {
                cnt++;
                dmax = max(dmax, target);
                continue;
            }
            dmax = max(dmax, dist[1][j]);
        }
        if (cnt == 1) {
            cout << dmax << " ";
            dbg(dmax, 2);
            continue;
        }
        cout << mx[1].mxDist << " ";
        dbg(mx[1].mxDist, 3);
    }
    cout << "\n";
}