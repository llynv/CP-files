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
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);   
    map<ii, int> mp;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{ min(u, v), max(u, v) }] = i;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto cmp = [&] (ii u, ii v) -> bool {
        if (u.first > 1 && v.first > 1) return u.first < v.first;
        if (u.first == 1 && v.first == 1) return u.second < v.second;
        return u.first > v.first;
    };

    set<ii, decltype(cmp)> total(cmp);
    for (int i = 0; i < n; ++i) {
        auto pos = total.lower_bound({ 0, a[i] });
        if (pos == total.end()) {
            total.insert({ 1, a[i] });
        } else {
            auto [cnt, val] = *pos;
            total.erase(pos);
            total.insert({ cnt+1, a[i],  });
        }
    }

    vector<int> ans (n-1, 0);

    auto dfs = [&] (int u, int p, auto&&dfs) -> set<ii, decltype(cmp)> {
        set<ii, decltype(cmp)> s(cmp);
        for (auto &c : adj[u]) {
            if (c == p) continue;
            auto t = dfs(c, u, dfs);
            if (sz(t) < sz(s)) {
                for (auto [cnt, val] : t) {
                    auto pos = s.lower_bound({ 0, val });
                    if (pos == s.end()) {
                        s.insert({ cnt, val });
                    } else {
                        auto [cnt2, val2] = *pos;
                        s.erase(pos);
                        s.insert({ cnt+cnt2, val });
                    }
                }
            }
        }

        auto pos = total.lower_bound({ 0, a[u-1]});
        if (pos != total.end()) {
            auto [cnt, val] = *pos;
            total.erase(pos);
            total.insert({ cnt-1, a[u-1] });
        }

        pos = s.lower_bound({ 0, a[u-1] });
        if (pos == s.end()) {
            s.insert({ 1, a[u-1] });
        } else {
            auto [cnt2, val2] = *pos;
            s.erase(pos);
            s.insert({ cnt2+1, a[u-1] });
        }

        dbg(u);
        dbg(s);
        dbg(total);

        if (p != 0) {
            ans[mp[{ min(u, p), max(u, p) }]] = (s.begin()->first == 1) ? 0 : s.begin()->second;
        }

        return s;
    };

    auto s = dfs(1, 0, dfs);
    dbg(s);
    dbg(ans);
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