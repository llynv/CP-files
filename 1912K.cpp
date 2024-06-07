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
const int mod = 998244353;

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int even = 0;
    vector<ii> segs;
    for (auto &c : a) {
        cin >> c;
        even += (c % 2 == 0);
    }

    int ans = fpow(2, even) - n - n * (n-1) / 2 - 1;
    ans = (ans % mod + mod) % mod;

    vector<int> dp(n+1, 1);
    for (int i = 1; i <= n; ++i) {
        int odd = 0;
        if (a[i-1] & 1) {
            for (int j = i-1; j >= 1; --j) {
                odd += !(a[j-1] & 1);
                if (a[j-1] & 1) 
                    dp[i] = (dp[i] + dp[j] * odd * (odd - 1) / 2) % mod;
            }
        } else {
            dp[i] = dp[i-1];
        }
    }

    vector<int> dp2(n+1, 0);
    dp2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int even = 0;
        if (!(a[i-1] & 1)) {
            for (int j = i-1; j >= 1; --j) {
                even += (a[j-1] & 1);
                if (!(a[j-1] & 1))
                    dp2[i] = (dp2[i] + dp2[j] * even * (even - 1) / 2) % mod;
            }
        } else {
            dp2[i] = dp2[i-1];
        }
    }
    dbg(dp, dp2);
    dp[n] = (dp[n] % mod + mod) % mod;
    dp2[n] = (dp2[n] % mod + mod) % mod;

    cout << dp[n] << " " << dp2[n] << "\n";
    cout << (ans + dp[n] + dp2[n]) % mod;
}
