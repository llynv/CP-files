/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    if (n == 2) return void (cout << max(a[0]+a[1], 2 * abs(a[0]-a[1])) << '\n');
    if (n == 3) return void (cout << max({a[0]+a[1]+a[2], 2*abs(a[0]-a[1]) + a[2], 2*abs(a[1]-a[2]) + a[0], 3 * abs(a[0] - a[2]), 3 * abs(abs(a[0] - a[1]) - a[2]), 3 * abs(abs(a[1] - a[2]) - a[0]), abs(a[0] - a[1]) + 2 * abs(abs(a[0] - a[1]) - a[2]), abs(a[1] - a[2]) + 2 * abs(abs(a[1] - a[2]) - a[0]), 3 * a[0], 3 * a[2], abs(a[0] - a[1]) * 3, abs(a[1] - a[2]) * 3}) << '\n');
    cout << n * (*max_element(all(a))) << '\n';
}   


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}