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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ii> valid_a;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != -1) valid_a.push_back({a[i], i});
    }

    auto isExpOf2 = [&](int x) {
        if (x == 1) return false;
        return (x & (x - 1)) == 0;
    };

    vector<ii> ex;

    for (int i = 1; i < sz(valid_a); ++i) {
        int div = (max(valid_a[i].first, valid_a[i - 1].first) - (max(valid_a[i].first, valid_a[i - 1].first) & 1)) / min(valid_a[i].first, valid_a[i - 1].first);
        if (isExpOf2(div)) continue;
        if ((int) log2(valid_a[i].first) + (int) log2(valid_a[i - 1].first) == valid_a[i].second - valid_a[i - 1].second) {
            int x = valid_a[i-1].first;
            bool ok = true;
            for (int j = valid_a[i - 1].second + 1; j < valid_a[i].second; ++j) {
                if (x > 1 && ok) {
                    x /= 2;
                } else {
                    x = x * 2 + !(valid_a[i].first & 1);
                    ok = false;
                }
                ex.push_back({x, j});
            }
            continue;
        }
        if (div == 1) {
            int x = valid_a[i-1].first;
            bool ok = true;
            for (int j = valid_a[i - 1].second + 1; j < valid_a[i].second; ++j) {
                if (x > 1 && ok) {
                    x /= 2;
                } else {
                    x = x * 2 + !(valid_a[i].first & 1);
                    ok = false;
                }
                ex.push_back({x, j});
            }
            continue;
        }
        return void (cout << "-1\n");
    }

    for (int i = 0; i < sz(ex); ++i) {
        valid_a.push_back(ex[i]);
    }
    sort(all(valid_a), [&](ii a, ii b) {
        return a.second < b.second;
    });
    dbg(valid_a);

    vector<int> b(n);

    for (int i = 0; i < sz(valid_a) - 1; ++i) {
        auto [v, idx] = valid_a[i];
        b[idx] = v;
        if (idx != 0 && b[idx - 1] == 0) {
            for (int j = idx - 1; j >= 0; --j) {
                if ((j & 1) && b[j+1] != 1) {
                    b[j] = b[j + 1] / 2;
                } else {
                    b[j] = b[j + 1] * 2 + (valid_a[i].first & 1);
                }
            }
        }
        v = (v < valid_a[i+1].first ? v * 2 + (valid_a[i+1].first & 1) : v / 2);
        idx++;
        while (idx < valid_a[i+1].second && v < valid_a[i+1].first) {
            b[idx] = v;
            v = v * 2 + (valid_a[i+1].first & 1);
            ++idx;
        }
        while (idx < valid_a[i+1].second && v > valid_a[i+1].first) {
            b[idx] = v;
            v = v / 2;
            ++idx;
        }

        if (i != valid_a[i+1].second) {
            for (int j = idx; j < valid_a[i+1].second; ++j) {
                if ((j & 1) && b[j-1] != 1) {
                    b[j] = b[j-1] * 2 + (valid_a[i+1].first & 1);
                } else {
                    b[j] = b[j-1] / 2;
                }
            }
        }
    }
    int id = (sz(valid_a) ? valid_a.back().second : 0);
    b[id] = (sz(valid_a) ? valid_a.back().first : 1);
    dbg(b);
    if (id != 0 && b[id-1] == 0) {
        for (int j = id - 1; j >= 0; --j) {
            if (b[j] != 0) break;
            if ((j & 1) && b[j+1] != 1) {
                b[j] = b[j + 1] / 2;
            } else {
                b[j] = b[j + 1] * 2 + (sz(valid_a) ? valid_a.back().first & 1 : 0);
            }
        }
    }
    for (int i = id + 1; i < n; ++i) {
        if (b[i] != 0) break;
        if ((i & 1) || b[i-1] == 1) {
            b[i] = b[i-1] * 2 + (sz(valid_a) ? valid_a.back().first & 1 : 0);
        } else {
            b[i] = b[i-1] / 2;
        }
    }
    dbg(b);
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] == (b[i+1] / 2)) continue;
        if (b[i+1] == (b[i] / 2)) continue;
        return void (cout << "-1\n");
    }
    for (int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n - 1];
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