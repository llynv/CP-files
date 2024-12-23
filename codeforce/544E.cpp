
/*
  Code by: linvg
  Created: 18.09.2024 16:30:02
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
    vector<vector<char>> s(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> s[i][j];
        }
    }
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(m + 1, vector<int>(1 << n + 1, INF)), calc(m + 1, vector<int>(1 << n + 1, INF));

    for (int i = 0; i < m; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            int tmp = 0;
            unordered_map<char, int> mp;
            for (int j = 0; j < n; ++j) {
                if (mask >> j & 1) {
                    tmp += a[j][i];
                    continue;
                }
                mp[s[j][i]]++;
            }
            int finalMask = mask;
            for (int j = 0; j < n; ++j) {
                if (mp[s[j][i]] == 1) {
                    finalMask |= (1 << j);
                }
            }
            calc[i + 1][finalMask] = min(calc[i + 1][finalMask], tmp);
            // dbg(mask, finalMask, tmp, i);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) dp[0][mask] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {            
            int submask = mask;
            while (submask > 0) {
                if (mask != submask) {
                    dbg(mask, submask, mask ^ submask);
                    dp[i][mask] = min(dp[i][mask], dp[i - 1][submask] + calc[i][submask ^ mask]);
                    dbg(calc[i][submask ^ mask]);
                    dbg(dp[i][mask]);
                }
                submask = (submask - 1) & m;
            }
        }
    }
    cout << *min_element(all(dp[m])) << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}