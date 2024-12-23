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
const int N = 1e6 + 7;

struct segment
{
    int val, lazy;
} it[5 * N];

void build(int id, int l, int r)
{
    if (l == r) {
        it[id].val = INF;
        it[id].lazy = INF;
        return;
    }
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    it[id].val = INF;
    it[id].lazy = INF;
}

void down(int id, int l, int r)
{
    if (l == r) return;
    if (it[id].lazy == INF) return;
    it[id << 1].lazy = min(it[id << 1].lazy, it[id].lazy);
    it[id << 1 | 1].lazy = min(it[id << 1 | 1].lazy, it[id].lazy);
    it[id << 1].val = min(it[id << 1].val, it[id].lazy);
    it[id << 1 | 1].val = min(it[id << 1 | 1].val, it[id].lazy);
    it[id].lazy = INF;
}

void update(int id, int l, int r, int u, int v, int val)
{
    down(id, l, r);
    if (r < u || v < l) return;
    down(id, l, r);
    if (u <= l && r <= v) {
        it[id].val = min(it[id].val, val);
        it[id].lazy = min(it[id].lazy, val);
        down(id, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(id << 1, l, m, u, v, val);
    update(id << 1 | 1, m + 1, r, u, v, val);
    it[id].val = min(it[id << 1].val, it[id << 1 | 1].val);
}

int get(int id, int l, int r, int u, int v)
{
    down(id, l, r);
    if (r < u || v < l) return INF;
    down(id, l, r);
    if (u <= l && r <= v) return it[id].val;
    int m = (l + r) >> 1;
    return min(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
}


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    build(1, 0, n);
    update(1, 0, n, 0, 0, 0);
    update(1, 0, n, 1, a[0], 1);
    for (int i = 1; i < n; ++i) {
        int step = get(1, 0, n, i, i) + 1;
        if (a[i] == 0) continue;
        update(1, 0, n, i+1, min(i + a[i], n), step);
    }
    for (int i = 0; i <= n; ++i) {
        cerr << get(1, 0, n, i, i) << " ";
    }
    int res = get(1, 0, n, n, n);
    cout << (res == INF ? "CANNOT GET DESTINATION" : to_string(res)) << "\n";
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