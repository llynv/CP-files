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
const int N = 1e5 + 11;

vector<int> adj[N], adj2[N];
int vst[N], a[N], l[N], r[N];

void dfsT(int u) {
    vst[u] = 1;
    for (auto v : adj2[u]) {
        if (!vst[v]) {
            adj[u].pb(v);
            dfsT(v);
        }
    }
}

void dfs(int u, int &cnt) {
    l[u] = cnt;
    for (auto c : adj[u]) {
        cnt++;
        dfs(c, cnt);
    }
    r[u] = cnt;
}

struct itnode
{
    itnode *lf, *rg;
    int cnt = 0;

    itnode() {
        lf = rg = nullptr;
    }
};

vector<itnode*> vers;

void CreateNode (itnode *&it)
{
    it = new itnode();
    it->lf = new itnode();
    it->rg = new itnode();
}

void build (itnode *&it, int L, int R)
{
    if (L == R) {
        it->cnt = 0;
        return;
    }

    int mid = (L + R) >> 1;
    CreateNode(it);
    build (it->lf, L, mid);
    build (it->rg, mid + 1, R);
}

void update (itnode *&it, int L, int R, int pos)
{
    if (L == R) {
        it = new itnode();
        it->cnt = 1;
        return;
    }

    int mid = (L + R) >> 1;
    itnode *tmp = new itnode();
    *tmp = *it;
    if (pos <= mid) {
        update (tmp->lf, L, mid, pos);
    } else {
        update (tmp->rg, mid + 1, R, pos);
    }
    tmp->cnt = tmp->lf->cnt + tmp->rg->cnt;
    it = tmp;
}

int get (itnode *&it1, itnode *&it2, int L, int R, int k)
{
    if (L == R) {
        return L;
    }

    int mid = (L + R) >> 1;
    int numb = it2->lf->cnt - it1->lf->cnt;

    if (numb >= k) {
        return get (it1->lf, it2->lf, L, mid, k);
    }  else {
        return get (it2->rg, it1->rg, mid + 1, R, k - numb);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    rep (i, 1, n+1) cin >> a[i];
    rep (i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    dfsT(1);
    int cnt = 1;
    dfs(1, cnt);

    itnode *ver0 = new itnode();
    build (ver0, 1, n);
    vers.push_back(ver0);

    for (int i = 1; i <= n; ++i) {
        itnode *nxt = vers.back();
        update (nxt, 1, n, a[i]);
    }

    rep (i, 0, m) {
        int u, v, k;
        cin >> u >> v >> k;
        if (l[u] > l[v]) swap(u, v);
        
    }
}
