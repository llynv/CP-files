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
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m % k != 0) return void (cout << "IMPOSSIBLE\n");
    int area = n * m / k;
    vector<int> f;
    for (int i = 1; i * i <= area; ++i) {
        if (area % i == 0) {
            f.pb(i);
            if (i * i != area) f.pb(area / i);
        }
    }
    sort(all(f));
    vector<vector<char>> ans(n, vector<char>(m, '.'));
    for (int i = 0; i < sz(f); ++i) {
        int a = f[i], b = area / a;
        if (n % a == 0 && m % b == 0) {
            char c = 'A';
            for (int i = 0; i < n; i += a) {
                for (int j = 0; j < m; j += b) {
                    for (int x = i; x < i + a; ++x) {
                        for (int y = j; y < j + b; ++y) {
                            ans[x][y] = c;
                        }
                    }
                    ++c;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << ans[i][j];
                }
                cout << '\n';
            }
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
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