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

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            cin >> a[i][j];
        }
    }

    vector<int> rootIdx(n * m + 1), rootCnt(n * m + 1);
    iota(all(rootIdx), 0);
    vector<int> vst(n * m + 1);

    for (int k = 0; k < n; ++k) {
        iota(all(rootIdx), 0);
        fill(all(vst), 0);
        fill(all(rootCnt), 0);

        vector<int> vss;
        for (int j = 0; j < m; ++j) {
            if (a[k][j] == '.') continue;
            a[k][j] = '#';
            vss.push_back(j);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '.') {
                    continue;
                }
                if (vst[i * m + j]) {
                    continue;
                }
                queue<ii> q;
                q.push({ i, j });
                vst[i * m + j] = 1;
                int cnt = 0;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    rootIdx[x * m + y] = i * m + j;
                    ++cnt;
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (a[nx][ny] == '.' || vst[nx * m + ny]) continue;
                        vst[nx * m + ny] = 1;
                        q.push({ nx, ny });
                    }
                }
                rootCnt[i * m + j] = cnt;
            }
        }
        for (auto j : vss) {
            a[k][j] = '.';
        }
    }

    int res2 = 0;
    for (int j = 0; j < m; ++j) {
        int tmp = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            tmp += (a[i][j] != '#');
            mp[rootIdx[i * m + j]] = 1;
            if (j != 0) {
                mp[rootIdx[i * m + j - 1]] = 1;
            }
            if (j != m - 1) {
                mp[rootIdx[i * m + j + 1]] = 1;
            }
        }
        for (auto& [k, v] : mp) {
            tmp += rootCnt[k];
        }
        res2 = max(res2, tmp);
    }
    cout << res2 << '\n';
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