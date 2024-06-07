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

int store[] = {
    2,
    3,
    4,
    8,
    16,
    32,
    64,
    128,
    143,
    256,
    285,
    512,
    569,
    683,
    1024,
    1138,
    1366,
    2048,
    2276,
    4096,
    8192,
    16384,
    32768,
    65536,
    131072
};

void solve()
{
    int n, k;
    cin >> n >> k;
    n -= (n == k);
    if (k == 1) {
        cout << 25 << '\n';
        cout << "2 3 4 ";
        for (int i = 3; i < 25; ++i) {
            cout << (1 << i) << ' ';
        }
        cout << '\n';
        return;
    }
    int total = 0;
    vector<int> ans;
    bool isFind = false, isAdd = false;
    for (int i = 0; i < 25; ++i) {
        if (total >= n) break;
        if (!isFind && 2 * total + 1 >= k) {
            dbg(k, total);
            ans.push_back(k - total - 1);
            total += k - total - 1;
            ans.push_back(k + 1);
            total += k + 1;
            isFind = true;
            continue;
        }
        int bonus = 0;
        if (!isAdd && isFind) {
            if (total + ans.back() <= n) {
                bonus = total + ans.back();
                ans.push_back(bonus);
            }
            isAdd = true;
        }
        ans.push_back(total + 1);
        total += max(bonus, total) + 1;
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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