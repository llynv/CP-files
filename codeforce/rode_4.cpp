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
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    vector<int> b = a;
    vector<int> pos;
    for (int i = 1; i <= n; ++i) pos.push_back(i % n);
    vector<vector<int>> T;
    T.push_back(a);
    map<vector<int>, bool> mp;
    int TT = 0;
    for (int i = 1; i < m; ++i) {
        int c0 = 0;
        for (int j = 0; j < n; ++j) {
            a[j] = T.back()[j] ^ T.back()[(j + 1) % n];
            c0 += a[j] == 0;
        }
        dbg(a);
        if (mp[a]) {
            TT = i - mp[a] - 1;
            break;
        }
        mp[a] = i;
        T.push_back(a);
    }
    dbg(TT, T.size(), m);
    dbg(T);
    int id = (m - (T.size() - TT) + 1) % TT;
    cerr << id << '\n';
    dbg(T[id]);
    
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