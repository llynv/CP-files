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
const int N = 1e5 + 5;

ostream& operator<<(ostream& os, const tuple<int, int, int>& t) {
    return os << get<0>(t) << " " << get<1>(t) << " " << get<2>(t);
}

int curL = 1, curR = 0;
int dp[N][21] = {INF};
int cnt[N], res = 0;

int cost(int l, int r, vector<int>& a) {
    while (curL < l) {
        cnt[a[curL]]--;
        res -= cnt[a[curL]];
        curL++;
    }
    while (curL > l) {
        curL--;
        res += cnt[a[curL]];
        cnt[a[curL]]++;
    }
    while (curR < r) {
        curR++;
        res += cnt[a[curR]];
        cnt[a[curR]]++;
    }
    while (curR > r) {
        cnt[a[curR]]--;
        res -= cnt[a[curR]];
        curR--;
    }
    return res;
}

int leftj[N][21];

void calc(int k, int l, int r, int ll, int rr, vector<int>& a) {
    if (l > r) return;
    int mid = (l + r) / 2;
    int best = 0;
    for (int i = ll; i <= min(mid, rr); ++i) {
        int cur = dp[i][k - 1] + cost(i+1, mid, a);
        // dbg(i, mid, cur, dp[mid][k], dp[i][k - 1], cost(i, mid, a));
        if (cur < dp[mid][k]) {
            dp[mid][k] = cur;
            best = i;
        }
    }
    calc(k, l, mid - 1, ll, best, a);
    calc(k, mid + 1, r, best, rr, a);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = INF;
        }
    }
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = cost(1, i, a);
    }
    for (int i = 2; i <= k; ++i) calc(i, 1, n, 0, n, a);
    // int totalCost = 0;
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= k; ++j) {
    //         cerr << dp[i][j] << " \n"[j == k];
    //     }
    // }
    cout << dp[n][k] << endl;
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