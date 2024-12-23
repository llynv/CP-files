/*
  Code by: linvg
  Created: 28.09.2024 15:15:57
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
const int MOD = 1e9 + 7;


void solve()
{
    int n, x;
    cin >> n >> x;

    auto compute = [] (int n, int x) -> int {
        if (x <= n) return x * (x + 1) / 2;
        return n * (n + 1) / 2 + (n - 1) * (n - 1 + 1) / 2 - (2 * n - x - 1) * (2 * n - x) / 2;
    };

    int l = 1, r = 2 * n - 1, res = 2 * n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (compute(n, mid) >= x) {
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}