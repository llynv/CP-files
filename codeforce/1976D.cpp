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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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

const int N = 2e5 + 7;
 
struct tripe
{
    int results, open, close;
};
 
 
tripe it[4 * N];
string s;
 
 
void build (int index, int L, int R)
{
    if (L == R) {
        it[index].results = 0;
        it[index].open = (s[L-1] == '(');
        it[index].close = (s[L-1] == ')');
        return;
    }
 
    int mid = (L + R) / 2;
    build(2 * index, L, mid);
    build(2 * index + 1, mid + 1, R);
 
    tripe v1 = it[2 * index];
    tripe v2 = it[2 * index + 1];
 
    it[index].results = v1.results + v2.results + 2 * min(v1.open, v2.close);
    it[index].open = v1.open + v2.open - min(v1.open, v2.close);
    it[index].close = v1.close + v2.close - min(v1.open, v2.close);
}
 
tripe get (int index, int L, int R, int l, int r)
{
    if (R < l || L > r) {
        return {0, 0, 0};
    }
    if (l <= L && R <= r) {
        return it[index];
    }
 
    int mid = (L + R) / 2;
    tripe v1 = get(2 * index, L, mid, l, r);
    tripe v2 = get(2 * index + 1, mid + 1, R, l, r);
    // it[index].results = v1.results + v2.results + min(v1.open, v2.close);
    // it[index].open = v1.open + v2.open - min(v1.open, v2.close);
    // it[index].close = v1.close + v2.close - min(v1.close, v2.open);
    tripe res;
    res.results = v1.results + v2.results + 2 * min(v1.open, v2.close);
    res.open = v1.open + v2.open -  min(v1.open, v2.close);
    res.close = v1.close + v2.close - min(v1.open, v2.close);
    return res;
}


void solve()
{
    cin >> s;
    int n = sz(s);

    build(1, 1, n);

    vector<int> open(n + 1, 0), close(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        open[i] = open[i - 1] + (s[i - 1] == '(');
        close[i] = close[i - 1] + (s[i - 1] == ')');
    }
    int res = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int xo = open[j] - open[i], xc = close[j] - close[i];
            if (xo == xc && close[n] - close[j] - open[n] + open[j] >= get(1, 1, n, i + 1, j).close && open[i] - close[i] >= get(1, 1, n, i + 1, j).open) dbg(i, j);
            res += (xo == xc && close[n] - close[j] - open[n] + open[j] >= get(1, 1, n, i + 1, j).close && open[i] - close[i] >= get(1, 1, n, i + 1, j).open);
        }
    }
    cout << res << '\n';
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