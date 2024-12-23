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
// const int N = 2e5+7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &c : a) cin >> c;
    for (auto &c : b) cin >> c;

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].pb(i);
    }

    vector<vector<int>> f(20, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) f[0][i] = a[i];
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << (i-1)) < n; ++j) {
            f[i][j] = max(f[i-1][j], f[i-1][j+(1<<(i-1))]);
        }
    }

    auto get = [&](int l, int r) {
        int k = log2(r-l+1);
        return max(f[k][l], f[k][r-(1<<k)+1]);
    };

    vector<vector<int>> g(20, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) g[0][i] = b[i];
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j + (1 << (i-1)) < n; ++j) {
            g[i][j] = min(g[i-1][j], g[i-1][j+(1<<(i-1))]);
        }
    }

    auto getMin = [&](int l, int r) {
        int k = log2(r-l+1);
        return min(g[k][l], g[k][r-(1<<k)+1]);
    };
    
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            cout << "NO\n";
            // dbg("NO");
            return;
        }

        if (a[i] != b[i]) {
            int hi = upper_bound(all(mp[b[i]]), i) - mp[b[i]].begin();
            int lo = hi - 1;
            // dbg(i, lo, hi, mp[b[i]][lo], mp[b[i]][hi]);

            bool isLower = true, isUpper = true;

            if (lo >= 0) {
                int x = mp[b[i]][lo];

                if (get(x, i-1) > b[i]) isLower = false;
                if (getMin(x, i-1) < b[i]) isLower = false;
            } else {
                isLower = false;
            } 

            if (hi < sz(mp[b[i]])) {
                int x = mp[b[i]][hi];

                if (get(i+1, x) > b[i]) isUpper = false;
                if (getMin(i+1, x) < b[i]) isUpper = false;
            } else {
                isUpper = false;
            }

            if (!isLower && !isUpper) {
                cout << "NO\n";
                // dbg("NO");
                return;
            }
        }
    }
    cout << "YES\n";
    // dbg("YES");
}
