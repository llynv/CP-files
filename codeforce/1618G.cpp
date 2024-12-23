/*
  Code by: linvg
*/

// #pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

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

const int INF = 2e9 + 7;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m), cpy;
    int sum = 0;
    unordered_map<int, int> mp;
    for (auto& c : a) cin >> c, sum += c, mp[c]++, cpy.pb(c);
    for (auto& c : b) cin >> c, mp[c]++, cpy.pb(c);

    sort(all(a));
    sort(all(b));
    dbg(b);

    vector<ii> queries(q);
    for (int i = 0; i < q; ++i) {
        int p;
        cin >> p;
        queries[i] = { p, i };
    }

    sort(all(queries));
    vector<int> ans(q);

    unordered_map<int, int> nxt;

    sort(all(cpy));

    unordered_map<int, int> pos;
    for (int i = sz(cpy) - 1; i >= 0; --i) {
        pos[cpy[i]] = i;
    }
    map<int, vector<int>> events;
    for (int i = sz(cpy) - 1; i > 0; --i) {
        events[cpy[i] - cpy[i - 1]].pb(i);
    }

    vector<int> pref (sz(cpy) + 1, 0);
    vector<int> e(sz(cpy), -1), vers(sz(cpy), 0);
    for (int i = 0; i < sz(cpy); ++i) {
        pref[i + 1] = pref[i] + cpy[i];
        e[i] = i;
    }

    dbg(pos);
    dbg(cpy);

    set<ii> roots;

    unordered_map<int, pair<int, int>> range;
        
    for (int i = 0; i < sz(a); ++i) {
        roots.insert(pos[a[i]]);
        vers[pos[a[i]]] = 1;
        e[pos[a[i]]] = i;
        range[pos[a[i]]] = { pos[a[i]], pos[a[i]] };
        sum += a[i];
    }

    auto cmp = [&](ii x, ii y) {
        return abs(x.first - nxt[x.first]) >= abs(y.first - nxt[y.first]);
        };

    dbg(e);


    for (auto& [x, v] : events) {
        dbg(x, v);
        dbg(roots);
        for (auto& c : v) {
            auto itr = roots.upper_bound(make_pair(i, int(1e9)));
            auto itl = prev(itr);
            pair<int, int> pl = *itl;
            pair<int, int> pr = *itr;
            cur -= get(pcnt, psum, pl);
            cur -= get(pcnt, psum, pr);
            pair<int, int> p = make_pair(pl.first, pr.second);
            cur += get(pcnt, psum, p);
            roots.erase(pl);
            roots.erase(pr);
            roots.insert(p);

        }
        int ss = 0;
        dbg(e);
        dbg(range);
        for (auto& c : roots) {
            dbg(vers[e[c]]);
            ss += pref[range[c].second + 1] - pref[range[c].second - vers[e[c]] + 1];
        }
        dbg(ss);
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
