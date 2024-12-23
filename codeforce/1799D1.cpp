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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> cold(k), hot(k);
    for (auto& c : cold) cin >> c;
    for (auto& c : hot) cin >> c;
    hot.insert(hot.begin(), -1);
    cold.insert(cold.begin(), -1);
    a.insert(a.begin(), -1);

    unordered_map<int, set<int>> pos;
    for (int i = 1; i <= n; ++i) {
        pos[a[i]].insert(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, INF));

    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = dp[1][1] = cold[a[1]];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]]);
        dp[i][1] = dp[i-1][1] + (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]]);
        int cost = 0;
        for (int j = i - 1; j >= 1; --j) {
            if (a[i] == a[j]) {
                dp[i][0] = min(dp[i][0], dp[j][0] + cost + hot[a[i]]);
                auto it = pos[a[j+1]].lower_bound(j+1);
                dp[i][0] = min(dp[i][0], dp[j][1] + cost + hot[a[i]] - (it != pos[a[j+1]].begin() ? hot[a[j+1]] : 0));
            }

            cost += (a[j] == a[j+1] ? hot[a[j]] : cold[a[j]]);
        }
    }
    cout << dp[n] << '\n';
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