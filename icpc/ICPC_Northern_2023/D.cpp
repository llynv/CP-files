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

const int INF = 1e18;
const int N = 10011;
const int MOD = 123456789;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (m > n) swap(n, m);

    vector<int> mask;
    for (int i = 0; i < (1 << m); ++i) {
        if ((i & (i >> 1))) continue;
        mask.push_back(i);
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(sz(mask))));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < sz(mask); ++j) {
            int bit = __builtin_popcount(mask[j]);
            if (i == 1) {
                dp[i][bit][j] = 1;
                continue;
            }
            for (int l = 0; l < sz(mask); ++l) {
                if ((mask[j] & mask[l]) || (mask[j] >> 1 & mask[l]) || (mask[j] << 1 & mask[l])) continue;
                for (int t = 0; t <= k; ++t) {
                    if (t < bit) continue;
                    dp[i][t][j] = (dp[i][t][j] + dp[i-1][t-bit][l]) % MOD;
                }
            }
        }
    }

    int res = 0;
    for (int j = 0; j < sz(mask); ++j) {
        res = (res + dp[n][k][j]) % MOD;
        // cout << mask[j] << " " << dp[m][k][j] << "\n";
    }

    cout << res;
}
