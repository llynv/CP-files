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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;


vector<int> adj[1011];
bool edge[1011][1011];

int med = 0, type = 0;

void Create(int n, int k) {
    if (k == 1) {
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            for (int j = 1; j <= n; ++j) {
                adj[i].push_back(j);
                edge[i][j] = 1;
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                edge[i][j] = 0;
            }
        }
    }
}


void ADD(int u, int v) {
    if (!edge[u][v]) {
        edge[u][v] = 1;
        adj[u].push_back(v);    
    }
}

void DEL(int u, int v) {
    if (edge[u][v]) {
        edge[u][v] = 0;
    }
}

ii ANY () {
    for (int i = 1; i <= med; ++i) {
        for (auto c : adj[i]) {
            if (edge[i][c]) {
                edge[i][c] = 0;
                return {i, c};
            }
        }
    }
    return {-1, -1};
}

bool EDG (int u, int v) {
    return edge[u][v];
}

void solve()
{
    string s;
    cin >> s;
    while (s != "END") {
        int n, k;
        if (s == "NEW") {           
            cin >> n >> k;
            med = n;
            type = k;
            Create(n, k);
        } else if (s == "ADD") {
            cin >> n >> k;
            ADD(n, k);
        } else if (s == "DEL") {
            cin >> n >> k;
            DEL(n, k);
        } else if (s == "ANY") {
            ii cur = ANY();
            if (cur != ii{-1, -1}) {
                cout << cur.fi << " " << cur.se << "\n";
            }
        } else {
            cin >> n >> k;
            cout << (EDG(n, k) ? "YES\n" : "NO\n");
        }
        cin >> s;
    }
}
