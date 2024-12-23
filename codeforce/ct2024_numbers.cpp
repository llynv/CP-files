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

int xx, f;

int rev_x(vector<int> s) {
    int res = 0;
    for (auto& c : s) {
        res = res * 10 + c;
    }
    return res;
}

vector<int> v_x(int x) {
    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(all(res));
    return res;
}

void dfs (vector<int> t, int x, int& res, int& cres, int dist = 0) {
    dbg(t, rev_x(t), x, res, cres, dist);
    if (!x && rev_x(t) == f) {
        return;
    }
    if (x && rev_x(t) == f) {
        dbg(t);
        res = min(res, dist);
        return;
    }
    if (dist > 20) return;
    vector<int> tmp = t;
    while (next_permutation(all(tmp))) {
        dfs(tmp, x ^ 1, res, cres, dist + 1);
    }
    int p = rev_x(t);
    if (p <= 9999) {
        ++p;
        dfs(v_x(p), x ^ 1, res, cres, dist + 1);
    }
}

void solve()
{
    cin >> xx >> f;

    vector<int> s = v_x(xx);

    int cres = INF;
    int res = INF;
    dbg(cres, res);
    dfs(s, 0, res, cres);
    cout << (res == INF ? -1 : res) << '\n';
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