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
const double EPS = 1e-9;
const double M_PI = 3.14159265358979323846;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int dist = sqr(a - 1);
    int ddist = sqr(b - 1);
   
    auto check_sqrt = [&](int x) {
        return sqr((int) sqrt(x)) == x;
    };

    int res = 0, bonus = 0;
    for (int y = 1; y < a - 1; ++y) {
        int x = dist - sqr(y);
        if (check_sqrt(x)) {
            double zangle = atan2(y, sqrt(x)) * 180 / M_PI;
            double zopangle = (90.0 - zangle) * M_PI / 180;
            double opside = sin(zopangle) * (b - 1); 
            if (fabs(opside - (int) opside) < EPS) {
                int xx = sqr(b - 1) - sqr((int) opside);
                if (check_sqrt(xx)) {
                    ++res;
                    if (a == b) bonus++;
                }
            }
        }
    }
    cout << res * 2 - bonus + (a != b ? 2 : 1) << '\n';
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