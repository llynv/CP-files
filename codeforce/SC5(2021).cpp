/*
          Pray For Ranking!!!
               _oo0oo_ 
              o8888888o 
              88" . "88 
              (| -_- |) 
              0\  =  /0 
            ___/`---'\___ 
          .' \\|     |// '. 
         / \\|||  :  |||// \ 
        / _||||| -:- |||||- \ 
       |   | \\\  -  /// |   | 
       | \_|  ''\---/''  |_/ | 
       \  .-\__  '-'  ___/-. / 
     ___'. .'  /--.--\  `. .'___ 
  ."" '<  `.___\_<|>_/___.' >' "". 
 | | :  `- \`.;`\ _ /`;.`/ - ` : | | 
 \  \ `_.   \_ __\ /__ _/   .-` /  / 
=====`-.____`.___ \_____/___.-`___.-'===== 
               `=---=' 
*/


#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long

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
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
const int M = 27;

typedef pair<int, int> ii;

int n, m;
vector<ii> adj[M][M];
char a[M][M];
bool vst[M][M][11];

void dfs(int u, int v, int poison)
{
    // cout << poison << " ";
    // cout << u << " " << v << "\n";

    vst[u][v][poison] = true;
    
    for (auto c : adj[u][v]) {
        int x = c.first, y = c.second;
        int tpoison = poison;
        if (a[x][y] == 'S') {
            tpoison = 0;
        } else if (a[x][y] >= '1' && a[x][y] <= '9') {
            tpoison += (a[x][y] - '0');
        }

        if (tpoison >= 10) continue;

        if (vst[x][y][tpoison] == false) {
            dfs(x, y, tpoison);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            adj[i][j].clear();
        }
    }
    
    memset(vst, false, sizeof(vst));

    for (int i = 0; i <= n+1; ++i) a[i][0] = a[i][m+1] = '#';
    for (int j = 0; j <= m+1; ++j) a[0][j] = a[n+1][j] = '#';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] != '#') {
                if (a[i-1][j] != '#') adj[i][j].emplace_back(i-1, j);
                if (a[i][j+1] != '#') adj[i][j].emplace_back(i, j+1);
                if (a[i][j-1] != '#') adj[i][j].emplace_back(i, j-1);
                if (a[i+1][j] != '#') adj[i][j].emplace_back(i+1, j); 
            }
        }
    }
    dfs(1, 1, 0);
    bool isEscape = false;
    for (int i = 0; i <= 9; ++i) {
        isEscape = max(isEscape, vst[n][m][i]);
        // cout << i << " " << vst[n][m][i] << "\n";
    }
    cout << (isEscape ? "possible\n" : "impossible\n");
}
