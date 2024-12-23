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

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 7;

string ita[4 * N];
string a;

void buildA(int index, int L, int R)
{
    if (L == R)
    {
        ita[index] += a[L-1];
        return;
    }

    int mid = (L + R) / 2;
    buildA(index << 1, L, mid);
    buildA(index << 1 | 1, mid + 1, R);
    ita[index] = ita[index << 1];
    ita[index] += ita[index << 1 | 1];
    // cout << ita[index] << "\n";
}

string getA(int index, int L, int R, int l, int r)
{
    if (L > r || R < l) {
        return "";
    }
    if (L >= l && R <= r) {
        return ita[index];
    }

    int mid = (L + R) / 2;
    string v1 = getA(index << 1, L, mid, l, r);
    string v2 = getA(index << 1 | 1, mid + 1, R, l, r);
    string res = v1;
    res += v2;
    return res;
}

int KMP(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i)
    {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j])   
            j = pi[j-1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }
    int ret = 0;
    int i = 0, j = 0;
    while (i < n)
    {
        while (j > 0 && s[i] != t[j])
            j = pi[j-1];
        if (s[i] == t[j])
            j++;
        if (j == m)
        {
            ret++;
            j = pi[j-1];
        }
        ++i;
    }
    return ret;
}

int ZFunction(string s, string t)
{
    string str = t + "#" + s;
    int n = str.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int ret = 0;
    for (int i = t.size() + 1; i < n; ++i)
        if (z[i] == t.size())
            ++ret;
    return ret;
}

int total[N], check[N];

void Down(string &pre, string &suf)
{
    if (!pre.empty()) {
        pre.erase(pre.end()-1);
        suf.erase(suf.begin());
    }
}

void Zfunction(int z[], string s) {
    int n = (int)s.size();
    for (int i = 1; i <= n; i++) z[i] = 0;
    int L = 1, R = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= R) z[i] = min(z[i - L + 1], R - i + 1);
        while (i + z[i] <= n && s[z[i]] == s[i + z[i] - 1]) z[i]++;
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
}

vector<int> zfunc(const string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int stg[N], z[N];

void solve()
{
    cin >> a;
    int q;
    int n = a.size();
    // buildA(1, 1, n);
    // memset(check, 1, sizeof(check));
    // for (int i = 0; i < n; ++i) {
    //     string suf = getA(1, 1, n, n - i, n);
    //     string pre = getA(1, 1, n, 1, i + 1);
    //     // dbg(pre, suf);
    //     check[i] = (pre == suf);
    // }

    vector<int> res = zfunc(a);
    dbg(res);

    
    // Zfunction(z, a);
    // vector<int> sum(n + 1, 0);
    // for (int i = 1; i <= n; i++) {
    //     sum[z[i]]++;
    // }
    // for (int i = n - 1; i >= 0; i--) sum[i] += sum[i + 1];
    // // for (int i = 0; i < n; ++i) cout << sum[i] << " ";
    // // cout << endl;
    // int Q;
    // cin >> Q;
    // while (Q--) {
    //     int L;
    //     cin >> L;
    //     if (L >= n - 1)
    //         cout << "NO" << '\n';
    //     else {
    //         if (z[n - L + 1] < L) {
    //             cout << "NO" << '\n';
    //         } else {
    //             if (sum[L] < 2) {
    //                 cout << "NO" << '\n';
    //             } else {
    //                 cout << "YES"
    //                      << " " << sum[L] + 1 << '\n';
    //             }
    //         }
    //     }
    // }
}
