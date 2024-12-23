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


const int INF = 0x3f3f3f3f3f;
const int N = 11;

int pre[N][N];


int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    pre[2][0] = 0;
    pre[2][1] = 2;
    pre[2][2] = 6;
    pre[2][3] = 14;
    pre[2][4] = 20;

    pre[4][0] = 0;
    pre[4][1] = 4;
    pre[4][2] = 12;
    pre[4][3] = 18;
    pre[4][4] = 20;

    pre[8][0] = 0;
    pre[8][1] = 8;
    pre[8][2] = 14;
    pre[8][3] = 16;
    pre[8][4] = 20;

    pre[6][0] = 0;
    pre[6][1] = 6;
    pre[6][2] = 8;
    pre[6][3] = 12;
    pre[6][4] = 20;
    
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

int f(int n, int last, int len, int x)
{
    int res = (x + (n - len) * 5) * (last - n);

    // dbg(x, len, start, step, r, pre[start][r], n, res);
    return res; 
}

int ternarySearch(int l, int r, int len, int x, int k) {
    int ans = 0;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = f(m1, k, len, x);
        int f2 = f(m2, k, len, x);
        ans = max(ans, max(f1, f2));
        if (f1 < f2)
            l = m1 + 1;
        else
            r = m2 - 1;
    }
    // dbg(l, r);
    // cout << ans << " " << f(l, k, len, x) << " " << f(r, k, len, x) << endl;
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ch(10);
    int i = 0, x = n % 10;
    while (!ch[x]) {
        ch[x] = ++i;
        x = (2 * x) % 10;
    }
    int T = i - ch[x] + 1, start = x % 10, len = ch[x] - 1;
    dbg(T, len, start);

    int xs = n, ans = n * k;
    for (int i = 0; i < len; ++i) {
        n += (n % 10);
        xs += (xs % 10);
        ans = max(ans, xs * (k - i - 1));
    }

    if (T != 4) return cout << ans << "\n", void();

    int t = (5 * len - n + 5 * k) / 10;

    // dbg(t);

    cout << max(ans, ternarySearch(len, k-1, len, n, k)) << "\n";
}   
