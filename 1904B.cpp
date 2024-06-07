#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1001];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n;
        vector<int> b;
        cin >> a[0];
        bool check = true;
        for (int i = 1; i < n; ++i){
            cin >> k;
            if (a[i-1] - k >= 0 && k != 0){
                check = false;
            }
            a[i] = a[i-1] + k;
        }
        if (check){
            for (int i = 0; i < n; ++i)
                cout << a[i] << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}