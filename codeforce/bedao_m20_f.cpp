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
const int N = 3e5 + 7;
struct SegmentTree
{
    int val, updateVal;
} itA[3000111], itB[3000111], itC[3000111];

int a[N], b[N], c[N];

void buildB (int index, int L, int R, int l, int r)
{
    if (L == R) {
        itB[index].val = b[L];
        return;
    }

    int mid = (L + R) >> 1;
    buildB(index*2, L, mid, l, r);
    buildB(index*2+1, mid+1, R, l, r);
}

void buildC (int index, int L, int R, int l, int r)
{
    if (L == R) {
        itC[index].val = c[L];
        return;
    }

    int mid = (L + R) >> 1;
    buildC(index*2, L, mid, l, r);
    buildC(index*2+1, mid+1, R, l, r);
}

void lazyB (int index, int L, int R)
{
    if (itB[index].updateVal == 0) return;

    if (L == R) {
        itB[index].val = a[L];
        itB[index].updateVal = 0;
        return;
    }

    int mid = (L + R) >> 1;
    if (mid+1 == R) {
        itB[index << 1 | 1].val = a[L];
    } 
    if (L == mid) {
        itB[index << 1].val = a[L];
    }
    itB[index*2].updateVal = 1;
    itB[index*2+1].updateVal = 1;
    itB[index].updateVal = 0;
}

void lazyC (int index, int L, int R)
{
    if (itC[index].updateVal == 0) return;

    if (L == R) {
        itC[index].val = itB[index].val;
        itC[index].updateVal = 0;
        return;
    }

    int mid = (L + R) >> 1;
    if (mid+1 == R) {
        itC[index << 1 | 1].val = itB[index << 1 | 1].val;
    } 
    if (L == mid) {
        itC[index << 1].val = itB[index << 1 | 1].val;
    }
    itC[index*2+1].updateVal = 1;
    itC[index*2].updateVal = 1;      
    itC[index].updateVal = 0;
}

void updateB (int index, int L, int R, int l, int r, int val)
{
    lazyB(index, L, R);
    if (L > r || R < l) return;
    lazyB(index, L, R);
    if (L >= l && R <= r) {
        itB[index].val = val;
        itB[index].updateVal = 1;
        return;
    }

    lazyB(index, L, R);
    int mid = (L + R) >> 1;
    updateB(index*2, L, mid, l, r, val);
    updateB(index*2+1, mid+1, R, l, r, val);
}

void updateC (int index, int L, int R, int l, int r, int val)
{
    lazyB(index, L, R);
    lazyC(index, L, R);
    if (L > r || R < l) return;

    lazyB(index, L, R);
    lazyC(index, L, R);
    if (L >= l && R <= r) {
        itC[index].val = val;
        itC[index].updateVal = 1;
        return;
    }

    lazyB(index, L, R);
    lazyC(index, L, R);
    int mid = (L + R) >> 1;
    updateC(index*2, L, mid, l, r, val);
    updateC(index*2+1, mid+1, R, l, r, val);
}

int get (int index, int L, int R, int l, int r)
{
    lazyB(index, L, R);
    lazyC(index, L, R);
    if (L > r || R < l) return 0;

    lazyB(index, L, R);
    lazyC(index, L, R);
    if (L >= l && R <= r) return itC[index].val;

    lazyB(index, L, R);
    lazyC(index, L, R);
    int mid = (L + R) >> 1;
    return get(index*2, L, mid, l, r) + get(index*2+1, mid+1, R, l, r);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    rep (i, 1, n+1) cin >> a[i];
    rep (i, 1, n+1) cin >> b[i];
    rep (i, 1, n+1) cin >> c[i];

    buildB(1, 1, n, 1, n);
    buildC(1, 1, n, 1, n);

    rep (i, 0, q) {
        int t, x, y, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            updateB(1, 1, n, x, y, k);
        } else if (t == 2) {
            cin >> x >> y >> k;
            updateC(1, 1, n, x, y, k);
        } else {
            cin >> x;
            cout << get(1, 1, n, x, x) << "\n";
        }

        rep (j, 1, n+1) cout << get(1, 1, n, j, j) << " \n"[j==n];
    }
}
