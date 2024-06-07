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
    int n, r;
    cin >> n >> r;
    vector<ii> nev, pos;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (v < 0) nev.pb({u, v});
        else pos.pb({u, v});
    }

    if (sz(pos) > 1) {
        sort(all(pos), [&] (ii a, ii b) {
            return a.fi < b.fi;
        });
    }

    if (sz(nev) > 1) {
        sort(all(nev), [&](ii a, ii b) {
            if (abs(a.se) - a.fi != abs(b.se) - b.fi) return abs(a.se) - a.fi < abs(b.se) - b.fi;
            if (a.fi == b.fi) return a.se > b.se;
            return a.fi > b.fi;
        });
    }
 

    int res = 0;

    int sum = r;
    for (int i = 0; i < sz(pos); ++i) {
        if (sum < pos[i].fi) break;
        sum += pos[i].se;
        ++res;
    }
    
    vector<vector<int>> dp(sz(nev) + 1, vector<int>(sz(nev) + 1, -1));
    
    for (int i = 1; i <= sz(nev); ++i) {
        if (sum - nev[i-1].fi >= 0) {
            dp[i][1] = sum + nev[i-1].se;
        }
        for (int j = i-1; j >= 1; --j) {
            for (int k = 2; k <= sz(nev); ++k) {
                if (dp[j][k-1] == -1) continue;
                if (dp[j][k-1] - nev[i-1].fi >= 0) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + nev[i-1].se);
                }
            }
        }
    }

    // dbg(dp);

    int ans = 0;
    for (int i = 1; i <= sz(nev); ++i) {
        for (int j = 1; j <= sz(nev); ++j) {
            if (dp[i][j] >= 0) {
                ans = max(ans, j);
            }
        }
        dbg(dp[i]);
    }

    dbg(res, ans);

    cout << res + ans << '\n';

}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}