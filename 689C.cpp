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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

int u (int n, int x) {
    return n*n*n * x;  
}

int mulMod (int a, int b, int m, int &r) {
    int res = 0;
    while (b) {
        if (b & 1) {
            r += (res + a) / m;
            res = (res + a) % m;
        }
        r += (a + a) / m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

const int mod = 1e9 + 7;

bool compare (int a, int b, int c, int x, int m) {
    int r = 0;
    a = mulMod(a, b, mod, r);
    a = mulMod(a, c, mod, r);
    a = mulMod(a, x, mod, r);

    int r2 = m / mod;

    dbg(a, r, r2, m % mod);

    if (r > r2) return true;
    if (r < r2) return false;
    return a >= m % mod;
}

void solve()
{
    int n;
    cin >> n;
    int lo = 1, hi = 1e16, tt = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        int cnt = 0;
        for (int i = 2; i*i*i <= mid; ++i) {
            cnt += mid / (i*i*i);
        }
        if (cnt >= n) {
            hi = mid - 1;
            tt = cnt;
        }
        else {
            lo = mid + 1;
        }
    }
    if (tt != n) {
        cout << -1 << "\n";
        return;
    }
    cout << lo << "\n";
}
