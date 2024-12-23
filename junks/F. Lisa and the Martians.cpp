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
const int N = 2e5 + 7;

struct Node
{
    Node *child[2];
    int nums;

};

Node *CreateNode() {

    Node *p = new Node();

    p->child[0] = p->child[1] = NULL;
    p->nums = 0;

    return p;
}

Node *root = CreateNode();

void AddNode(int n, int k) {
    Node *p = root;
    k--;

    for (int i = k; i >= 0; --i) {
        int bit = (n & (1 << i)) > 0;
        if (p->child[bit] == NULL) p->child[bit] = CreateNode();
        p = p->child[bit];
        p->nums++;
    }
}

void DeleteNode(int n, int k)
{
    Node *p = root;
    k--;

    for (int i = k; i >= 0; --i) {
        int bit = (n & (1 << i)) > 0;
        p = p->child[bit];
        p->nums--;
    }
}

ii FindMaxEq(int n, int k) {
    Node *p = root;
    k--;
    int res = 0, val = 0;

    for (int i = k; i >= 0; --i) {
        int bit = (n & (1 << i)) > 0;
        if (p->child[bit] != NULL && p->child[bit]->nums > 0) {
            val |= (bit << i);
            res |= ((!bit) << i);
            p = p->child[bit];
        }
        else {
            val |= ((!bit) << i);
            p = p->child[!bit];
        }

    }

    return {res, val};
}

ii a[N];
int n;

void solve()
{
    root = CreateNode();

    int k;
    cin >> n >> k;
    rep (i, 0, n) {
        cin >> a[i].fi;
        a[i].se = i;
        AddNode(a[i].fi, k);
    }
    int maxVal = 0, xorVal = 0;
    ii res = {-1, -1};
    rep (i, 0, n - 1) {
        DeleteNode(a[i].fi, k);
        ii maxXor = FindMaxEq(a[i].fi, k);
        int c = (a[i].fi ^ maxXor.fi) & (maxXor.se ^ maxXor.fi);
        // dbg(c);
        if (maxVal <= c) {
            maxVal = c;
            xorVal = maxXor.fi;
            // dbg(c, maxXor, pos);
            res = {a[i].fi, maxXor.se};
        }
        // cout << a[i] << " ";
    }
    int x = res.fi, y = res.se, c = xorVal;
    // dbg(x, y, c);
    int fi = -1, se = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i].fi == x && fi == -1) fi = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].fi == y && fi != i + 1) se = i + 1;
    }
    cout << fi << " " << se << " " << xorVal << "\n";
    // dbg((a[x-1].fi^c)&(a[y-1].fi^c));
}
