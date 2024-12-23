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
const int N = 37;

int Case = 1;;
string ff = "Case #", ss = ": ";

vector<char> adj[277];
queue<char> topo;
bool state[277];

void preset()
{
    while (!topo.empty()) {
        topo.front();
    }
    for (int i = 'A'; i <= 'Z'; ++i){
        state[i] = 0;
        adj[i].clear();
    }
}

void dfs(char u)
{
    state[u] = true;
    for (auto v : adj[u]) {
        if (!state[v]) {
            dfs(v);
        }
    }
    topo.push(u);
}

bool appear(vector<char> a, char c)
{
    for (auto ii : a) if (ii == c) return false;
    return true;
}

void solve()
{
    preset();
    string res = "";

    char a[N][N];
    int n, m;
    cin >> n >> m;
    set<char> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            // cout << a[i][j] << " ";
            s.insert(a[i][j]);
        }
    }
    // cout << "\n";

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            bool ischeck = !(a[i][j] != a[i+1][j]);
            char cur = a[i][j];
            for (int k = i+1; k <= n; ++k) {
                if (a[k][j] == cur && a[k-1][j] != cur) {
                    if (ischeck) ischeck = false;
                    else {
                        res = "-1\n";
                        cout << ff + to_string(Case++) + ss + res;
                        return;
                    }
                }
                if (appear(adj[cur], a[k][j]) && a[k][j] != cur)
                    adj[cur].emplace_back(a[k][j]);
            }
        }
    }

    for (auto c : s) {
        if (!state[c]) {
            dfs(c);
        }
        // cout << c << " ";
    }

    while (!topo.empty()) {
        res += topo.front();
        topo.pop();
    }

    res += "\n";
    cout << ff + to_string(Case++) + ss + res;
}
