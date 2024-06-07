/*
  Code by: linvg
*/

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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

bool cmp(ii x, ii y) {
    return abs(x.fi - x.se) < abs(y.fi - y.se);
}

void solve()
{
    auto dist = [&] (int x, int y, int i, int j) {
        return abs(x - i) + abs(y - j);
    };

    int r, n;
    scanf("%lld %lld", &r, &n);
    vector<tuple<int, int, int>> a(n);
    for (auto& c : a) scanf("%lld %lld %lld", &get<0>(c), &get<1>(c), &get<2>(c));
    vector<int> dp(n+1);

    vector<int> maxi(n+1);

    for (int i = 1; i <= n; ++i) {
        int x = get<1>(a[i-1]);
        int y = get<2>(a[i-1]);
        if (get<0>(a[i-1]) - dist(1, 1, x, y) < 0) continue;
        dp[i] = 1;
        int j = i-1;
        for (; j >= 1 and get<0>(a[i-1]) - get<0>(a[j-1]) <= 1011; --j) {
            if (dp[j] == 0) continue;
            if (get<0>(a[i-1]) - get<0>(a[j-1]) >= dist(get<1>(a[j-1]), get<2>(a[j-1]), x, y)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        dp[i] = max(dp[i], maxi[j] + 1);
        maxi[i] = max(maxi[i-1], dp[i]);
    }
    printf("%lld\n", *max_element(all(dp)));
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