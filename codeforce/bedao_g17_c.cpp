
/*
  Code by: linvg
  Created: 15.09.2024 21:02:23
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
    int n;
    cin >> n;
    
    vector<array<int, 2>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    
    vector<array<int, 2>> p1, p2, p3;
    int res = INF;

    auto back = [&] (int j, auto&& back) -> void {    

        if (j == n) {

            if (sz(p1) == 0 || sz(p2) == 0 || sz(p3) == 0) {
                return;
            }

            int rr1 = 0, rr2 = 0, rr3 = 0;
            int t1 = -INF, t2 = -INF, t3 = -INF;
            int b1 = INF, b2 = INF, b3 = INF;
            int l1 = INF, l2 = INF, l3 = INF;
            int r1 = -INF, r2 = -INF, r3 = -INF;
            for (auto [u, v] : p1) {
                t1 = max(t1, v);
                b1 = min(b1, v);
                l1 = min(l1, u);
                r1 = max(r1, u);
            }

            for (auto [u, v] : p2) {
                t2 = max(t2, v);
                b2 = min(b2, v);
                l2 = min(l2, u);
                r2 = max(r2, u);
            }

            for (auto [u, v] : p3) {
                t3 = max(t3, v);
                b3 = min(b3, v);
                l3 = min(l3, u);
                r3 = max(r3, u);
            }

            rr1 = max({r1 - l1, t1 - b1, 1ll});
            rr2 = max({r2 - l2, t2 - b2, 1ll});
            rr3 = max({r3 - l3, t3 - b3, 1ll});

            res = min(res, max({rr1, rr2, rr3}));

            return;
        }

        for (int i = 0; i <= 2; ++i) {
            if (i == 0) {
                p1.push_back(points[j]);
            } else if (i == 1) {
                p2.push_back(points[j]);
            } else {
                p3.push_back(points[j]);
            }
            back(j + 1, back);
            if (i == 0) {
                p1.pop_back();
            } else if (i == 1) {
                p2.pop_back();
            } else {
                p3.pop_back();
            }
        }
    };

    back(0, back);

    cout << res * res << '\n';    
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}