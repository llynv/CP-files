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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f;
const int N = 100011;

int f[N][4][4][4];

int calc (int a, int b, int c)
{
    set<int> s;
    s.insert({a, b, c});
    s.erase(0);
    return s.size();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> food(n+1);
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        switch (c)
        {
        case 'M':
            food[i] = 1;
            break;

        case 'B':
            food[i] = 2;
            break;
        
        default:
            food[i] = 3;
            break;
        }
    }
    for (int q = 0; q <= n; ++q) {
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j <= 3; ++j) {
                for (int k = 0; k <= 3; ++k) {
                    // if (i || j || k) {
                        f[q][i][j][k] = -1;
                    // }
                }
            }
        }
    }
    f[0][0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int a = 0; a <= 3; ++a) {
            for (int b = 0; b <= 3; ++b) {
                for (int c = 0; c <= 3; ++c) { 
                    if (f[i][a][b][c] != -1) {
                        f[i+1][food[i]][b][c] = max(f[i+1][food[i]][b][c], f[i][a][b][c] + calc(food[i+1], a, food[i]));
                        
                        f[i+1][c][a][food[i]] = max(f[i+1][c][a][food[i]], f[i][a][b][c] + calc(food[i+1], b, c));
                        
                        // cout << calc(tmp) << " " << calc(tmp2) << "\n";
                        // cout << f[i][a][b][c] << "\n";
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 3; ++j) {
            for (int k = 0; k <= 3; ++k) {
                res = max(res, f[n][i][j][k]);
                // cout << f[n][i][j][k] << "\n";
            }
        }
    }
    cout << res;
}
