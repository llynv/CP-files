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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int Nx = 2e3 + 11;

int a[Nx][Nx];
int mdiag[Nx][Nx], odiag[Nx][Nx];

void solve()
{
    int n, m;
    cin >> n >> m;
    rep (i, 1, n+1) rep (j, 1, m+1) cin >> a[i][j];
    int ed = 2;
    for (int i = 1; i < n+m; ++i) {
        if (i <= m) {
            int st = m-i+1;
            // dbg(st);
            for (int j = 1; st <= m and j <= n; ++j) {
                // dbg(st, j);
                mdiag[j][st] = mdiag[j-1][st-1] + a[j][st];
                st++;
            }
        } else {
            int st = 1;
            // dbg(ed);
            for (int j = ed; j <= n and st <= m; ++j) {
                mdiag[j][st] = mdiag[j-1][st-1] + a[j][st];
                st++;
            }
            ed++;
        }
    }
    
    for (int i = 1; i < n+m; ++i) {
        if (i <= m) {
            int st = n;
            // dbg(st);
            for (int j = m-i+1; j <= m and st >= 1; ++j) {
                odiag[st][j] = odiag[st+1][j-1] + a[st][j];
                st--;
            }
        } else {
            int st = n-i+m;
            // dbg(st);
            for (int j = 1; st >= 1 and j <= m; ++j) {
                odiag[st][j] = odiag[st+1][j-1] + a[st][j];
                // dbg(st, j);
                st--;
            }
        }
    }
    int res = -INF;
    rep (i, 1, n+1) {
        rep (j, 1, m+1) {
            // cout << odiag[i][j] + mdiag[i][j] - a[i][j] << " ";
            // cout << mdiag[i][j] << " ";
            int nx = i, ny = j, bx = i, by = j;
            int st = min(m - j, n - i);
            nx += st;
            ny += st;
            int st2 = min(m - j, i - 1);
            bx -= st2;
            by += st2;
            res = max(res, mdiag[nx][ny] + odiag[bx][by] - a[i][j]);
        }
        // cout << "\n";
    }
    cout << res;
}
