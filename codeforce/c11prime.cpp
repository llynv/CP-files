#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int unsigned long long

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

int pow (int a, int b, int m)
{
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

bool check (int n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    int d = n - 1;
    while (d % 2 == 0) d /= 2;

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (a >= n) break;
        int t = d;
        int y = pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = (y * y) % n;
            t *= 2;
        }
        if (y != n - 1 && t % 2 == 0) return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 63; ++i) {
        int c = ceil(pow(n, 1.0/i));
        // cout << c << " ";
        // dbg(i, c, pow(c, i, 1e9+7), n);
        if (pow(c, i, 1e9 + 7) == n && check(c)) {
            cout << c << " " << i;
            return;
        }
    }
    cout << 0;
}
