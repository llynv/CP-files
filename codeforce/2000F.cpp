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
const int MOD = 1e8;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> w[i];
        if (c[i] < w[i]) swap(c[i], w[i]);
    }


    vector<vector<int>> costRect(n+1, vector<int>(k+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(k, c[i-1] + w[i-1]); ++j) {
            int cntC = c[i-1], cntW = w[i-1], points = 0;
            for (int l = 0; l < j and (cntC or cntW); ++l) {
                if (cntC <= cntW) {
                    points += cntC;
                    cntW--;
                } else {
                    points += cntW;
                    cntC--;
                }
            }
            costRect[i][j] = points;
        }
    }


    vector<int> dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= 0; --j) {
            for (int l = 1; l <= c[i] + w[i]; ++l) {
                if (j - l < 0) break;
                dp[j] = min(dp[j], dp[j - l] + costRect[i+1][l]);
            }
        }
    }
    cout << (dp[k] == INF ? -1 : dp[k]) << "\n";
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