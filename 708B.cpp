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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int delta = 1 + 8 * d;
    if (sqr((int)(sqrt(delta))) != delta) {
        cout << "Impossible\n";
        return;
    }
    if ((int) sqrt(delta) % 2 == 0) {
        cout << "Impossible\n";
        return;
    }
    int x = (1 + sqrt(delta)) / 2;
    vector<char> str (x, '1');
    delta = 1 + 8 * a;
    if (sqr((int)(sqrt(delta))) != delta) {
        cout << "Impossible\n";
        return;
    }
    if ((int) sqrt(delta) % 2 == 0) {
        cout << "Impossible\n";
        return;
    }
    int y = (1 + sqrt(delta)) / 2;
    dbg(x, y);
    int s1 = 0, s2 = 0;
    vector<int> pos;
    int cnt = y;
    for (int i = 0; i <= x; ++i) {
        while (cnt > 0 && s1 + (x - i) <= b && s2 + i <= c) {
            // str[i - 1] = '0';
            pos.pb(i);
            s1 += x - i;
            s2 += i;
            --cnt;
        }
    }
    if (s1 != b || s2 != c) {
        cout << "Impossible\n";
        return;
    }
    dbg(s1, s2);
    int step = 0;
    bool isInc = false;
    for (int i = 1; i < sz(pos); ++i) {
        if (pos[i] > pos[i - 1]) {
            isInc = true;
            break;
        }
    }
    for (int i = 0; i < sz(pos); ++i) {
        str.insert(str.begin() + pos[i] + (isInc ? step : 0), '0');
        step ++;
    }  

    unordered_map<int, int> mp;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < sz(str); ++i) {
        mp[str[i]]++;
        if (str[i] == '1') cnt1 += mp['0'];
        else cnt0 += mp['1'];
    }
    dbg(cnt1, cnt0);
    dbg(pos);
    
    if (str.empty()) cout << "1\n";
    if (b == 0 && c == 0) {
        if (a != 0 && d != 0) return void (cout << "Impossible\n");
        if (a != 0) {
            for (int i = 0; i < y; ++i) cout << "0";
        } else {
            for (int i = 0; i < x; ++i) cout << "1";
        }
        return;  
    }
    for (auto i : str) cout << i;
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