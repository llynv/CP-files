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
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int l = 1, r = n+1;
    set<int> s;
    while (r - l > 1) {
        int m = (l + r) / 2;
        s.insert(a[m]);
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    dbg(s);
    dbg(a[l]);
    if (a[l] == x) return void (cout << "0\n");

    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == x) p = i;
    }

    if (s.find(x) == s.end()) {
        cout << "1\n";
        cout << p << ' ' << l << '\n';
    } else {
        int p1 = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < x && s.find(a[i]) == s.end()) {
                p1 = i;
                break;
            }
        }
        if (p1 == 0) {
            cout << "1\n";
            cout << l << ' ' << p << '\n';
            return;
        }   
        cout << "2\n";
        cout << p1 << ' ' << p << '\n';
        cout << l << ' ' << p1 << '\n';
    }
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