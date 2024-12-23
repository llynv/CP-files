/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ii pair<int, int>

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
    if (k & 1) return void(cout << "No\n");

    int mx = 0;
    for (int i = 1; i <= n; ++i) mx += abs(2 * i - n - 1);
    if (mx < k) return void(cout << "No\n");

    vector<int> ans (n+1);
    ordered_set s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != 0) continue;
        int l = 0, r = sz(s) - 1, x = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = *s.find_by_order(m);
            if (abs(val - i) * 2 <= k) {
                l = m + 1;
                x = val;
            }
            else {
                r = m - 1;
            }
        }
        ans[i] = (x == 0 ? i : x);
        s.erase(ans[i]);
        k -= abs(i - x);
        if (x != 0) {
            ans[x] = i;
            s.erase(ans[x]);
            k -= abs(i - x);    
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
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