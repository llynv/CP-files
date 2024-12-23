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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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
const int N = 1e6 + 7;

int prime[N];

void sieve() {
    for (int i = 2; i < N; ++i) {
        if (prime[i] == 0) {
            for (int j = i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (prime[i] == 0) prime[i] = i;
    }
}

unordered_map<int, int> factorize(int n) {
    unordered_map<int, int> factors;
    while (n > 1) {
        factors[prime[n]]++;
        n /= prime[n];
    }
    return factors;
}

void solve()
{
    sieve();
    int n;
    cin >> n;
    unordered_map<int, int> f;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto factors = factorize(x);
        for (auto [p, cnt] : factors) {
            f[p] += cnt;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, p;
        cin >> x >> p;
        auto factors = factorize(x);
        bool isOk = true;
        for (auto [c, cnt] : factors) {
            if (f[c] < cnt * p) {
                isOk = false;
                break;
            }
        }
        cout << isOk;
    }
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