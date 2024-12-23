#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 100007;

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

bool isPrime(int n)
{
    if (n <= 2) return false;
    if (n <= 4) return true;
    
}

void solve()
{
    
}