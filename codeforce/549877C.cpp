
/*
  Code by: linvg
  Created: 14.09.2024 00:51:22
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
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
const int MOD = 1e8;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    set<array<int, 2>> nums;
    int cnt = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        cnt += (s[i] == '.');
        if (s[i] != '.') {
            if (cnt) {
                nums.insert({i - cnt + 1, i});
                res += cnt - 1;
                cnt = 0;
            }
        }
    }
    if (cnt) {
        nums.insert({n - cnt + 1, n});
        res += cnt - 1;
    }
    dbg(nums);

    while (q--) {
        int id;
        char c;
        cin >> id >> c;

        dbg(s[id - 1], c);

        if (s[id - 1] == c || (s[id - 1] != '.' && c != '.')) {
            cout << res << '\n';
            continue;
        }

        if (s[id - 1] != '.') {
            s[id - 1] = c;

            auto it = nums.lower_bound({id, -INF});
            int tt = 1;
            int newl = id, newr = id;

            auto [l, r] = *it;
            if (id == l - 1) {
                res -= r - l;
                tt += r - l + 1;
                newr = max(newr, r);
                newl = min(newl, l);
            }
            
            if (it != nums.begin()) {
                auto [u, v] = *prev(it);
                if (id == v + 1) {
                    res -= v - u;
                    tt += v - u + 1;
                    nums.erase(prev(it));
                    newl = min(newl, u);
                    newr = max(newr, v);
                }
            }
            res += tt - 1;
            nums.insert({newl, newr});
            if (id == l - 1) nums.erase(it);

            cout << res << '\n'; 
        } else {
            auto it = nums.lower_bound({id, INF});
            it = prev(it);
            auto [l, r] = *it;
            res -= r - l;

            s[id - 1] = c;

            if (id == l) {
                nums.erase(it);
                if (l != r) {
                    nums.insert({l + 1, r});
                    res += r - l - 1;
                }

                cout << res << '\n';

                dbg(nums);
                continue;
            }

            if (id == r) {
                nums.erase(it);
                if (l != r) {
                    nums.insert({l, r - 1});
                    res += r - l - 1;
                }

                cout << res << '\n';

                dbg(nums);
                continue;
            }

            int u = id - 1, v = id + 1;
            res += u - l;
            res += r - v;
            nums.erase(it);
            nums.insert({l, u});
            nums.insert({v, r});

            cout << res << '\n';

            dbg(id);
            dbg(*it);
        }
        dbg(nums);
    }
}   


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}