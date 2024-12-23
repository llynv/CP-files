/*
  Code by: linvg
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;


#define int long long
#define ii pair<int, int>
typedef tree<ii, null_type, greater<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

int fen[N];
void add(int x, int v) {
    for (; x < N; x += x & -x) fen[x] += v;
}
int get(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += fen[x];
    return res;
}

void init(int n) {
    for (int i = 1; i <= n; ++i) fen[i] = 0;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    multiset<ii, greater<ii>> maxs;
    for (int i = 1; i < n; ++i) maxs.insert({a[i], i});
    cout << (a[0] + c < maxs.begin()->first ? 1 : 0) << ' ';

    int mx = a[0] + c, sum = a[0];
    for (int i = 1; i < n; ++i) {
        maxs.erase({a[i], i});
        if (a[i] < maxs.begin()->first) {
            if (a[i] + sum + c < maxs.begin()->first) {
                cout << i + 1 << ' ';
            } else {
                cout << i << ' ';
            }
        } else {
            if (a[i] <= mx) {
                cout << i << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        mx = max(mx, a[i]);
        sum += a[i];
    }
    cout << '\n';
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