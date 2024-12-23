#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e7 + 11;

vector<int> uoc(N, 0);

void config(int n)
{
    for (int i = 1; i*i <= n; ++i){
        for (int j = i; j*i <= n; ++j){
            if (i * j > n) break;

            if (i != j)
                uoc[i*j] += i + j;
            else
                uoc[i*j] += i;
        }
    }
    for (int i = 1; i <= n; ++i)
        uoc[i] -= i;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int a, b;
    cin >> a >> b;
    config(b);
    long long res = 0;
    for (int i = a; i <= b; ++i)
        res += abs(i - uoc[i]);
    cout << res;
}
