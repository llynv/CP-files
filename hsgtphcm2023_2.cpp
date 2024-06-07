#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops");
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define LOCAL
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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 1e9 + 7;
const int N = 411;

int dp[N][N];

void (int &a, int b) {
    a = min(a, b);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pre(n+1);
    for (auto &c : a) cin >> c;
    for (int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i-1];

    rep (i, 0, n+1) memset(dp[i], INF, sizeof(dp[i]));

    int mx = 0;
    for (int i = 1; i <= n; ++i) { 
        mx = max(mx, a[i-1]);
        // dbg(lp[i-1], i, mx);
        dp[i][0] = i * mx - pre[i];

        mx = a[i-1];
        for (int l = i - 1; l >= 0; --l) {
            mx = max(mx, a[l]);
            for (int j = 1; j <= k; ++j) {
                update(dp[i][j], dp[l][j-1] + (i - l) * mx - (pre[i] - pre[l]));
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= k; ++i) update(res, dp[n][i]);
    cout << res;
}
