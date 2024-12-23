// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3", "unroll-loops")

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

int Pow[19];

void solve();

#define LOCAL

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    Pow[0] = 1;
    rep(i, 1, 19) Pow[i] = Pow[i-1] * 10;

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

clock_t startTime;
double getCurrentTime() {
    return (double) (clock() - startTime) / CLOCKS_PER_SEC;
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    vector<vector<int>> nsz(16);
    for (auto &c : a) cin >> c;

    startTime = clock();

    sort(all(a));
    for (auto &c : a) {
        int csz = (int) log10(c) + 1;
        nsz[csz].pb(c);
    }
    dbg(nsz);
    int res = 0;
    int lsz = to_string(l).size(), rsz = to_string(r).size(), csz, lpos, rpos;
    for (auto &c : a) {
        if (c > r) break;
        csz = (int) log10(c) + 1;
        for (int i = max(lsz-csz, 1LL); i <= rsz-csz; ++i) {
            lpos = lower_bound(all(nsz[i]), l - c * Pow[i]) - nsz[i].begin();
            rpos = upper_bound(all(nsz[i]), r - c * Pow[i]) - nsz[i].begin();
            // dbg(c * Pow[i], r - c * Pow[i], rpos, sz(nsz[i]));
            res += rpos - lpos;
        }
    }
    // dbg("end");
    cout << res << "\n";

    cerr << "Time elapsed: " << 1.0 * (clock() - startTime) / CLOCKS_PER_SEC << " s.\n";
}