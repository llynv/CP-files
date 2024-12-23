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

    // ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 4e5 + 11;

int a[N], l[N], r[N], vst[N], times;
vector<int> adj[N];

struct itnode
{
    int colors;
    int isUpd = 0;
};
itnode it[11000111];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].colors = ((1LL) << (a[L] - 1));
        it[index].isUpd = 0;
        return;
    }
    int mid = (L + R) >> 1;
    build (index << 1, L, mid);
    build (index << 1 | 1, mid + 1, R);
    it[index].colors = (it[index << 1].colors | it[index << 1 | 1].colors);
}

void lazyUpdate (int index)
{
    int k = it[index].isUpd;
    if (!k) return;
    if (it[index << 1].isUpd < k) {
        it[index << 1].colors = it[index].colors;
        it[index << 1].isUpd = k;
    }
    if (it[index << 1 | 1].isUpd < k) {
        it[index << 1 | 1].colors = it[index].colors;
        it[index << 1 | 1].isUpd = k;
    }
    it[index].isUpd = 0;
}

void update (int index, int L, int R, int l, int r, int val)
{
    if (L > r || R < l) return;

    lazyUpdate(index);

    if (l <= L && R <= r) {
        it[index].colors = val;
        it[index].isUpd = times;
        lazyUpdate(index);
        return;
    }
    lazyUpdate(index);

    int mid = (L + R) >> 1;
    update (index << 1, L, mid, l, r, val);
    update (index << 1 | 1, mid + 1, R, l, r, val);
    
    it[index].colors = (it[index << 1].colors | it[index << 1 | 1].colors);
}

int get (int index, int L, int R, int l, int r)
{
    lazyUpdate(index);
    if (L > r || R < l) return 0;

    lazyUpdate(index);
    if (l <= L && R <= r) {
        return it[index].colors;
    }

    lazyUpdate(index);
    int mid = (L + R) >> 1;
    int v1 = get(index << 1, L, mid, l, r);
    int v2 = get(index << 1 | 1, mid + 1, R, l, r);
    return (v1 | v2);
}

void dfs(int u, int &cnt)
{
    vst[u] = 1;
    l[u] = cnt;
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        cnt++;
        dfs(v, cnt);
    }
    r[u] = cnt;
}

void solve()
{
    int n, m;
    scanf("%lld %lld", &n, &m);
    rep (i, 1, n+1) scanf("%lld", &a[i]);

    rep (i, 0, n-1) {
        int u, v;
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 1;
    dfs(1, cnt);

    vector<int> b(n+1);
    for (int i = 1; i <= n; ++i) {
        b[l[i]] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i];
    }

    build (1, 1, n);

    // rep (i, 1, n+1) cout << i << " : " << l[i] << " -> " << r[i] << "\n";
    // cout << "\n";

    rep (i, 0, m) {
        int t;
        scanf("%lld", &t);
        if (t == 1) {
            int v, c;
            scanf("%lld %lld", &v, &c);
            // dbg(v, l[v], r[v], c);
            times++;
            update (1, 1, n, l[v], r[v], ((1LL) << (c-1)));
        } else {
            int v;
            scanf("%lld", &v);
            // dbg(v, l[v], r[v]);
            int res = __builtin_popcountll(get(1, 1, n, l[v], r[v]));
            printf("%lld\n", res);
        }
    }
}
