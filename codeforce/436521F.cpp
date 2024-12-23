
/*
  Code by: linvg
  Created: 12.09.2024 11:06:18
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
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<vector<int>> f(20, vector<int>(n+1));
    for (int i = 1; i <= n; ++i) f[0][i] = a[i-1];
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j + (1 << (i - 1)) <= n; ++j) {
            f[i][j] = max(f[i-1][j], f[i-1][j + (1 << (i - 1))]);            
        }
    }
    auto get = [&] (int l, int r) {
        if (l > r) return -1ll;
        int lg = log2(r - l + 1);
        return max(f[lg][l], f[lg][r - (1 << lg)]);
    };
    int sum = 0, mn = 0, pos = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (get(pos+1, i+1) < sum - mn) return void (cout << "NO\n");
        if (mn >= sum) {
            pos = i;
            mn = sum;
        }
    }
    cout << "YES\n";
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}