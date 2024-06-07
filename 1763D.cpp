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
const int N = 101;
const int MOD = 1e9+7;

int fact[N], inv[N];

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precalc() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) fact[i] = fact[i-1] * i % MOD;
    inv[N-1] = powmod(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; --i) inv[i] = inv[i+1] * (i+1) % MOD;
}

int C(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

void solve()
{
    int n, u, v, x, y;
    cin >> n >> u >> v >> x >> y;

    if (x > y) {
        
        int u1 = n - v + 1;
        int v1 = n - u + 1;

        u = u1;
        v = v1;
        swap(x, y);
    }

    int res = 0; // n ..... y : 5;
    // ..u....i....v...
    // y-x-1 + 1
    // C (y-x-1 + (5-4) , (i-u-1))
    if (y == n) {
        if (v == n) {
            res = 0;
        } else {
            res = C(x-1, u-1) * C(y-x-1, v-u-1);
            res %= MOD;
        }
    } else {
        for (int i = u+1; i < v; ++i) {
            res += C(x-1, u-1) * C(y-x-1, i-u-1 - max(0LL, n-y-v+i)) % MOD * C(n-y-1, v-i-1);
            res %= MOD;
        }

        for (int i = v+1; i < n; ++i) {
            res += C(x-1, u-1) * C(y-x-1, v-u-1) % MOD * C(n-y-1, i-v-1);
            res %= MOD;
        }
    }

    cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    precalc();

   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}