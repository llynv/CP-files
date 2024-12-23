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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

vector<int> maxSubarray(vector<int> a) {
    int sum = 0, smin = 0, res = -111000111, sa = 0, isSa = false, maxE = a[0];
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
        if (a[i] >= 0) {
            sa += a[i];
            isSa = true;
        }
        maxE = max(maxE, a[i]);
        res = max(res, sum - smin);
        smin = min(smin, sum);
    }
    if (!isSa) {
        sa = maxE;
    }
    vector<int> vt;
    vt.emplace_back(res); vt.emplace_back(sa);
    return vt;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> vt = maxSubarray(a);
    cout << vt[0] << " " << vt[1] << "\n";
}