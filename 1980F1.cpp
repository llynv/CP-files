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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<ii> a(k);
    for (auto &c : a) cin >> c.fi >> c.se;

    vector<ii> b = a;

    sort(all(a), [&](ii x, ii y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    });

    for (int i = 1; i < k; ++i) {
        if (a[i].first == a[i-1].first) {
            a[i].second = a[i-1].second;    
        }
    }

    vector<int> minX(k+1, INF);
    for (int i = k - 1; i >= 0; --i) {
        minX[i] = min(minX[i + 1], a[i].second);
    }
    
    map<int, int> effectF;
    for (int i = 0; i < k; ++i) {
        effectF[minX[i]] = max(effectF[minX[i]], a[i].first);
    }

    int ans = 0, x = 1;
    while (effectF.count(x) != 0) x++;
    
    for (auto &c : effectF) {
        int area = (c.first - 1) * (c.second - x + 1);
        ans += area;
        dbg(area);
        x = c.second + 1;
    }

    if (effectF[m] != n) {
        ans += m * (n - x + 1);
        dbg(m * (n - x + 1));
    }

    dbg(effectF);

    cout << ans << "\n";
    
    for (int i = 0; i < k; ++i) {
        if (effectF[b[i].second] == b[i].first) {
            auto it = effectF.find(b[i].second);
            auto itl = it;
            auto itr = it;
            itl--;
            itr++;
            if (itr == effectF.end()) {
                if (effectF[m] != n) {
                    cout << (m - itl->first + 1) * (n - b[i].first + 1) << ' ';
                } else {
                    cout << (m - itl->first + 1) * (it->first - itl->first + 1) << ' ';
                }
            } else {
                cout << (it)
            }
        } else {
            cout << "0 ";
        }
    }
    cout << "\n";
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