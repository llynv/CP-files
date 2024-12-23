
/*
  Code by: linvg
  Created: 01.09.2024 23:14:04
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
    vector<int> a(n);
    int _gcd = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], _gcd = gcd(_gcd, a[i]);
    if (_gcd == 1) {
        cout << n + k - 1 << '\n';
        return;
    }
    vector<int> f;
    if (n == 1) {
        f.push_back(_gcd);
    } else {
        for (int i = 0; i < n; ++i) {
            f.push_back(i * _gcd);
        }
    }
    f.erase(unique(all(f)), f.end());
    dbg(f);
    int cur = k - 1;
    while (binary_search(all(f), cur)) cur++;
    cout << cur << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}