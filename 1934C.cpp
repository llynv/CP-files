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
    int n, m;
    cin >> n >> m;
    auto ask = [&](int x, int y) {
        cout << "? " << x << ' ' << y << endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
        };

    int c = ask(1, 1), c1 = ask(1, m), c2 = ask(n, 1);

    int x1 = (c - c1 + m - 1);
    if (x1 % 2 == 0) {
        x1 /= 2;
        dbg(c, x1);
        int y1 = c - x1 + 1;
        if (y1 <= 0 || ask(y1, x1+1) != 0) {
            int x2 = (c + c2 - n + 1);
            x2 /= 2;
            dbg(c, x2);
            cout << "! " << c - x2 + 1 << ' ' << x2 + 1 << '\n';
            cout.flush();
            return;
        }
        cout << "! " << y1 << ' ' << x1 + 1 << '\n';
        cout.flush();
    }
    else {
        int x2 = (c + c2 - n + 1);
        x2 /= 2;
        cout << "! " << c - x2 + 1 << ' ' << x2 + 1 << '\n';
        cout.flush();
    }
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