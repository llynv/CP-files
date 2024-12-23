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
    int n, m;
    cin >> n >> m;
    vector<int> segs;
    unordered_map<int, int> st, ed;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        segs.push_back(l);
        segs.push_back(r+1);
        st[l]++;
        ed[r+1]++;
    }
    sort(all(segs));
    vector<int> amt (segs.size());
    int total = 0;
    for (int i = 0; i < m; ++i) {
        total += st[segs[i]];
        total -= ed[segs[i]];

        amt[i] = total;
    }
    dbg(amt);
    vector<vector<int>> f(20, vector<int>(segs.size()));
    for (int i = 0; i < sz(segs); ++i) {
        f[0][i] = amt[i];
    }
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << i) <= sz(segs); ++j) {
            f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i-1))]);
        }
    }
    auto query = [&](int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return max(f[k][l], f[k][r - (1 << k) + 1]);
    };
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l = lower_bound(all(segs), l) - segs.begin();
        r = lower_bound(all(segs), r+1) - segs.begin() - 1;
        ans = max(ans, query(l, r));
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