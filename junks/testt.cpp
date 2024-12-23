#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)
#define endl "\n"
#define fill(x, y) memset(x, y, sizeof(x))
#define heapMax priority_queue<int>
#define heapMin priority_queue<int, vector<int>, greater<int>>

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LINVG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

int n, m;

char a[1001][1001];
// u d l r
pair<int, int> Exit;

ii MoveEnemy(pair<int, int> Enemy, int playerX, int playerY)
{
    int nX = 0, nY = 0;
    for (int i = 0; i < 2; ++i) {
        int x = Enemy.x, y = Enemy.y;
        if (x == playerX && y == playerY) {
            return {nX, nY};
        }

        if (x == playerX || (abs(y - playerY) <= abs(x - playerX) && y != playerY)) {
            y += (y < playerY ? 1 : -1);
            if (a[x][y] != '#') {
                Enemy = {x, y};
                nY += (Enemy.y < playerY ? 1 : -1);
                continue;
            }

            if (x != playerX) {
                x += (x < playerY ? 1 : -1);
                if (a[x][y] != '#') {
                    Enemy = {x, y};
                    nX += (Enemy.x < playerX ? 1 : -1);
                    continue;
                }
            }
        }
        if (y == playerY || (abs(x - playerX) <= abs(y - playerY) && x != playerX)) {
            x += (x < playerX ? 1 : -1);
            if (a[x][y] != '#') {
                Enemy = {x, y};
                nX += (Enemy.x < playerX ? 1 : -1);
                continue;
            }

            if (y != playerY) {
                y += (y < playerY ? 1 : -1);
                if (a[x][y] != '#') {
                    Enemy = {x, y};
                    nY += (Enemy.y < playerY ? 1 : -1);
                    continue;
                }
            }
        }
    }
    return {nX, nY};
}


const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool CheckValid(int x, int y, pair<int, int> Enemy, int dir)
{
    int xx = x + dx[dir], yy = y + dy[dir];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) return false;
    if (a[xx][yy] == '#') return false;
    if (x == Enemy.x && y == Enemy.y) return false;
    return true;
}

ii operator+(ii a, ii b)
{
    return {a.x + b.x, a.y + b.y};
}

void dfs(string path, int PlayerX, int PlayerY, pair<int, int> Enemy)
{
    if (PlayerX < 0 || PlayerX >= n || PlayerY < 0 || PlayerY >= m) return;
    if (Enemy.x == PlayerX && Enemy.y == PlayerY) return;
    if (a[PlayerX][PlayerY] == '#') return;
    if (path.size() == 30) return;

    if (PlayerX == Exit.x && PlayerY == Exit.y) {
        cout << path << " - " << PlayerX << " " << PlayerY << endl;
        // return;
        return;
    }

    //cout << "path: " << path << " - Enemy " << Enemy << " , Player " << PlayerX << " " << PlayerY << endl;

    for (int i = 0; i < 4; ++i) {
        int x = Enemy.x, y = Enemy.y;
        ii tmp = MoveEnemy(Enemy, PlayerX, PlayerY);
        dfs(path + "LRUD"[i], PlayerX + dx[i], PlayerY + dy[i], Enemy + tmp);
        Enemy = {x, y};
    }

}

int dist[1001];

int dijkstra(int x, int y)
{
    for (int i = 1; i <= 1000; ++i) dist[i] = INF;
    dist[x * m + y] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, x * m + y});

    while (!pq.empty()) {
        ii u = pq.top(); pq.pop();
        int d = u.x, id = u.y;
        int x = id / m, y = id % m;
        if (d > dist[id]) continue;
        if (x == Exit.x && y == Exit.y) return d;

        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (a[xx][yy] == '#') continue;
            int id = xx * m + yy;
            if (dist[id] > d + 1) {
                dist[id] = d + 1;
                pq.push({dist[id], id});
            }
        }
    }
    return -1;
}

void solve()
{
    pair<int, int> enemy, player;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];

            if (a[i][j] == 'E') enemy = {i, j};
            if (a[i][j] == 'P') player = {i, j};
            if (a[i][j] == 'G') Exit = {i, j};
        }
    }

    int playerId = player.x * m + player.y;
    int exitId = Exit.x * m + Exit.y;
    int dst = dijkstra(player.x, player.y);
    cout << dst << endl;
    
    dfs("", player.x, player.y, enemy);
    cout << "IMPOSSIBLE" << endl;
}
