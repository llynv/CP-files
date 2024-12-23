#include <iostream>
using namespace std;

#define ll long long

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    int pday = (x * 10LL + y * 12LL + z * 5LL);
    int total = pday * 31LL * 2000LL;
    cout << total << "\n";
    for (int i = 1; i <= 12; ++i) {
        cout << pday * days[i] * 2000LL << " ";
    }
    cout << "\n";
    int X = 300, Y = 500, Z = 700;
    int elt = (X * 10LL + Y * 12LL + Z * 5LL);
    int volumn = elt * 31, bill = 0;
    if (volumn <= 50) {
        bill = volumn * 2000LL;
    }
    else if (volumn <= 100) {
        bill = 50 * 31 * 2000LL + (volumn - 50) * 31 * 2200LL;
    }
    else {
        bill = 50 * 31 * 4200LL + (volumn - 100) * 31 * 2500LL;
    }
    cout << bill;
}
