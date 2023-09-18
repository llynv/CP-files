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
    // int t;
    // cin >> t;
    // while (t--)
        solve();
    return 0;
}

const int INF = 0x3f3f3f3f3f;
const int N = 2e5 + 7;

int a[N];

struct SegTree
{
    int height, type;
};

SegTree it[4 * N];

void lazyUpdate(int index, int L, int R)
{
    int t = it[index].type;
    if (t == 0) return;
    int mid = (L + R) >> 1;
    it[index*2].type = it[index*2+1].type = t;
    }

void update (int index, int L, int R, int l, int r, int val)
{
    if (L > r || R < l) return;
    if (l <= L && R <= r) {
        it[index].val += (R - L + 1) * val;
        it[index].updateVal += val;
        lazyUpdate(index, L, R);
        return;
    }
    lazyUpdate(index, L, R);
    int mid = (L + R) >> 1;
    update(index*2, L, mid, l, r, val);
    update(index*2+1, mid+1, R, l, r, val);
    it[index].val = it[2 * index].val + it[2 * index + 1].val;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        --r;
        if (t == 1) {
            int v;
            cin >> v;
            update(1, 0, n-1, l, r, v);
        } else {
            cout << get(1, 0, n-1, l, r) << endl;
        }
        // cout << get(1, 0, n-1, 0, n-1) << endl;

    }
}
