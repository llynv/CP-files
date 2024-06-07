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
    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);
    for (auto& c : a) cin >> c;
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; ++i) mp1[a[i]]++;
    for (int i = n; i < 2 * n; ++i) mp2[a[i]]++;
    vector<int> r1, r2, r3, r4;
    for (int i = 1; i <= n; ++i) {
        if (mp1[i] == 2) {
            r3.pb(i);
        }
        if (mp1[i] == 1) {
            r1.pb(i);
        }
        if (mp2[i] == 2) {
            r2.pb(i);
        }
        if (mp2[i] == 1) {
            r4.pb(i);
        }
    }
    dbg(r1, r2, r3);
    for (int i = 1; i <= min(sz(r3), k); i++) {
        cout << r3[i - 1] << " " << r3[i - 1] << " ";
    }
    for (int i = 1; i <= 2 * k - 2 * min(sz(r3), k); i++) {
        cout << r1[i - 1] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= min(sz(r2), k); i++) {
        cout << r2[i - 1] << " " << r2[i - 1] << " ";
    }
    for (int i = 1; i <= 2 * k - 2 * min(sz(r2), k); i++) {
        cout << r4[i - 1] << " " ;
    }
    cout << "\n";
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