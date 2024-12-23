
/*
  Code by: linvg
  Created: 14.09.2024 16:48:40
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
    int n;
    cin >> n;
    map<int, vector<vector<int>*>> store;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            (store[x].size()) ? (*store[x].back()).push_back(i) : (store[x].push_back(new vector<int>(i)));
        } else {
            int x, y;
            cin >> x >> y;
            if (x == y) continue;
            for (auto v : store[x]) {
                store[y].push_back(v);
                dbg(*v);
            }
            store[x] = vector<vector<int>*>();
        }
    }
    vector<array<int, 2>> ans;
    for (auto [u, v]: store) {
        for (auto c : v) {
            for (auto d : *c) {
                ans.push_back({u, d});
            }
        }
    }
    sort(all(ans));
    for (auto [_, c] : ans) cout << c << ' ';
    cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
//    int t;
//    cin >> t;
//    while (t--)
   solve();
   return 0;
}