#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;

const int N = 1011;

char a[N][N], b[N][N];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
int vst[N][N];
ii goal;
string ans;
char c[N][N];

void dfs(int u, int v, vector<ii> monsters, vector<ii> s) {
    vst[u][v] = 1;
    vector<ii> nxtMonsters;
    vector<ii> path = s;

    if (u == 0 || u == n - 1 || v == 0 || v == m - 1) {
        for (auto pth : monsters) cout << pth << "\n";
        ans.clear();
        ans += to_string(path.size());
        ii current = goal;
        for (auto c : s) {
            if (c.x > current.x) ans += "D";
            if (c.y > current.y) ans += "R";
            if (c.x < current.x) ans += "U";
            if (c.y < current.y) ans += "L";
            current = c;
        }
    }

    for (int i = 0; i < 4; ++i) {
        int xx = dx[i] + u;
        int yy = dy[i] + v;
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '.' && !vst[xx][yy]) {
            for (auto c : monsters) {
                int mx = dx[i] + c.x;
                int my = dy[i] + c.y;
                if (mx >= 0 && mx < n && my >= 0 && my < m && a[xx][yy] != '#') {
                    nxtMonsters.emplace_back(make_pair(mx, my));
                } else {
                    nxtMonsters.emplace_back(c);
                }
            }

            bool isAvai = true;

            for (auto c : nxtMonsters) {
                if (c == make_pair(xx, yy)) {
                    isAvai = false;
                    break;
                }
            }

            if (isAvai) {
                path.emplace_back(make_pair(xx+1, yy+1));
                dfs(xx, yy, nxtMonsters, path);
                path.erase(path.end()-1);
            }
        }
    }
}

void solve()
{   
    cin >> n >> m;
    vector<vector<char>> b(n);
    vector<ii> monsters;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            b[i].emplace_back(a[i][j]);
            if (a[i][j] == 'M') {
                monsters.emplace_back(make_pair(i, j));
            }
        }
    }
    vector<ii> res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'A') {
                goal = make_pair(i+1, j+1);
                dfs(i, j, monsters, res);
                if (ans.empty()) {
                    cout << "NO";
                    return;
                }
                cout << "YES\n" << ans[0] << "\n";
                cout << ans.substr(1, ans.size()-1);
                return;
            }
        }
    }
}
