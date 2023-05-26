#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f

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

int pw(int a, int b, int M)
{
    if (b == 1) return a;
    if (b&1) return (a * pw(a, b-1, M)) % M;
    int res = pw(a, b/2, M);
    return (res * res) % M;
    b >>= 1;
}

void solve()
{
    int a, b;
    
}