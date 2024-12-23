/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e8;
const int N = 4e3 + 5;
int a[N], f[N][N];
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i + 1, n); ++j) {
            f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1];
        }
        int mn = a[i], mx = a[i];
        for (int j = i + 2; j <= n; ++j) {
            f[i][j] = a[i-1] * a[j-1] * (a[i-1] * a[j-1] >= 0 ? mx : mn) + f[i][j-1] + f[i-1][j] - f[i-1][j-1];
            mx = max(mx, a[j-1]);
            mn = min(mn, a[j-1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << f[r][r] - f[r][l-1] - f[l-1][r] + f[l-1][l-1] << '\n';
    }
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