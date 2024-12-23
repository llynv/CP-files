/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v : a) for (auto &c : v) cin >> c;
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));

    vector<int> st;
    st.push_back(0);

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i][m] = dp[i][0] = 0;
        multiset<int> storeDP;
        storeDP.insert(0);
        for (int j = 2; j < m; ++j) {
            dbg(storeDP);
            dp[i][j] = min(dp[i][j], *storeDP.begin() + a[i-1][j-1] + 1);
            dbg(dp[i][j]);
            storeDP.insert(dp[i][j]);
            if (sz(storeDP) > d+1) storeDP.erase(storeDP.find(dp[i][j-d-1]));
        }
        dbg(dp[i]);
        int mn = INF;   
        for (int j = m-1; j >= max(1LL, m-d-1); --j) mn = min(mn, dp[i][j]);
        st.pb(mn + 2);
    }   
    int ans = INF;
    for (int i = 1; i < sz(st); ++i) st[i] += st[i-1];
    for (int i = k; i <= n; ++i) ans = min(ans, st[i] - st[i-k]);
    cout << ans << '\n';
    dbg(st);
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}