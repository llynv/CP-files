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

string t[] = {"0", "1", "01", "10", "11"};

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> pref(2, vector<int>(n+1));
    for (int i = 0; i < n; ++i) {
        pref[0][i+1] = pref[0][i] + (s[i] == '0');
        pref[1][i+1] = pref[1][i] + (s[i] == '1');
    }

    dbg(pref[0], pref[1]);

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int id = 0; id < 5; ++id) {
                
                int cnt = (int) ceil((j-i+1) / 2.0) ;

                bool ok0 = false, ok1 = false;
                int n1 = 0, n0 = 0;
                ok0 = (pref[0][j+1] - pref[0][i] > 0);
                ok1 = (pref[1][j+1] - pref[1][i] > 0);
                int s1 = pref[1][j+1] - pref[1][i];
                int s0 = pref[0][j+1] - pref[0][i];
                for (auto &c : t[id]) {
                    n1 += (c == '1');
                    n0 += (c == '0');
                } 
                dbg(s, n0, n1, i, j, cnt, res);
                if (ok0 && ok1 && n1 && n0 && s1 >= cnt && s0 >= cnt) {
                    res += n1;
                    break;
                } else if (ok0 && n0 && !ok1 && !n1 && s0 >= cnt) {
                    res += n1;
                    break;
                } else if (ok1 && n1 && !ok0 && !n0 && s1 >= cnt) {
                    res += n1;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
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