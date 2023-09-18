#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
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
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    int s[3][3];
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) s[i][j] = 0;
    int fsum = 0;
    for (int i = 0; i < 3; ++i) {
        int x, y;
        // cout << "and " << i << " " <<  << "\n";
        printf("and %d %d\n", i, (i + 1 == 3 ? 0 : i + 1));
        fflush(stdout);
        scanf("%d", &x);
        printf("or %d %d\n", i, (i + 1 == 3 ? 0 : i + 1));
        fflush(stdout);
        scanf("%d", &y);
        s[i][(i + 1 == 3 ? 0 : i + 1)] = x + y;
        fsum += x + y;
    }
    fsum /= 2;
    a[0] = fsum - s[1][2];
    a[1] = fsum - s[2][0];
    a[2] = fsum - s[0][1];
    for (int i = 3; i < n; ++i) {
        int x, y;
        // cout << "and " << i << " " << (i + 1 == n ? 0 : i + 1) << "\n";
        printf("and %d %d\n", i-1, i);
        fflush(stdout);
        scanf("%d", &x);
        // cout << "or " << i << " " << aft << "\n";
        printf("or %d %d\n", i-1, i);
        fflush(stdout);
        scanf("%d", &y);
        fsum = x + y;
        printf("sum : %d %d\n", x, y);
        a[i] = x + y - a[i-1];
    }
    sort(a.begin(), a.end());
    printf("finish %d\n", a[k-1]);
    fflush(stdout);
}
