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

const int INF = 1e18;

void solve()
{
    int n, d, k;
    cin >> n >> k >> d;
    vector<int> t(n), a(k), b(k);
    for (auto& x : t) cin >> x;
    for (auto& c : a) cin >> c;
    for (auto& c : b) cin >> c;

    int ans = INF;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int cnt = 0, cur = (mask & 1);
        bool ok = true;
        int res = 0;
        vector<unordered_map<int, int>> cv(2);
        for (int j = 0; j < n; ++j) {
            if (cur == (mask >> j & 1)) {
                cnt++;
            }
            else {
                cnt = 1;
                cur ^= 1;
            }
            if (cnt > d) {
                ok = false;
                break;
            }
            int idx = (mask >> j & 1);
            cv[idx][t[j] - 1]++;
            if (cv[idx][t[j] - 1] == 1) {
                res += a[t[j] - 1];
            }
            else {
                res += b[t[j] - 1];
            }
        }

        if (ok) {
            ans = min(ans, res);
        }
    }
    cout << ans << '\n';
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