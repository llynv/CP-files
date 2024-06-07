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
    int n, m;
    cin >> n >> m;
    int mx = 0;
    vector<int> a(n);
    iota(all(a), 1);
    do {
        int total = 0;
        for (int i = 0; i < sz(a); ++i) {
            int mn = a[i];
            for (int j = i; j < sz(a); ++j) {
                mn = min(mn, a[j]);
                total += mn;
            }
        }
        mx = max(mx, total);
    } while (next_permutation(all(a)));
    int cnt = 0;
    do {
        int total = 0;
        for (int i = 0; i < sz(a); ++i) {
            int mn = a[i];
            for (int j = i; j < sz(a); ++j) {
                mn = min(mn, a[j]);
                total += mn;
            }
        }
        cnt += (total == mx);

        cout << total << '\n';
        for (auto &c : a) cout << c << ' ';
        cout << '\n';

        if (cnt == m) return;
    } while (next_permutation(all(a)));

}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   // int t;
   // cin >> t;
   // while (t--)
   solve();
   return 0;
}