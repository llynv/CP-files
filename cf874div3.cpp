#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define int long long
#define ii pair<int, int>
#define x first
#define y second
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

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int tt [200007], pre[100007], suf[100007];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// void extendedEuclid(int A, int B, int &x, int &y) {
//     if (B == 0) {
//         x = 1;
//         y = 0;
//     }
//     else {
//         extendedEuclid(B, A%B, x, y);
//         int temp = x;
//         x = y;
//         y = temp - (A/B)*y;
//     }
// }

int fpow (int a, int b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    int pp = fpow(a, b/2);
    if (b % 2 == 0) return ((pp % MOD) * pp) % MOD;
    else return (((pp % MOD) * pp % MOD) * a) % MOD;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &c : a) {
        cin >> c;
        mp[c]++;
    }
    vector<int> s;
    for (auto c : mp) s.emplace_back(c.x);
    n = s.size();
    int res = 0;
    vector<int> tt(n+1);
    // int modulo = 1;
    tt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        tt[i] = (tt[i-1] % MOD * mp[s[i-1]]) % MOD;
        // modulo = (modulo * mp[s[i]]) % MOD;
    }
    for (int i = 0; i < n-m+1; ++i) {
        // modulo *= mp[s[i+m-1]];
        if (s[i+m-1] - s[i] < m) {
            // int x = 1, y = 1;
            // extendedEuclid(tt[i], MOD, x, y);
            // x = (x % MOD + MOD) % MOD;
            // x = x * tt[i+m] % MOD;
            int x = tt[i+m];
            x = ((x % MOD) * fpow(tt[i], MOD-2)) % MOD;
            res = (res + x) % MOD;
        }
    }
    cout << res << "\n";
    // dbg(s);
}
