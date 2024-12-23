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
#define vector2d(var, y, z, type, x) vector<vector<type>> var(y, vector<type>(z, x))
#define vector3d(var, y, z, w, type, x) vector<vector<vector<type>>> var(y, vector<vector<type>>(z, vector<type>(w, x)))
#define vector4d(var, y, z, w, u, type, x) vector<vector<vector<vector<type>>>> var(y, vector<vector<vector<type>>>(z, vector<vector<type>>(w, vector<type>(u, x)))

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

int hexToDec(string s) {
    int res = 0;
    for (char c : s) {
        res = res * 16 + (isdigit(c) ? c - '0' : c - 'A' + 10);
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> s(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> s[i];
    }
    map<tuple<int, int, int>, int> mp;

    auto convert = [&] (string s) -> tuple<string, string, string> {
        string a, b, c;
        for (int i = 1; i <= 2; ++i) {
            a += s[i];
            b += s[i + 2];
            c += s[i + 4];
        }
        return {a, b, c};
    };

    for (int i = 0; i < n; ++i) {
        auto [a, b, c] = convert(s[i]);
        auto [d, e, f] = convert(s[i + n]);
        int x = hexToDec(a);
        int y = hexToDec(b);
        int z = hexToDec(c);
        int u = hexToDec(d);
        int v = hexToDec(e);
        int w = hexToDec(f);
        // dbg(a, b, c, d, e, f);
        // dbg(x, y, z, u, v, w);
        mp[{(u - x + 256) % 256, (v - y + 256) % 256, (w - z + 256) % 256}]++;
    }

    int ans = 0;
    for (auto [k, v] : mp) {
        // cerr << get<0>(k) << " " << get<1>(k) << " " << get<2>(k) << " " << v << endl;
        ans = max(ans, v);
    }
    cout << fixed << setprecision(2) << ans * 100.0 / n << "%\n";
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