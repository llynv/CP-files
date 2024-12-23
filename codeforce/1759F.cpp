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
const int MOD = 1e8;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b;
    int start = -1;
    unordered_map<int, int> mp;
    for (auto &c : a) {
        cin >> c;
        mp[c]++;
        start = c;
    }
    b = a;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int mx = p - 1, mn = start - 1;
    while (mp[mx]) --mx;
    while (mp[mn]) --mn;
    
    if (mx == -1 && mn == -1) return void (cout << "0\n");
    if (start <= mn || mn == -1) return void (cout << mx - start << '\n');
    int res = p - start;
    int ex = 1;
    b[n-1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (b[i] + ex == p) {
            b[i] = 0;
            mp[0] = 1;
            continue;
        }
        b[i]++;
        mp[b[i]] = 1;
        ex = 0;
        break;
    }
    if (ex == 1) {
        b.insert(b.begin(), 1);
        mp[1] = 1;
    }
    while (mp[mn]) --mn;
    if (mn == -1) return void (cout << res << '\n');
    cout << res + mn << '\n';
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