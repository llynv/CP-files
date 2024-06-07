#include <bits/stdc++.h>
#define int long long
#define fu(i, a, b) for (int i = a; i <= b; i++)
#define fd(i, a, b) for (int i = a; i >= b; i--)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
// #define double long double
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 3);
    fu(i, 1, n) {
        cin >> a[i];
    }
    int pos = -1;
    fu(i, 2, n) {
        if (a[i] > a[i - 1]) {
            pos = i - 1;
            break;
        }
    }

    double sum = a[pos];
    double res = 0;
    fd(l, pos - 1, 1) {
        sum += a[l];
        double tmp = sum;
        fu(r, pos + 1, n) {
            tmp += a[r];
            res = max(res, tmp / (r - l + 1));
        }
    }
    cout << fixed << setprecision(9) << res << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    freopen("template.inp", "r", stdin);
    freopen("template.ans", "w", stdout);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}