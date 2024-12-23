/*
  Code by: linvg
*/

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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

int fpow(int a, int b, int m) {
    if (b < 0) return 0;
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
const int N = 5011;

vector<int> fact, inv;

void precalc(int n, int p) {
    fact.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % p;
    }
    inv[n] = fpow(fact[n], p - 2, p);
    for (int i = n - 1; i >= 0; --i) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

int C(int n, int k, int p) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv[k] % p * inv[n - k] % p;
}

int P(int n, int k, int p) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv[n - k] % p;
}

void solve()
{
    int n, p;
    cin >> n >> p;

    precalc(n, p);

    int res = 0;
    for (int i = n / 2; i <= n - 2; ++i) {
        for (int j = 0; j <= n - i - 2; ++j) {
            res = res + ((C(n - i - 2, j, p) * fact[i + j - 1]) % p) * (2 * (n / 2) - i);
            res %= p;
        }
    }
    res *= n;
    res %= p;
    if (n % 2 == 0) {
        res += (n * fact[n - 2] )% p;

        res %= p;
    }
    cout << res << "\n";
}


int32_t main() {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}