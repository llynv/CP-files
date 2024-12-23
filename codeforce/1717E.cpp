#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }

// #define DBG

#ifdef DBG
#include "debug.h"
#else
#define dbg(...)
#endif
const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;   

int phi[N];

void sieve() {
    for (int i = 2; i < N; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i < N; ++i) {
        if (phi[i] == i)
        {
            for (int j = i; j < N; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    // for (int i = 1; i < N; ++i) {
    //     phi[i] += phi[i-1];
    //     phi[i] %= mod;
    // }
}

int C2 (int n)
{
    return n * (n - 1) / 2LL;
}

void solve()
{
    int n;
    cin >> n;

    // for (int i = 1; i <= 5; ++i) {
    //     dbg(i, phi[i]);

    vector<int> a(n);
    for (auto &c : a) {
        cout << &c - &a[0] << "\n";
    }
    // }   

    int ans = 0;
    for (int c = 0; c <= n; ++c) {
        int ab = n - c;
        // k | ab
        // num(k) * lcm(c, k) 
        // phi[n]
        for (int k = 1; k * k <= ab; ++k) {
            if (ab % k != 0) continue;

            int limit = ab / k; 
            // dbg(k, limit);
            ans += lcm(c, k) * phi[limit];
            ans %= mod;


            // dbg(c, k, lcm(c, k), phi[limit], limit);

            if (k*k != ab) {
                limit = k;
                ans += lcm(c, ab / k) * phi[limit];
                ans %= mod;
            }
        }
    }
    cout << ans << "\n";
}



int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    sieve();
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}