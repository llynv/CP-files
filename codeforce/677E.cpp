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
const int mod = 1e9 + 7;

int minx[2011];

void sieve() {
    int cnt2 = 1, cnt3 = 1, val2 = 2, val3 = 3, cnt = 1;
    minx[1] = 0;
    for (int i = 2; i <= 2007; ++i) {
        val2 *= 2;
        if (val2 >= mod) {
            cnt2 += val2 / mod;
            val2 %= mod;
        }
        while (cnt3 <= cnt2 && val3 < val2)
        {
            val3 *= 3;
            if (val3 >= mod) {
                cnt3 += val3 / mod;
                val3 %= mod;
            }
            cnt++;
        }
        minx[i] = cnt-1;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (auto &c : a) for (auto &x : c) cin >> x;   

    vector<vector<int>> cnt2dd(n+n), cnt2du(n+n), cnt3dd(n+n), cnt3du(n+n), cnt2d(n+n), cnt3d(n+n);

    vector<vector<int>> id(n, vector<int>(n, -1));

    vector<vector<int>> zero(n+n), zerod(n), zerou(n);

    int x = n-1, y = 0;
    bool isInc = true;
    for (int i = 0; i < n+n-1; ++i) {
        cnt2[i].push_back(0);
        cnt3[i].push_back(0);
        int u = x, v = y;
        while (u < n && v < n) {
            cnt2[i].push_back(a[u][v] == '2' + cnt2[i].back());
            cnt3[i].push_back(a[u][v] == '3' + cnt3[i].back());
            id[u][v] = i;
            if (a[u][v] == 0) zero[i].push_back(u * n + v);
            ++u;
            ++v;
        }

        dbg(x, y);

        if (x == 0) isInc = false;

        x -= isInc ? 1 : 0;
        y += isInc ? 0 : 1;
    }

    for (int i = 0; i < n; ++i) {

    }

    for (int i = 0; i < n+n-1; ++i) {
        dbg(i, cnt2[i], cnt3[i]);
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
   sieve();
   solve();
   return 0;
}