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

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void solve()
{
    int n;
    cin >> n;
    vector<ii> banned(n);
    int move = 0;
    map<ii, int> bannedMap;
    vector<vector<int>> bannedVec (111, vector<int>(111, 0));
    vector<vector<int>> ballVec (111, vector<int>(111, 0));
    for (auto &x : banned) {
        cin >> x.fi >> x.se;
        bannedMap[x] = 1;
        if (x.fi < 0 || x.se < 0) continue;
        bannedVec[x.fi][x.se] = 1;
    }

    int m;
    cin >> m;
    vector<ii> balls(m);
    int mxn = 0, mxm = 0;
    map<ii, int> ballMap;
    for (auto &x : balls) {
        cin >> x.fi >> x.se;
        ballMap[x] = 1;
        ballVec[x.fi][x.se] = 1;
    }

    if (m == 2 && n == 0) {
        cout << abs(balls[0].fi - balls[1].fi) + abs(balls[0].se - balls[1].se) << "\n";
        return;
    }

    int ans = INF;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if (bannedVec[i][j]) continue;
            queue<ii> q;
            q.push({i, j});
            vector2d(dist, 111, 111, int, INF);
            dist[i][j] = 0;
            int sum = 0, cnt = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                if (ballVec[x][y] == 1) {
                    sum += dist[x][y];
                    ++cnt;
                }
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
                    if (bannedVec[nx][ny]) continue;
                    if (dist[nx][ny] == INF) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            if (cnt == m) ans = min(ans, sum);
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
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
