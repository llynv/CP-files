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

struct SegmentTree {
    vector<int> t;
    int n;
    SegmentTree(int n) : n(n), t(4 * n) {}
    SegmentTree(vector<int> a) : SegmentTree(a.size()) {
        build(a, 1, 0, n - 1);
    }
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(v * 2, tl, tm, pos, new_val);
            }
            else {
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            }
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[1][1] = a[0];

    vector < vector <

        for (int i = 2; i <= n; ++i) {
            dp[i][1] = (dp[i - 1][1] & a[i - 1]);
            for (int j = 2; j <= i; ++j) {
                int andVal = a[i - 1];
                for (int k = i - 1; k >= 1; --k) {
                    andVal &= a[k];
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + andVal);
                    if (andVal == 0) break;
                }
            }
        }

    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 3) {
            cout << dp[n][x] << '\n';
        }
    }
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