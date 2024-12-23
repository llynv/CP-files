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

const int INF = 0x3f3f3f3f3f;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    vector<int> pref(n+1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i-1] + a[i-1];
    }
    vector<int> cnt(n+2);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n, pos = n+1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (pref[m] - pref[i-1] > x) {
                r = m - 1;
                pos = m;
            } else {
                l = m + 1;
            }
        }
        cnt[pos] += cnt[i-1] + 1;
        res += (pos - i) * (cnt[i-1] + 1);
    }
    cout << res << "\n";
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