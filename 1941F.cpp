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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    set<int> d, f;
    for (auto &c : a) cin >> c;
    rep (i, 0, m) {
        int x;
        cin >> x;
        d.insert(x);
    }

    rep (i, 0, k) {
        int x;
        cin >> x;
        f.insert(x);
    }

    int mx = 0, mx2 = 0;
    int cnt = 0, lf = 0, rg = 0;

    for (int i = 1; i < n; ++i) {
        mx = max(a[i] - a[i-1], mx);
        if (mx == a[i] - a[i-1]) {
            lf = a[i-1];
            rg = a[i];
        }
    }

    for (int i = 1; i < n; ++i) {
        cnt += mx == a[i] - a[i-1];
        if (mx != a[i] - a[i-1]) mx2 = max(mx2, a[i] - a[i-1]);
    }
    if (cnt > 1) return void (cout << mx << '\n');

    int mid = (lf + rg) / 2;
    dbg (mid);
    int ans = mx;
    for (auto &c : d) {
        auto it = f.upper_bound(mid - c);
        auto it2 = f.end();
        if (it != f.begin()) {
            it2 = prev(it);
        }

        int r1 = INF, r2 = INF;
        dbg (*it, *it2, c);
        if (it != f.end() && c + *it <= rg && c + *it >= lf) r1 = max(rg - c - *it, c + *it - lf);
        if (it2 != f.end() && c + *it2 <= rg && c + *it2 >= lf) r2 = max(rg - c - *it2, c + *it2 - lf);
        dbg (r1, r2);
        ans = min(ans, min(r1, r2));
    }
    cout << max(mx2, ans) << '\n';

    dbg("END\n");
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