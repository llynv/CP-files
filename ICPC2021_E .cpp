#include <bits/stdc++.h>
using namespace std;

#define int long long
#define float double

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

double A, H;

float f()
{
    if (A == 100) return (5*H / 6 * 100); 
    if (A == 0) return (2*H/3 * 100);
    float x = (700 - 8*A) * H / (12 * (100 - A)); 
    if (x > H/3) return (2*H/3 * 100);
    if (x < H/6) {
        return A * (5*H/6);
    }
    return 2*H*(125-A) - 2*x*(125-A); 
}

void solve()
{
    cin >> A >> H;
    cout << fixed << setprecision(8) << f() << "\n";
}