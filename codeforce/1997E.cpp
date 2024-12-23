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
const int MOD = 1e8;
const int N = 2e5 + 7;

int fw[N];

void add(int i, int x) {
    for (; i < N; i += i & -i) {
        fw[i] += x;
    }
}

int get(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[i];
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> minK(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i-1];
        int l = 1, r = n, k = n;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (get(m) / m + 1 > a[i-1]) {
                l = m + 1;
            } else {
                k = m;
                r = m - 1;
            }
        }
        add(k, 1);
        minK[i] = k;
    }
    while (q--) {
        int i, k;
        cin >> i >> k;
        cout << (minK[i] <= k ? "YES" : "NO") << "\n";
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