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
    vector<int> a(n), b(n);
    int total = 0;
    vector<int> ss;
    for (auto &c : a) {
        cin >> c;
        total += c;
        ss.push_back(c);
    }
    for (auto &c : b) {
        cin >> c;
        total += c;
        ss.push_back(c);
    }
    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[0][0] = 1;
    

    sort(all(ss));
    dbg(ss);

    dbg(total);

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = a[i-1] + min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = b[i-1] + min(dp[i-1][0], dp[i-1][1]);
        int s1 = a[i-1], s2 = b[i-1];
        for (int j = i-1; j >= 1; --j) {
            s1 += a[j-1];
            s2 += b[j-1];
            dp[i][0] = min(dp[i][0], s1 + min(dp[j][0], dp[j][1]));
            dp[i][1] = min(dp[i][1], s2 + min(dp[j][0], dp[j][1]));
        }
    }    

    dbg(dp[n][0], dp[n][1]);

    // dbg(dp);
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