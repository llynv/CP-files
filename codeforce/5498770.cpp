
/*
  Code by: linvg
  Created: 14.09.2024 00:04:49
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
    vector<tuple<int, int, int>> S, C;
    map<int, vector<int>> straight;
    map<int, array<int, 2>> C_fix;
    unordered_map<int, bool> flag;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        if (c == 'C') {
            C.push_back({ x1, x3, x2 });
            C_fix[x1][0] = max(C_fix[x1][0], x3);
            C_fix[x1][1] = min((flag[x1] ? C_fix[x1][1] : x2), x2);
            flag[x1] = 1;
        }
        else {
            S.push_back({ x1, x2, x3 });
        }

    }
    sort(all(C));
    for (auto [r1, r2, delta] : S) {
        for (int p = lower_bound(all(C), tuple<int, int, int>({ r1, -INF, -INF })) - C.begin(); get<0>(C[p]) <= r2; ++p) {
            straight[get<0>(C[p])].push_back(delta);
        }
    }

    C.clear();
    for (auto [x1, pi] : C_fix) {
        auto [x3, x2] = pi;
        C.push_back({x1, x3, x2});
    }
    sort(all(C));

    for (int i = 1; i < sz(C); ++i) {
        vector<int> segments(360);
        auto [u, delta1, delta2] = C[i];
        auto [pu, p_delta1, p_delta2] = C[i - 1];
        auto v = straight[u];
        auto pv = straight[pu];
        dbg(u, v);
        dbg(pu, pv);

        int bf = 0, af = 0;
        for (auto angle : v) {
            (angle >= min(delta2, p_delta2) && angle <= max(delta1, p_delta1)) ? af++ : bf++;
            if (bf && af) return void(cout << "NO\n");
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