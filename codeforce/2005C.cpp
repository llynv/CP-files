/*
  Code by: linvg
  Created: 14.09.2024 22:11:59
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int res = 0, mx = 0;
    for (auto &c : s) cin >> c;
    string target = "narek", cur;
    for (int i = 0; i < n; ++i) {
        int pre = res;
        string pre_cur = cur;
        bool isOk = false;
        int nxt = i;
        for (int k = i; k < min(n, i + 5); ++k) {
            for (int j = 0; j < s[k].size(); ++j) {
                if (target[sz(cur)] == s[k][j]) {
                    cur += s[k][j];
                    if (cur == target) {
                        res += 5;
                        cur = "";
                    }
                } else {
                    res -= (find(all(target), s[k][j]) - target.begin() != sz(target));
                }
            }
            if (res - sz(cur) >= pre) {
                pre = res;
                pre_cur = cur;
                nxt = k;
            }
        }
        res = pre;
        cur = pre_cur;
        i = nxt;
    }
    cout << res - sz(cur) << '\n';
    dbg(res);
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}