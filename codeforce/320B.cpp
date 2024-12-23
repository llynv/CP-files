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

const int N = 111;

vector<int> adj[N];

struct DSU{
    vector<int> e;
    int mx = 0;
    DSU(int N){ e = vector<int>(N, -1);}
    int get(int x){
        if(e[x] < 0) return x;
        return e[x] = get(e[x]);
    }
    int size(int x){return -e[get(x)];}
    bool unite(int a, int b){
        a = get(a); b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        mx = max(mx, -e[a]);
        return true;
    }
};

int vs[N];

void dfs(int u) {
    vs[u] = 1;
    for (auto &v : adj[u]) {
        if (vs[v]) continue;
        dfs(v);
    }
}

void solve()
{   
    int n;
    cin >> n;
    vector<ii> qr;

    rep (i, 0, n) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;

            if (a >= b) continue;

            for (int i = 0; i < sz(qr); ++i) {
                int u = qr[i].fi, v = qr[i].se;
                if ((a < u && u < b) || (a < v && v < b)) {
                    adj[i+1].push_back(sz(qr)+1);
                    // dsu.unite(i+1, sz(qr)+1);
                }

                if ((u < a && a < v) || (u < b && b < v)) {
                    adj[sz(qr)+1].push_back(i+1);
                    // dsu.unite(i+1, sz(qr)+1);
                }
            }

            qr.push_back({a, b});
        } else {
            int a, b;
            cin >> a >> b;
        
            memset(vs, 0, sizeof(vs));

            dfs(a);
            if (vs[b]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}