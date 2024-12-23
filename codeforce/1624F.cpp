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
const int MOD = 1e8;

int judge (int n, int& x, int v) {
    x += v;
    return x / n;
}

void solve()
{
    int n;
    cin >> n;

    int sol = 3;

    int cnt = 0;

    auto ask = [&] (int x) -> int {
        cout << "+ " << x << '\n';
        cout.flush();
        int res;
        cin >> res;
        // res = judge(n, sol, x);
        // cerr << x << ' ' << res << '\n';
        // ++cnt;
        return res;
    };

    int pre = 0;
    bool flag = false;
    int l = 1, r = n - 1, ans = 0;
    
    while (l <= r) {
        int m = (l + r) >> 1;
        int x = ask(m);
        ans = x;
        if (n - x > ans) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        l = (l + n - m) % n;
        r = (r + n - m) % n;
    }
    dbg(cnt);
    dbg(ans, l, r);
    cout << "! " << ans * n + l << '\n';
    cout.flush();
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