#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

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

vector<int> adj[807];
int vst[807], valid[807];
bitset<811> bst[811];

void dfs(int n, vector<int> &s)
{
    vst[n] = 1;
    s.emplace_back(n);
    for (auto c : adj[n]) {
        if (!vst[c]) {
            dfs(c, s);
        }
    }
}

void init(int n)
{
    for (int i = 0; i <= n; ++i) {
        vst[i] = 0;
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
    }
    init(n);
    set<vector<int>> res;
    for (int j = 1; j <= n; ++j) {
        vector<int> tmp;
        for (int i = 1; i <= n; ++i) {  
            if (!valid[i]) {
                init(n);
                vector<int> s;
                dfs(i, s);
                // sort(s.begin(), s.end());
                if (tmp.size() < s.size()) tmp = s;
            }
        }
        if (!tmp.empty()) {
            sort(tmp.begin(), tmp.end());
            res.insert(tmp);  
            for (auto c : tmp) valid[c] = 1;
        }
        // for (int i )
    }
    cout << res.size();
    // dbg(res);
    // cout << res;
}
