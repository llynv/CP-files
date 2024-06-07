/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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
    int v;
    cin >> v;
    vector<int> a(9);
    for (auto &c : a) cin >> c;
    vector<int> dp(v+1, -1);
    vector<ii> pre(v+1, {-1, -1});
    int mx = 1;
    dp[0] = 0;
    for (int i = 1; i <= v; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (i >= a[j] && dp[i-a[j]] + 1 >= dp[i]) {
                if (dp[i-a[j]] + 1 == dp[i]) {
                    if (j > pre[i].se) {
                        pre[i] = {i-a[j], j};
                    } else if (j == pre[i].se) {
                        if (i-a[j] >= pre[i].fi) {
                            pre[i] = {i-a[j], j};
                        }
                    }
                } else {
                    pre[i] = {i-a[j], j};
                }
                dp[i] = dp[i-a[j]] + 1;
                mx = max(mx, dp[i]);
            }
        }
    }

    auto maxx = [&] (string &r1, string &r2) {
        if (r1.size() > r2.size()) return r1;
        if (r1.size() < r2.size()) return r2;
        for (int i = 0; i < r1.size(); ++i) {
            if (r1[i] > r2[i]) return r1;
        }
        return r2;
    };

    dbg(mx);

    string ans = "";
    for (int i = v; i >= 1; --i) {
        if (dp[i] == mx) {
            dbg(i, dp[i], pre[i]);
            string tmp = "";
            int x = i, y = pre[i].se;
            for (int j = 0; j < mx; ++j) {
                ii p = pre[x];
                x = p.fi;
                y = p.se;
                tmp += ('1' + y);
            }
            dbg(ans, tmp);
            ans = maxx(ans, tmp);
        }
    }

    if (ans.empty()) return void (cout << "-1\n");

    // sort(ans.begin(), ans.end());
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