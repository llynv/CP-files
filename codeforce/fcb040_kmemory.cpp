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

template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }


void solve();

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 5e5 + 7;

struct SegTree
{
    int minV, maxV;
};


SegTree it[4 * N];
int a[N];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].minV = a[L-1];
        it[index].maxV = a[L-1];
        return;
    }

    int mid = (L + R) / 2;
    build(index * 2, L, mid);
    build(index * 2 + 1, mid + 1, R);
    it[index].maxV = max(it[index * 2].maxV, it[index * 2 + 1].maxV);
    it[index].minV = min(it[index * 2].minV, it[index * 2 + 1].minV);
}

int getMax(int index, int L, int R, int u, int v)
{
    if (v < L || R < u) return -INF;
    if (u <= L && R <= v) return it[index].maxV;

    int mid = (L + R) / 2;
    int left = getMax(index * 2, L, mid, u, v);
    int right = getMax(index * 2 + 1, mid + 1, R, u, v);
    return max(left, right);
}

int getMin(int index, int L, int R, int u, int v)
{
    if (v < L || R < u) return INF;
    if (u <= L && R <= v) return it[index].minV;

    int mid = (L + R) / 2;
    int left = getMin(index * 2, L, mid, u, v);
    int right = getMin(index * 2 + 1, mid + 1, R, u, v);
    return min(left, right);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0, i = 0, j = 0, maxV = a[0], minV = a[0];
    build(1, 1, n);
    while (i < n || j < n) {
        if (i < n && (maxV - minV <= k || j == i)) {
            res += (i - j);
            // dbg(i, j);
            ++i;
        } else {
            ++j;
        }
        maxV = getMax(1, 1, n, j+1, i+1);
        minV = getMin(1, 1, n, j+1, i+1);
        // dbg(i, j, maxV, minV);
    }
    cout << res + n;
}
