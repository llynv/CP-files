#include <bits/stdc++.h>
#define int long long

using namespace std;

int seed = chrono::steady_clock::now().time_since_epoch().count();

mt19937 rng(seed);

int bruth(int a, int b, int x, int y) {
    int ans = 0;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            int c1 = i, c2 = a - i;
            int c3 = j, c4 = b - j;
            ans = max(ans, min(c1 / x, c3 / y) + min(c2 / y, c4 / x));
        }
    }
    return ans;
}

int sol(int a, int b, int x, int y) {
    int c1 = a / x;
    int c2 = (a % x) / y;
    int c3 = a / y;
    int c4 = (a % y) / x;

    int c5 = b / y;
    int c6 = (b % y) / x;
    int c7 = b / x;
    int c8 = (b % x) / y;

    return max({ min(c1, c5) + min(c2, c6), min(c1, c6) + min(c2, c5), min(c3, c7) + min(c4, c8)});

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        a = rng() % 200, b = rng() % 200, x = rng() % 200, y = rng() % 200;
        // cin >> a >> b >> x >> y;

        cout << (bruth(a, b, x, y) == sol(a, b, x, y) ? "AC\n" : "WA\n");
        if (bruth(a, b, x, y) != sol(a, b, x, y)) {
            cout << a << " " << b << " " << x << " " << y << "\n";
            cout << bruth(a, b, x, y) << " " << sol(a, b, x, y) << "\n";
        }
        // cout << sol(a, b, x, y) << "\n";
    }
}
