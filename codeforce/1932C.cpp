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

int fpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> prd;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string s;
    cin >> s;
    
    int l = 0, r = n-1;
    vector<int> vt;
    rep (i, 0, n) {
        if (s[i] == 'L') {
            vt.push_back(l);
            l++;
        } else {
            vt.push_back(r);
            r--;
        }
    }
    int mul = 1;
    vector<int> res;
    for (int i = n-1; i >= 0; --i) {
        mul = (mul * a[vt[i]]) % m;
        res.push_back(mul);
    }
    reverse(all(res));
    for (auto &c : res) {
        cout << c << ' ';
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