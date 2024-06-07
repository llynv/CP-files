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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * n);
    map<int, int> mp;
    unordered_map<int, vector<int>> vt;

    for (int i = 0; i < n * n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
        vt[a[i]].pb(i);
    }

    dbg(a);
    dbg(mp);

    auto cmp = [&](ii b, ii d) {
        return b.fi > d.fi;
        };

    multiset<ii, decltype(cmp)> s(cmp);
    for (auto& c : mp) {
        s.insert({ c.se, c.fi });
    }

    dbg(s);

    vector<int> ans(n * n);

    for (int i = 1; i <= n; ++i) {
        int amt = s.rbegin()->fi;
        if (amt >= n) {
            int tmp = amt - n, pre = amt;
            amt = n;
            while (amt > 0)
            {
                ans[vt[s.rbegin()->se].back()] = i;
                vt[s.rbegin()->se].pop_back();
                amt--;
            }

            int id = s.rbegin()->se;
            s.erase(prev(s.end()));
            if (tmp != 0) s.insert({ tmp, id });
            dbg(1, s);
        }
        else {
            int att = amt;
            while (att) {
                ans[vt[s.rbegin()->se].back()] = i;
                vt[s.rbegin()->se].pop_back();
                att--;
            }
            s.erase(prev(s.end()));
            int tmp = amt;
            amt = n - amt;

            while (amt > 0)
            {
                ans[vt[s.begin()->se].back()] = i;
                vt[s.begin()->se].pop_back();
                amt--;
            }

            int id = s.begin()->se, nums = s.begin()->fi - n + tmp;
            s.erase(s.begin());
            s.insert({ nums, id });
            dbg(2, s);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n * n; ++i) {
        cout << ans[i] << " ";
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