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
const int N = 5e5 + 7;

int fw[N];

void add(int p, int v) {
    for (; p < N; p += p & -p) fw[p] += v;
}   

int get(int p) {
    int res = 0;
    for (; p > 0; p -= p & -p) res += fw[p];
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &c : a) cin >> c;

    vector<int> compress;
    for (int i = 0; i < n; ++i) compress.push_back(a[i]);
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());
    for (int i = 0; i < n; ++i) a[i] = lower_bound(all(compress), a[i]) - compress.begin();
    int mx = compress[compress.size()-2];
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) continue;
        add(i+1, 1);
    }

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            if (a[x] == mx) add(x+1, -1);
            if (a[x] != mx) add(x+1, 1);
            a[x] = lower_bound(all(compress), y) - compress.begin();
        } else {
            cout << (y-x+1) - (get(y) - get(x-1)) << '\n';
        }
        mx = compress[compress.size()-2];
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