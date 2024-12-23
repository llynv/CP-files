#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

const int INF = 0x3f3f3f3f3f;
const int mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> pref(n + 2), suf(n + 2);
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] ^ a[i - 1];
    for (int i = 1; i <= n; ++i) pref[i] = ((pref[i - 1] + (pref[i] * i % mod)) % mod);
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] ^ a[i - 1];
    for (int i = n; i >= 1; --i) suf[i] = ((suf[i + 1] + (suf[i] * (n - i + 1) % mod)) % mod);
    set<int> s;
    dbg(s);
    int ans = 0;
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        ans += pref[i] + suf[n - i + 1];
        ans %= mod;
    }
    cout << ans << endl;
}



int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}