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
const int N = 1011;

int f[2][57][N];
int prep[2][N], checkStudent[2][N];

void solve()
{
    int n, p, k;
    cin >> n >> p >> k;

    vector<vector<int>> st(2);
    for (int i = 0; i < 2; ++i) {
        int x;
        cin >> x;
        for (int j = 0; j < x; ++j) {
            int s;
            cin >> s;
            st[i].emplace_back(s);
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= st[i].size(); ++j) {
            prep[i][st[i][j-1]] = 1; 
            checkStudent[i][st[i][j-1]] = 1;
        }
        for (int j = 1; j <= n; ++j) {
            prep[i][j] += prep[i][j-1];
        }
        // for (int j = k; j <= n; ++j) {
        //     cout << j << " : " << prep[i][j] - prep[i][j-k] << "\n";
        // }
        // cout << "\n";
    }

    f[0][0][0] = f[1][0][0] = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= p; ++j) {
            for (int l = 1; l <= n; ++l) {
                if (checkStudent[i][l]) {
                    f[i][j][l] = max(f[i][j][l-1], (int)(f[i][j-1][max(0LL, l-k)] + prep[i][l] - prep[i][max(0LL, l-k)]));
                } else {
                    f[i][j][l] = max(f[i][j][l], f[i][j][l-1]);
                }
                // cout << f[i][j][l] << " ";
            }
            // cout << "\n";
        }
        // cout << "\n";
    }

    int res = 0;
    for (int i = 0; i <= p; ++i) {
        int l = i, r = p - i;
        res = max(res, f[0][l][n] + f[1][r][n]);
    }
    cout << res;
}