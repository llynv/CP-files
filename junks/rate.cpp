#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double

const int N = 300007;

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cout << (fixed) << setprecision(6);
    solve();
    return 0;
}

bool check (float mid, int n, int k, vector<int> a)
{
    float sum[n+1];
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; ++i) {
        sum[i] = float(a[i]) - mid + sum[i-1];
    }
    float amin = sum[0]; 
    for (int i = k; i <= n; ++i) {
        amin = min(amin, sum[i-k]);
        if (sum[i] >= amin) return true;
    }
    return false;
}

void solve()
{
    freopen("rate.inp", "r", stdin);
    freopen("rate.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    float ans = 0, lo = 0, hi = float(1000000), mid;
    for (int i = 0; i < 200; ++i) {
        mid = (lo + hi) / 2.0;
        if (check(mid, n, k, a)) {
            lo = mid;
            ans = mid;
        } else {
            hi = mid;
        }
    }
    cout << (fixed) << setprecision(6) << ans;
}