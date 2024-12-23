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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) {
        char x;
        cin >> x;
        a[i][j] = (x-'0');
    }

    if (min(m, n) >= 4) return void(cout << "-1\n");
    if (n > m) swap(n, m);

    auto check = [&] (int mask1, int mask2) {
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt = 0;
            cnt += (mask1 >> (i-1) & 1) > 0;
            cnt += (mask1 >> i & 1) > 0;
            cnt += (mask2 >> i & 1) > 0;
            cnt += (mask2 >> (i-1) & 1) > 0;
            if (cnt & 1) continue;
            return false;
        }
        return true;
    };

    auto dif = [&] (int mask, int id) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (a[i][id-1]) != (mask >> i & 1);
        }
        return cnt;
    };

    vector<vector<int>> dp(m+1, vector<int>(1 << n, INF));
 
    for (int mask = 0; mask < (1 << n); ++mask) dp[1][mask] = dif(mask, 1);

    for (int i = 2; i <= m; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int valid = 0; valid < (1 << n); ++valid) {
                if (check(mask, valid)) {
                    dp[i][valid] = min(dp[i][valid], dp[i-1][mask] + dif(valid, i));
                }
            }
        }
    }
    cout << *min_element(all(dp[m])) << '\n';
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