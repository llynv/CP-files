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
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    int n = sz(s);
    bool isQ = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            isQ = false;
            break;
        }
    }
    if (isQ) return void (cout << "0\n");
    
    if (x < y) {
        bool isX = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') s[i] = isX + '0';
            if (s[i] == '1' && !isX) {
                isX = true;
            }
        }
        dbg(s);
        int res = 0;
        int cnt = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                res += cnt * x;
            }
            cnt += (s[i] == '0');
        }
        cnt = (s[n-1] == '0' ? 1 : 0);
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '1') {
                res += cnt * y;
            }
            cnt += (s[i] == '0');   
        }
        cout << res << "\n";
    } else if (x > y) {
        bool isY = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') s[i] = isY + '0';
            if (s[i] == '0' && isY) {
                isY = false;
            }
        }
        dbg(s);
        int res = 0;
        int cnt = (s[0] == '1' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                res += cnt * y;
            }
            cnt += (s[i] == '1');
        }
        cnt = (s[n-1] == '1' ? 1 : 0);
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') {
                res += cnt * x;
            }
            cnt += (s[i] == '1');   
        }
        cout << res << "\n";
    } else {
        int tt0 = 0;
        for (auto &c : s) tt0 += (c == '0');
        char last = '1';
        if (tt0 > n - tt0) last = '0';
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') s[i] = last;
        }
        dbg(s);
        int res = 0;
        int cnt = (s[0] == '1' ? 1 : 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                res += cnt * y;
            }
            cnt += (s[i] == '1');
        }
        cnt = (s[n-1] == '1' ? 1 : 0);
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') {
                res += cnt * x;
            }
            cnt += (s[i] == '1');   
        }
        cout << res << "\n";
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
   solve();
   return 0;
}