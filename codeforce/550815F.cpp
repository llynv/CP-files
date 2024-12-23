
/*
  Code by: linvg
  Created: 18.09.2024 00:22:09
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
    int n, k;
    cin >> n >> k;
    if (k != 1) {
        int cur = 1, max = 1, step = 1;
        vector<int> res;
        while (max <= n) {
            // cout << cur << ' ';
            res.push_back(cur);
            // dbg(res);
            if (2 * max + 1 >= k && max < k) {
                
            }
            else {
                cur = max + 1;
            }
            max += cur;
        }
        if (cur) res.push_back(cur);
        cout << sz(res) << '\n';
        for (int i = 0; i < sz(res); ++i) cout << res[i] << " \n"[i == sz(res) - 1];
    }
    else {
        // vector<int> res = { 2, 3, 4 };
        // vector<int> avai = { 2, 3, 4, 5, 6, 7, 9 };
        // while (avai.back() < 1e6) {
        //     bool isOk = false;
        //     for (int i = 1; i < sz(avai); ++i) {
        //         if (avai[i] - avai[i - 1] > 1) {
        //             res.push_back(avai[i - 1] + 1);
        //             int x = sz(avai);
        //             vector<int> tmp;
        //             for (int j = 0; j < x; ++j) {
        //                 tmp.push_back(res.back() + avai[j]);
        //             }
        //             avai.insert(avai.end(), all(tmp));
        //             avai.push_back(avai[i - 1] + 1);
        //             sort(all(avai));
        //             avai.erase(unique(all(avai)), avai.end());
        //             isOk = true;
        //             break;
        //         }
        //     }
        //     if (!isOk) {
        //         res.push_back(avai.back() + 1);
        //         int x = sz(avai);
        //         vector<int> tmp;
        //         for (int j = 0; j < x; ++j) {
        //             tmp.push_back(res.back() + avai[j]);
        //         }
        //         avai.insert(avai.end(), all(tmp));
        //     }
        //     dbg(sz(res), res);
        //     sort(all(avai));
        //     avai.erase(unique(all(avai)), avai.end());

        //     dbg(sz(avai));
        //     dbg(avai.back());
        // }
        vector<int> res = {2, 3, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};
        cout << sz(res) << '\n';
        for (int i = 0; i < sz(res); ++i) cout << res[i] << " \n"[i == sz(res) - 1];
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}