/*
  Code by: linvg
  Created: 13.09.2024 14:05:42
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
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int v, w;
            cin >> v >> w;
            adj[i].push_back({ v, w });
        }
    }

    vector<int> Z, sum(n + 1);
    vector<array<int, 2>> cnt(n + 1);
    int zero = 0, res = 0;
    auto dfs = [&](int u, auto&& dfs) -> void {
        for (auto& [v, w] : adj[u]) {
            if (w) {
                zero++;
                cnt[u][!w]++;
                zero %= MOD;
                if (sum[v]) {
                    zero += cnt[v][1];
                    zero %= MOD;
                    continue;
                }
            }
            else {
                if (sum[v]) {
                    cnt[v][1] %= MOD;
                    cnt[v][0] %= MOD;

                    res += zero * cnt[v][0];
                    res %= MOD;

                    continue;
                }

                res += zero;
                res %= MOD;
            }

            dfs(v, dfs);

            cnt[u][!w]++;
            cnt[u][0] += cnt[v][0];
            cnt[u][1] += cnt[v][1];
            if (cnt[u][0]) sum[u] = 1;
            cnt[u][0] %= MOD;
            cnt[u][1] %= MOD;
        }

        dbg(u, cnt[u][0], cnt[u][1]);
        
        };
    dfs(1, dfs);

    dbg(zero);

    cout << res << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}