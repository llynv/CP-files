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

vector<int> adj[100111];

int bfs(int u, int v)
{
    int dist[100111];
    memset(dist, -1, sizeof(dist));
    queue<int> Q;
    Q.push(u);
    dist[u] = 0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (auto c : adj[cur]) {
            if (dist[c] == -1) {
                dist[c] = dist[cur] + 1;
                Q.push(c);
            }
        }
    }
    return dist[v];
}

void solve()
{
    int u, v;
    cin >> u >> v;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> st;
    st.emplace_back(u);
    bool isOut = false;
    while (true) {
        int sz = st.size();
        for (int i = 0; i < sz; ++i) {
            for (auto ii : a) {
                adj[st[0]].emplace_back((ii*st[0])%100000);
                st.emplace_back((ii*st[0])%100000);
                if ((ii*st[0])%100000 >= v) {
                    isOut = true;
                }
            }
            st.erase(st.begin());
        }
        if (isOut) break;
    }
    // for (auto c : st) cout << c << " ";
    int res = INF;
    for (auto c : a) {
        res = min(res, bfs(u, v));
    }
    cout << res;
}
