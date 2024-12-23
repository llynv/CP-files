#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
void DBVT (T (&arr)) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Vector[" << i+1 << "] = " << arr[i] << "\n";
    }
}

template<typename T, int N>
void DBARR (T (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cout << "Array[" << i+1 << "] = " << arr[i] << "\n";
    }
}

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), f(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    f[0] = 0;
    f[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; ++i) {
        f[i] = min(abs(a[i] - a[i-1]) + f[i-1], abs(a[i] - a[i-2]) + f[i-2]);
    }
    // DBVT(f);
    cout << f[n-1];
}