#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
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

#define _(x) ((x) & (-x))

const int INF = 0x3f3f3f3f;

const int N = 1e5 + 7;
int fw[N][11], f[N][11];

void update(int index, int nums, int value)
{
    int i = index;
    while (i < N)
    {
        fw[i][nums] += value;
        i += _(i);
    }
}


int get(int index, int nums)
{
    int i = index, ret = 0;
    while (i > 0) {
        ret += fw[i][nums];
        i -= _(i);
    }
    return ret;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin(), a.end());
    // dbg(a);
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) f[i][1] = 1;
    for (int j = 2; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            f[i][j] = get(a[i-1].se - 1, j - 1);
            update(a[i-1].se, j - 1, f[i][j-1]);
        }
    }
    // dbg(a);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += f[i][k];
    }
    cout << ans;
}