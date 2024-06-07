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

ii com (ii a, ii b) {
    if (a.fi * b.se <= a.se * b.fi) return a;
    return b;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;

    vector<int> f;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            f.pb(i);
            if (i != n / i) f.pb(n / i);
        }
    }

    vector<vector<int>> pref(sz(f)+1);
    int cnt = 1;
    for (auto &c : f) {
        pref[cnt].assign(n+1, 0);
        for (int j = c, i = 1; j <= n; j += c, ++i) {
            pref[cnt][i] = pref[cnt][i-1] + a[j-1];
        }
    }

    ii p = ii{*max_element(all(a)), *min_element(all(a))};

    for (int i = 0; i <= n; ++i) {
        for (auto &c : f) {
            int mx = 0, mn = INF;
            for (int j = n-c; j <= n; ++j) {
                if (j % c == 0) {
                    
                    continue;
                }
                mx = max(mx, pref[c].back() - pref[c][j-(n-c)+1]);
                mn = min(mn, pref[c][j+1] - pref[c][j-(n-c)+1]);
            }
            p = com(p, ii{mx, mn});
        }
    }

    dbg(p);

    int _gcd = gcd(p.fi, p.se);
    cout << p.fi / _gcd << " " << p.se / _gcd << "\n";
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