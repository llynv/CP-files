#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
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
const int N = 2e5 + 7;

vector<int> adj[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    a.pb(0);
    rep (i, 1, n+1) {
        int x;
        cin >> x;
        a.pb(x);
    }
    rep (i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    auto bfs = [&] (int start, int end, int val) {
        if (a[start] > val) return -1LL;

        vector<int> dist(n+1, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : adj[u]) {
                if (dist[v] == -1 && a[v] <= val) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        // dbg(dist);
        return dist[end];
    };

    int lo = 0, hi = n, minLeft = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        if (bfs(1, n, mid) != -1) {
            minLeft = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (minLeft == -1) return cout << -1, void();

    int l = minLeft, r = n;
    while (l < r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
    
        int sum1 = bfs(1, n, m1);
        int sum2 = bfs(1, n, m2);

        if (abs(sum1 - m1) > abs(sum2 - m2)) {
            l = m1 + 1;
        } else {
            r = m2 - 1;
        }
    }
    // dbg(l, r);
    int sum = bfs(1, n, l);
    // dbg(sum);
    cout << abs(sum - l) << "\n";
}
