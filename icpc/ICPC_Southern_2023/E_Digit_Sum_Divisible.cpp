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

string to_upper(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 'a' - 'A'; return a; }
string to_lower(string a) { for (int i = 0;i < (int)a.size();++i) if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 'a' - 'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
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



const int INF = 0x3f3f3f3f3f;
const int M = 126;

void solve()
{
    int n;
    cin >> n;
    int mx = 0;
    string s = to_string(n);
    int sum = 0;
    for (auto& c : s) sum += (c - '0');
    mx = max(mx, sum);
    sum = (s[0] - '0' - 1) + (sz(s) - 1) * 9;
    mx = max(mx, sum);

    int res = sz(s);
    vector<int> v(10);
    iota(all(v), 0);
    dbg(v);
    int u = 2;
    vector<int> vis (M, 0);
    while (u <= mx) {
        if (!vis[u]) {
            for (int k = u; k <= mx; k += u) {
                vector<vector<int>> dp(k+2, vector<int> (sz(s)+1, 0));;
                dp[0][0] = 1;
                for (int i = 0; i <= k; ++i) {
                    for (int l = 0; l < sz(s); ++l) {
                        for (int j = 0; j < 10; ++j) {
                            if (i + v[j] <= k) {
                                dp[i + v[j]][l + 1] += dp[i][l];
                            }
                        }
                    }
                    // cout << dp[i] << " ";
                }

                // dbg(dp);
                res = res + dp[k][sz(s)];
                vis[k] = 1;
            }
        }
        u++;
    }
    cout << res << endl;
}



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