
/*
  Code by: linvg
  Created: 15.09.2024 20:18:09
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

map<int, array<int, 2>> mp;

void solve()
{
    int n;
    cin >> n;
    auto [a, b] = mp[n];
    if (a == 0) {
        int l = 1e6 + 1, r = 1e18;
        while (l <= r) {
            int m = (l + r) / 2;
            long double total = 1;
            total += m;
            long double j = m;
            total += j * m;

            if (total > 1e18) {
                r = m - 1;
            } else if (total == n) {
                a = m;
                b = 2;
                break;
            } else if (total < n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (a == 0) {
            cout << "-1\n";
            return;
        }
    }
    cout << a << ' ' << b << '\n';
}

int xx = 0;

int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    for (int i = 2; i <= 1e6 + 1; ++i) {
        long double total = 1;
        int cnt = 1;
        for (long double j = i; total + j <= 1e18 + 9; j *= i, ++cnt) {
            total += j;
            if (cnt == 1) continue;
            if (mp[total][0] == 0) {
                mp[total] = {i, cnt};
            }
            ++xx;
        }
    }

   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}