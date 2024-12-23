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
const int N = 1e5 + 7;

int fw[N];  

void update(int i, int v) {
    for (; i < N; i += i & -i) fw[i] += v;
}

int get(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += fw[i];
    return res;
}

vector<vector<int>> C(211, vector<int>(12));

void preCalc() {
    C[0][0] = 1;
    for (int i = 1; i < 200; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= 10; ++j) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}

void solve()
{
    preCalc();

    int n, k;
    cin >> n >> k;
    int res = 0;
    rep (i, 0, n) {
        int x;
        cin >> x;
        int e = get(x);
        if (e >= k) {
            res += C[e][k];
            cout << x << ' ' << e << " " << C[e][k] << endl;
        }
        update(x, 1);
    }
    cout << res << endl;
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