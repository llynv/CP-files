
/*
  Code by: linvg
  Created: 17.09.2024 23:01:04
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<vector<int>> f(20, vector<int> (n + 1)), g(20, vector<int> (n + 1));
    for (int i = 1; i <= n; ++i) f[0][i] = g[0][i] = a[i-1];
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j + (1 << (i - 1)) <= n; ++j) {
            f[i][j] = gcd(f[i-1][j], f[i-1][j + (1 << (i - 1))]);
            g[i][j] = min(g[i-1][j], g[i-1][j + (1 << (i - 1))]);
        }
    }
    auto get = [&] (int l, int r) -> int {
        if (l > r) return -1;
        if (l == r) return f[0][l];
        int lg = log2(r - l + 1);
        return gcd(f[lg][l], f[lg][r - (1 << lg) + 1]);
    };

    auto get_min = [&] (int l, int r) -> int {
        if (l > r) return -1;
        if (l == r) return g[0][l];
        int lg = log2(r - l + 1);
        return min(g[lg][l], g[lg][r - (1 << lg) + 1]);    
    };

    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1, cnt = 0;
        for (int i = 1; i <= n - mid; ++i) {
            int _gcd = get(i, i + mid);
            int mn = get_min(i, i + mid);
            if (_gcd == mn) ++cnt;
        }
        if (cnt) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    int total = 0;
    vector<int> res;
    for (int i = 1; i <= n - ans; ++i) {
        int _gcd = get(i, i + ans);
        int mn = get_min(i, i + ans);
        if (_gcd == mn) {
            res.push_back(i);
            ++total;
        }
    }
    cout << total << ' ' << ans << '\n';
    for (int i = 0; i < sz(res); ++i) cout << res[i] << " \n"[i == sz(res) - 1];
}   


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}