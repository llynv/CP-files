#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve();

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    // return 0;
}

// const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n, k;
    scanf("%lld%lld", &n, &k);
    vector<int> a(n+1);
    int s[4][4] = {0};
    int fsum = 0;
    for (int i = 1; i <= 3; ++i) {
        int x, y;
        // cout << "and " << i << " " <<  << "\n";
        printf("and %lld %lld\n", i, i % 3 + 1);
        fflush(stdout);
        scanf("%lld", &x);
        printf("or %lld %lld\n", i, i % 3 + 1);
        fflush(stdout);
        scanf("%lld", &y);

        s[i][i % 3 + 1] = x + y;
        fsum += x + y;
    }
    fsum /= 2;
    a[1] = fsum - s[2][3];
    a[2] = fsum - s[3][1];
    a[3] = fsum - s[1][2];
    for (int i = 4; i <= n; ++i) {
        int x = 0, y = 0;
        // cout << "and " << i << " " << (i + 1 == n ? 0 : i + 1) << "\n";
        printf("and %lld %lld\n", i-1, i);
        fflush(stdout);
        scanf("%lld", &x);
        // cout << "or " << i << " " << aft << "\n";
        printf("or %lld %lld\n", i-1, i);
        fflush(stdout);
        scanf("%lld", &y);
        fsum = x + y;
        a[i] = fsum - a[i-1];
    }
    sort(a.begin(), a.end());
    printf("finish %lld\n", a[k]);
    fflush(stdout);
}
