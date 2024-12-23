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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    a.insert(a.begin(), INF);
    a.push_back(INF);
    ii mn = {INF, INF};
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= mn.second) {
            mn.first = mn.second;
            mn.second = a[i];
        } else if (a[i] < mn.first) {
            mn.first = a[i];
        }
    }
    int ans = (mn.first + 1) / 2 + (mn.second + 1) / 2;

    auto calc = [] (int tmp, int lr, int m) {
        int tlr = lr - m * 2;
        int ttmp = tmp - m;
        int ex = 0;
        if (ttmp > 0 || tlr > 0) {
            ex = max({0ll, (ttmp + 1) / 2, tlr});
        }
        int t = (lr + 1) / 2;
        return min(ex + m, t + (lr - t + 1) / 2);
    };

    for (int i = 1; i <= n; ++i) {
        int lr = min(a[i-1], a[i+1]), tmp = a[i];
        if (tmp < lr) swap(tmp, lr);
        int res = 0;
        int l = 0, r = tmp;
        while (l <= r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            int res1 = calc(lr, tmp, m1);
            int res2 = calc(lr, tmp, m2);
            res = min(res1, res2);
            if (res1 <= res2) {
                r = m2 - 1;
            } else {
                l = m1 + 1;
            }
        }
        ans = min(ans, res);

        if (a[i] >= a[i-1] && a[i] >= a[i+1]) {
            res = min(a[i-1], a[i+1]) + (max(a[i-1], a[i+1]) - min(a[i-1], a[i+1]) + 1) / 2;
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
//    int t;
//    cin >> t;
//    while (t--)
   solve();
   return 0;
}