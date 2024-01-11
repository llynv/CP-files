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

#define LOCAL;

int32_t main() {

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 3e5 + 7;

int a[N], b[N];

struct SegmentTree
{
    int L, R;
    bool isInc;
};

SegmentTree it[4 * N];

void build (int index, int L, int R)
{
    if (L == R) {
        it[index].L = it[index].R = b[L-1];
        it[index].isInc = true;
        return;
    }

    int mid = (L + R) >> 1;
    build (index * 2, L, mid);
    build (index * 2 + 1, mid + 1, R);
    it[index].L = it[index * 2].L;
    it[index].R = it[index * 2 + 1].R;
    it[index].isInc = (it[index * 2].isInc && it[index * 2 + 1].isInc && it[index * 2].R <= it[index * 2 + 1].L);
}

SegmentTree getInc (int index, int L, int R, int l, int r)
{
    if (L > r || R < l) return {INF, -1, true};
    if (l <= L && R <= r) {
        return it[index];
    }
    int mid = (L + R) >> 1;
    SegmentTree v1 = getInc (index * 2, L, mid, l, r);
    SegmentTree v2 = getInc (index * 2 + 1, mid + 1, R, l, r);
    SegmentTree res = {v1.L, v2.R, v1.isInc && v2.isInc && v1.R <= v2.L};
    return res;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> cntA(n+1), cntB(n+1);

    rep (i, 0, n) {
        cin >> a[i];
        cntA[a[i]]++;
    }
    rep (i, 0, n) {
        cin >> b[i];
        cntB[b[i]]++;
    }

    if (cntA != cntB) return void(cout << "NO\n");
    

    bool isDif = false;
    int start = -1, currentPos = 0;
    bool isInc = true;
    int mxA = -1, miA = INF, mxB = -1, miB = INF;
    
    for (int i = 0; i < n; ++i) {

        if (a[i] != b[i] && !isDif) {
            isDif = true;
            start = (start == -1 ? i : start);
            isInc = true;
            mxA = -1, miA = INF, mxB = -1, miB = INF;
        }   
        
        if (isDif) {
            mxA = max(mxA, a[i]);
            miA = min(miA, a[i]);
            mxB = max(mxB, b[i]);
            miB = min(miB, b[i]);

            if (i > 0 && b[i] < b[i-1]) isInc = false;

            if (isInc && mxA == mxB && miA == miB) {
                isDif = false;
                start = -1;
            }
        }
    }
    cout << (isDif ? "NO\n" : "YES\n");
}