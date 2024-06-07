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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> vst(n+1);

    vector<int> save;
    save.pb(x);
    int pre = 0, pos = 1;

    for (int i = 0; i < m; ++i) {
        int u;
        char c;
        cin >> u >> c;
        
        unordered_map<int, bool> mp;

        int ss = sz(save);
        pos = ss;
        if (c == '?') {
            for (int i = pre; i < ss; ++i) {
                int nxc = (save[i] + u) > n ? u + save[i] - n : (u + save[i]);
                int prc = (save[i] - u) <= 0 ? save[i] - u + n : save[i] - u;
                if (mp.find(nxc) == mp.end()) {
                    mp[nxc] = true;
                    save.pb(nxc);
                }
                if (mp.find(prc) == mp.end()) {
                    mp[prc] = true;
                    save.pb(prc);
                }
                dbg(nxc, prc);
            }
        } else if (c == '0') {
            for (int i = pre; i < ss; ++i) {
                int nxc = (save[i] + u) > n ? u + save[i] - n : (u + save[i]);
                dbg(nxc);
                if (mp.find(nxc) == mp.end()) {
                    mp[nxc] = true;
                    save.pb(nxc);
                }
            }
        } else {
            for (int i = pre; i < ss; ++i) {
                int prc = (save[i] - u) <= 0 ? save[i] - u + n : save[i] - u;
                dbg(prc);
                if (mp.find(prc) == mp.end()) {
                    mp[prc] = true;
                    save.pb(prc);
                }
            }
        }
        pre = ss;

        dbg(pre, sz(save));
    }
    dbg(pre, sz(save));
    set<int> st;
    for (int i = pos; i < sz(save); ++i) {
        st.insert(save[i]);
    }
    cout << st.size() << '\n';
    for (auto c : st) {
        cout << c << ' ';
    }
    cout << '\n';
    dbg("END\n");
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