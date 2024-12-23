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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<ii> comp;
    for (int i = 0; i < n; ++i) comp.push_back({ a[i], b[i] });
    vector<ii> mp;
    map<int, ii> tmp;
    for (auto [x, y] : comp) {
        if (tmp.find(x-y) == tmp.end()) {
            tmp[x-y] = {x,y};
            continue;
        }
        tmp[x-y] = min(tmp[x-y], {x, y});
    }
    for (auto &[_, c] : tmp) mp.push_back(c); 
    priority_queue<int> p;
    unordered_map<int, int> tt;
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        tt[c]++;
        if (tt[c] == 1) p.push(c);
    }
    int res = 0;
    for (auto &[x, y]: mp) {
        while (p.size() && p.top() >= x) {
            dbg(p.top(), x, y);
            int t = p.top();
            p.pop();
            if (tt[t] == 0) continue;
            dbg((t - x) / (x - y) + 1);
            res += ((t - x) / (x - y) + 1) * tt[t];
            tt[t - ((t - x) / (x - y) + 1) * (x - y)] += tt[t];
            tt[t] = 0;
            p.push(t - ((t - x) / (x - y) + 1) * (x - y));
        }
    }
    cout << res * 2 << '\n';
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