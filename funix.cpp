#include <bits/stdc++.h>
#define int long long

using namespace std;

int res = 0, t[37], p, x[37];

void get (int j, int n, int nxt, int k, int sum)
{
    if (j == n) {
        res += (sum == k);
        if (res == p) {
            for (int i = 0; i < j; i++) {
                cout << x[i];
            }
        }
        return;
    }

    for (int i = nxt; i <= k - sum; ++i) {
        x[j] = i;
        get(j+1, n, i+1, k, sum + i);
    }
}

int32_t main()
{
    
}