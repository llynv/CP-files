
/*
  Code by: linvg
  Created: 17.09.2024 21:53:44
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> mons(n);
    for (int i = 0; i < n; ++i) cin >> mons[i][0];
    for (int i = 0; i < n; ++i) cin >> mons[i][1];
    if (sz(mons) > 1) {
        sort(all(mons), [&](array<int, 2> x, array<int, 2> y) {
            if (x[0] < y[0]) return true;
            if (x[0] == y[0]) return x[1] > y[1];
            return false;
            });
    }

    vector<int> mn(n + 1);
    mn[n] = INF;

    for (int i = n - 1; i >= 0; --i) mn[i] = min(mn[i + 1], mons[i][1]);
    int damage = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        mons[i][0] -= damage;
        cur = max(cur, i);
        while (mons[i][0] > 0 && k > 0) {
            mons[i][0] -= k;
            damage += k;
            if (mons[i][0] > 0) {
                k -= mn[cur];
            }
            else {
                while (cur < n && mons[cur][0] <= damage) {
                    ++cur;
                }
                if (cur >= n) {
                    cout << "YES\n";
                    return;
                }
                k -= mn[cur];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mons[i][0] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}