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
const int M = 2e5 + 7;

vector<int> adj[M];
int vst[M], par[M];
vector<vector<int>> res;
unordered_set<int> center;
bool isOk = false, isFlower = true;
int cnt = 0, k;

void dfs_circle(int n, int father)
{

    if (vst[n] == -1) return;

    if (vst[n] == 1) {
        if (isFlower) {
            int v = father;
            unordered_set<int> tmp;
            tmp.insert(father);
            while (v != n) {
                v = par[v];
                tmp.insert(v);
            }
            if (tmp == center) {
                isOk = true;
            }
            if (tmp.size() != k) {
                isFlower = false;  
            }
            cnt++;
        }
        return;
    }

    par[n] = father;
    vst[n] = 1;

    for (auto c : adj[n]) {
        if (c == par[n]) continue;

        dfs_circle(c, n);
    }

    vst[n] = -1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    k = m - n;
    for (int i = 0; i <= n; ++i) {
        vst[i] = 0;
        par[i] = 0;
        adj[i].clear();
    }
    cnt = 0;
    isOk = false;
    isFlower = true;    

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    center.clear();
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 4) {
            center.insert(i);
        }
    }

    if (k*k != n || k*(k+1) != m) {
        cout << "NO\n";
        return;
    }

    dfs_circle(1, -1);
    // dbg(res);

    if (cnt != k + 1) {
        cout << "NO\n";
        return;
    }

    if (isOk && isFlower) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
