/*
  Code by: linvg
*/

#include <bits/stdc++.h>
using namespace std;

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

// #define LOCAL

const int INF = 0x3f3f3f3f3f;
const int N = 5e5 + 7;

vector<int> factors[N];
void sieve() {
    for (int i = 1; i * i < N; ++i) {
        for (int j = i; j * i < N; ++j) {
            factors[j * i].push_back(i);
            if (i != j) {
                factors[j * i].push_back(j);
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& c : a) cin >> c;
    a.insert(a.begin(), 0);
    unordered_map<int, vector<int>> posA;
    vector<int> pref(n + 1), idx(n + 1);
    iota(all(idx), 0);

    vector<ii> v;
 
    for (int i = 1; i <= n; ++i) {
        int _gcd = gcd(a[i], i);
        a[i] /= _gcd;
        idx[i] = i / _gcd;
        v.push_back({a[i], idx[i]});
    }
 
    sort(all(v), [&](ii a, ii b) {
        if (a.se == b.se) return a.fi < b.fi;
        return a.se < b.se;
    });
 
    for (int i = 1; i <= n; ++i) {
        a[i] = v[i - 1].fi;
        idx[i] = v[i - 1].se;
    }
 
    long long res = 0;

    for (int i = 1; i <= n; ++i) {
        int id = idx[i];
        pref[i] = pref[i - 1];

        if (a[i] % id == 0) {
            res += pref[i];
            pref[i]++;
            posA[id].push_back(i);
            continue;
        }

        for (auto& f : factors[a[i]]) {
            int l = 0, r = sz(posA[f]) - 1, pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[posA[f][mid]] >= id / f) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (pos == -1) continue;
            res += count_if(posA[f].begin() + pos, posA[f].end(), [&](int j) {
                return (long long) a[j] * f % id == 0;
            });
            // reduce the complexity
        }

        posA[id].push_back(i);
    }
    dbg(res);
    cout << res << '\n';
}


int32_t main() {

#ifdef LOCAL
    freopen("template.inp", "r", stdin);
    freopen("template.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}