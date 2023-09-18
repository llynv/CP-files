#include <bits/stdc++.h>
using namespace std;

#define LINVG
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
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

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 57;
const int M = 2e5 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char a[N][N];
int root[M];

int FindSet(int n)
{
    if (n == root[n]) return n;
    return root[n] = FindSet(root[n]);
}

void UnionSet(int u, int v)
{
    int ru = FindSet(u);
    int rv = FindSet(v);
    root[ru] = rv;
}

bool CheckUnion(int u, int v)
{
    return FindSet(u) == FindSet(v);
}

void solve()
{
    // int a = 1;
    
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i <= n * m; ++i)
        root[i] = i;
 
    rep (i, 0, n)
        rep (j, 0, m)
            cin >> a[i][j];

    rep (i, 0, n) {
        rep (j, 0, m) {
            if (a[i][j] == 'B') {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'G') return void(cout << "NO\n");
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.') a[x][y] = '#';
                }
            }
        }
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (a[i][j] != '#' && a[i][j] != 'B') {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#') {
                        int id = x * m + y + 1;
                        UnionSet(i * m + j + 1, id);
                    }
                }
            }
        }
    }
    rep (i, 0, n) {
        rep (j, 0, m) {
            if (a[i][j] == 'G') {
                if (!CheckUnion(i * m + j + 1, n * m)) return void(cout << "NO\n");
            }
        }
    }
    cout << "YES\n";
}
