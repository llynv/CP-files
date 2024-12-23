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

void solve()
{
    int n, m;
    cin >> n >> m;


    if ((n ^ m) < n) {
        cout << "1\n" << n << " " << m << '\n';
        return;
    }

    int tmp = 0;
    vector<int> pos;

    for (int i = 0; i < 63 - __builtin_clzll(n); ++i) {
        if ((m >> i & 1) || (n >> i & 1)) {
            // pos.pb(i);
            tmp |= (1LL << i);
        }
    }
 

    for (int i = 0; i < 64 - __builtin_clzll(tmp); ++i) {
        if (!(m >> i & 1) && (n >> i & 1)) {
            pos.pb(i);
        }
    }


    if ((tmp ^ n) >= n) return void (cout << "-1\n");
 
    sort(all(pos), greater<int>());
 
    queue<int> q;
    q.push(tmp);
 
    int check = tmp, x = tmp;
    for (auto &c : pos) {
        if ((check ^ (1LL << c)) >= check) return void (cout << "-1\n");
        check ^= (1LL << c);
    }
    if (check != m) return void (cout << "-1\n");
 
    dbg(pos);
 
    cout << sz(pos)+1 << '\n' << n << ' ' << x << ' ';
 
    for (auto &c : pos) {
        x ^= (1LL << c);
        cout << x << ' ';
    }
    cout << '\n';

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