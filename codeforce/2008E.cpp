
/*
  Code by: linvg
  Created: 01.09.2024 22:14:35
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
    string s;
    cin >> s;
    vector<vector<vector<int>>> pref(2, vector<vector<int>>(26, vector<int>(n+3))), suf(2, vector<vector<int>>(26, vector<int>(n+3)));
    for (int i = 1; i <= n; i ++) {
        int id = (i & 1);
        pref[id][s[i-1]-'a'][i] = 1;
        for (int j = 0; j < 26; ++j) {
            pref[0][j][i] += pref[0][j][i-1];
            pref[1][j][i] += pref[1][j][i-1];
        }
        
    } 
    for (int i = n; i >= 1; i --) {
        int id = (i & 1);
        suf[id][s[i-1]-'a'][i] = 1;
        for (int j = 0; j < 26; ++j) {
            suf[0][j][i] += suf[0][j][i+1];
            suf[1][j][i] += suf[1][j][i+1];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
        int id = (i & 1);
        for (int j = 0; j < 26; ++ j) {
            if (n & 1) {
                r1 = max(r1, pref[id][j][i-1] + suf[id^1][j][i+1]);
                r2 = max(r2, pref[id^1][j][i-1] + suf[id][j][i+1]);
            } else {
                r3 = max(r3, pref[id][j][i] + suf[id][j][i+1]);
                r4 = max(r4, pref[id^1][j][i] + suf[id^1][j][i+1]);
            }
        }
        res = max({res, r1 + r2, r3 + r4});
    }
    cout << n - res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}