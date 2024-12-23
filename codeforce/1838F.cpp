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
    int n;
    cin >> n;

    vector<vector<char>> a(n, vector<char>(n, 'v'));

    auto ask = [&](int r, int c) {
        cout << "? " << r << " " << c << endl;
        for (auto& c : a) {
            for (auto& x : c) cout << x;
            cout << endl;
        }

        ii res;
        cin >> res.fi >> res.se;
        return res;
        };


    // for (auto& c : a) {
    //     for (auto& x : c) cout << x;
    //     cout << endl;
    // }

    int l = 1, r = n;
    auto pos = ii(0, 0);

    if (n <= 8) {
        pos = ii(1, n);
    }
    else {
        while (r - l > 2) {
            int m = (l + r) / 2;
            m = max(m, 3ll);

            fill(all(a), vector<char>(n, 'v'));

            for (int i = 0; i < n; ++i) {
                for (int j = l - 1; j < m; ++j) {
                    a[i][j] = (i & 1) ? '<' : '>';
                }
                if (i % 2 == 0) {
                    a[i][m - 1] = 'v';
                }
                else {
                    a[i][l - 1] = 'v';
                }
            }

            auto res = ask(1, l);

            ii goal = { n, l };
            if (n & 1) {
                goal = { n, m };
            }


            if (a[goal.fi - 1][goal.se - 1] == '<') {
                goal.se--;
            }
            else if (a[goal.fi - 1][goal.se - 1] == '>') {
                goal.se++;
            }
            else if (a[goal.fi - 1][goal.se - 1] == '^') {
                goal.fi--;
            }
            else {
                goal.fi++;
            }

            dbg(l, r, m);
            dbg(res, goal);

            if (goal != res) {
                r = m;
                pos = { l , m };
                continue;
            }

            fill(all(a), vector<char>(n, 'v'));

            for (int i = 0; i < n; ++i) {
                for (int j = l - 1; j < m; ++j) {
                    a[i][j] = (i & 1) ? '>' : '<';
                }
                if (i > 0 && (i & 1)) {
                    a[i][m - 1] = '^';
                }
                else {
                    a[i][l - 1] = '^';
                }
            }

            if (n & 1) {
                res = ask(n, m);
            }
            else {
                res = ask(n, l);
            }

            goal = { 1, l };

            if (a[goal.fi - 1][goal.se - 1] == '<') {
                goal.se--;
            }
            else if (a[goal.fi - 1][goal.se - 1] == '>') {
                goal.se++;
            }
            else if (a[goal.fi - 1][goal.se - 1] == '^') {
                goal.fi--;
            }
            else {
                goal.fi++;
            }

            dbg(l, r, m);
            dbg(res, goal);

            if (goal != res) {
                r = m;
                pos = { l , m };
                continue;
            }

            l = m + 1;
            pos = { m + 1, r };
        }
    }

    dbg(l, r, pos);
    int broke = pos.fi;
    char dir = '>';
    for (int i = pos.fi; i <= pos.se; ++i) {

        fill(all(a), vector<char>(n, 'v'));

        auto r1 = ask(1, i);

        fill(all(a), vector<char>(n, '^'));

        auto r2 = ask(n, i);

        if (r1 == ii{ n + 1, i } && r2 == ii{ 0, i }) continue;

        broke = i;

        if (r1 != ii{ n + 1, i }) {
            if (r1 == ii{ n + 1, i + 1 } || (i == n && r1.second == i + 1)) {
                dir = '>';
            }
            else if (r1 == ii{ n + 1, i - 1 } || (i == 1 && r1.second == i - 1)) {
                dir = '<';
            }
            else {
                if (r2 == ii{ 0, i }) {
                    dir = '^';
                }
                else {
                    dir = 'v';
                }
            }
        }
        else {
            dir = 'v';
        }
    }

    if (dir != '^') {
        for (int i = 0; i < n; ++i) a[i][broke - 1] = '^';

        int res = 1;
        int lo = 1, hi = n;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            auto r = ask(m, broke);
            if (r == ii{ -1ll, -1ll } || r != ii{ 0, broke }) {
                hi = m - 1;
                res = m;
            }
            else {
                lo = m + 1;
            }
        }
        cout << "! " << res << " " << broke << " " << dir << endl;
        cout.flush();
    }
    else {
        for (int i = 0; i < n; ++i) a[i][broke - 1] = 'v';

        int res = 1;
        int lo = 1, hi = n;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            auto r = ask(m, broke);
            if (r == ii{ -1ll, -1ll } || r != ii{ n + 1, broke }) {
                lo = m + 1;
                res = m;
            }
            else {
                hi = m - 1;
            }
        }
        cout << "! " << res << " " << broke << " " << dir << endl;
        cout.flush();
    }
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