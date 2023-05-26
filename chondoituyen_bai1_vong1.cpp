#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 2000007;
int slq[M], slr[M], a[M];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, P, Q, R;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];   
    cin >> P >> Q >> R;

    for (int i = 1; i <= n; ++i) {
        slq[i] = slq[i-1] + (a[i] == P);
        slr[n-i+1] = slr[n-i+2] + (a[n-i+1] == R);
    }
    
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == Q) {
            res += (slq[i-1] * slr[i+1]);
            //cout << slq[i-1] << " " << slr[i+1] << "\n";
        }
        
    }
    cout << res;
}   