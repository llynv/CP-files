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
    while (cin >> n) {
        int m;
        cin >> m;
        vector<int> a(n);
        for (auto &c : a) cin >> c;
        sort(a.begin(), a.end());
        int l = 0, r = a.size()-1;
        int lans = 0, rans = 0;
        while (l < r) {
            if (a[l] + a[r] == m) {
                lans = l;
                rans = r;
                l++;
                r--;
            } else if (a[l] + a[r] > m) 
                r--;
            else
                l++;
        }
        cout << "Peter should buy books whose prices are " << a[lans] << " and " << a[rans] << ".\n";
    }
}