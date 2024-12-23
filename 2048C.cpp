/*
  Code by: linvg
  Created: 19.12.2024 21:47:05
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T gcd(initializer_list<T> __l) { int a = 0; for (auto x : __l) { a = gcd(a, x); } return a; }
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
const int MOD = 1e9 + 7;

string xor_s(string a, string& b) {
    string res;
    int i = sz(a) - 1, j = sz(b) - 1;
    while (i >= 0 && j >= 0) {
        res += (a[i] == b[j] ? '0' : '1');
        --i, --j;
    }
    while (i >= 0) {
        res += a[i];
        --i;
    }
    while (j >= 0) {
        res += b[j];
        --j;
    }
    reverse(all(res));
    return res;
}

void solve()
{
    string s;
    cin >> s;
    string t;
    string mxXor = s, curXor;
    pair<int, int> pivot;
    for (int i = 0; i < sz(s); ++i) {
        string t, curXor = s;
        int mov = sz(s) - 1;
        for (int j = i; j >= 0; --j) {
            curXor[mov] = (s[mov] == s[j] ? '0' : '1');
            --mov;
            if (curXor >= mxXor) {
                mxXor = curXor;
                pivot = { min(i, j), max(i, j) };
            }
        }
    }
    cout << "1 " << sz(s) << ' ' << pivot.first + 1 << ' ' << pivot.second + 1 << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}