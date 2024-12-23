
/*
  Code by: linvg
  Created: 01.09.2024 22:01:31
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
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    string s;
    cin >> s;
    vector<int> f(n+1);
    vector<int> vis(n+1);
    for (int i = 1; i <= n; ++i) {
        if (f[i]) continue;
        int x = i;
        vector<int> cycle;
        int cnt = 0;
        while (!vis[x]) {
            vis[x] = 1;
            x = a[x];
            cnt += (s[x-1] == '0');
            cycle.push_back(x);
        }
        for (auto &c : cycle) f[c] = cnt;
    }
    for (int i = 1; i <= n; ++i) cout << f[i] << ' ';
    cout << '\n';
}


int32_t main() {
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}