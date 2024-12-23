#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

int MOD = 1e6 + 3;

int power (int a, int b)
{
    if (b == 0) return 1;
    int res = 1;
    for (int i = 1; i <= b; ++i) {
        res = (res * a) % MOD;
    }
    return res % MOD;
}

void solve()
{
    int n;
    cin >> n;
    cout << n-1 << "\n";
    cout << power(3, n-1);
}
