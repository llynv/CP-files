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

int f(int n)
{
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int res = 1e18;

void calc (int n, int mn, int nxt, int m, int k)
{
    if (nxt == 0) {
        // dbg(n, m);
        if (n % m == k) {
            res = min(res, n);
            return;
            // dbg(n, m);
        }
        return;
    }

    if (n >= mn) if (n % m == k) res = min(res, n);

    for (int i = 1; i <= nxt; ++i) {
        calc (n * 10 + i, mn, nxt - i, m, k);
    }
}           

int check (string s, int m, int k)
{
    int r = 0, mul = 0;
    for (int i = 0; i < sz(s); ++i) {
        mul = mul * 10 + (s[i]-'0');
        if (mul >= m)
            mul %= m;
    }
    return mul;
}

void solve()
{
    int l, r, m, k;
    cin >> l >> r >> m >> k;
    if (m == 1) {
        string s = "";
        while (l >= 9) {
            s += '9';
            l -= 9;
        }
        if (l != 0) s += (l+'0');
        reverse(all(s));
        return cout << s << "\n", void();
    }
    if (r == 1) {
        string s = "1";
        int mul = 1;
        while (sz(s) <= 100000 && mul != k) {
            s += '0';
            mul *= 10;
            if (mul >= m) mul %= m;
        }
        if (mul == k) return cout << s << "\n", void();
        return cout << "-1\n", void();
    }

    int n = k, cnt = 0;
    while (f(n) < l || f(n) > r) {
        
    }
    cout << (cnt > 10000 ? -1 : n) << "\n";
}
