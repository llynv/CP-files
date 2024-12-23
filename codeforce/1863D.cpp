#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3", "unroll-loops")

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
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator>>(ostream &is, const T_container &v) { for (auto &c : v) is >> c; }
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<int> row(n), col(m);
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> a[i][j];
            if (a[i][j] != '.')
            {
                row[i]++;
                col[j]++;
            }
        }
    }

    rep (i, 0, n) {
        rep (j, 0, m) {
            if (row[i] & 1 || col[j] & 1) {
                cout << "-1" << endl;
                return;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        int up = -1, down = -1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'D' && a[i-1][j] == 'U') {
                if (up == -1) {
                    up = 1;
                    down = 0;
                    a[i-1][j] = 'W';
                    a[i][j] = 'B';
                } else {
                    if (up == 1) {
                        a[i-1][j] = 'B';
                        a[i][j] = 'W';
                    } else {
                        a[i-1][j] = 'W';
                        a[i][j] = 'B';
                    }
                    up = !up;
                    down = !down;
                }
            }
        }
    }

    for (int j = 1; j < m; j ++) {
        int left = -1, right = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i][j] == 'R' && a[i][j-1] == 'L') {
                if (left == -1) {
                    left = 1;
                    right = 0;
                    a[i][j-1] = 'W';
                    a[i][j] = 'B';
                } else {
                    if (left == 1) {
                        a[i][j-1] = 'B';
                        a[i][j] = 'W';
                    } else {
                        a[i][j-1] = 'W';
                        a[i][j] = 'B';
                    }
                    left = !left;
                    right = !right;
                }
            }
        }
    }
    for (auto &c : a) {
        for (auto &d : c) {
            cout << d;
        }
        cout << endl;
    }
}   
