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

void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    sort(all(a));

    auto calc = [&] (int v1, int v2, int v3, int x) -> int {
        queue<int> q;
        q.push(v1);
        q.push(v2);
        q.push(v3);

        int r2 = -1;
        for (int i = 0; i < n; ++i) {
            if (x <= a[i]) {
                while (!q.empty() && x <= a[i])
                {
                    x *= q.front();
                    q.pop();
                }
                if (x <= a[i]) {
                    r2 = i;
                    break;
                }
            }
            x += a[i] / 2;
        }
        r2 = (r2 == -1 ? n : r2);
        return r2;
    };

    cout << max({calc(2, 2, 3, h), calc(2, 3, 2, h), calc(3, 2, 2, h)}) << '\n';
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