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
    int n, w1, w2;
    cin >> n >> w1 >> w2;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    vector<int> pref(n + 1), suf(n + 1);
    int mn = a[0], mx = a[0];
    for (int i = 1; i < n; ++i) {
        pref[i] = max(pref[i - 1], a[i] * w2 + max(mn * w1, mx * w1));
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    mn = a[n - 1], mx = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = max(suf[i + 1], a[i] * w2 + max(mn * w1, mx * w1));
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for (int i = 2; i < n - 2; ++i) {
        ans = max(ans, pref[i-1] + suf[i+1] + a[i-1]);
    }
    cout << ans << '\n';
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