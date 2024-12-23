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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) return void (cout << "NO\n");
        if (a[i] != b[i]) ok = false;
    }
    if (ok) return void (cout << "YES\n");

    int mn = *min_element(all(a));
    int pos = 0;
    for (int i = n-1; i >= 0; --i) {
        if (a[i] == mn) {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i, pos = (pos == 0 ? n-1 : pos-1)) {
        if (a[pos == 0 ? n-1 : pos-1] == b[pos == 0 ? n-1 : pos-1]) continue;
        if (b[pos == 0 ? n-1 : pos-1] - b[pos] > 1) return void (cout << "NO\n");
    }
    
    cout << "YES\n";
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