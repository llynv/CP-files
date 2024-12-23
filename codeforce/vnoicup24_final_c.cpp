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

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> chd(n + 1);
    bool isLine = true;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        p[i] = x;
        chd[x].pb(i);
        if (chd[x].size() > 1) isLine = false;
    }
    vector<int> a(n), b(n);
    for (int i = 1; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];

    if (n <= 20) {
        vector<int> dp(1 << n, INF);
        vector<int> ans(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) dp[1 << i] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            // int cnt = __builtin_popcount(mask);
            if (dp[mask] == INF) continue;
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) continue;
                int total = dp[mask];
                if (i != 0 && (mask >> p[i] & 1)) total += a[i];
                for (int t = 0; t < chd[i].size(); ++t) {
                    if (mask >> chd[i][t] & 1) total += b[chd[i][t]];
                }
                // dbg(mask, i, total);
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], total);
            }
            int id = __builtin_popcount(mask);
            ans[id] = min(ans[id], dp[mask]);
        }
        for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
    } else if (isLine) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 1; --j) {
                for (int k = )
            }
        }
    }
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