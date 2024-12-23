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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    a.push_back(3);
    a.insert(a.begin(), -1);
    vector<vector<int>> pre(n+1, vector<int>(3)), suf(n+2, vector<int>(3));
    vector<int> cnt(n+2, 0);
    int ans = 0;
    
    pre[1][0] = (a[1] == 1);
    pre[1][1] = (a[1] == 2);
    for (int i = 2; i <= n; ++i) {
        pre[i][0] = pre[i-1][0] + (a[i] == 1);
        pre[i][1] = pre[i-1][1] + (a[i] == 2);
        // pre[i][2] = max({pre[i-1][2] + (a[i] == 2), pre[i][1], pre[i][0]});
    }

    vector<vector<int>> mxp (n+2, vector<int>(n+2, 0)), mnp (n+2, vector<int>(n+2, 0)); 

    for (int i = 1; i <= n; ++i) {
        int n1 = 0, n2 = 0;
        for (int j = i; j <= n; ++j) {        
            n1 += (a[j] == 1);
            n2 += (a[j] == 2);
            mxp[i][j] = max({n1, n2, mxp[i][j-1] + (a[j] == 2)});
        }
    }
    
    suf[n][0] = (a[n] == 1);
    suf[n][1] = (a[n] == 2);
    for (int i = n-1; i >= 1; --i) {
        suf[i][0] = suf[i+1][0] + (a[i] == 1);
        suf[i][1] = suf[i+1][1] + (a[i] == 2);
        // suf[i][2] = max({suf[i+1][2] + (a[i] == 2), suf[i][1], suf[i][0]});
    }

    for (int i = n; i >= 1; --i) {
        int n1 = 0, n2 = 0;
        for (int j = i; j >= 1; --j) {
            n1 += (a[j] == 1);
            n2 += (a[j] == 2);
            mnp[j][i] = max({n1, n2, mnp[j+1][i] + (a[j] == 2)});
        }
    }

    ans = max(ans, pre[n][2]);

    dbg(ans);
    dbg(pre);
    dbg(suf);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = max(ans, pre[i-1][0] + suf[i][0] - suf[j+1][0] + pre[n][0] - pre[j][0]);
            ans = max(ans, pre[i-1][0] + suf[i][0] - suf[j+1][0] + mxp[j+1][n]);
            ans = max(ans, pre[i-1][0] + mnp[i][j] + pre[n][1] - pre[j][1]);
            ans = max(ans, pre[i-1][1] + suf[i][1] - suf[j+1][1] + pre[n][1] - pre[j][1]);
            ans = max(ans, mxp[1][i-1] + suf[i][1] - suf[j+1][1] + pre[n][1] - pre[j][1]);
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
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}