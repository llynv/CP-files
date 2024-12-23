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
    int n;
    cin >> n;
    int mx = 0;

    auto ask = [&] (int a, int b, int c, int d) {
        cout << "? " << a << " " << b << " " << c << " " << d << endl;
        cout.flush();
        char x;
        cin >> x;
        return x;
    };

    for (int i = 1; i < n; ++i) {
        char x = ask(mx, mx, i, i);
        if (x == '<') {
            mx = i;
        } 
    }
    int sub = (mx == 0 ? 1 : 0);
    for (int i = 0; i < n; ++i) {
        if (i == mx) continue;
        char x = ask(i, mx, sub, mx);
        if (x == '>') {
            sub = i;
        } else if (x == '=') {
            char c = ask(i, i, sub, sub);
            if (c == '<') {
                sub = i;
            }
        }
    }
    cout << "! " << sub << " " << mx << '\n';
    cout.flush();
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