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

void solve()
{
    int n, m;
    cin >> n >> m;
    int tn = n, tm = m;
    int n2 = 0, n5 = 0;
    while (n % 2 == 0) {
        n /= 2;
        n2++;
    }
    while (n % 5 == 0)
    {
        n /= 5;
        n5++;
    }

    if (n2 >= n5) {
        n2 -= n5;
        n5 = 0;
    } else {
        n5 -= n2;
        n2 = 0;
    }

    int mx = 1;
    while (mx * 2 <= m && n5 > 0) {
        n5--;
        mx *= 2;
    }
    while (mx * 5 <= m && n2 > 0)
    {
        n2--;
        mx *= 5;
    }

    while (mx * 10 <= m)
    {
        mx *= 10;
    }

    cout << mx * (int) (m / mx) * tn << '\n';
}


int32_t main() {

#ifdef LOCAL
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
   solve();
   return 0;
}