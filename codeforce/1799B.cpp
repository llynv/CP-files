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
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    multiset<ii> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i - 1];
        cnt[a[i - 1]]++;
        s.insert({ a[i-1], i });
    }
    if (cnt.size() == 1) return void(cout << "0\n");
    if (cnt.size() != 1 && cnt[1] != 0) return void(cout << "-1\n");
    int total = 0;
    vector<ii> ans;
    while (s.begin()->fi != 1 && prev(s.end())->fi != s.begin()->fi) {
        auto itl = s.begin();
        auto itr = prev(s.end());
        int x = (int)ceil(1.0 * itr->fi / itl->fi);
        s.insert({ x, itr->se });
        s.erase(prev(s.end()));

        ans.pb({ itr->se, itl->se });
    }
    if (s.begin()->fi == 1) return void (cout << "-1\n");
    cout << sz(ans) << '\n';
    for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
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