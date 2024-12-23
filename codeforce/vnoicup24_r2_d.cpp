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

int kmp (string s, string t) {
    s = t + "#" + s;
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    int res = 0;
    for (int i = sz(t) + 1; i < n; ++i) {
        if (pi[i] == sz(t)) ++res;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = sqr(kmp(s, "OK")) - sqr(kmp(s, "KO"));
    vector<int> O, K;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'O') {
            if (sz(O) > 30) continue;
            if (sz(O) > 3 && O[sz(O) - 3] == i-3 && i < n - 1 && s[i+1] != 'K') continue;
            O.pb(i);
        } else {
            if (sz(K) > 30) continue;
            if (sz(K) > 3 && K[sz(K) - 3] == i-3 && i < n - 1 && s[i+1] != 'O') continue;
            K.pb(i);
        }
    }
    for (int i = 0; i < sz(O); ++i) {
        for (int j = 0; j < sz(K); ++j) {
            swap(s[O[i]], s[K[j]]);
            ans = max(ans, sqr(kmp(s, "OK")) - sqr(kmp(s, "KO")));
            swap(s[O[i]], s[K[j]]);
        }
    }
    cout << ans << "\n";
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
