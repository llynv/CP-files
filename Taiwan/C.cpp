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
#include "../debug.h"
#endif

const int INF = 0x3f3f3f3f3f;

bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

void solve()
{
    string s;
    cin >> s;

    dbg(s);

    if (s == "0") {
        cout << "0\n";
        return;
    }

    string b;
    cin >> b;

    int n = sz(s);

    string cur = "";
    queue<pair<string, ii>> q;
    vector<int> dist(n, INF);
    for (int i = n - 1; i >= 0; --i) {
        cur = s[i] + cur;
        if (s[i] != '0' && comp(cur, b)) {
            dist[i] = 0;
            q.push(make_pair(cur, make_pair(i, 0)));
        }
    }


    while (!q.empty()) {
        auto [str, x] = q.front();
        auto [i, d] = x;
        q.pop();
        cur = "";
        for (int j = i - 1; j >= 0; --j) {
            cur = s[j] + cur;
            if (!comp(cur, str)) break;
            if (s[j] != '0') {
                if (dist[j] == INF || dist[j] > d + 1) {
                    dist[j] = d + 1;
                    q.push(make_pair(cur, make_pair(j, dist[j])));
                }
            }
        }
    }

    dbg(dist);

    if (dist[0] == INF) {
        cout << "NO WAY\n";
        return;
    }
    cout << dist[0] << '\n';
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