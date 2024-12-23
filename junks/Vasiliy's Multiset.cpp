#include <bits/stdc++.h>
using namespace std;

#define LOCAL
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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<class T> T mulmod(T a, T b, T m) { T q = (T)(((long double)a * (long double)b) / (long double)m); T r = a * b - q * m; if (r > m) r %= m; if (r < 0) r += m; return r; }
template<class T> nCr(T n, T r) { if (r > n - r) r = n - r; T ans = 1; for (T i = 1; i <= r; ++i) { ans *= n - r + i; ans /= i; } return ans; }
template<class T> fastPow(T a, T b, T m) { T res = 1; while (b) { if (b & 1) res = ((res % m) * (a % m)) % m; a = ((a % m) * (a % m)) % m; b >>= 1; } return res; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;

struct Node
{
    Node *child[2];
    int cnt = 0;

    Node() {
        rep (i, 0, 2) {
            this->child[i] = NULL;
        }
    }
};

Node *root = new Node();

void AddNum(int n)
{
    Node *p = root;
    for (int i = 30; i >= 0; --i) {
        int x = (n & (1 << i)) > 0;
        if (p->child[x] == NULL) {
            p->child[x] = new Node();
        }
        p = p->child[x];
        p->cnt++;
    }
}

void EraseNum(int n)
{
    Node *p = root;
    for (int i = 30; i >= 0; --i) {
        int x = (n & (1 << i)) > 0;
        p->child[x]->cnt -= 1;
        p = p->child[x];
    }
}

int FindMax(int n)
{
    Node *p = root;
    int x = 0;
    for (int i = 30; i >= 0; --i) {
        int c = !((n & (1 << i)) > 0);
        if (p->child[c] != NULL && p->child[c]->cnt > 0) {
            x |= (c << i);
            p = p->child[c];
        } else {
            x |= ((!c) << i);
            p = p->child[!c];
        }

    }
    // dbg(x);
    return (x ^ n);
}

void Out (int n)
{
    Node *p = root;
    cout << n << " : ";
    for (int i = 30; i >= 0; --i) {
        int c = (n & (1 << i)) > 0;
        p = p->child[c];
        cout << p->cnt << " ";
    }
    cout << "\n";
}

void solve()
{
    char q;
    int n;
    cin >> q >> n;
    AddNum(0);
    if (q == '+') {
        AddNum(n);
    } else if (q == '-') {
        EraseNum(n);
        // Out(n);
    } else {
        cout << FindMax(n) << "\n";
    }
}
