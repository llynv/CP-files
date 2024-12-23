
/*
  Code by: linvg
  Created: 15.09.2024 21:57:16
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

int calc (int a, int b, int x, int y) {
    if (a >= x) return x;
    if (a < x && b >= y) return y;
    return 0;
}

void solve()
{
    int n;
    cin >> n;

    if (n <= 300) {
        vector<array<int, 2>> a(n);
        vector<int> top, bot;
        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1];
            top.push_back(a[i][0]);
            bot.push_back(a[i][1]);
        }
        sort(all(top));
        sort(all(bot));

        top.erase(unique(all(top)), top.end());
        bot.erase(unique(all(bot)), bot.end());

        int res = 0;
        for (int i = 0; i < sz(top); ++i) {
            int p = lower_bound(all(bot), top[i]) - bot.begin();
            for (int j = 0; j < p; ++j) {
                int sum = 0;
                for (auto [u, v] : a) {
                    sum += calc(u, v, top[i], bot[j]);
                }
                res = max(res, sum);
            }
        }
        cout << res << '\n';
    } else {
        bool isAllBotZero = true, isAllTopEQBot = true;
        vector<array<int, 2>> a(n);
        vector<int> top;

        for (int i = 0; i < n; ++i) {
            cin >> a[i][0] >> a[i][1];
            top.push_back(a[i][0]);
            if (a[i][1] != 0) isAllBotZero = false;
            if (a[i][0] != a[i][1]) isAllTopEQBot = false;
        }

        sort(all(top));
        top.erase(unique(all(top)), top.end());

        if (isAllBotZero || isAllTopEQBot) {
            vector<int> fix_a(n), fix_b(n);
            for (int i = 0; i < n; ++i) {
                fix_a[i] = a[i][0];
                fix_b[i] = a[i][1];
            }
            sort(all(fix_a));
            sort(all(fix_b));
            int res = 0;
            for (auto [t, tt] : a) {
                int p = lower_bound(all(fix_a), t) - fix_a.begin();
                int pp = lower_bound(all(fix_b), tt) - fix_b.begin();
                res = max(res, (n - pp) * tt + (n - p) * t);
            }
            cout << res << '\n';
        } 
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