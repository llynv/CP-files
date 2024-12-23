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

const int INF = 100001;

void solve()
{
    int n;
    cin >> n;
    vector<ii> points(n);
    int mn = INF, mx = -INF;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].fi >> points[i].se;
    }

    auto calc = [&] (int x, int y) {
        int ans = 0; 
        for (int i = 0; i < n; ++i) {
            ans += abs(points[i].fi - x) + abs(points[i].se - y);
        }
        return ans;
    };

    auto f = [&] (int x) {
        int lo = -INF, hi = INF, pos = -1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int f1 = calc (x, m);
            int f2 = calc (x, m + 1);
            if (f1 <= f2) {
                pos = m;
                hi = m - 1;
            } else {
                lo = m + 1;
            }
        }
        return calc(x, pos);
    };

    int l = -INF, r = INF, u = INF, d = -INF;
    while (l <= r) {
        int m = (l + r) / 2;
        int f1 = f(m);
        int f2 = f(m + 1);
        if (f1 <= f2) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    int x = l;
    while (d <= u) {
        int m = (d + u) / 2;
        int f1 = f(m);
        int f2 = f(m + 1);
        if (f1 <= f2) {
            u = m - 1;
        } else {
            d = m + 1;
        }
    }

    int y = d;
    cout << x << ' ' << y << '\n';
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