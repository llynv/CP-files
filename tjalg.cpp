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
const int N = 10007;

vector<int> adj[N];
int vst[N], numb[N], low[N], del[N];
stack<int> st;
int vertex = 0, cnt = 0;

void dfs(int u)
{
    vertex++;
    numb[u] = vertex;
    low[u] = vertex;
    st.push(u);
    for (auto v : adj[u]) {
        if (del[v]) continue;

        if (numb[v] == 0) {
            dfs(v);
            low[u] = min(low[v], low[u]);
        } else {
            low[u] = min(low[u], numb[v]);
        }

        if (low[u] == numb[u]) {
            cnt++;
            while (!st.empty() && st.top() != u) {
                del[st.top()] = true;
                st.pop();
            }
            // cout << u << "\n";
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v, e;
        cin >> v >> e;
        adj[v].emplace_back(e);
    }

    for (int i = 1; i <= n; ++i) {
        cout << numb[i] << "\n";
        if (!numb[i]) {
            dfs(i);
        }
    }
    cout << cnt;
}