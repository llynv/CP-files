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
const int mod = 1e9 + 7;

int fpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

const int N = 1e7 + 7;
int f[N];

void sieve() 
{
    f[1] = f[2] = 0;
    int mul3 = 3, mul2 = 2;
    for (int i = 3; i < N; ++i) {
        mul3 = mul3 * 3 % mod;
        mul2 = mul2 * 2 % mod;
        f[i] = (mul3 - 2*mul2 + 1) % mod;
    }
}

int grid[1007][1007], vst[1007][1007];

const int dx[] = {1, 0};
const int dy[] = {0, 1};

void dfs(int i, int j, int n, int m)
{
    vst[i][j] = 1;
    for (int k = 0; k < 2; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x > n || y > m || grid[x][y] || vst[x][y]) continue;
        dfs(x, y, n, m);
    }
}

int res = 0;

void get (int mask, int i, int n)
{
    if (i == n) {
        if (grid[1][1] || grid[n][n]) return;
        memset(vst, 0, sizeof(vst));
        dfs(1, 1, n, n);
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        if (vst[n][n]) res++;
    }
    for (int j = 1; j < (1 << n); j <<= 1) {
        if (!(mask & j)) {
            int x = __builtin_popcount(mask ^ j);
            int y = 64 - __builtin_clzll(j);
            // dbg(x, y);
            grid[x][y] = 1;
            get(mask ^ j, i+1, n);
            grid[x][y] = 0;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    get (0, 0, n);
    cout << res << endl;
}
