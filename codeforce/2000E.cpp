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
    int n, m, k, w;
    cin >> n >> m >> k >> w;    
    vector<int> rec(w);
    for (auto &d : rec) cin >> d;

    vector<vector<int>> rect(n+2, vector<int>(m+2));
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            rect[i-k+1][j-k+1] += 1;
            rect[i+1][j+1] += 1;
            rect[i-k+1][j+1] -= 1;
            rect[i+1][j-k+1] -= 1;
        }
    }

    vector<int> best;

    for (int i = 1; i <= n; ++i) rect[i][0] += rect[i-1][0];
    for (int i = 1; i <= m; ++i) rect[0][i] += rect[0][i-1];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            rect[i][j] += rect[i-1][j] + rect[i][j-1] - rect[i-1][j-1];
            best.pb(rect[i][j]);
        }
    }
    
    sort(best.begin(), best.end(), greater<int>());
    sort(rec.begin(), rec.end(), greater<int>());

    int kq = 0;
    for (int i = 0; i < w; ++i) {
        kq += best[i] * rec[i];
    }

    cout << kq << "\n";
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